#ifndef SCENEBASE_H
#define SCENEBASE_H
#include <QObject>

class SceneBase : public QObject
{
    Q_OBJECT
public:
    explicit SceneBase(QObject* parent);
};
#endif //SCENEBASE_H