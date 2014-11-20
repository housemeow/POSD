#include "stdafx.h"
#include "mind_map_window.h"
#include <QtWidgets/QApplication>
#include "node.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MindMapWindow w;
    Node c(1);
    w.show();
    return a.exec();
}
