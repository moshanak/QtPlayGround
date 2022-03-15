#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include "SceneBase.h"
#include <vector>
#include <memory>
class ActorBase;

class SceneMain : public SceneBase
{
public:
    SceneMain();
    void initialize();
private:
    std::vector<std::shared_ptr<ActorBase>> actors_;
};
#endif //SCENEMAIN_H