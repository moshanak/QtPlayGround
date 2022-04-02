#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include "SceneBase.h"
#include <memory>
#include <vector>
class ActorBase;

class SceneMain : public SceneBase
{
public:
	SceneMain() = delete;
	SceneMain(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer);

	void initialize();
};
#endif // SCENEMAIN_H