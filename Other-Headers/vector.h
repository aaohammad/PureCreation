#ifndef VECTOR_H
#define VECTOR_H

#include <QtOpenGL>

class Vector
{
public:
    Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    void setSelectionIdentifier(int selectionIdentifier);
    int getID();
    void setSelected(bool isSelected);
    bool getSelection();
    void move(float x, float y);
    void mousePressed(float x, float y);
    void replace(Vector *vector);
    void appendNormal(Vector *normal);
    Vector * getNormal();

    float x;
    float y;
    float z;
    float yTemp;
    float xTemp;
    float firstX;
    float firstY;
private:
    void calculateNormal();
    int selectionIdentifier;
    bool isSelected;
    float normal[3];
    QList<Vector *> *normalList;
};

#endif // VECTOR_H
