#include "ActorBase.h"

ActorBase::ActorBase(const int actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer)
	:actorID_(actorID)
	,actorRenderer_(actorRenderer)
{
}

ActorBase::~ActorBase()
{
}
