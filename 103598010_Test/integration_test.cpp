#include "stdafx.h"
#include <limits.h>
#include <direct.h>
#include <stdio.h>
#include "gtest/gtest.h"
#include "mind_map_model.h"
#include "delete_command.h"
#include "change_parent_command.h"
#include "text_ui_view.h"

class IntegrationTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        createFolder("testdata");
        createFile("testdata/test_file1.mm", "\
0 \"Computer\" 2 7\n\
1 \"windows\" 5 6\n\
2 \"OS\" 1 3 4\n\
3 \"IOS\"\n\
4 \"Linux\"\n\
5 \"DirectX\"\n\
6 \"Microsoft Office\"\n\
7 \"Network\" 8 9\n\
8 \"Wireless\"\n\
9 \"Cable\"");
    }
    virtual void TearDown()
    {
        deleteFile("testdata/test_file1.mm");
        deleteFolder("testdata");
    }

    void createFolder(string folderName)
    {
        _mkdir(folderName.c_str());
    }

    void createFile(string fileName, string content)
    {
        ofstream file;
        file.open(fileName);
        file << content;
        file.close();
    }

    void deleteFile(string fileName)
    {
        remove(fileName.c_str());
    }

    void deleteFolder(string folder)
    {
        _rmdir(folder.c_str());
    }

    string getMindMapString()
    {
        ostringstream ostringstream;
        TextUIView textUIView(ostringstream);
        textUIView.printMindMap(_mindMapModel.getMindMap());
        return ostringstream.str();
    }

    DeleteCommand* createDeleteCommand(int id)
    {
        return new DeleteCommand(_mindMapModel.getMindMap()->findNode(id));
    }

    ChangeParentCommand* createChangeParentCommand(int id, int newParentId)
    {
        Component* component = _mindMapModel.getMindMap()->findNode(id);
        Component* parentComponent = _mindMapModel.getMindMap()->findNode(newParentId);
        return new ChangeParentCommand(component, parentComponent);
    }

    MindMapModel _mindMapModel;
};
TEST_F(IntegrationTest, testLoadFileNotExist)
{
    try {
        _mindMapModel.loadMindMap("testdata/file_not_exist.erd");
        FAIL();
    } catch (exception exception) {
        ASSERT_TRUE(strcmp(exception.what(), "File not found!!") == 0);
    }
}
TEST_F(IntegrationTest, testUndoDeleteNode)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    // 儲存原始的mindmap
    string originMindMap = getMindMapString();
    // 刪除id=2的OS
    _mindMapModel.execute(createDeleteCommand(2));
    string expectDeleteOSMindMapString = "\
The mind map Computer is displayed as follows:\n\
＋－Computer(Root, ID: 0)\n\
　　＋－Network(Node, ID: 7)\n\
　　｜　＋－Wireless(Node, ID: 8)\n\
　　｜　＋－Cable(Node, ID: 9)\n\
　　＋－windows(Node, ID: 1)\n\
　　｜　＋－DirectX(Node, ID: 5)\n\
　　｜　＋－Microsoft Office(Node, ID: 6)\n\
　　＋－IOS(Node, ID: 3)\n\
　　＋－Linux(Node, ID: 4)\n";
    ASSERT_EQ(expectDeleteOSMindMapString, getMindMapString());
    // undo比較最原始的mindmap
    _mindMapModel.undo();
    ASSERT_EQ(originMindMap, getMindMapString());
    // 刪除id=2的DirectX
    _mindMapModel.execute(createDeleteCommand(5));
    // undo比較最原始的mindmap
    _mindMapModel.undo();
    ASSERT_EQ(originMindMap, getMindMapString());
    // 刪除id=7的Network並儲存狀態
    _mindMapModel.execute(createDeleteCommand(7));
    string afterDeleteNetworkString = getMindMapString();
    // 刪除id=8的Network
    _mindMapModel.execute(createDeleteCommand(8));
    // undo比較刪除network的mindmap
    _mindMapModel.undo();
    ASSERT_EQ(afterDeleteNetworkString, getMindMapString());
    // undo比較最原始的mindmap
    _mindMapModel.undo();
    ASSERT_EQ(originMindMap, getMindMapString());
}

