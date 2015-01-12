#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "menu_state.h"
#include "node.h"
#include "text_ui_state_factory.h"

class MenuStateTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};


TEST_F(MenuStateTest, testMenuState)
{
    void setTextUIView(TextUIView * textUIView);
    void setIStream(istream * istream);
    ostringstream oss;
    ostringstream isinput;
    istringstream iss(isinput.str());
    cout << isinput.str();
    TextUIView  textUIView(oss);
    MindMapModel mindMapModel;
    MenuState* menuState;
    stringstream s;
    menuState = new MenuState(&mindMapModel);
    menuState->setTextUIView(&textUIView);
    menuState->setIStream(&s);
    s << MenuState::TEXT_UI_CREATE_MIND_MAP_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_INSERT_NODE_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_EDIT_NODE_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_SAVE_MIND_MAP_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_LOAD_MIND_MAP_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_REDO_INSTRUCTION << endl;
    s << MenuState::TEXT_UI_UNDO_INSTRUCTION << endl;
    s << 11111 << endl;
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
    ASSERT_TRUE(NULL != menuState->run());
}