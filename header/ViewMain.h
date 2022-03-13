#ifndef VIEWMAIN_H
#define VIEWMAIN_H
#include "ViewBase.h"

class ViewMain : public ViewBase
{
    Q_OBJECT
public:
    explicit ViewMain(QWindow* parent);
    void initialize();
};
#endif //VIEWMAIN_H