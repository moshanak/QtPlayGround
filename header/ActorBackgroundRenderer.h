#ifndef ACTORBACKGROUNDRENDERER_H
#define ACTORBACKGROUNDRENDERER_H
#include "ActorBaseRenderer.h"

class ActorBackgroundRenderer : public ActorBaseRenderer
{
public:
	ActorBackgroundRenderer() = delete;
	ActorBackgroundRenderer(const int& actorID);

	void draw() final;
};
#endif // ACTORBACKGROUNDRENDERER_H