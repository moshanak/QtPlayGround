#ifndef ACTORTRIANGLETEST_H
#define ACTORTRIANGLETEST_H
#include "ActorBase.h"

class ActorTriangleTest : public ActorBase
{
public:
    ActorTriangleTest() = delete;
    ActorTriangleTest(const int& actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer);
    void initialize();
};
#endif //ACTORTRIANGLETEST_H