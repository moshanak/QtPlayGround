#ifndef ACTORBASERENDERER_H
#define ACTORBASERENDERER_H
#include <GL/glew.h>

class ActorBaseRenderer
{
public:
    ActorBaseRenderer() = delete;
    ActorBaseRenderer(const int& actorID);
    virtual ~ActorBaseRenderer();

    virtual void draw() = 0;

    const int& getActorID() const { return actorID_; }
private:
    int actorID_;
};
#endif //ACTORBASERENDERER_H