TEST_F(IntegrationTest, testRedoDeleteNode)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    string originMindMap = getMindMapString();
    string afterDeleteNetworkString;
    string afterDeleteOSString;
    string afterDeleteMicrosoftOffictString;
    string afterDeleteIOSString;
    // 刪除Network(7)並儲存狀態
    _mindMapModel.execute(createDeleteCommand(7));
    afterDeleteNetworkString = getMindMapString();
    // 刪除OS(2)並儲存狀態
    _mindMapModel.execute(createDeleteCommand(2));
    afterDeleteOSString = getMindMapString();
    // 刪除Microsoft Office(6)並儲存狀態
    _mindMapModel.execute(createDeleteCommand(6));
    afterDeleteMicrosoftOffictString = getMindMapString();
    // 刪除IOS(3)並儲存狀態
    _mindMapModel.execute(createDeleteCommand(3));
    afterDeleteIOSString = getMindMapString();
    // undo到最原始狀態
    _mindMapModel.undo();
    _mindMapModel.undo();
    _mindMapModel.undo();
    _mindMapModel.undo();
    // redo後比較刪除Network後的狀態
    _mindMapModel.redo();
    ASSERT_EQ(afterDeleteNetworkString, getMindMapString());
    // redo後比較刪除OS後的狀態
    _mindMapModel.redo();
    ASSERT_EQ(afterDeleteOSString, getMindMapString());
    // redo後比較刪除Microsoft Office的狀態
    _mindMapModel.redo();
    ASSERT_EQ(afterDeleteMicrosoftOffictString, getMindMapString());
    // redo後比較刪除IOS的狀態
    _mindMapModel.redo();
    ASSERT_EQ(afterDeleteIOSString, getMindMapString());
    // undo
    _mindMapModel.undo();
    // redo後比較刪除IOS的狀態
    _mindMapModel.redo();
    ASSERT_EQ(afterDeleteIOSString, getMindMapString());
}

TEST_F(IntegrationTest, testChangeNodeParent)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    string originMindMap = getMindMapString();
    string afterChangeWindowsParentToWirelessMindMapString;
    string afterChangeWindowsParentToDirecrXMindMapString;
    string afterDeleteOSMindMapString;
    string afterDeleteDirectXMindMapString;
    // =====移動到非自己的子節點與自己的子節點=====
    // 將Windows(1)的Parent改為Wireless(8)再改成DirectX(5)，接著刪除節點8, 7再還原到最先狀態
    _mindMapModel.execute(createChangeParentCommand(1, 8));
    afterChangeWindowsParentToWirelessMindMapString = getMindMapString();
    string expectedAfterChangeWindowsParentToWirelessMindMapString = "\
The mind map Computer is displayed as follows:\n\
＋－Computer(Root, ID: 0)\n\
　　＋－OS(Node, ID: 2)\n\
　　｜　＋－IOS(Node, ID: 3)\n\
　　｜　＋－Linux(Node, ID: 4)\n\
　　＋－Network(Node, ID: 7)\n\
　　　　＋－Wireless(Node, ID: 8)\n\
　　　　｜　＋－windows(Node, ID: 1)\n\
　　　　｜　　　＋－DirectX(Node, ID: 5)\n\
　　　　｜　　　＋－Microsoft Office(Node, ID: 6)\n\
　　　　＋－Cable(Node, ID: 9)\n";
    ASSERT_EQ(expectedAfterChangeWindowsParentToWirelessMindMapString, afterChangeWindowsParentToWirelessMindMapString);
    _mindMapModel.execute(createChangeParentCommand(1, 5));
    afterChangeWindowsParentToDirecrXMindMapString = getMindMapString();
    _mindMapModel.execute(createDeleteCommand(2));
    afterDeleteOSMindMapString = getMindMapString();
    _mindMapModel.execute(createDeleteCommand(5));
    afterDeleteDirectXMindMapString = getMindMapString();
    _mindMapModel.undo();
    ASSERT_EQ(afterDeleteOSMindMapString, getMindMapString());
    _mindMapModel.undo();
    ASSERT_EQ(afterChangeWindowsParentToDirecrXMindMapString, getMindMapString());
    _mindMapModel.undo();
    ASSERT_EQ(afterChangeWindowsParentToWirelessMindMapString, getMindMapString());
    _mindMapModel.undo();
    ASSERT_EQ(originMindMap, getMindMapString());
}

