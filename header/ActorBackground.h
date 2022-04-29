#ifndef ACTORBACKGROUND_H
#define ACTORBACKGROUND_H
#include "ActorBase.h"

class ActorBackground : public ActorBase
{
public:
	ActorBackground() = delete;
	ActorBackground(const int& actorID, std::shared_ptr<ActorBaseRenderer> actorRenderer);
	void initialize();
};
#endif // ACTORBACKGROUND_H