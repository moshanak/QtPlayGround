#include "SceneMainRenderer.h"
#include "ActorBaseRenderer.h"

SceneMainRenderer::SceneMainRenderer(const QString& sceneName)
	:SceneBaseRenderer(sceneName)
{
}

void SceneMainRenderer::draw()
{
	for (auto& actorRenderer : actorRenderers_) {
		actorRenderer.second->draw();
	}
}
