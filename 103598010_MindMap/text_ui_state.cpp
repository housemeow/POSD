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

// �n�D�ϥΪ̿�J�@���r
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



// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@�Ӿ��
int TextUIState::readInt()
{
    _textUIView.printInputNotify();
    int integer;
    cin >> integer;
    return integer;
}