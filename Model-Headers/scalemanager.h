#ifndef SCALEMANAGER_H
#define SCALEMANAGER_H

#include "modelmanager.h"
#include "undomanager.h"

class ScaleManager
{
public:
    ScaleManager(ModelManager *modelManager, UndoManager *undoManager);
    void mousePressed(float x, float y);
    void mouseMoved(float x, float y);
    void mouseReleased();
    void drawHandle(float zoomFactor);
    bool isSelected(float x, float y);
private:
    ModelManager *modelManager;
    UndoManager *undoManager;
    float xCenter, yCenter, zoomFactor;
    bool scaleXY;
    bool scaleX;
    bool scaleY;
    float preX;
    float preY;
    float curX;
    float curY;
};

#endif // SCALEMANAGER_H
