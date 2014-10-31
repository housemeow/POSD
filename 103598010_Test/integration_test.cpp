#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "mind_map_model.h"

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
6 \"Microsfot Office\"\n\
7 \"Network\" 8 9\n\
8 \"Wireless\"\n\
9 \"Cable\"\n)");
    }
    virtual void TearDown()
    {
        deleteFolder("testdata");
    }

    void createFolder(string folderName)
    {
        mkdir(folderName.c_str());
    }

    void createFile(string fileName, string content)
    {
    }

    void deleteFolder(string folder)
    {
    }
};
TEST_F(IntegrationTest, testLoadFileNotExist)
{
    //void MindMapModel::loadMindMap(string filePath)
    //{
    //	ifstream ifstream(filePath, ifstream::in);
    //	if (!ifstream) {
    //		throw exception("File not found!!");
    //	}
}
TEST_F(IntegrationTest, testUndoDeleteNode)
{
}
TEST_F(IntegrationTest, testRedoDeleteNode)
{
}
TEST_F(IntegrationTest, testChangeNodeParent)
{
}