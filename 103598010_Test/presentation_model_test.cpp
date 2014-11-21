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
    mindMapPresentationModel.createMindMap("Game");
    // can save
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
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
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    // deselected a component
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getSelected(_mindMapModel.getMindMap()));
    mindMapPresentationModel.clickNode(_mindMapModel.getMindMap());
    // insert a component
    mindMapPresentationModel.insertChild("PAD");
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
    //delete a component
    mindMapPresentationModel.clickNode(*(_mindMapModel.getMindMap()->getNodeList().begin()));
    mindMapPresentationModel.insertSibling("AOE");
    mindMapPresentationModel.insertParentNode("App");
    ASSERT_EQ("PAD", mindMapPresentationModel.getSelectedComponentDescription());
    mindMapPresentationModel.deleteComponent();
    ASSERT_EQ(true, mindMapPresentationModel.getSaveMindMapActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getDeleteNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getEditNodeActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertChildActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertSiblingActionEnabled());
    ASSERT_EQ(false, mindMapPresentationModel.getInsertParentActionEnabled());
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
