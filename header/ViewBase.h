#ifndef VIEWBASE_H
#define VIEWBASE_H
#include <QQuickView>

class ViewBase : public QQuickView
{
    Q_OBJECT
public:
    explicit ViewBase(QWindow* parent);
};
#endif //VIEWBASE_H