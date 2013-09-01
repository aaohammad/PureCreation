#include "rotate-manager.h"

RotateManager * RotateManager::m_rotateManager = NULL;
RotateManager * RotateManager::getInstance ()
{
    if(m_rotateManager)
        m_rotateManager = new RotateManager;
    return m_rotateManager;
}

RotateManager::RotateManager()
{
//    this->isHandleSelected = false;
}

void RotateManager::mousePressed(float x, float y, float z)
{
//    preX = x;
//    preY = y;
//    preZ = z;
//    int i = 0;
//    while(i != modelManager->size())
//    {
//        Model *s = modelManager->at(i);
//        if(s->getSelected() == true)
//        {
//            s->mousePressed(x, y, z);
//        }
//        i++;
//    }
}

void RotateManager::mouseMoved(float x, float y, float z)
{
//    curX = x;
//    curY = y;
//    curZ = z;
//    float r2 = sqrt(pow(xCenter - preX, 2) + pow(yCenter - preY, 2)) * (sqrt(pow(xCenter - curX, 2) + pow(yCenter - curY, 2)));
//    float rot = acos((((preX - xCenter) * (curX - xCenter) + ((preY - yCenter) * (curY - yCenter)))) / r2);
//    degree = 180 * rot / M_PI;
//    if((preX - xCenter) * (curY - yCenter) - (preY - yCenter) * (curX - xCenter) < 0)
//        degree = -degree;
//    if(preX * curY - preY * curX == 0)
//        degree = 0;
//    int i = 0;
//    while(i < modelManager->size())
//    {
//        Model *s = modelManager->at(i);
//        if(s->getSelected() == true)
//        {
//            //s->rotateMouseMoved(degree * M_PI/180);
//        }
//        i++;
//    }
}

void RotateManager::mouseReleased()
{
//    int i = 0;
//    while(i != modelManager->size())
//    {
//        Model *s = modelManager->at(i);
//        if(s->getSelected() == true)
//        {
//            //s->rotate(-degree * M_PI/180);
//            undoManager->rotateModel(s, degree * M_PI/180);
//            s->mouseReleased();
//        }
//        i++;
//    }
//    isHandleSelected = false;
}

void RotateManager::drawHandle(float zoomFactor)
{
//    this->zoomFactor = zoomFactor;
//    this->xCenter = 0.0;
//    this->yCenter = 0.0;
//    float x, y;
//    int i = 0, counter = 0;
//    while(i != modelManager->size())
//    {
//        Model *m = modelManager->at(i);
//        if(m->getSelected())
//        {
//            //m->getCenter(x, y);
//            xCenter += x;
//            yCenter += y;
//            counter++;
//        }
//        i++;
//    }
//    if(counter != 0)
//    {
//        this->xCenter /= counter;
//        this->yCenter /= counter;
//        glColor3f(0.0, 0.0, 1.0);
//        glLineWidth(5);
//        glBegin(GL_LINE_LOOP);
//        for(float angle = 0; angle < 6.3; angle += 0.1)
//        {
//            glVertex2f(xCenter + cos(angle) * 2.5 * zoomFactor / 30, yCenter + sin(angle) * 2.5 * zoomFactor / 30);
//        }
//        glEnd();
//        if(isHandleSelected)
//        {
//            glColor3f(1.0, 1.0, 1.0);
//            glLineWidth(2);
//            glBegin(GL_LINES);
//            glVertex2f(xCenter, yCenter);
//            glVertex2f(preX, preY);
//            glEnd();

//            glBegin(GL_LINES);
//            glVertex2f(xCenter, yCenter);
//            glVertex2f(curX, curY);
//            glEnd();
//        }
//        glLineWidth(1);
//    }
}

bool RotateManager::isSelected(float x, float y, float z)
{
//    isHandleSelected = false;
//    float pointDistance = sqrt(pow(xCenter - x, 2) + pow(yCenter - y, 2));
//    if(pointDistance > 2.5 * zoomFactor / 30 - 0.3 * zoomFactor / 30 && pointDistance < 2.5 * zoomFactor / 30 + 0.3 * zoomFactor / 30)
//    {
//        isHandleSelected = true;
//        return true;
//    }
//    return false;
}
