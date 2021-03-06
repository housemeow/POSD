#include "stdafx.h"
#include "text_ui_state.h"
#include "menu_state.h"
#include "mind_map_model.h"

TextUIState::TextUIState(MindMapModel* mindMapModel)
{
    _mindMapModel = mindMapModel;
    cin = &std::cin;
}


TextUIState::~TextUIState()
{
}


void TextUIState::setTextUIView(TextUIView* textUIView)
{
    _textUIView = textUIView;
}

// 要求使用者輸入一行文字
string TextUIState::readLineString(bool printNotify)
{
    string line;
    if (printNotify)
        _textUIView->printInputNotify();
    while (getline(*cin, line)) {
        if (!line.empty()) {
            return line;
        }
    }
    return "";
}

// 要求使用者輸入一個整數
int TextUIState::readInt(bool printNotify)
{
    if (printNotify)
        _textUIView->printInputNotify();
    int integer;
    *cin >> integer;
    return integer;
}


// 要求使用者輸入一個字元
char TextUIState::readChar(bool printNotify)
{
    if (printNotify)
        _textUIView-> printInputNotify();
    char character;
    *cin >> character;
    return character;
}
void TextUIState::setIStream(istream* istream)
{
    cin = istream;
}