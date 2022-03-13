#include "TestView.h"
#include <fstream>

TestView::TestView(QWindow* parent)
	:QQuickView(parent)
    , oldParent_(parent)
{
}

void TestView::mousePressEvent(QMouseEvent*)
{
    using namespace std;
    ofstream ofs("log.txt");
    ofs << "onmouse" << endl;

    if (parent() != nullptr) {
        setParent(nullptr);
    }
    else {
        setParent(oldParent_);
    }
}