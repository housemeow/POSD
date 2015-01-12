#include "gui_graphics.h"

GUIGraphics::GUIGraphics(QPainter* painter)
{
    _painter = painter;
}

GUIGraphics::~GUIGraphics()
{
}

void GUIGraphics::drawText(string text, int x, int y, int width, int height)
{
    QRectF rect(x, y, width, height);
    _painter->drawText(rect, Qt::AlignCenter, QString::fromStdString(text));
}
void GUIGraphics::drawRectangle(int x, int y, int width, int height)
{
    QRectF rect(x, y, width, height);
    _painter->setPen(QPen(Qt::black, 3));
    _painter->drawRect(rect);
}
void GUIGraphics::drawCircle(int x, int y, int width, int height)
{
}
void GUIGraphics::drawTriangle(int x, int y, int width, int height)
{
}