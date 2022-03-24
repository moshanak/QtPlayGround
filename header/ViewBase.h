#ifndef VIEWBASE_H
#define VIEWBASE_H
#include <QQuickView>

class ViewBase : public QQuickView
{
    Q_OBJECT
public:
    ViewBase() = delete;
    explicit ViewBase(QWindow* parent);
    virtual ~ViewBase();
};
#endif //VIEWBASE_H