#pragma once

using namespace std;

extern const string kRootCannotAddParentException;
extern const string kRootCannotAddSiblingException;
extern const string kTextUIMenuString;
extern const string kTextUIInsertNewNodeMenu;
extern const string kTextUICreateMindMapMessage;
extern const string kTextUINotifyUserInputCharacter;
extern const string kTextUIEnterNodeIdMessage;
extern const string kTextUIEnterNodeNameMessage;
extern const string kRootName;
extern const string kNodeName;
extern const string kSaveMindMapSuccess;
extern const string kTheMindMapString;
extern const string kIsDisplayedAsFollows;
extern const string kMindMapNotExist;

enum ComponentType {
    ComponentTypeRoot,
    ComponentTypeNode
};

enum InsertNodeMode {
    InsertNodeModeParent = 'a',
    InsertNodeModeChild = 'b',
    InsertNodeModeSibling = 'c'
};
