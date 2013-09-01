#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

// This class is singleton class.

#include "light.h"
#include <QList>

class LightManager
{
public:
    static LightManager * getInstance();
    void append(Light *light);
    void removeLight(Light *light);
    void disableLighting();
    void enableLighting();
    void disableAllLights();
    void doLight();
    void suspendLighting(){}
    void unSuspendLighting(){}

private:
    LightManager();
    QList<Light *> * m_lightList;
    static LightManager * m_lightManager;
};

#endif // LIGHTMANAGER_H
