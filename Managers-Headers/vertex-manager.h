#ifndef VERTEXMANAGER_H
#define VERTEXMANAGER_H

#include "vector.h"
#include <QList>

class VertexManager
{
public:
    VertexManager();
    void append(QList<Vector *> vectorList);
    void append(VertexManager *vertexManager);
    void append(Vector *vector);
    Vector *at(int index);
    Vector *last();
    void clear();
    int size();
private:
    QList<Vector *> vertices;
};

#endif // VERTEXMANAGER_H
