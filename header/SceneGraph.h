#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H
#include "SceneGraphRenderer.h"
#include <QQuickItem>

class SceneBase;

class SceneGraph : public QQuickItem
{
	Q_OBJECT
public:
	SceneGraph();

public slots:
	void sync();
	void cleanup();

private slots:
	void handleWindowChanged(QQuickWindow* win);

private:
	void releaseResources() override;

	std::unordered_map<QString, std::shared_ptr<SceneBase>> scenes_;
	QString currentSceneName_;
	std::unique_ptr<SceneGraphRenderer> sceneGraphRenderer_;
};
#endif // SCENEGRAPH_H