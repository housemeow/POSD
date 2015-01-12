#pragma once
#include "i_graphics.h"
#include "qpainter.h"

class GUIGraphics :
    public IGraphics
{
public:
    GUIGraphics(QPainter* painter);
    ~GUIGraphics();
    void drawText(string text, int x, int y, int width, int height);
    void drawRectangle(int x, int y, int width, int height);
    void drawCircle(int x, int y, int width, int height);
    void drawTriangle(int x, int y, int width, int height);
private:
    QPainter* _painter;
};

