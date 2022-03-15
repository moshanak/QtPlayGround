#ifndef SCENEGRAPHRENDERER_H
#define SCENEGRAPHRENDERER_H
#include <QObject>
#include <QSize>
#include <QQuickWindow>

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

public slots:
    void init();
    void paint();

private:
    QSize m_viewportSize;
    QQuickWindow* m_window;
    bool isGlewInit_;
};
#endif //SCENEGRAPHRENDERER_H