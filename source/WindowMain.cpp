#include "WindowMain.h"
#include "ViewMain.h"
#include "ViewLog.h"

WindowMain::WindowMain(QWindow* parent)
	:QQuickView(parent)
{
}

void WindowMain::initialize()
{
    //ウィンドウのサイズが変化した時に、GUI も追従して自動でリサイズしてくれる設定
    //もし QQuickView::SizeViewToRootObject をセットすれば、自動でリサイズしなくなる
    setResizeMode(QQuickView::SizeRootObjectToView);

    setSource(QUrl("qrc:///WindowMain.qml"));
    show();

    std::shared_ptr<ViewMain> viewMain = std::make_shared<ViewMain>(this);
    viewMain->initialize();
    views_.push_back(viewMain);

    std::shared_ptr<ViewLog> viewLog = std::make_shared<ViewLog>(this);
    viewLog->initialize();
    views_.push_back(viewLog);
}
