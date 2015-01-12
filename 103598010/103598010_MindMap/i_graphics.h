#pragma once
#include <string>

using namespace std;

class IGraphics
{
public:
    IGraphics();
    virtual ~IGraphics();
    virtual void drawText(string text, int x, int y, int width, int height) = 0;
    virtual void drawRectangle(int x1, int y1, int x2, int y2) = 0;
    virtual void drawCircle(int x1, int y1, int x2, int y2) = 0;
    virtual void drawTriangle(int x1, int y1, int x2, int y2) = 0;
};

