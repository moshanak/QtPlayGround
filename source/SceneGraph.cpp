#include "SceneGraph.h"
#include "SceneGraphRenderer.h"
#include <QQuickWindow>
#include <QRunnable>

SceneGraph::SceneGraph()
    :QQuickItem(nullptr)
    ,m_renderer(nullptr)
{
    //ウィンドウに変化があったときに呼ばれるシグナルと接続する
    //QQuickItem はデフォルトでは QQuickWindow に属していない（どこに描画するか決まっていない）
    //どの QQuickWindow に属するか決まったタイミングと、QQuickWindow から外れるタイミングでも windowChanged シグナルは呼ばれる
    connect(this, &QQuickItem::windowChanged, this, &SceneGraph::handleWindowChanged);
}

void SceneGraph::handleWindowChanged(QQuickWindow* win)
{
    if (win) {
        //GUI スレッドをブロックする直前に呼ばれるシグナルを接続する
        //このスロットで GUI の設定をレンダラーに渡す
        //DirectConnection は RENDER スレッドで接続するために必須。
        //これがないとレンダリングコンテキストが存在しないスレッドで接続されるケースが出てくる。
        connect(win, &QQuickWindow::beforeSynchronizing, this, &SceneGraph::sync, Qt::DirectConnection);

        //レンダリングコンテキストが無効になったときに呼ばれるシグナルに接続する
        //このスロットでレンダラーを破棄する
        //DirectConnection は RENDER スレッドで接続するために必須。
        //これがないとレンダリングコンテキストが存在しないスレッドで接続されるケースが出てくる。
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &SceneGraph::cleanup, Qt::DirectConnection);

        // Ensure we start with cleared to black. The squircle's blend mode relies on this.
        //win->setColor(Qt::black);
    }
}

void SceneGraph::cleanup()
{
    delete m_renderer;
    m_renderer = nullptr;
}

class CleanupJob : public QRunnable
{
public:
    CleanupJob(SceneGraphRenderer* renderer) : m_renderer(renderer) { }
    void run() override {
        delete m_renderer;
    }
private:
    SceneGraphRenderer* m_renderer;
};

void SceneGraph::releaseResources()
{
    //RENDER スレッドで OpenGL の終了処理を実行するために使う
    //レンダリングしている時に、１度だけ実行する（one shot）タスクを予約する
    //第一引数が実行タスク、第二引数でレンダリング中のどのタイミングで実行するか変更可
    //Squircle::cleanup()でも同様の処理を記述しているが、それだけではすべてのケースの終了処理をカバーできないため、この処理が必要
    window()->scheduleRenderJob(new CleanupJob(m_renderer), QQuickWindow::BeforeSynchronizingStage);
    m_renderer = nullptr;
}

void SceneGraph::sync()
{
    if (!m_renderer) {
        m_renderer = new SceneGraphRenderer(nullptr);
        //レンダリング前に呼ばれるシグナルを接続する
        //このスロットではOpenGLのAPIを直接呼ぶことが可能
        connect(window(), &QQuickWindow::beforeRendering, m_renderer, &SceneGraphRenderer::init, Qt::DirectConnection);
        //beforeRendering のあとに呼ばれるシグナルを接続する
        //RHIを使う場合、メインレンダリングパスのコマンドバッファに記録することが可能(vulkan,directxで考慮が必要)
        //OpenGLのAPIを直接呼びたい場合は、このシグナルスロットではなく、前述のbeforeRenderingかafterRenderingシグナルを使う
        connect(window(), &QQuickWindow::beforeRenderPassRecording, m_renderer, &SceneGraphRenderer::paint, Qt::DirectConnection);
    }
    m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
    m_renderer->setWindow(window());
}
