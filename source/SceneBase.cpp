#include "SceneBase.h"
#include "ActorBase.h"
#include "ActorBaseRenderer.h"
#include "SceneBaseRenderer.h"

SceneBase::SceneBase(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer)
	: sceneName_(sceneName)
	, sceneRenderer_(sceneRenderer)
{
}

SceneBase::~SceneBase() {}

void SceneBase::addActor(std::shared_ptr<ActorBase> actor, std::shared_ptr<ActorBaseRenderer> actorRenderer)
{
	actors_.emplace(actor->getActorID(), actor);
	sceneRenderer_->addActorRenderer(actorRenderer);
}
