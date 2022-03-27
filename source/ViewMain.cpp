#include "ViewMain.h"

ViewMain::ViewMain(QQuickView* parent)
	:ViewBase(parent)
{
}

void ViewMain::initialize()
{
	setResizeMode(QQuickView::SizeRootObjectToView);
	setSource(QUrl("qrc:///ViewMain.qml"));
	resize(parent()->size());
	show();
}
