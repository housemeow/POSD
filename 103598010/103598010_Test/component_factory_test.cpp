#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "component_factory.h"
#include "component.h"
#include "node.h"

class ComponentFactoryTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _factory.resetCurrentId();
    }

    virtual void TearDown()
    {
    }
    ComponentFactory _factory;
};


TEST_F(ComponentFactoryTest, resetCurrentId)
{
    _factory.resetCurrentId();
    ASSERT_EQ(0, _factory.getCurrentId());
}

TEST_F(ComponentFactoryTest, copyMindMap)
{
    Component* component = new Node(1);
    component->setDescription("hello");
    Component* copyComponent = _factory.copyMindMap(component);
    ASSERT_EQ(component->getDescription(), copyComponent->getDescription());
}

TEST_F(ComponentFactoryTest, createComponent)
{
    Component* nodeComponent = _factory.createComponent(ComponentType::ComponentTypeNode);
    Component* rootComponent = _factory.createComponent(ComponentType::ComponentTypeRoot);
    ASSERT_EQ(0, nodeComponent->getId());
    ASSERT_EQ(1, rootComponent->getId());
    ASSERT_EQ("Root", rootComponent->getTypeName());
    ASSERT_EQ("Node", nodeComponent->getTypeName());
}

TEST_F(ComponentFactoryTest, constructor)
{
    ASSERT_EQ(0, _factory.getCurrentId());
}

TEST_F(ComponentFactoryTest, setCurrentId)
{
    _factory.setCurrentId(100);
    ASSERT_EQ(100, _factory.getCurrentId());
}

TEST_F(ComponentFactoryTest, clone)
{
    Component* nodeComponent = _factory.createComponent(ComponentType::ComponentTypeNode);
    Component* cloneNodeComponent = nodeComponent->clone();
    ASSERT_EQ(1, cloneNodeComponent->getId());
    ASSERT_EQ("Node", cloneNodeComponent->getTypeName());
}