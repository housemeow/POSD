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


// ����TextUI
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

// �إ�MindMap
bool TextUIController::createMindMap()
{
    string description;
    description = readLineString(kTextUICreateMindMapMessage);
    _mindMapModel->createMindMap(description);
    displayMindMap();
    return true;
}

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@�Ӿ��
int TextUIController::readInt(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    int integer;
    _istream >> integer;
    return integer;
}

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@���r
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

// ��ܴ��ܰT���ín�D�ϥΪ̿�J�@�Ӧr��
char TextUIController::readChar(string message)
{
    _ostream << message << kTextUINotifyUserInputCharacter;
    char character;
    _istream >> character;
    return character;
}

// ���ϥΪ̥[�J�@�Ӹ`�I
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

// �b�ù��W���MindMap
bool TextUIController::displayMindMap()
{
    _ostream << _mindMapModel->getMindMapDisplayString() << endl;
    return true;
}

// �x�sMindMap
bool TextUIController::saveMindMap()
{
    _mindMapModel->saveMindMap();
    _ostream << kSaveMindMapSuccess;
    return true;
}

// ���}�D�{��
bool TextUIController::exit()
{
    return false;
}
