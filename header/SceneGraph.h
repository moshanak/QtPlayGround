#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H
#include <QObject>

class SceneBase;

class SceneGraph : public QObject
{
    Q_OBJECT
public:
    explicit SceneGraph(QObject* parent);

public slots:
    void init();
    void paint();

private:
    std::vector<std::shared_ptr<SceneBase>> scenes_;
    bool isGlewInit_;
};
#endif //SCENEGRAPH_H