#ifndef SCENEMAINRENDERER_H
#define SCENEMAINRENDERER_H
#include "SceneBaseRenderer.h"

class SceneMainRenderer : public SceneBaseRenderer
{
public:
    SceneMainRenderer() = delete;
    SceneMainRenderer(const QString& sceneName);

    void draw() final;
};
#endif //SCENEMAINRENDERER_H