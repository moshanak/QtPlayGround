#ifndef SCENEBASERENDERER_H
#define SCENEBASERENDERER_H
#include <GL/glew.h>
#include <QString>
#include <map>

class ActorBaseRenderer;

class SceneBaseRenderer
{
public:
	SceneBaseRenderer() = delete;
	SceneBaseRenderer(const QString& sceneName);
	virtual ~SceneBaseRenderer();

	virtual void draw() = 0;

	void addActorRenderer(std::shared_ptr<ActorBaseRenderer> actorRenderer);

	const QString& getSceneName() const { return sceneName_; }

protected:
	std::map<int, std::shared_ptr<ActorBaseRenderer>> actorRenderers_;

private:
	QString sceneName_;
};
#endif // SCENEBASERENDERER_H