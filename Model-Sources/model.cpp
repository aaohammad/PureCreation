#include "model.h"

void Model::move(float x, float y)
{
    yDrawingTranslation = x;
    xDrawingTranslation = y;
}

void Model::resetMove()
{
    xTranslate = xTranslate + xDrawingTranslation;
    centerX += xDrawingTranslation;
    xDrawingTranslation = 0.0;
    yTranslate = yTranslate + yDrawingTranslation;
    centerY += yDrawingTranslation;
    yDrawingTranslation = 0.0;
}

void Model::scale(float x, float y)
{
    yDrawingScale = x / 50;
    xDrawingScale = y / 50;
}

void Model::resetScale()
{
    xScale = xScale + xDrawingScale;
    xDrawingScale = 0.0;
    yScale = yScale + yDrawingScale;
    yDrawingScale = 0.0;
}

void Model::rotate(float angle)
{
    drawingRotationAngle = angle / 5;
}

void Model::resetRotate()
{
    angle = angle + drawingRotationAngle;
    drawingRotationAngle = 0.0;
}

void Model::open(float xTranslate, float yTranslate, float xScale, float yScale, float angle)
{
    this->xTranslate = xTranslate;
    this->yTranslate = yTranslate;
    this->xScale = xScale;
    this->yScale = yScale;
    this->angle = angle;
}

int Model::getGroupID()
{
    return groupID;
}

void Model::setGroupID(int gID)
{
    groupID = gID;
}

void Model::setColor(QColor *color)
{
    this->color->setRedF(color->redF());
    this->color->setGreenF(color->greenF());
    this->color->setBlueF(color->blueF());
}

QColor * Model::getColor()
{
    return color;
}

void Model::setID(int iD)
{
    this->iD = iD;
}

int Model::getID()
{
    return iD;
}

bool Model::getSelected()
{
    return selected;
}

void Model::setSelected(bool selectoion)
{
    selected = selectoion;
}

void Model::setMouseStatus(bool status)
{
    isMouseUp = status;
}

bool Model::getMouseStatus()
{
    return isMouseUp;
}

void Model::getCenter(float &x, float &y)
{
    x = centerX;
    y = centerY;
}

TypeOfModel Model::getType()
{
    return this->type;
}
