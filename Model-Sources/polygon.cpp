#include "polygon.h"

Polygon::Polygon(VertexManager *vertexManager) : Model()
{
    this->m_vertexManager->append(vertexManager);
    calculateCenter();
}

void Polygon::drawEdgeMode()
{
}

void Polygon::drawFaceMode()
{
}

void Polygon::drawObjectMode()
{
    if(m_selected)
    {
        glColor3f(0.0, 1.0, 0.0);
        int i = 0;
        glBegin(GL_LINE_LOOP);
        while(i != m_vertexManager->size())
        {
            glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
            i++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    int i = 0;
    m_faceManager->calculateNormals ();
    while(i != m_vertexManager->size())
    {
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
        i++;
    }
    glEnd();
}

void Polygon::drawVertexMode()
{
    glColor3f(0.0, 1.0, 0.0);
    int i = 0;
    glBegin(GL_LINE_LOOP);
    while(i != m_vertexManager->size())
    {
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
        i++;
    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    i = 0;
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
}

void Polygon::drawEdgeModeSelect()
{
}

void Polygon::drawFaceModeSelect()
{
}

void Polygon::drawObjectModeSelect()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    int i = 0;
    while(i != m_vertexManager->size())
    {
        glVertex2f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y);
        i++;
    }
    glEnd();
}

void Polygon::drawVertexModeSelect(int index)
{
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
    glEnd();
}

void Polygon::save(QDataStream *out)
{
//    QString name("Polygon");
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
//    (*out) << isFilled;
//    (*out) << xMovement;
//    (*out) << yMovement;
//    (*out) << xScale;
//    (*out) << yScale;
//    (*out) << angle;
}

bool Polygon::completeModel ()
{
    return true;
}
