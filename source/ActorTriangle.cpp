#include "ActorTriangle.h"

ActorTriangle::ActorTriangle(const int& actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer)
	: ActorBase(actorID, actorRenderer)
{
}

void ActorTriangle::initialize() {}
