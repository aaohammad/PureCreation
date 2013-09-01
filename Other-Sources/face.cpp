#include "face.h"

Face::Face(Vector *v1, Vector *v2, Vector *v3)
{
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    appendedVector = new Vector(0.0f, 0.0f, 0.0f);
    this->v1->appendNormal (appendedVector);
    this->v2->appendNormal (appendedVector);
    this->v3->appendNormal (appendedVector);
}

void Face::setVertex(Vector * vect[3])
{
    v1 = vect[0];
    v2 = vect[1];
    v3 = vect[2];
}

Vector * Face::getV1()
{
    return v1;
}

Vector * Face::getV2()
{
    return v2;
}

Vector * Face::getV3()
{
    return v3;
}

void Face::calculateNormal ()
{
    float ax, ay, az;
    float bx, by, bz;
    ax = this->v2->x - this->v1->x;
    ay = this->v2->y - this->v1->y;
    az = this->v2->z - this->v1->z;

    bx = this->v3->x - this->v1->x;
    by = this->v3->y - this->v1->y;
    bz = this->v3->z - this->v1->z;

    float nx = ay * bz - az * by;
    float ny = az * bx - ax * bz;
    float nz = ax * by - ay * bx;

    // Normalizing normal vectors
    float length = sqrt (pow (nx, 2.0) + pow(ny, 2.0) + pow(nz, 2.0));
    nx /= length;
    ny /= length;
    nz /= length;

    Vector *vector = new Vector(nx, ny, nz);
    this->appendedVector->replace (vector);
}
