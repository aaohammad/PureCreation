#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/gl.h>

class Material
{
public:
    Material();
    void setAmbient	(float red,	float green,	float blue,	float alpha);
    void setDiffuse	(float red,	float green,	float blue,	float alpha);
    void setSpecular	(float red,	float green,	float blue,	float alpha);
    void setShininess	(float frontShininess);
    void setMaterial	();

private:
    float frontAmbient[4];
    float frontDiffuse[4];
    float frontSpecular[4];
    float frontShininess;

    float backAmbient[4];
    float backDiffuse[4];
    float backSpecular[4];
    float backShininess;
};

#endif // MATERIAL_H
