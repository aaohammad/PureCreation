#include "text.h"

Text::Text(QString str, float x, float y, float size, QFont font)
{
    this->str.append(str);
    this->x = x;
    this->y = y;
    this->size = size;
    this->font = new QFont(font);

    vertexManager = new VertexManager();
    edgeManager = new EdgeManager();
    color = new QColor();
    iD = 0;
    groupID = 0;
    selected = false;
    xTranslate = 0.0;
    xDrawingTranslation = 0.0;
    yTranslate = 0.0;
    yDrawingTranslation = 0.0;
    xScale = 1.0;
    xDrawingScale = 0.0;
    yScale = 1.0;
    yDrawingScale = 0.0;
    drawingRotationAngle = 0.0;
    angle = 0.0;
    isMouseUp = true;
    this->type = TextType;
}

void Text::drawEdgeSelectMode()
{

}

void Text::drawFaceSelectMode()
{

}

void Text::drawObjectSelectMode()
{
}

void Text::drawVertexSelectMode()
{

}

void Text::save(QTextStream*)
{
}

void Text::showAttribute()
{
}

void Text::reflect(float, float)
{

}

void Text::changeAttributes()
{
}

void Text::changeColorAE()
{
}
