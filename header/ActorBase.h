#ifndef ACTORBASE_H
#define ACTORBASE_H
#include <memory>

class ActorBaseRenderer;

class ActorBase
{
public:
    ActorBase() = delete;
    ActorBase(const int actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer);
    virtual ~ActorBase();

    const int& getActorID() const { return actorID_; }

private:
    int actorID_;
    std::shared_ptr<ActorBaseRenderer> actorRenderer_;
};
#endif //ACTORBASE_H