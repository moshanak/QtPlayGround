#ifndef VIEWLOG_H
#define VIEWLOG_H
#include "ViewBase.h"

class ViewLog : public ViewBase
{
    Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)
public:
    ViewLog() = delete;
    explicit ViewLog(QQuickView* parent);
    void initialize();

    qreal t() const { return m_t; }
    void setT(qreal t);

signals:
    void tChanged();

private:
    qreal m_t;
};
#endif //VIEWLOG_H