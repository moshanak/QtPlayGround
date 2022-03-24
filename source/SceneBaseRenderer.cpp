#include "SceneBaseRenderer.h"
#include "ActorBaseRenderer.h"

SceneBaseRenderer::SceneBaseRenderer(const QString& sceneName)
	:sceneName_(sceneName)
{
}

SceneBaseRenderer::~SceneBaseRenderer()
{
}

void SceneBaseRenderer::addActorRenderer(std::shared_ptr<ActorBaseRenderer> actorRenderer)
{
	actorRenderers_.emplace(actorRenderer->getActorID(), actorRenderer);
}
