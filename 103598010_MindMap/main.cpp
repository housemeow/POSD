// 103598010_MindMap.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "mind_map_model.h"
#include "text_ui.h"

using namespace std;

// 程式進入點
int _tmain(int argc, _TCHAR* argv[])
{
    MindMapModel mindMapModel;
    TextUI textUI(&mindMapModel, cout, cin);
    while (textUI.performUI());
    return 0;
}