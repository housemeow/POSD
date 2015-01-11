#include "stdafx.h"
#include "component.h"

const int Component::CHARARATER_WIDTH_PIXEL = 6;
const int Component::LINE_HEIGHT_PIXEL = 20;
const int Component::MAX_WIDTH_CHARACTER = 25;
const int Component::MAX_LINE = 3;
const int Component::PADDING = 20;
const int Component::MAX_HEIGHT_PIXEL = LINE_HEIGHT_PIXEL * MAX_LINE;
const int Component::MAX_WIDTH_PIXEL = CHARARATER_WIDTH_PIXEL * MAX_WIDTH_CHARACTER;

Component::Component(int id)
{
    _id = id;
    _parent = NULL;
}

Component::~Component()
{
    for (list<Component*>::iterator iterator = _children.begin(); iterator != _children.end(); iterator++) {
        delete *iterator;
    }
}

int Component::getId()
{
    return _id;
}

void Component::setId(int id)
{
    _id = id;
}

string Component::getDescription()
{
    return _description;
}

void Component::setDescription(string description)
{
    _description = description;
}

list<Component*>& Component::getNodeList()
{
    return _children;
}

Component* Component::getParent()
{
    return _parent;
}

string Component::getName()
{
    ostringstream stream;
    stream << _description << "(" << getTypeName() << ", ID: " << _id << ")";
    return stream.str();
}

void Component::setParent(Component* parent)
{
    if (this->getParent()) {
        this->getParent()->getNodeList().remove(this);
    }
    _parent = parent;
}

// 尋找指定id的節點
Component* Component::findNode(int id)
{
    if (_id == id) {
        return this;
    } else {
        for (ComponentIterator iterator = _children.begin(), end = _children.end(); iterator != end; ++iterator) {
            Component* result = (*iterator)->findNode(id);
            if (result) {
                return result;
            }
        }
    }
    return NULL;
}

void Component::draw(IGraphics* graphics)
{
    graphics->drawText(_description, getX(), getY(), getWidth(), getHeight());
}

int Component::getLineCount(string str) const
{
    int count = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    return count;
}

string Component::getBreakLineString() const
{
    istringstream iss(_description);
    vector<string> tokens { istream_iterator<string>{iss},
                            istream_iterator<string>{}
                          };
    vector<string> processedString;
    for (vector<string>::iterator iterator = tokens.begin(); iterator != tokens.end(); iterator++) {
        if (processedString.empty()) {
            processedString.push_back(*iterator);
        } else {
            string text = processedString.back() + *iterator;
            if (text.length() < MAX_WIDTH_CHARACTER) {
                string back = processedString.back() + " " + *iterator;
                processedString.pop_back();
                processedString.push_back(back);
            } else {
                processedString.push_back(*iterator);
            }
        }
        string str = getConcatenationString(processedString);
        if (getLineCount(str) > MAX_LINE) {
            string back = processedString.back() + "...";
            processedString.pop_back();
            processedString.push_back(back);
            break;
        }
    }
    return getConcatenationString(processedString);
}

string Component::getConcatenationString(vector<string> strings) const
{
    if (strings.empty()) {
        return "";
    } else {
        string str = strings.back();
        strings.pop_back();
        while (!strings.empty()) {
            str = strings.back() + "\n" + str;
            strings.pop_back();
        }
        return str;
    }
}

int Component::getWidth()
{
    string breakLineText = getBreakLineString();
    int maxWidth = 10;
    int count = 0;
    for (int i = 0; i < breakLineText.length(); i++) {
        if (breakLineText[i] == '\n')
            count = 0;
        count++;
        if (count > maxWidth)
            maxWidth = count;
    }
    return (maxWidth > 25 ? 25 : maxWidth) * CHARARATER_WIDTH_PIXEL;
    return CHARARATER_WIDTH_PIXEL * 10;
}

int Component::getHeight()
{
    return getLineCount(getBreakLineString()) * LINE_HEIGHT_PIXEL;
    return LINE_HEIGHT_PIXEL;
}

int Component::getX()
{
    return _x;
}

void Component::setX(int x)
{
    _x = x;
}

int Component::getY()
{
    return _y;
}

void Component::setY(int y)
{
    _y = y;
}