#ifndef ACTORTRIANGLETESTRENDERER_H
#define ACTORTRIANGLETESTRENDERER_H
#include "ActorBaseRenderer.h"
class ActorTriangleTestRenderer : public ActorBaseRenderer
{
public:
    ActorTriangleTestRenderer() = delete;
    ActorTriangleTestRenderer(const int& actorID);

    void draw() final;
};
#endif //ACTORTRIANGLETESTRENDERER_H