#ifndef ACTORTRIANGLETESTRENDERER_H
#define ACTORTRIANGLETESTRENDERER_H
#include "ActorBaseRenderer.h"
class ActorTriangleRenderer : public ActorBaseRenderer
{
public:
	ActorTriangleRenderer() = delete;
	ActorTriangleRenderer(const int& actorID);

	void draw() final;
};
#endif // ACTORTRIANGLETESTRENDERER_H