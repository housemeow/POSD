#include "stdafx.h"
#include "text_ui_state.h"
#include "menu_state.h"

TextUIState::TextUIState(MindMapModel* mindMapModel)
{
    _mindMapModel = mindMapModel;
}


TextUIState::~TextUIState()
{
}

// 要求使用者輸入一行文字
string TextUIState::readLineString()
{
    string line;
    _textUIView.printInputNotify();
    while (getline(cin, line)) {
        if (!line.empty()) {
            return line;
        }
    }
    return "";
}