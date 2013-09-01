#include "line.h"

Line::Line(VertexManager *vertexManager) : Model()
{
    this->m_vertexManager->append(vertexManager);
    calculateCenter();
}

void Line::drawEdgeMode()
{
}

void Line::drawFaceMode()
{
}

void Line::drawObjectMode()
{
    int i = 0;
    glBegin(GL_LINE_STRIP);
    while(i != m_vertexManager->size())
    {
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
        i++;
    }
    glEnd();
}

void Line::drawVertexMode()
{
    int i = 0;
    glBegin(GL_LINE_STRIP);
    while(i != m_vertexManager->size())
    {
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
        i++;
    }
    glEnd();

    glClear(GL_DEPTH_BUFFER_BIT);
    i = 0;
    glPointSize(8);
    glBegin(GL_POINTS);
    while(i != m_vertexManager->size())
    {
        if(m_vertexManager->at(i)->getSelection())
        {
            glColor3f(0.0, 1.0, 0.0);
        }
        else
        {
            glColor3f(1.0, 1.0, 1.0);
        }
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
        i++;
    }
    glEnd();
    glPointSize(1);
}

void Line::drawEdgeModeSelect()
{
}

void Line::drawFaceModeSelect()
{
}

void Line::drawObjectModeSelect()
{
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.

    int i = 0;
    glBegin(GL_LINE_STRIP);
    while(i != m_vertexManager->size())
    {
        glVertex2f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y);
        i++;
    }
    glEnd();
}

void Line::drawVertexModeSelect(int index)
{
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
    glEnd();
}

void Line::save(QDataStream *out)
{
//    QString name("Bezier");
//    (*out) << name;
//    (*out) << m_vertexManager->size();
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        (*out) << m_vertexManager->at(i)->x;
//        (*out) << m_vertexManager->at(i)->y;
//        i++;
//    }
//    (*out) << color->redF();
//    (*out) << color->greenF();
//    (*out) << color->blueF();
//    (*out) << color->alphaF();
//    (*out) << m_selectionIdentifier;
//    (*out) << groupID;
//    (*out) << xMovement;
//    (*out) << yMovement;
//    (*out) << xScale;
//    (*out) << yScale;
//    (*out) << angle;
}

bool Line::completeModel ()
{
    return true;
}
