#include "SceneGraphRenderer.h"
#include "SceneMainRenderer.h"
#include "GLSLManager.h"
#include <QQuickWindow>
#include <GL/glew.h>

SceneGraphRenderer::SceneGraphRenderer(QObject* parent)
    :QObject(parent)
    , m_window(nullptr)
    , isGlewInit_(true)
{
}

SceneGraphRenderer::~SceneGraphRenderer()
{
}

void SceneGraphRenderer::init()
{
    if (isGlewInit_) {
        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            //using namespace std;
            //ofstream ofs("log.txt");
            ///* Problem: glewInit failed, something is seriously wrong. */
            //ofs << "Error: " << glewGetErrorString(err);
            return;
        }
        isGlewInit_ = false;

        // シェーダーの初期化
        GLSLManager::getInstance();
    }
}

void SceneGraphRenderer::addSceneRenderer(std::shared_ptr<SceneBaseRenderer> sceneRenderer)
{
    sceneRenderers_.emplace(sceneRenderer->getSceneName(), sceneRenderer);
}

void SceneGraphRenderer::paint()
{
    m_window->beginExternalCommands();
    sceneRenderers_.at(currentSceneName_)->draw();
    m_window->endExternalCommands();
}