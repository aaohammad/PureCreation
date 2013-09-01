#include "move-manager.h"

MoveManager * MoveManager::m_moveManager = NULL;
MoveManager * MoveManager::getInstance ()
{
    if(!m_moveManager)
        m_moveManager = new MoveManager();
    return m_moveManager;
}

MoveManager::MoveManager()
{
//    this->drawingMode = ObjectMode;
}

void MoveManager::mousePressed(float x, float y, float z)
{
//    if(drawingMode == ObjectMode)
//    {
//        preX = x;
//        preY = y;
//        preZ = z;
//        int i = 0;
//        while(i != ModelManager::getInstance ()->size())
//        {
//            Model *s = modelManager->at(i);
//            if(s->getSelected() == true)
//            {
//                s->mousePressed(x, y, z);
//            }
//            i++;
//        }
//    }
//    else if(drawingMode == VertexMode)
//    {
//        int i = 0;
//        while(i != modelManager->size())
//        {
//            for(int k = 0; k < modelManager->at(i)->getVertexManager()->size(); k++)
//            {
//                if(modelManager->at(i)->getVertexManager()->at(k)->getSelection())
//                {
//                    modelManager->at(i)->getVertexManager()->at(k)->mousePressed(x, y);
//                }
//            }
//            i++;
//        }
//    }
}

void MoveManager::mouseMoved(float x, float y, float z)
{
//    curX = x;
//    curY = y;
//    curZ = z;
//    if(drawingMode == ObjectMode)
//    {
//        int i = 0;
//        while(i < modelManager->size())
//        {
//            Model *s = modelManager->at(i);
//            if(s->getSelected())
//            {
//                s->moveMouseMoved(x, y, z);
//            }
//            i++;
//        }
//    }
//    else if(drawingMode == VertexMode)
//    {
//        int i = 0;
//        while(i != modelManager->size())
//        {
//            for(int k = 0; k < modelManager->at(i)->getVertexManager()->size(); k++)
//            {
//                if(modelManager->at(i)->getVertexManager()->at(k)->getSelection())
//                {
//                    modelManager->at(i)->getVertexManager()->at(k)->move(x, y);
//                }
//            }
//            i++;
//        }
//    }
}

void MoveManager::mouseReleased()
{
//    if(drawingMode == ObjectMode)
//    {
//        int i = 0;
//        while(i != modelManager->size())
//        {
//            Model *s = modelManager->at(i);
//            if(s->getSelected())
//            {
//                s->move(-(curX - preX), -(curY - preY), -(curZ - preZ));
//                undoManager->moveModel(s, (curX - preX), (curY - preY));
//                s->mouseReleased();
//            }
//            i++;
//        }
//    }/*
//    else if(drawingMode == VertexMode)
//    {
//        int i = 0;
//        while(i != modelManager->size())
//        {
//            for(int k = 0; k < modelManager->at(i)->getVertexManager()->size(); k++)
//            {
//                if(modelManager->at(i)->getVertexManager()->at(k)->getSelection())
//                {
//                    modelManager->at(i)->getVertexManager()->at(k)->mouseReleased();
//                }
//            }
//            i++;
//        }
//    }*/
}

void MoveManager::changeDrawingMode(DrawingModes drawingMode)
{
//    this->drawingMode = drawingMode;
}
