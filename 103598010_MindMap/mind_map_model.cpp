#include "stdafx.h"
#include "mind_map_model.h"
#include "component_factory.h"

using namespace std;

MindMapModel::MindMapModel()
{
    _mindMap = NULL;
}

MindMapModel::~MindMapModel()
{
    delete _mindMap;
}

// 建立一個全新的MindMap
void MindMapModel::createMindMap(string mindMapName)
{
    if (_mindMap) {
        delete _mindMap;
    }
    ComponentFactory factory;
    _mindMap = factory.createComponent(ComponentType::ComponentTypeRoot, _currentId++);
    _mindMap->setDescription(mindMapName);
}

// 嘗試加入一個空節點，如果不成功會拋出exception
void MindMapModel::tryInsertNewNode(Component* component, InsertNodeMode insertMode)
{
    insertNode(component, NULL, insertMode);
}

// 加入一個節點
void MindMapModel::insertNode(Component* component, Component* node, InsertNodeMode insertMode)
{
    try {
        switch (insertMode) {
            case InsertNodeMode::InsertNodeModeParent:
                component->addParent(node);
                break;
            case InsertNodeMode::InsertNodeModeChild:
                component->addChild(node);
                break;
            case InsertNodeMode::InsertNodeModeSibling:
                component->addSibling(node);
                break;
            default:
                break;
        }
    } catch (string exception) {
        throw exception;
    }
}

// 建立並加入一個新結點
void MindMapModel::insertNewNode(Component* component, string description, InsertNodeMode insertMode)
{
    ComponentFactory factory;
    Component* newNode = factory.createComponent(ComponentType::ComponentTypeNode, _currentId++);
    newNode->setDescription(description);
    insertNode(component, newNode, insertMode);
}

//取得MindMap的輸出
string MindMapModel::getMindMapDisplayString()
{
    stringstream stringStream;
    getMindMapString(_mindMap, stringStream, false);
    string displayMindMapString = kTheMindMapString + _mindMap->getDescription() + kIsDisplayedAsFollows;
    displayMindMapString += stringStream.str();
    return displayMindMapString;
}

// 產出MindMapString的遞迴函數
void MindMapModel::getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine)
{
    if (component) {
        stringStream << "＋－" << component->getName() << endl;
        stringstream tempStringstream;
        for (ComponentIterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end;) {
            Component* child = *iterator;
            ++iterator;
            getMindMapString(child, tempStringstream, component->getNodeList().size() > 1 && iterator != end);
        }
        bool first = true;
        while (!tempStringstream.eof()) {
            string line;
            getline(tempStringstream, line);
            if (line.size() != 0) {
                if (needVerticleLine) {
                    stringStream << "｜　" << line << endl;
                } else {
                    stringStream << "　　" << line << endl;
                }
            }
            first = false;
        }
    }
}

// 將MindMap存檔
void MindMapModel::saveMindMap()
{
    ofstream file;
    file.open("mindMap.txt");
    for (int id = 0; id < _currentId; id++) {
        Component* component = _mindMap->findNode(id);
        if (component) {
            file << id << " \"" << component->getDescription() << "\"";
            for (ComponentIterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end; ++iterator) {
                Component* child = *iterator;
                file << " " << child->getId();
            }
            file << endl;
        }
    }
    file.close();
}

// 取得當前的MindMap根節點
Component* MindMapModel::getMindMap()
{
    return _mindMap;
}