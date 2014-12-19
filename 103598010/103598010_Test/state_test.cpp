#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "text_ui_state_factory.h"
#include "delete_command.h"

class StateTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    string getMindMapString()
    {
        ostringstream ostringstream;
        TextUIView textUIView(ostringstream);
        textUIView.printMindMap(_mindMapModel.getMindMap());
        return ostringstream.str();
    }

    MindMapModel _mindMapModel;
};


TEST_F(StateTest, testUndoState)
{
    TextUIState* undoState = TextUIStateFactory::createTextUIState(UndoStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    undoState->setTextUIView(&textUIView);
    undoState->run();
    ASSERT_EQ("Cant't Undo!\n", ostringstream.str());
    _mindMapModel.createMindMap("Computer");
    _mindMapModel.insertNewNode(_mindMapModel.getMindMap(), "Child", InsertNodeModeChild);
    _mindMapModel.execute(new DeleteCommand(&_mindMapModel, _mindMapModel.getMindMap()->findNode(1)));
    ostringstream.str("");
    ostringstream.clear();
    undoState->run();
    ASSERT_EQ("\
The mind map Computer is displayed as follows:\n\
¡Ï¡ÐComputer(Root, ID: 0)\n\
¡@¡@¡Ï¡ÐChild(Node, ID: 1)\n", ostringstream.str());
}

TEST_F(StateTest, testRedoState)
{
    TextUIState* redoState = TextUIStateFactory::createTextUIState(RedoStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    redoState->setTextUIView(&textUIView);
    redoState->run();
    ASSERT_EQ("Cant't Redo!\n", ostringstream.str());
    _mindMapModel.createMindMap("Computer");
    _mindMapModel.insertNewNode(_mindMapModel.getMindMap(), "Child", InsertNodeModeChild);
    _mindMapModel.execute(new DeleteCommand(&_mindMapModel, _mindMapModel.getMindMap()->findNode(1)));
    ostringstream.str("");
    ostringstream.clear();
    _mindMapModel.undo();
    redoState->run();
    ASSERT_EQ("\
The mind map Computer is displayed as follows:\n\
¡Ï¡ÐComputer(Root, ID: 0)\n", ostringstream.str());
}

TEST_F(StateTest, testMenuState)
{
    TextUIState* menuState = TextUIStateFactory::createTextUIState(MenuStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    istringstream istringstream("1\n");
    TextUIView textUIView(ostringstream);
    menuState->setTextUIView(&textUIView);
    menuState->setIStream(&istringstream);
    menuState->run();
    ASSERT_EQ("\
1. Create a new mind map\n\
2. Insert a new node\n\
3. Edit a node\n\
4. Display mind map\n\
5. Save mind map\n\
6. Load mind map\n\
7. Redo\n\
8. Undo\n\
9. Exit\n>", ostringstream.str());
}

TEST_F(StateTest, testInsertMenuState)
{
    TextUIState* insertMenuState = TextUIStateFactory::createTextUIState(InsertMenuStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    istringstream istringstream("a\n");
    TextUIView textUIView(ostringstream);
    insertMenuState->setTextUIView(&textUIView);
    insertMenuState->setIStream(&istringstream);
    insertMenuState->run();
    ASSERT_EQ("Mind map is not exist\n", ostringstream.str());
}

TEST_F(StateTest, testExitState)
{
    TextUIState* exitState = TextUIStateFactory::createTextUIState(ExitStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    exitState->setTextUIView(&textUIView);
    ASSERT_EQ(NULL, exitState->run());
}

TEST_F(StateTest, testEditDescriptionState)
{
    _mindMapModel.createMindMap("Computer");
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(EditDescriptionStateInstruction, &_mindMapModel, _mindMapModel.getMindMap());
    ostringstream ostringstream;
    istringstream istringstream("New\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testDeleteNodeState)
{
    _mindMapModel.createMindMap("Computer");
    Component* root = _mindMapModel.getMindMap();
    _mindMapModel.insertNewNode(root, "OS", InsertNodeModeChild);
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(DeleteNodeStateInstruction, &_mindMapModel, root->findNode(1));
    ostringstream ostringstream;
    istringstream istringstream("a\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testChangeParentState)
{
    _mindMapModel.createMindMap("Computer");
    Component* root = _mindMapModel.getMindMap();
    _mindMapModel.insertNewNode(root, "OS", InsertNodeModeChild);
    _mindMapModel.insertNewNode(root, "IOS", InsertNodeModeChild);
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(ChangeParentStateInstruction, &_mindMapModel, root->findNode(1));
    ostringstream ostringstream;
    istringstream istringstream("2\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testInsertChildNodeState)
{
    _mindMapModel.createMindMap("Computer");
    Component* root = _mindMapModel.getMindMap();
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(InsertChildNodeStateInstruction, &_mindMapModel, root->findNode(0));
    ostringstream ostringstream;
    istringstream istringstream("Child\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testInsertParentNodeState)
{
    _mindMapModel.createMindMap("Computer");
    Component* root = _mindMapModel.getMindMap();
    _mindMapModel.insertNewNode(root, "OS", InsertNodeModeChild);
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(InsertParentNodeStateInstruction, &_mindMapModel, root->findNode(1));
    ostringstream ostringstream;
    istringstream istringstream("New Parent\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testInsertSiblingNodeState)
{
    _mindMapModel.createMindMap("Computer");
    Component* root = _mindMapModel.getMindMap();
    _mindMapModel.insertNewNode(root, "OS", InsertNodeModeChild);
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(InsertSiblingNodeStateInstruction, &_mindMapModel, root->findNode(1));
    ostringstream ostringstream;
    istringstream istringstream("New Sibling\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testCreateMindMapState)
{
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(CreateMindMapStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    istringstream istringstream("Computer\n");
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testDisplayMindState)
{
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(DisplayMindMapStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->run();
    _mindMapModel.createMindMap("Computer");
    textUIState->run();
}

TEST_F(StateTest, testLoadState)
{
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(LoadStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    istringstream istringstream("testfile\n");
    textUIState->setTextUIView(&textUIView);
    textUIState->setIStream(&istringstream);
    textUIState->run();
}

TEST_F(StateTest, testSaveState)
{
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(SaveStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->run();
}

TEST_F(StateTest, testEditMenu)
{
    TextUIState* textUIState = TextUIStateFactory::createTextUIState(EditMenuStateInstruction, &_mindMapModel);
    ostringstream ostringstream;
    TextUIView textUIView(ostringstream);
    textUIState->setTextUIView(&textUIView);
    textUIState->run();
}