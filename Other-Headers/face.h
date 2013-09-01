#ifndef FACE_H
#define FACE_H

#include "vector.h"

class Face
{
public:
    Face(Vector *, Vector *, Vector *);
    void setVertex(Vector * [3]);
    Vector *getV1();
    Vector *getV2();
    Vector *getV3();
    void calculateNormal();
private:
    Vector *v1;
    Vector *v2;
    Vector *v3;
    Vector *appendedVector;
};

#endif // FACE_H
