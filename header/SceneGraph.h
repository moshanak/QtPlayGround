#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H
#include <QQuickItem>
#include "SceneGraphRenderer.h"
//class SceneGraphRenderer;

class SceneGraph : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit SceneGraph();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow* win);

private:
    void releaseResources() override;

    SceneGraphRenderer* m_renderer;
};
#endif //SCENEGRAPH_H