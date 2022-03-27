#include "SceneGraph.h"
#include "SceneGraphRenderer.h"
#include "SceneMain.h"
#include "SceneMainRenderer.h"
#include <QQuickWindow>
#include <QRunnable>

SceneGraph::SceneGraph()
    :QQuickItem(nullptr)
    ,sceneGraphRenderer_(nullptr)
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
    }
}

void SceneGraph::cleanup()
{
    sceneGraphRenderer_.release();
}

void SceneGraph::releaseResources()
{
    class CleanupJob : public QRunnable
    {
    public:
        CleanupJob(std::unique_ptr<SceneGraphRenderer>&& renderer) : sceneGraphRenderer_(std::move(renderer)) { }
        void run() override {
            sceneGraphRenderer_.release();
        }
    private:
        std::unique_ptr<SceneGraphRenderer> sceneGraphRenderer_;
    };

    //RENDER スレッドで OpenGL の終了処理を実行するために使う
    //レンダリングしている時に、１度だけ実行する（one shot）タスクを予約する
    //第一引数が実行タスク、第二引数でレンダリング中のどのタイミングで実行するか変更可
    //Squircle::cleanup()でも同様の処理を記述しているが、それだけではすべてのケースの終了処理をカバーできないため、この処理が必要
    window()->scheduleRenderJob(new CleanupJob(std::move(sceneGraphRenderer_)), QQuickWindow::BeforeSynchronizingStage);
}

void SceneGraph::sync()
{
    if (!sceneGraphRenderer_) {
        sceneGraphRenderer_ = std::make_unique<SceneGraphRenderer>(nullptr);
        //レンダリング前に呼ばれるシグナルを接続する
        //このスロットではOpenGLのAPIを直接呼ぶことが可能
        connect(window(), &QQuickWindow::beforeRendering, sceneGraphRenderer_.get(), &SceneGraphRenderer::init, Qt::DirectConnection);
        //beforeRendering のあとに呼ばれるシグナルを接続する
        //RHIを使う場合、メインレンダリングパスのコマンドバッファに記録することが可能(vulkan,directxで考慮が必要)
        //OpenGLのAPIを直接呼びたい場合は、このシグナルスロットではなく、前述のbeforeRenderingかafterRenderingシグナルを使う
        connect(window(), &QQuickWindow::beforeRenderPassRecording, sceneGraphRenderer_.get(), &SceneGraphRenderer::paint, Qt::DirectConnection);
    }

    //<todo>: GUIからイベントをもらってから、シーンを作る仕組みにした方がよい
    if (scenes_.empty()) {
        const QString sceneName("main");
        std::shared_ptr<SceneMainRenderer> sceneMainRenderer = std::make_shared<SceneMainRenderer>(sceneName);
        std::shared_ptr<SceneMain> mainScene = std::make_shared<SceneMain>(sceneName, sceneMainRenderer);
        mainScene->initialize();
        scenes_.emplace(sceneName, mainScene);
        sceneGraphRenderer_->addSceneRenderer(sceneMainRenderer);
        currentSceneName_ = sceneName;
    }

    QSize test=window()->size();
    qreal test2=window()->devicePixelRatio();
    auto test3 = window()->visibility();
    auto test6 = window()->windowState();
    auto test34 = window()->flags();
    sceneGraphRenderer_->setViewportSize(window()->size() * window()->devicePixelRatio());
    sceneGraphRenderer_->setWindow(window());
    sceneGraphRenderer_->setCurrentSceneName(currentSceneName_);
}
