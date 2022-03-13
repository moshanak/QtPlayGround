#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "squircle.h"
#include "TestView.h"

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

    QQuickView view;

    //ウィンドウのサイズが変化した時に、GUI も追従して自動でリサイズしてくれる設定
    //もし QQuickView::SizeViewToRootObject をセットすれば、自動でリサイズしなくなる
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    //QQuickView view2(&view);
    TestView view2(&view);

    //ウィンドウのサイズが変化した時に、GUI も追従して自動でリサイズしてくれる設定
    //もし QQuickView::SizeViewToRootObject をセットすれば、自動でリサイズしなくなる
    view2.setResizeMode(QQuickView::SizeRootObjectToView);

    view2.setSource(QUrl("qrc:///sub.qml"));
    view2.show();

//    view2.setParent(nullptr);

    return app.exec();
}
