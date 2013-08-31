#ifndef MOVEMANAGER_H
#define MOVEMANAGER_H

#include "modelmanager.h"
#include "undomanager.h"

class MoveManager
{
public:
    MoveManager(ModelManager *modelManager, UndoManager *undoManager);
    void mousePressed(float x, float y);
    void mouseMoved(float x, float y);
    void mouseReleased();
private:
    ModelManager *modelManager;
    UndoManager *undoManager;
    float preX;
    float preY;
    float curX;
    float curY;
};

#endif // MOVEMANAGER_H
