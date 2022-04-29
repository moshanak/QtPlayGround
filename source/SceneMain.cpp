#include "SceneMain.h"
#include "ActorTriangle.h"
#include "ActorTriangleRenderer.h"
#include "ActorBackground.h"
#include "ActorBackgroundRenderer.h"

SceneMain::SceneMain(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer)
	: SceneBase(sceneName, sceneRenderer)
{
}

void SceneMain::initialize()
{
	int actorID = 0;
	std::shared_ptr<ActorBackgroundRenderer> actorBackgroundRenderer =
		std::make_shared<ActorBackgroundRenderer>(actorID);
	std::shared_ptr<ActorBackground> actorBackground =
		std::make_shared<ActorBackground>(actorID, actorBackgroundRenderer);
	addActor(actorBackground, actorBackgroundRenderer);

	actorID = 1;
	std::shared_ptr<ActorTriangleRenderer> actorTriangleRenderer = std::make_shared<ActorTriangleRenderer>(actorID);
	std::shared_ptr<ActorTriangle> actorTriangle = std::make_shared<ActorTriangle>(actorID, actorTriangleRenderer);
	addActor(actorTriangle, actorTriangleRenderer);
}
