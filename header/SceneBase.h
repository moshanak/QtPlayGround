#ifndef SCENEBASE_H
#define SCENEBASE_H
#include <QString>
#include <map>

class ActorBase;
class ActorBaseRenderer;
class SceneBaseRenderer;

class SceneBase
{
public:
	SceneBase() = delete;
	SceneBase(const QString& sceneName, std::shared_ptr<SceneBaseRenderer> sceneRenderer);
	virtual ~SceneBase();

	void addActor(std::shared_ptr<ActorBase> actor, std::shared_ptr<ActorBaseRenderer> actorRenderer);

private:
	QString sceneName_;
	std::map<int, std::shared_ptr<ActorBase>> actors_;
	std::shared_ptr<SceneBaseRenderer> sceneRenderer_;
};
#endif // SCENEBASE_H