//void createMindMap(string mindMapName);
TEST_F(IntegrationTest, testCreateMindMap)
{
    _mindMapModel.createMindMap("First MindMap");
    ASSERT_EQ("First MindMap", _mindMapModel.getMindMap()->getDescription());
    _mindMapModel.createMindMap("Second MindMap");
    ASSERT_EQ("Second MindMap", _mindMapModel.getMindMap()->getDescription());
}

//Component* insertNewNode(Component* node, string description, InsertNodeMode insertMode);
TEST_F(IntegrationTest, testInsertNewNode)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    Component* windowsComponent = _mindMapModel.getMindMap()->findNode(1);
    _mindMapModel.insertNewNode(windowsComponent, "TaskManager", InsertNodeModeChild);
    string expectInsertTaskManagerMindMapString = "\
The mind map Computer is displayed as follows:\n\
＋－Computer(Root, ID: 0)\n\
　　＋－OS(Node, ID: 2)\n\
　　｜　＋－windows(Node, ID: 1)\n\
　　｜　｜　＋－DirectX(Node, ID: 5)\n\
　　｜　｜　＋－Microsoft Office(Node, ID: 6)\n\
　　｜　｜　＋－TaskManager(Node, ID: 10)\n\
　　｜　＋－IOS(Node, ID: 3)\n\
　　｜　＋－Linux(Node, ID: 4)\n\
　　＋－Network(Node, ID: 7)\n\
　　　　＋－Wireless(Node, ID: 8)\n\
　　　　＋－Cable(Node, ID: 9)\n";
    ASSERT_EQ(expectInsertTaskManagerMindMapString, getMindMapString());
    _mindMapModel.insertNewNode(windowsComponent, "OSX", InsertNodeModeSibling);
    string expectInsertOSXMindMapString = "\
The mind map Computer is displayed as follows:\n\
＋－Computer(Root, ID: 0)\n\
　　＋－OS(Node, ID: 2)\n\
　　｜　＋－windows(Node, ID: 1)\n\
　　｜　｜　＋－DirectX(Node, ID: 5)\n\
　　｜　｜　＋－Microsoft Office(Node, ID: 6)\n\
　　｜　｜　＋－TaskManager(Node, ID: 10)\n\
　　｜　＋－IOS(Node, ID: 3)\n\
　　｜　＋－Linux(Node, ID: 4)\n\
　　｜　＋－OSX(Node, ID: 11)\n\
　　＋－Network(Node, ID: 7)\n\
　　　　＋－Wireless(Node, ID: 8)\n\
　　　　＋－Cable(Node, ID: 9)\n";
    ASSERT_EQ(expectInsertOSXMindMapString, getMindMapString());
    _mindMapModel.insertNewNode(windowsComponent, "Microsoft", InsertNodeModeParent);
    string expectInsertMicrosoftMindMapString = "\
The mind map Computer is displayed as follows:\n\
＋－Computer(Root, ID: 0)\n\
　　＋－OS(Node, ID: 2)\n\
　　｜　＋－IOS(Node, ID: 3)\n\
　　｜　＋－Linux(Node, ID: 4)\n\
　　｜　＋－OSX(Node, ID: 11)\n\
　　｜　＋－Microsoft(Node, ID: 12)\n\
　　｜　　　＋－windows(Node, ID: 1)\n\
　　｜　　　　　＋－DirectX(Node, ID: 5)\n\
　　｜　　　　　＋－Microsoft Office(Node, ID: 6)\n\
　　｜　　　　　＋－TaskManager(Node, ID: 10)\n\
　　＋－Network(Node, ID: 7)\n\
　　　　＋－Wireless(Node, ID: 8)\n\
　　　　＋－Cable(Node, ID: 9)\n";
    ASSERT_EQ(expectInsertMicrosoftMindMapString, getMindMapString());
}
//void tryInsertNewNode(Component* component, InsertNodeMode insertMode);
TEST_F(IntegrationTest, testTryInsertNewNode)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    Component* windowsComponent = _mindMapModel.getMindMap()->findNode(1);
    _mindMapModel.tryInsertNewNode(windowsComponent, InsertNodeModeChild);
    _mindMapModel.tryInsertNewNode(windowsComponent, InsertNodeModeSibling);
    _mindMapModel.tryInsertNewNode(windowsComponent, InsertNodeModeParent);
    Component* root = _mindMapModel.getMindMap();
    _mindMapModel.tryInsertNewNode(root, InsertNodeModeChild);
    try {
        _mindMapModel.tryInsertNewNode(root, InsertNodeModeSibling);
        FAIL();
    } catch (exception exception) {
        ASSERT_EQ("Root can't insert sibling node", string(exception.what()));
    }
    try {
        _mindMapModel.tryInsertNewNode(root, InsertNodeModeParent);
        FAIL();
    } catch (exception exception) {
        ASSERT_EQ("Root can't insert parent node", string(exception.what()));
    }
}

