#include "stdafx.h"
#include "text_ui.h"
#include "mind_map_model.h"
#include "componentFactory.h"

using namespace std;

TextUI::TextUI(MindMapModel* mindMapModel, ostream& ostream, istream& istream)
    : _ostream(ostream), _istream(istream)
{
    _mindMapModel = mindMapModel;
    _instructionMap[1] = &TextUI::createMindMap;
    _instructionMap[2] = &TextUI::insertNewNode;
    _instructionMap[3] = &TextUI::displayMindMap;
    _instructionMap[4] = &TextUI::saveMindMap;
    _instructionMap[5] = &TextUI::exit;
}

TextUI::~TextUI()
{
}

// ����TextUI
bool TextUI::performUI()
{
    int instruction = readInt(kTextUIMenuString);
    if (_instructionMap[instruction]) {
        _ostream << endl;
        bool result = (this->*_instructionMap[instruction])();
        _ostream << endl;
        return result;
    }
    return true;
}

// �إ�MindMap
bool TextUI::createMindMap()
{
    string description;
    description = readLineString(kTextUICreateMindMapMessage);
    _mindMapModel->createMindMap(description);
    displayMindMap();
    return true;
}

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@�Ӿ��
int TextUI::readInt(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    int integer;
    _istream >> integer;
    return integer;
}

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@���r
string TextUI::readLineString(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    string line;
    while (getline(_istream, line)) {
        if (!line.empty()) {
            return line;
        }
    }
    return "";
}

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@�Ӧr��
char TextUI::readChar(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    char character;
    _istream >> character;
    return character;
}

// ���ϥΪ̥[�J�@�Ӹ`�I
bool TextUI::insertNewNode()
{
    if (!_mindMapModel->getMindMap()) {
        _ostream << kMindMapNotExist;
        return true;
    }
    displayMindMap();
    int id;
    Component* component = NULL;
    while (component == NULL) {
        id = readInt(kTextUIEnterNodeIdMessage);
        _ostream << endl;
        component = _mindMapModel->getMindMap()->findNode(id);
    }
    ComponentFactory factory;
    bool continueInput = true;
    while (continueInput) {
        char instruction = readChar(kTextUIInsertNewNodeMenu);
        try {
            _mindMapModel->tryInsertNewNode(component, (InsertNodeMode)instruction);
            string description = readLineString(kTextUIEnterNodeNameMessage);
            _mindMapModel->insertNewNode(component, description, (InsertNodeMode)instruction);
            continueInput = false;
        } catch (string exception) {
            _ostream << exception << endl << endl;
        }
    }
    displayMindMap();
    return true;
}

// �b�ù��W���MindMap
bool TextUI::displayMindMap()
{
    _ostream << _mindMapModel->getMindMapDisplayString() << endl;
    return true;
}

// �x�sMindMap
bool TextUI::saveMindMap()
{
    _mindMapModel->saveMindMap();
    _ostream << kSaveMindMapSuccess;
    return true;
}

// ���}�D�{��
bool TextUI::exit()
{
    return false;
}
