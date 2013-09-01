#include "edge-manager.h"

FaceManager::FaceManager()
{

}

void FaceManager::append(QList<Face *> faceList)
{
    this->faces.append(faceList);
}

void FaceManager::append(FaceManager *edgeManager)
{
    for(int i = 0; i < edgeManager->size(); i++)
    {
        Vector *v1 = new Vector(edgeManager->at(i)->getV1()->x, edgeManager->at(i)->getV1()->y, edgeManager->at(i)->getV1()->z);
        Vector *v2 = new Vector(edgeManager->at(i)->getV2()->x, edgeManager->at(i)->getV2()->y, edgeManager->at(i)->getV1()->z);
        Vector *v3 = new Vector(edgeManager->at(i)->getV3()->x, edgeManager->at(i)->getV3()->y, edgeManager->at(i)->getV1()->z);
        Face *face = new Face(v1, v2, v3);
        this->faces.append(face);
    }
}

void FaceManager::append(Face *face)
{
    this->faces.append(face);
}

Face *FaceManager::at(int index)
{
    return faces.at(index);
}

void FaceManager::clear()
{
    faces.clear();
}

int FaceManager::size()
{
    return faces.size();
}

void FaceManager::calculateNormals ()
{
    for(int i = 0; i < faces.size (); i++)
        faces.at (i)->calculateNormal ();
}
