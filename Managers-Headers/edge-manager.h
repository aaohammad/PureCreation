#ifndef EDGEMANAGER_H
#define EDGEMANAGER_H

#include "face.h"
#include <QList>

class FaceManager
{
public:
    FaceManager();
    void append(QList<Face *> faceList);
    void append(FaceManager *edgeManager);
    void append(Face *face);
    Face *at(int index);
    void clear();
    int size();
    void calculateNormals();
private:
    QList<Face *> faces;
};

#endif // EDGEMANAGER_H
