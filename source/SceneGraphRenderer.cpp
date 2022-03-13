#include "SceneGraphRenderer.h"
#include <QQuickWindow>
#include <GL/glew.h>

SceneGraphRenderer::SceneGraphRenderer(QObject* parent)
    :QObject(parent)
    ,isGlewInit_(true)
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
    }
}
void SceneGraphRenderer::paint()
{
    m_window->beginExternalCommands();
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    m_window->endExternalCommands();
}