#include "light.h"

Light::Light(LightType lightType)
{
    this->lightType = lightType;
    ambient[0] = 0.25f;
    ambient[1] = 0.25f;
    ambient[2] = 0.25f;
    ambient[3] = 1.0f;

    diffuse[0] = 0.3f;
    diffuse[1] = 0.3f;
    diffuse[2] = 0.3f;
    diffuse[3] = 1.0f;

    specular[0] = 1.0f;
    specular[1] = 1.0f;
    specular[2] = 1.0f;
    specular[3] = 1.0f;

    position[0] = 10.0f;
    position[1] = 10.0f;
    position[2] = 10.0f;
    position[3] = 1.0f;

    modelAmbient[0] = 0.2f;
    modelAmbient[1] = 0.2f;
    modelAmbient[2] = 0.2f;
    modelAmbient[3] = 1.0f;

    localViewer = false;
    modelTwoSided = true;
}

void Light::setAmbientColor (float red, float green, float blue, float alpha)
{
    ambient[0] = red;
    ambient[1] = green;
    ambient[2] = blue;
    ambient[3] = alpha;
}

void Light::setDiffuseColor(float red, float green, float blue, float alpha)
{
    diffuse[0] = red;
    diffuse[1] = green;
    diffuse[2] = blue;
    diffuse[3] = alpha;
}

void Light::setPosition(float x, float y, float z, float w)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
    position[3] = w;
}

void Light::setSpecularColor(float red, float green, float blue, float alpha)
{
    specular[0] = red;
    specular[1] = green;
    specular[2] = blue;
    specular[3] = alpha;
}

void Light::setSpotLightRange(float innerAngle, float outerAngle, float falloff)
{

}

void Light::setSpotLightDirection (float x, float y, float z, float w)
{

}

void Light::setType (LightType lightType)
{
    this->lightType = lightType;
}

void Light::enable (int lightNumber)
{
    if(lightNumber == 0)
    {
        glLightfv (GL_LIGHT0, GL_POSITION, position);
        glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT0, GL_SPECULAR, specular);
        glEnable (GL_LIGHT0);
    }
    else if (lightNumber == 1)
    {
        glLightfv (GL_LIGHT1, GL_POSITION, position);
        glLightfv (GL_LIGHT1, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT1, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT1, GL_SPECULAR, specular);
        glEnable (GL_LIGHT1);
    }
    else if (lightNumber == 2)
    {
        glLightfv (GL_LIGHT2, GL_POSITION, position);
        glLightfv (GL_LIGHT2, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT2, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT2, GL_SPECULAR, specular);
        glEnable (GL_LIGHT2);
    }
    else if (lightNumber == 3)
    {
        glLightfv (GL_LIGHT3, GL_POSITION, position);
        glLightfv (GL_LIGHT3, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT3, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT3, GL_SPECULAR, specular);
        glEnable (GL_LIGHT3);
    }
    else if (lightNumber == 4)
    {
        glLightfv (GL_LIGHT4, GL_POSITION, position);
        glLightfv (GL_LIGHT4, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT4, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT4, GL_SPECULAR, specular);
        glEnable (GL_LIGHT4);
    }
    else if (lightNumber == 5)
    {
        glLightfv (GL_LIGHT5, GL_POSITION, position);
        glLightfv (GL_LIGHT5, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT5, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT5, GL_SPECULAR, specular);
        glEnable (GL_LIGHT5);
    }
    else if (lightNumber == 6)
    {
        glLightfv (GL_LIGHT6, GL_POSITION, position);
        glLightfv (GL_LIGHT6, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT6, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT6, GL_SPECULAR, specular);
        glEnable (GL_LIGHT6);
    }
    else if (lightNumber == 7)
    {
        glLightfv (GL_LIGHT7, GL_POSITION, position);
        glLightfv (GL_LIGHT7, GL_AMBIENT, ambient);
        glLightfv (GL_LIGHT7, GL_DIFFUSE, diffuse);
        glLightfv (GL_LIGHT7, GL_SPECULAR, specular);
        glEnable (GL_LIGHT7);
    }
    glLightModelfv (GL_LIGHT_MODEL_AMBIENT, modelAmbient);
    glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);
    glLightModeli (GL_LIGHT_MODEL_TWO_SIDE, modelTwoSided);
}

void Light::disable (int lightNumber)
{
    if(lightNumber == 0)
        glDisable (GL_LIGHT0);
    else if (lightNumber == 1)
        glDisable (GL_LIGHT1);
    else if (lightNumber == 2)
        glDisable (GL_LIGHT2);
    else if (lightNumber == 3)
        glDisable (GL_LIGHT3);
    else if (lightNumber == 4)
        glDisable (GL_LIGHT4);
    else if (lightNumber == 5)
        glDisable (GL_LIGHT5);
    else if (lightNumber == 6)
        glDisable (GL_LIGHT6);
    else if (lightNumber == 7)
        glDisable (GL_LIGHT7);
}

void Light::drawObjectMode ()
{

}

void Light::drawObjectModeSelect ()
{

}

void Light::save (QDataStream *out)
{

}

void Light::showAttribute ()
{

}

void Light::changeAttributes ()
{

}
