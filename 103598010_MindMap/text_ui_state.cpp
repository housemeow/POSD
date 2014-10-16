#include "stdafx.h"
#include "text_ui_state.h"
#include "menu_state.h"
#include "mind_map_model.h"

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

// �n�D�ϥΪ̿�J�@�Ӿ��
int TextUIState::readInt()
{
    _textUIView.printInputNotify();
    int integer;
    cin >> integer;
    return integer;
}


// �n�D�ϥΪ̿�J�@�Ӧr��
char TextUIState::readChar()
{
    _textUIView.printInputNotify();
    char character;
    cin >> character;
    return character;
}