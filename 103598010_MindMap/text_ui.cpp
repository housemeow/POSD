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

// 執行TextUI
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

// 建立MindMap
bool TextUI::createMindMap()
{
    string description;
    description = readLineString(kTextUICreateMindMapMessage);
    _mindMapModel->createMindMap(description);
    displayMindMap();
    return true;
}

// 顯示提示訊息並要求使用者輸入一個整數
int TextUI::readInt(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    int integer;
    _istream >> integer;
    return integer;
}

// 顯示提示訊息並要求使用者輸入一行文字
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

// 顯示提示訊息並要求使用者輸入一個字元
char TextUI::readChar(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    char character;
    _istream >> character;
    return character;
}

// 讓使用者加入一個節點
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

// 在螢幕上顯示MindMap
bool TextUI::displayMindMap()
{
    _ostream << _mindMapModel->getMindMapDisplayString() << endl;
    return true;
}

// 儲存MindMap
bool TextUI::saveMindMap()
{
    _mindMapModel->saveMindMap();
    _ostream << kSaveMindMapSuccess;
    return true;
}

// 離開主程式
bool TextUI::exit()
{
    return false;
}
