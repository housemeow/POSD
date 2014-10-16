#include "stdafx.h"
#include "text_ui_view.h"


TextUIView::TextUIView()
{
}


TextUIView::~TextUIView()
{
}

void TextUIView::printMenu()
{
    cout << "1. Create a new mind map\n";
    cout << "2. Insert a new node\n";
    cout << "3. Display mind map\n";
    cout << "4. Save mind map\n";
    cout << "5. Exit\n";
}