//Component* createNode(ComponentType componentType, string description);
TEST_F(IntegrationTest, testCreateNode)
{
    Component* node = _mindMapModel.createNode(ComponentTypeNode, "Node Description");
    Component* root = _mindMapModel.createNode(ComponentTypeRoot, "Root Description");
    ASSERT_EQ("Node", node->getTypeName());
    ASSERT_EQ("Node Description", node->getDescription());
    ASSERT_EQ(0, node->getId());
    ASSERT_EQ("Root", root->getTypeName());
    ASSERT_EQ("Root Description", root->getDescription());
    ASSERT_EQ(1, root->getId());
}
//void saveMindMap(string fileName);
TEST_F(IntegrationTest, testSaveMindMap)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    _mindMapModel.insertNewNode(_mindMapModel.getMindMap(), "Screen", InsertNodeModeChild);
    string saveMindMapString = getMindMapString();
    _mindMapModel.saveMindMap("testdata/save_file.mm");
    _mindMapModel.loadMindMap("testdata/save_file.mm");
    ASSERT_EQ(saveMindMapString, getMindMapString());
}

//Component* findComponent(list<Component*> components, int id);
TEST_F(IntegrationTest, testFindComponent)
{
    _mindMapModel.loadMindMap("testdata/test_file1.mm");
    list<Component*> osNodeList = _mindMapModel.getMindMap()->findNode(2)->getNodeList();
    Component* directXComponent = _mindMapModel.getMindMap()->findNode(1);
    ASSERT_EQ(directXComponent, _mindMapModel.findComponent(osNodeList, 1));
    ASSERT_EQ(NULL, _mindMapModel.findComponent(osNodeList, 8));
}
//void readComponentData(string line, int& id, string& description, string& children);
TEST_F(IntegrationTest, testReadComponentData)
{
    int id;
    string description;
    string children;
    _mindMapModel.readComponentData("0 \"Computer\" 2 7", id, description, children);
    ASSERT_EQ(0, id);
    ASSERT_EQ("Computer", description);
    ASSERT_EQ(" 2 7", children);
}