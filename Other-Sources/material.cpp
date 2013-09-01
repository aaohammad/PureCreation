#include "material.h"

Material::Material()
{
    this->frontAmbient[0] = 0.2f;
    this->frontAmbient[1] = 0.2f;
    this->frontAmbient[2] = 0.2f;
    this->frontAmbient[3] = 1.0f;

    this->frontDiffuse[0] = 0.4f;
    this->frontDiffuse[1] = 0.4f;
    this->frontDiffuse[2] = 0.4f;
    this->frontDiffuse[3] = 1.0f;

    this->frontSpecular[0] = 0.0f;
    this->frontSpecular[1] = 0.0f;
    this->frontSpecular[2] = 0.0f;
    this->frontSpecular[3] = 1.0f;

    this->frontShininess = 0.0f;

    this->backAmbient[0] = 0.2f;
    this->backAmbient[1] = 0.2f;
    this->backAmbient[2] = 0.2f;
    this->backAmbient[3] = 1.0f;

    this->backDiffuse[0] = 0.4f;
    this->backDiffuse[1] = 0.4f;
    this->backDiffuse[2] = 0.4f;
    this->backDiffuse[3] = 1.0f;

    this->backSpecular[0] = 0.0f;
    this->backSpecular[1] = 0.0f;
    this->backSpecular[2] = 0.0f;
    this->backSpecular[3] = 1.0f;

    this->backShininess = 0.0f;
}

void Material::setAmbient (float red, float green, float blue, float alpha)
{
    this->frontAmbient[0] = red;
    this->frontAmbient[1] = green;
    this->frontAmbient[2] = blue;
    this->frontAmbient[3] = alpha;
}

void Material::setDiffuse (float red, float green, float blue, float alpha)
{
    this->frontDiffuse[0] = red;
    this->frontDiffuse[1] = green;
    this->frontDiffuse[2] = blue;
    this->frontDiffuse[3] = alpha;
}

void Material::setSpecular (float red, float green, float blue, float alpha)
{
    this->frontSpecular[0] = red;
    this->frontSpecular[1] = green;
    this->frontSpecular[2] = blue;
    this->frontSpecular[3] = alpha;
}

void Material::setShininess (float shininess)
{
    this->frontShininess = shininess;
}

void Material::setMaterial ()
{
    glMaterialfv (GL_FRONT, GL_AMBIENT, frontAmbient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, frontDiffuse);
    glMaterialfv (GL_FRONT, GL_SPECULAR, frontSpecular);
    glMaterialf (GL_FRONT, GL_SHININESS, frontShininess);

    glMaterialfv (GL_BACK, GL_AMBIENT, backAmbient);
    glMaterialfv (GL_BACK, GL_DIFFUSE, backDiffuse);
    glMaterialfv (GL_BACK, GL_SPECULAR, backSpecular);
    glMaterialf (GL_BACK, GL_SHININESS, backShininess);
}
