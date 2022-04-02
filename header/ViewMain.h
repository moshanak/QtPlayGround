#ifndef VIEWMAIN_H
#define VIEWMAIN_H
#include "ViewBase.h"

class ViewMain : public ViewBase
{
	Q_OBJECT
public:
	ViewMain() = delete;
	explicit ViewMain(QQuickView* parent);
	void initialize();
};
#endif // VIEWMAIN_H