#include "scale-manager.h"

ScaleManager * ScaleManager::m_scaleManager = NULL;
ScaleManager * ScaleManager::getInstance ()
{
    if(m_scaleManager)
        m_scaleManager = new ScaleManager();
    return m_scaleManager;
}

ScaleManager::ScaleManager()
{
//    this->scaleX = false;
//    this->scaleXY = false;
//    this->scaleY = false;
}

void ScaleManager::mousePressed(float x, float y)
{
    //    preX = x;
    //    preY = y;
    //    int i = 0;
    //    while(i != modelManager->size())
    //    {
    //        Model *s = modelManager->at(i);
    //        if(s->getSelected() == true)
    //        {
    //            //s->mousePressed(x, y);
    //        }
    //        i++;
    //    }
}

void ScaleManager::mouseMoved(float x, float y)
{
    //    curX = x;
    //    curY = y;
    //    int i = 0;
    //    while(i < modelManager->size())
    //    {
    //        Model *s = modelManager->at(i);
    //        if(s->getSelected() == true)
    //        {
    //            if(this->scaleX)
    //            {
    //                float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                if(curX < preX)
    //                    distant = -distant;
    //                s->scaleMouseMoved(distant + 1, 1);
    //            }
    //            else if(this->scaleY)
    //            {
    //                float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                if(curY < preY)
    //                    distant = -distant;
    //                s->scaleMouseMoved(1, distant + 1);
    //            }
    //            else if(this->scaleXY)
    //            {
    //                if(this->preX >= this->curX)
    //                {
    //                    float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                    s->scaleMouseMoved(-distant + 1, -distant + 1);
    //                }
    //                else if(this->preX < this->curX)
    //                {
    //                    float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                    s->scaleMouseMoved(distant + 1, distant + 1);
    //                }
    //            }
    //        }
    //        i++;
    //    }
}

void ScaleManager::mouseReleased()
{
    //    int i = 0;
    //    while(i != modelManager->size())
    //    {
    //        Model *s = modelManager->at(i);
    //        if(s->getSelected() == true)
    //        {
    //            if(this->scaleX)
    //            {
    //                float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                if(curX < preX)
    //                    distant = -distant;
    //                s->scale(1 / (distant + 1), 1);
    //                undoManager->scaleModel(s, distant + 1, 1);
    //                s->mouseReleased();
    //            }
    //            else if(this->scaleY)
    //            {
    //                float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                if(curY < preY)
    //                    distant = -distant;
    //                s->scale(1, 1 / (distant + 1));
    //                undoManager->scaleModel(s, 1, distant + 1);
    //                s->mouseReleased();
    //            }
    //            else if(this->scaleXY)
    //            {
    //                if(this->preX >= this->curX)
    //                {
    //                    float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                    s->scale(1 / (-distant + 1), 1 / (-distant + 1));
    //                    undoManager->scaleModel(s, -distant + 1, -distant + 1);
    //                    s->mouseReleased();
    //                }
    //                else if(this->preX < this->curX)
    //                {
    //                    float distant = (float)sqrt(pow(preX - curX, 2) + pow(preY - curY, 2));
    //                    s->scale(1 / (distant + 1), 1 / (distant + 1));
    //                    undoManager->scaleModel(s, distant + 1, distant + 1);
    //                    s->mouseReleased();
    //                }
    //            }
    //        }
    //        i++;
    //    }
}

