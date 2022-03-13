#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include <QQuickView>

class WindowMain : public QQuickView
{
    Q_OBJECT
public:
    explicit WindowMain(QWindow* parent);
};
#endif //WINDOWMAIN_H