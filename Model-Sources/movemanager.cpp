#include "movemanager.h"

MoveManager::MoveManager(ModelManager *modelManager, UndoManager *undoManager)
{
    this->modelManager = modelManager;
    this->undoManager = undoManager;
}

void MoveManager::mousePressed(float x, float y)
{
    preX = x;
    preY = y;
    int i = 0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            s->setMouseStatus(false);
        }
        i++;
    }
}

void MoveManager::mouseMoved(float x, float y)
{
    curX = x;
    curY = y;
    int i = 0;
    while(i < modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected())
        {
            s->move(curY - preY, curX - preX);
        }
        i++;
    }
}

void MoveManager::mouseReleased()
{
    int i = 0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected())
        {
            s->move(-(curY - preY), -(curX - preX));
            undoManager->moveModel(s, curY - preY, curX - preX);
            s->setMouseStatus(true);
        }
        i++;
    }
}
