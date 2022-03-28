#include "ViewLog.h"

ViewLog::ViewLog(QQuickView* parent)
	:ViewBase(parent)
	, m_t(0)
{
}

void ViewLog::initialize()
{
	setResizeMode(QQuickView::SizeRootObjectToView);
	setSource(QUrl("qrc:///ViewLog.qml"));
	show();
}

void ViewLog::setT(qreal t)
{
	if (m_t == t) {
		return;
	}
	m_t = t;
	emit tChanged();
}
