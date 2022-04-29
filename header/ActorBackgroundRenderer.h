#ifndef ACTORTRIANGLETESTRENDERER_H
#define ACTORTRIANGLETESTRENDERER_H
#include "ActorBaseRenderer.h"
class ActorBackgroundRenderer : public ActorBaseRenderer
{
public:
	ActorBackgroundRenderer() = delete;
	ActorBackgroundRenderer(const int& actorID);

	void draw() final;
};
#endif // ACTORTRIANGLETESTRENDERER_H