// 103598010_MindMap.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "mind_map_model.h"
#include "text_ui_controller.h"
#include "text_ui_view.h"

using namespace std;

// �{���i�J�I
int _tmain(int argc, _TCHAR* argv[])
{
    MindMapModel mindMapModel;
    TextUIView textUIView(cout);
    TextUIController textUIController(&mindMapModel, &textUIView);
    textUIController.run();
    return 0;
}