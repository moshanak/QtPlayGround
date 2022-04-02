#include "ViewMain.h"

ViewMain::ViewMain(QQuickView* parent)
	:ViewBase(parent)
{
	if (parent) {
		connect(parent, &QQuickWindow::widthChanged, this, &ViewBase::setWidth);
		connect(parent, &QQuickWindow::heightChanged, this, &ViewBase::setHeight);
	}
}

void ViewMain::initialize()
{
	setResizeMode(QQuickView::SizeRootObjectToView);
	setSource(QUrl("qrc:///ViewMain.qml"));
	resize(parent()->size());
	show();
}
