#ifndef ROTATEMANAGER_H
#define ROTATEMANAGER_H

#include "model-manager.h"
#include "undo-manager.h"

class RotateManager
{
public:
    static RotateManager * getInstance();
    void mousePressed(float x, float y, float z);
    void mouseMoved(float x, float y, float z);
    void mouseReleased();
    void drawHandle(float zoomFactor);
    bool isSelected(float x, float y, float z);

private:
    RotateManager();
    static RotateManager * m_rotateManager;
    float xCenter, yCenter, zoomFactor;
    float degree;
    bool isHandleSelected;
    float preX;
    float preY;
    float preZ;
    float curX;
    float curY;
    float curZ;
};

#endif // ROTATEMANAGER_H
