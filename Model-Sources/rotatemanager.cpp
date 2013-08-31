#include "rotatemanager.h"

RotateManager::RotateManager(ModelManager *modelManager, UndoManager *undoManager)
{
    this->modelManager = modelManager;
    this->undoManager = undoManager;
}

void RotateManager::mousePressed(float x, float y)
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

void RotateManager::mouseMoved(float x, float y)
{
    curX = x;
    curY = y;
    int i = 0;
    while(i < modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            s->rotate(preX - curX);
        }
        i++;
    }
}

void RotateManager::mouseReleased()
{
    int i = 0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            float angle = preX - curX;
            s->rotate(-angle);
            undoManager->rotateModel(s, angle);
            s->setMouseStatus(true);
        }
        i++;
    }
}

void RotateManager::drawHandle(float zoomFactor)
{
    this->zoomFactor = zoomFactor;
    this->xCenter = 0.0;
    this->yCenter = 0.0;
    float x, y;
    int i = 0, counter = 0;
    while(i != modelManager->size())
    {
        Model *m = modelManager->at(i);
        if(m->getSelected())
        {
            m->getCenter(x, y);
            xCenter += x;
            yCenter += y;
            counter++;
        }
        i++;
    }
    if(counter != 0)
    {
        this->xCenter /= counter;
        this->yCenter /= counter;
        glColor3f(0.0, 0.0, 1.0);
        glLineStipple(1, 0xFFFF);
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        for(float angle = 0; angle < 6.3; angle += 0.1)
        {
            glVertex2f(xCenter + cos(angle) * 2.5 * zoomFactor / 30, yCenter + sin(angle) * 2.5 * zoomFactor / 30);
        }
        glEnd();
    }
}

bool RotateManager::isSelected(float x, float y)
{

}
