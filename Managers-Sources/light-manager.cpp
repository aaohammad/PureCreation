#include "light-manager.h"

LightManager * LightManager::m_lightManager = 0;
LightManager * LightManager::getInstance ()
{
    if(!m_lightManager)
        m_lightManager = new LightManager();
    return m_lightManager;
}

LightManager::LightManager()
{
    m_lightList = new QList<Light *>();
}

void LightManager::append (Light *light)
{
    this->m_lightList->append (light);
}

void LightManager::removeLight (Light *light)
{
    this->m_lightList->removeOne (light);
}

void LightManager::disableLighting ()
{
    glDisable (GL_LIGHTING);
}

void LightManager::enableLighting ()
{
    glEnable (GL_LIGHTING);
}

void LightManager::disableAllLights ()
{
}

void LightManager::doLight()
{
    for(int i = 0; i < this->m_lightList->size (); i++)
    {
        this->m_lightList->at (i)->enable (i);
    }
}
