#include "WindowMain.h"
#include "ViewMain.h"

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

	std::shared_ptr<ViewMain> mainView = std::make_shared<ViewMain>(this);
    mainView->initialize();
	views_.push_back(mainView);
}
