#pragma once

using namespace std;

extern const int TEXT_UI_CREATE_MIND_MAP_INSTRUCTION;
extern const int TEXT_UI_INSERT_NODE_INSTRUCTION;
extern const int TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION;
extern const int TEXT_UI_SAVE_MIND_MAP_INSTRUCTION;
extern const int TEXT_UI_EXIT_INSTRUCTION;

extern const string kRootCannotAddParentException;
extern const string kRootCannotAddSiblingException;
extern const string kRootName;
extern const string kNodeName;

enum ComponentType {
    ComponentTypeRoot,
    ComponentTypeNode
};

enum InsertNodeMode {
    InsertNodeModeParent = 'a',
    InsertNodeModeChild = 'b',
    InsertNodeModeSibling = 'c'
};
