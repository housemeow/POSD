#include "stdafx.h"
#include "root.h"

Root::Root(int id) : Composite(id)
{
}

Root::~Root()
{
}

// Root�L�k�s�W�{�`�I
void Root::addSibling(Component* component)
{
    throw exception("Root can't insert sibling node");
}

// Root�L�k�s�W���`�I
void Root::addParent(Component* component)
{
    throw exception("Root can't insert parent node");
}

// ���oRoot���W��
string Root::getTypeName()
{
    return "Root";
}

bool Root::isAncientOf(Component* component)
{
    return true;
}