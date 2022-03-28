#include <QGuiApplication>
#include "WindowMain.h"
#include "SceneGraph.h"
#include "Logger.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    //高 DPI のモニターで表示する時に、GUI が小さくなりすぎないように、自動調整してくれる設定
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //Qtで使用するグラフィックスライブラリを指定する
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);

    qmlRegisterSingletonInstance("Qt.example.qobjectSingleton", 1, 0, "MyApi", &Logger::getInstance());
    qmlRegisterType<SceneGraph>("SceneGraph", 1, 0, "SceneGraph");

    WindowMain mainWindow(nullptr);
    mainWindow.initialize();

    return app.exec();
}