void ScaleManager::drawHandle(float zoomFactor)
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
    //            m->getCenter(x, y);
    //            xCenter += x;
    //            yCenter += y;
    //            counter++;
    //        }
    //        i++;
    //    }
    //    if(counter != 0)
    //    {
    //        glPolygonMode(GL_FRONT, GL_FILL);
    //        this->xCenter /= counter;
    //        this->yCenter /= counter;
    //        glColor3f(1.0, 0.0, 0.0);
    //        // Central Square
    //        glBegin(GL_LINE_LOOP);
    //        glVertex2d(xCenter - 0.2 * zoomFactor / 30, yCenter + 0.2 * zoomFactor / 30);
    //        glVertex2d(xCenter + 0.2 * zoomFactor / 30, yCenter + 0.2 * zoomFactor / 30);
    //        glVertex2d(xCenter + 0.2 * zoomFactor / 30, yCenter - 0.2 * zoomFactor / 30);
    //        glVertex2d(xCenter - 0.2 * zoomFactor / 30, yCenter - 0.2 * zoomFactor / 30);
    //        glEnd();

    //        // Horizontal Line
    //        glColor3f(1.0, 1.0, 1.0);
    //        glLineWidth(2);
    //        glBegin(GL_LINES);
    //        glVertex2f(xCenter + 0.2 * zoomFactor / 30, yCenter);
    //        glVertex2f(xCenter + 2 * zoomFactor / 30, yCenter);
    //        glEnd();

    //        // X Handle
    //        glColor3f(0.0, 1.0, 0.0);
    //        glBegin(GL_QUADS);
    //        glVertex2f(xCenter + 2 * zoomFactor / 30, yCenter + 0.3 * zoomFactor / 30);
    //        glVertex2f(xCenter + 2.5 * zoomFactor / 30, yCenter + 0.3 * zoomFactor / 30);
    //        glVertex2f(xCenter + 2.5 * zoomFactor / 30, yCenter - 0.3 * zoomFactor / 30);
    //        glVertex2f(xCenter + 2 * zoomFactor / 30, yCenter - 0.3 * zoomFactor / 30);
    //        glEnd();

    //        // vertical Line
    //        glColor3f(1.0, 1.0, 1.0);
    //        glBegin(GL_LINES);
    //        glVertex2f(xCenter, yCenter + 0.2 * zoomFactor / 30);
    //        glVertex2f(xCenter, yCenter + 2 * zoomFactor / 30);
    //        glEnd();

    //        // Y Handle
    //        glColor3f(0.0, 0.0, 1.0);
    //        glBegin(GL_QUADS);
    //        glVertex2f(xCenter + 0.3 * zoomFactor / 30, yCenter + 2 * zoomFactor / 30);
    //        glVertex2f(xCenter + 0.3 * zoomFactor / 30, yCenter + 2.5 * zoomFactor / 30);
    //        glVertex2f(xCenter - 0.3 * zoomFactor / 30, yCenter + 2.5 * zoomFactor / 30);
    //        glVertex2f(xCenter - 0.3 * zoomFactor / 30, yCenter + 2 * zoomFactor / 30);
    //        glEnd();
    //        glLineWidth(1);
    //    }
}

bool ScaleManager::isSelected(float x, float y)
{
    //    if(x <= xCenter + 0.2 * zoomFactor / 30 && x >= xCenter - 0.2 * zoomFactor / 30 &&
    //       y <= yCenter + 0.2 * zoomFactor / 30 && y >= yCenter - 0.2 * zoomFactor / 30)
    //    {
    //        this->scaleX = false;
    //        this->scaleXY = true;
    //        this->scaleY = false;
    //        return true;
    //    }
    //    else if(x >= xCenter + 0.2 * zoomFactor / 30 && x <= xCenter + 2 * zoomFactor / 30 &&
    //            y <= yCenter + 0.5 && y >= yCenter - 0.5)
    //    {
    //        this->scaleX = true;
    //        this->scaleXY = false;
    //        this->scaleY = false;
    //        return true;
    //    }
    //    else if(x >= xCenter + 2 * zoomFactor / 30 && x <= xCenter + 2.5 * zoomFactor / 30 &&
    //            y <= yCenter + 0.3 * zoomFactor / 30 && y >= yCenter - 0.3 * zoomFactor / 30)
    //    {
    //        this->scaleX = true;
    //        this->scaleXY = false;
    //        this->scaleY = false;
    //        return true;
    //    }
    //    else if(x <= xCenter + 1 && x >= xCenter - 1 &&
    //            y >= yCenter + 0.2 * zoomFactor / 30 && y <= yCenter + 2 * zoomFactor / 30)
    //    {
    //        this->scaleX = false;
    //        this->scaleXY = false;
    //        this->scaleY = true;
    //        return true;
    //    }
    //    else if(x <= xCenter + 0.3 * zoomFactor / 30 && x >= xCenter - 0.3 * zoomFactor / 30 &&
    //            y >= yCenter + 2 * zoomFactor / 30 && y <= yCenter + 2.5 * zoomFactor / 30)
    //    {
    //        this->scaleX = false;
    //        this->scaleXY = false;
    //        this->scaleY = true;
    //        return true;
    //    }
    //    this->scaleX = false;
    //    this->scaleXY = false;
    //    this->scaleY = false;
    //    return false;
}
