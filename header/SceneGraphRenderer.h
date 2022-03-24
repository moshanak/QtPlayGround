#ifndef SCENEGRAPHRENDERER_H
#define SCENEGRAPHRENDERER_H
#include <QObject>
#include <QSize>
#include <QQuickWindow>
class SceneBaseRenderer;

class SceneGraphRenderer : public QObject
{
    Q_OBJECT
public:
    SceneGraphRenderer() = delete;
    explicit SceneGraphRenderer(QObject* parent);
    ~SceneGraphRenderer();
    SceneGraphRenderer(const SceneGraphRenderer&) = delete;
    SceneGraphRenderer& operator=(const SceneGraphRenderer&) = delete;
    SceneGraphRenderer(SceneGraphRenderer&&) = default;
    SceneGraphRenderer& operator=(SceneGraphRenderer&&) = default;


    void setViewportSize(const QSize& size) { m_viewportSize = size; }
    void setWindow(QQuickWindow* window) { m_window = window; }
    void addSceneRenderer(std::shared_ptr<SceneBaseRenderer> sceneRenderer);
    void setCurrentSceneName(const QString& currentSceneName) { currentSceneName_ = currentSceneName; }

public slots:
    void init();
    void paint();

private:
    QSize m_viewportSize;
    QQuickWindow* m_window;
    bool isGlewInit_;
    QString currentSceneName_;
    std::unordered_map<QString, std::shared_ptr<SceneBaseRenderer>> sceneRenderers_;
};
#endif //SCENEGRAPHRENDERER_H