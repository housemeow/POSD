#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "mind_map_model.h"
#include "text_ui_controller.h"
#include "mind_map_presentation_model.h"

class PresentationModelTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    MindMapModel _mindMapModel;
};

TEST_F(PresentationModelTest, testConstructor)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    // init state
    ASSERT_EQ(false, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
}

TEST_F(PresentationModelTest, createMindMapState)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    // can save
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
}

TEST_F(PresentationModelTest, selectNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    ASSERT_EQ(_mindMapModel.getMindMap(), mindMapPresentationModel.getSelectedComponent());
    // selected a component
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertParentActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getSelected(_mindMapModel.getMindMap()));
    ASSERT_EQ(false, mindMapPresentationModel.getCutActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getCopyActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getPasteActionEnabled());
}

TEST_F(PresentationModelTest, deselectNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    // init state
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    // insert a component
    mindMapPresentationModel.insertChild("PAD");
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
}

TEST_F(PresentationModelTest, insertNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
}

TEST_F(PresentationModelTest, deleteNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.insertParentNode("App");
    //delete a component
    mindMapPresentationModel.deleteComponent();
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
}

TEST_F(PresentationModelTest, doubleClick)
{
    /*
    Game-App-PAD
    	-AOE
    */
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.insertParentNode("App");
    mindMapPresentationModel.deleteComponent();
    mindMapPresentationModel.doubleClick(_mindMapModel.getMindMap());
    ASSERT_EQ(true, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getInsertParentActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getSelected(_mindMapModel.getMindMap()));
    try {
        mindMapPresentationModel.saveMindMap("");
        FAIL();
    } catch (exception) {
    }
    try {
        mindMapPresentationModel.loadMindMap("");
        FAIL();
    } catch (exception) {
    }
}

TEST_F(PresentationModelTest, copyNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.copy();
    ASSERT_EQ(false, mindMapPresentationModel.getCutActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getCopyActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getPasteActionEnabled());
}

TEST_F(PresentationModelTest, cutNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.cut();
    ASSERT_EQ(false, mindMapPresentationModel.getCutActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getCopyActionEnabled());
    ASSERT_EQ(true, mindMapPresentationModel.getPasteActionEnabled());
}

TEST_F(PresentationModelTest, pasteNode)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("Game");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("PAD");
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.cut();
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.paste();
    ASSERT_EQ(2, mindMapPresentationModel.getMindMap()->getNodeList().size());
}

TEST_F(PresentationModelTest, testGetUndoActionEnabled)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    ASSERT_EQ(false, mindMapPresentationModel.getUndoActionEnabled());
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("child");
    ASSERT_EQ(true, mindMapPresentationModel.getUndoActionEnabled());
}

TEST_F(PresentationModelTest, testGetRedoActionEnabled)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    ASSERT_EQ(false, mindMapPresentationModel.getRedoActionEnabled());
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("child");
    mindMapPresentationModel.undo();
    ASSERT_EQ(true, mindMapPresentationModel.getRedoActionEnabled());
}

TEST_F(PresentationModelTest, testGetSelected)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.insertChild("child");
    ASSERT_FALSE(mindMapPresentationModel.getSelected(_mindMapModel.getMindMap()->getNodeList().back()));
}

TEST_F(PresentationModelTest, testEditDescription)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.editDescription("new");
    ASSERT_EQ("new", _mindMapModel.getMindMap()->getDescription());
}

TEST_F(PresentationModelTest, testGetSelectedDescription)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    ASSERT_EQ("root", mindMapPresentationModel.getSelectedComponentDescription());
}

TEST_F(PresentationModelTest, testUndo)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.editDescription("new");
    mindMapPresentationModel.undo();
    ASSERT_EQ("root", _mindMapModel.getMindMap()->getDescription());
}

TEST_F(PresentationModelTest, testRedo)
{
    MindMapPresentationModel mindMapPresentationModel(&_mindMapModel);
    mindMapPresentationModel.createMindMap("root");
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    mindMapPresentationModel.editDescription("new");
    mindMapPresentationModel.undo();
    mindMapPresentationModel.redo();
    ASSERT_EQ("new", _mindMapModel.getMindMap()->getDescription());
}