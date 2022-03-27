#include "ViewLog.h"

ViewLog::ViewLog(QQuickView* parent)
	:ViewBase(parent)
{
}

void ViewLog::initialize()
{
	//setResizeMode(QQuickView::SizeRootObjectToView);
	setSource(QUrl("qrc:///ViewLog.qml"));
	show();
}
