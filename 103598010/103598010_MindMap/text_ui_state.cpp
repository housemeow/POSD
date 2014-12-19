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

// �n�D�ϥΪ̿�J�@���r
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

// �n�D�ϥΪ̿�J�@�Ӿ��
int TextUIState::readInt(bool printNotify)
{
    if (printNotify)
        _textUIView->printInputNotify();
    int integer;
    *cin >> integer;
    return integer;
}


// �n�D�ϥΪ̿�J�@�Ӧr��
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