#include "ActorBackgroundRenderer.h"

ActorBackgroundRenderer::ActorBackgroundRenderer(const int& actorID)
	: ActorBaseRenderer(actorID)
{
}

void ActorBackgroundRenderer::draw()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
