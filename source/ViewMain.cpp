#include "ViewMain.h"

ViewMain::ViewMain(QWindow* parent)
	:ViewBase(parent)
{
}

void ViewMain::initialize()
{
	setResizeMode(QQuickView::SizeRootObjectToView);
	setSource(QUrl("qrc:///main.qml"));
	show();
}
