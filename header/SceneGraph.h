#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H
#include "SceneGraphRenderer.h"
#include <QQuickItem>

class SceneBase;

class SceneGraph : public QQuickItem
{
    Q_OBJECT
public:
    explicit SceneGraph();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow* win);

private:
    void releaseResources() override;

    std::vector<std::shared_ptr<SceneBase>> scenes_;
    std::unique_ptr<SceneGraphRenderer> m_renderer;
};
#endif //SCENEGRAPH_H