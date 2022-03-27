#ifndef ACTORTRIANGLETEST_H
#define ACTORTRIANGLETEST_H
#include "ActorBase.h"

class ActorTriangle : public ActorBase
{
public:
    ActorTriangle() = delete;
    ActorTriangle(const int& actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer);
    void initialize();
};
#endif //ACTORTRIANGLETEST_H