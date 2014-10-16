#pragma once

using namespace std;

enum ComponentType {
    ComponentTypeRoot,
    ComponentTypeNode
};

enum InsertNodeMode {
    InsertNodeModeParent = 'a',
    InsertNodeModeChild = 'b',
    InsertNodeModeSibling = 'c'
};