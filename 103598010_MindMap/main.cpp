// 103598010_MindMap.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "mind_map_model.h"
#include "text_ui_controller.h"

using namespace std;

// 程式進入點
int _tmain(int argc, _TCHAR* argv[])
{
    MindMapModel mindMapModel;
    TextUIController textUIController(&mindMapModel, cout, cin);
    textUIController.run();
//    while (textUIController.performUI());
    system("pause");
    return 0;
}