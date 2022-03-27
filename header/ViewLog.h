#ifndef VIEWLOG_H
#define VIEWLOG_H
#include "ViewBase.h"

class ViewLog : public ViewBase
{
    Q_OBJECT
public:
    ViewLog() = delete;
    explicit ViewLog(QQuickView* parent);
    void initialize();
};
#endif //VIEWLOG_H