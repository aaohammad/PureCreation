#include "vertexmanager.h"

VertexManager::VertexManager()
{

}

void VertexManager::append(QList<Vector> vectorList)
{
    this->vertices.append(vectorList);
}

void VertexManager::append(Vector vector)
{
    this->vertices.append(vector);
}

Vector VertexManager::at(int index)
{
    return vertices.at(index);
}

void VertexManager::clear()
{
    vertices.clear();
}

int VertexManager::size()
{
    return vertices.size();
}
