#ifndef MOVEMANAGER_H
#define MOVEMANAGER_H

#include "model-manager.h"
#include "undo-manager.h"

class MoveManager
{
public:
    static MoveManager * getInstance();
    void mousePressed(float x, float y, float z);
    void mouseMoved(float x, float y, float z);
    void mouseReleased();
    void changeDrawingMode(DrawingModes drawingMode);

private:
    MoveManager();
    static MoveManager * m_moveManager;
    DrawingModes drawingMode;
    float preX;
    float preY;
    float preZ;
    float curX;
    float curY;
    float curZ;
};

#endif // MOVEMANAGER_H
