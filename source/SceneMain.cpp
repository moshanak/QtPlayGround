#include "SceneMain.h"
#include "ActorTriangleTest.h"

SceneMain::SceneMain()
{
}

void SceneMain::initialize()
{
	std::shared_ptr<ActorTriangleTest> sctorTriangleTest = std::make_shared<ActorTriangleTest>();
	actors_.push_back(sctorTriangleTest);
}
