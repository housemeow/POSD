#include "stdafx.h"
#include "mind_map_window.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MindMapWindow w;
    w.show();
    return a.exec();
}
