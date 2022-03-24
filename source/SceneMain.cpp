#include "SceneMain.h"
#include "ActorTriangleTest.h"
#include "ActorTriangleTestRenderer.h"

SceneMain::SceneMain(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer)
	: SceneBase(sceneName, sceneRenderer)
{
}

void SceneMain::initialize()
{
	const int actorID = 0;
	std::shared_ptr<ActorTriangleTestRenderer> actorTriangleTestRenderer = std::make_shared<ActorTriangleTestRenderer>(actorID);
	std::shared_ptr<ActorTriangleTest> actorTriangleTest = std::make_shared<ActorTriangleTest>(actorID, actorTriangleTestRenderer);
	addActor(actorTriangleTest, actorTriangleTestRenderer);
}
