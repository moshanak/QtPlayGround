#pragma once
#include <qquickview.h>

class TestView : public QQuickView
{
public:
    explicit TestView(QWindow* parent);
    void mousePressEvent(QMouseEvent*) override;
private:
    QWindow* oldParent_;
};