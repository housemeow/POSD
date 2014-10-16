#pragma once
#include "composite.h"

class Node :
    public Composite
{
public:
    Node(int id);
    ~Node();
    string getTypeName();
};

