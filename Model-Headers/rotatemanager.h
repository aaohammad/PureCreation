#ifndef ROTATEMANAGER_H
#define ROTATEMANAGER_H

#include "modelmanager.h"
#include "undomanager.h"

class RotateManager
{
public:
    RotateManager(ModelManager *modelManager, UndoManager *undoManager);
    void mousePressed(float x, float y);
    void mouseMoved(float x, float y);
    void mouseReleased();
    void drawHandle(float zoomFactor);
    bool isSelected(float x, float y);
private:
    ModelManager *modelManager;
    UndoManager *undoManager;
    float xCenter, yCenter, zoomFactor;
    float preX;
    float preY;
    float curX;
    float curY;
};

#endif // ROTATEMANAGER_H
