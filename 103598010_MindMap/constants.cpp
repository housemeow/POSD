#include "stdafx.h"
#include "constants.h"



const int TEXT_UI_CREATE_MIND_MAP_INSTRUCTION = 1;
const int TEXT_UI_INSERT_NODE_INSTRUCTION = 2;
const int TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION = 3;
const int TEXT_UI_SAVE_MIND_MAP_INSTRUCTION = 4;
const int TEXT_UI_EXIT_INSTRUCTION = 5;

const string kRootCannotAddParentException = "Root can't insert parent node";
const string kRootCannotAddSiblingException = "Root can't insert sibling node";
const string kTextUIMenuString = "\
1. Create a new mind map\n\
2. Insert a new node\n\
3. Display mind map\n\
4. Save mind map\n\
5. Exit\n";

const string kTextUIInsertNewNodeMenu = "\
a. Insert a parent node\n\
b. Insert a child node\n\
c. Insert a sibling node\n";

const string kTextUICreateMindMapMessage = "Please enter the topic:\n";
const string kTextUINotifyUserInputCharacter = ">";
const string kTextUIEnterNodeIdMessage = "Enter the node ID:\n";
const string kTextUIEnterNodeNameMessage = "Enter the node name\n";
const string kRootName = "Root";
const string kNodeName = "Node";
const string kSaveMindMapSuccess = "Save MindMap Success\n";
const string kTheMindMapString = "The mind map ";
const string kIsDisplayedAsFollows = "is displayed as follows:\n";
const string kMindMapNotExist = "Mind map is not exist\n";