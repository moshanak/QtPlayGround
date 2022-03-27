#include "ViewBase.h"

ViewBase::ViewBase(QQuickView* parent)
	:QQuickView(parent)
{
	if (parent) {
		connect(parent, &QQuickWindow::widthChanged, this, &ViewBase::setWidth);
		connect(parent, &QQuickWindow::heightChanged, this, &ViewBase::setHeight);
	}
}

ViewBase::~ViewBase()
{
}
