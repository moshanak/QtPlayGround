#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <QQuickView>

class ViewBase;

class WindowMain : public QQuickView
{
	Q_OBJECT
public:
	WindowMain() = delete;
	explicit WindowMain(QWindow* parent);

	void initialize();

private:
	std::vector<std::shared_ptr<ViewBase>> views_;
};
#endif // WINDOWMAIN_H