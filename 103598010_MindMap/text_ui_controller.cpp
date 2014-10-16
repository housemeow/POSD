#include "stdafx.h"
#include "text_ui_controller.h"
#include "mind_map_model.h"
#include "componentFactory.h"
#include "text_ui_state.h"
#include "menu_state.h"

using namespace std;

TextUIController::TextUIController(MindMapModel* mindMapModel, ostream& ostream, istream& istream)
    : _ostream(ostream), _istream(istream)
{
    _mindMapModel = mindMapModel;
    _instructionMap[1] = &TextUIController::createMindMap;
    _instructionMap[2] = &TextUIController::insertNewNode;
    _instructionMap[3] = &TextUIController::displayMindMap;
    _instructionMap[4] = &TextUIController::saveMindMap;
    _instructionMap[5] = &TextUIController::exit;
}

TextUIController::~TextUIController()
{
}


void TextUIController::run()
{
    TextUIState* state = new MenuState();
    do {
        TextUIState* nextState = state->run();
        delete state;
        state = nextState;
    } while(state != NULL);
}


// 執行TextUI
bool TextUIController::performUI()
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
bool TextUIController::createMindMap()
{
    string description;
    description = readLineString(kTextUICreateMindMapMessage);
    _mindMapModel->createMindMap(description);
    displayMindMap();
    return true;
}

// 顯示提示訊息並要求使用者輸入一個整數
int TextUIController::readInt(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    int integer;
    _istream >> integer;
    return integer;
}

// 顯示提示訊息並要求使用者輸入一行文字
string TextUIController::readLineString(string message)
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
char TextUIController::readChar(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    char character;
    _istream >> character;
    return character;
}

// 讓使用者加入一個節點
bool TextUIController::insertNewNode()
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
bool TextUIController::displayMindMap()
{
    _ostream << _mindMapModel->getMindMapDisplayString() << endl;
    return true;
}

// 儲存MindMap
bool TextUIController::saveMindMap()
{
    _mindMapModel->saveMindMap();
    _ostream << kSaveMindMapSuccess;
    return true;
}

// 離開主程式
bool TextUIController::exit()
{
    return false;
}
