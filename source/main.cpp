#include <QGuiApplication>
#include "squircle.h"
#include "WindowMain.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    //高 DPI のモニターで表示する時に、GUI が小さくなりすぎないように、自動調整してくれる設定
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //Qtで使用するグラフィックスライブラリを指定する
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);

    qmlRegisterType<Squircle>("squircle", 1, 0, "Squircle");

    WindowMain mainWindow(nullptr);
    mainWindow.initialize();

    return app.exec();
}
