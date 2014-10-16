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
    throw kRootCannotAddSiblingException;
}

// Root�L�k�s�W���`�I
void Root::addParent(Component* component)
{
    throw kRootCannotAddParentException;
}

// ���oRoot���W��
string Root::getTypeName()
{
    return kRootName;
}