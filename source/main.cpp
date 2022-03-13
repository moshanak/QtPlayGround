#include <QGuiApplication>
#include "WindowMain.h"
#include "SceneGraph.h"
#include "squircle.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    //高 DPI のモニターで表示する時に、GUI が小さくなりすぎないように、自動調整してくれる設定
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //Qtで使用するグラフィックスライブラリを指定する
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);

//    qmlRegisterType<Squircle>("SceneGraph", 1, 0, "SceneGraph");
    qmlRegisterType<SceneGraph>("SceneGraph", 1, 0, "SceneGraph");

    WindowMain mainWindow(nullptr);
    mainWindow.initialize();

    return app.exec();
}
