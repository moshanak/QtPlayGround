#include "SceneMain.h"
#include "ActorTriangle.h"
#include "ActorTriangleRenderer.h"

SceneMain::SceneMain(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer)
	: SceneBase(sceneName, sceneRenderer)
{
}

void SceneMain::initialize()
{
	const int actorID = 0;
	std::shared_ptr<ActorTriangleRenderer> actorTriangleTestRenderer = std::make_shared<ActorTriangleRenderer>(actorID);
	std::shared_ptr<ActorTriangle> actorTriangleTest = std::make_shared<ActorTriangle>(actorID, actorTriangleTestRenderer);
	addActor(actorTriangleTest, actorTriangleTestRenderer);
}
