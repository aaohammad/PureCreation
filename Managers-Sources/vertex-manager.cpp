#include "vertex-manager.h"

VertexManager::VertexManager()
{
}

void VertexManager::append(QList<Vector *> vectorList)
{
    this->vertices.append(vectorList);
}

void VertexManager::append(VertexManager *vertexManager)
{
    for(int i = 0; i < vertexManager->size(); i++)
    {
        Vector *vect = new Vector(vertexManager->at(i)->x, vertexManager->at(i)->y, vertexManager->at(i)->z);
        this->vertices.append(vect);
    }
}

void VertexManager::append(Vector *vector)
{
    this->vertices.append(vector);
}

Vector *VertexManager::at(int index)
{
    return vertices.at(index);
}

Vector * VertexManager::last ()
{
    return vertices.last ();
}

void VertexManager::clear()
{
    vertices.clear();
}

int VertexManager::size()
{
    return vertices.size();
}
