#include "spline.h"

Spline::Spline(VertexManager *vertexManager)
{
    this->m_vertexManager->append(vertexManager);
    calculateCenter();
}

void Spline::drawEdgeMode()
{
}

void Spline::drawFaceMode()
{
}

void Spline::drawObjectMode()
{
    if(m_vertexManager->size() >= 4)
    {
        glBegin(GL_LINE_STRIP);
        for(int i = 1 ; i < m_vertexManager->size() - 2 ; i++)
        {
            for(int j = 0 ; j != 20 ; j++)
            {
                float u = (float)j / (20 - 1);
                float x = 0.5 * (2 * m_vertexManager->at(i)->x +
                                 (-1 * m_vertexManager->at(i - 1)->x + m_vertexManager->at(i + 1)->x) * u +
                                 (2 * m_vertexManager->at(i - 1)->x - 5 * m_vertexManager->at(i)->x + 4 * m_vertexManager->at(i + 1)->x - m_vertexManager->at(i + 2)->x) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->x + 3 * m_vertexManager->at(i)->x - 3 * m_vertexManager->at(i + 1)->x + m_vertexManager->at(i + 2)->x) * u * u * u);

                float y = 0.5 * (2 * m_vertexManager->at(i)->y +
                                 (-1 * m_vertexManager->at(i - 1)->y + m_vertexManager->at(i + 1)->y) * u +
                                 (2 * m_vertexManager->at(i - 1)->y - 5 * m_vertexManager->at(i)->y + 4 * m_vertexManager->at(i + 1)->y - m_vertexManager->at(i + 2)->y) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->y + 3 * m_vertexManager->at(i)->y - 3 * m_vertexManager->at(i + 1)->y + m_vertexManager->at(i + 2)->y) * u * u * u);

                float z = 0.5 * (2 * m_vertexManager->at(i)->z +
                                 (-1 * m_vertexManager->at(i - 1)->z + m_vertexManager->at(i + 1)->z) * u +
                                 (2 * m_vertexManager->at(i - 1)->z - 5 * m_vertexManager->at(i)->z + 4 * m_vertexManager->at(i + 1)->z - m_vertexManager->at(i + 2)->z) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->z + 3 * m_vertexManager->at(i)->z - 3 * m_vertexManager->at(i + 1)->z + m_vertexManager->at(i + 2)->z) * u * u * u);

                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}

void Spline::drawVertexMode()
{
    if(m_vertexManager->size() >= 4)
    {
        glBegin(GL_LINE_STRIP);
        for(int i = 1 ; i < m_vertexManager->size() - 2 ; i++)
        {
            for(int j = 0 ; j != 20 ; j++)
            {
                float u = (float)j / (20 - 1);
                float x = 0.5 * (2 * m_vertexManager->at(i)->x +
                                 (-1 * m_vertexManager->at(i - 1)->x + m_vertexManager->at(i + 1)->x) * u +
                                 (2 * m_vertexManager->at(i - 1)->x - 5 * m_vertexManager->at(i)->x + 4 * m_vertexManager->at(i + 1)->x - m_vertexManager->at(i + 2)->x) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->x + 3 * m_vertexManager->at(i)->x - 3 * m_vertexManager->at(i + 1)->x + m_vertexManager->at(i + 2)->x) * u * u * u);

                float y = 0.5 * (2 * m_vertexManager->at(i)->y +
                                 (-1 * m_vertexManager->at(i - 1)->y + m_vertexManager->at(i + 1)->y) * u +
                                 (2 * m_vertexManager->at(i - 1)->y - 5 * m_vertexManager->at(i)->y + 4 * m_vertexManager->at(i + 1)->y - m_vertexManager->at(i + 2)->y) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->y + 3 * m_vertexManager->at(i)->y - 3 * m_vertexManager->at(i + 1)->y + m_vertexManager->at(i + 2)->y) * u * u * u);
                float z = 0.5 * (2 * m_vertexManager->at(i)->z +
                                 (-1 * m_vertexManager->at(i - 1)->z + m_vertexManager->at(i + 1)->z) * u +
                                 (2 * m_vertexManager->at(i - 1)->z - 5 * m_vertexManager->at(i)->z + 4 * m_vertexManager->at(i + 1)->z - m_vertexManager->at(i + 2)->z) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->z + 3 * m_vertexManager->at(i)->z - 3 * m_vertexManager->at(i + 1)->z + m_vertexManager->at(i + 2)->z) * u * u * u);

                glVertex3f(x , y, z);
            }
        }
        glEnd();
    }
    glClear(GL_DEPTH_BUFFER_BIT);
    int i = 0;
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

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    i = 0;
    while(i != m_vertexManager->size())
    {
        glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
        i++;
    }
    glEnd();
}

void Spline::drawEdgeModeSelect()
{

}

void Spline::drawFaceModeSelect()
{

}

void Spline::drawObjectModeSelect()
{
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
    if(m_vertexManager->size() >= 4)
    {
        glBegin(GL_LINE_STRIP);
        for(int i = 1 ; i < m_vertexManager->size() - 2 ; i++)
        {
            for(int j = 0 ; j != 20 ; j++)
            {
                float u = (float)j / (20 - 1);
                float x = 0.5 * (2 * m_vertexManager->at(i)->x +
                                 (-1 * m_vertexManager->at(i - 1)->x + m_vertexManager->at(i + 1)->x) * u +
                                 (2 * m_vertexManager->at(i - 1)->x - 5 * m_vertexManager->at(i)->x + 4 * m_vertexManager->at(i + 1)->x - m_vertexManager->at(i + 2)->x) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->x + 3 * m_vertexManager->at(i)->x - 3 * m_vertexManager->at(i + 1)->x + m_vertexManager->at(i + 2)->x) * u * u * u);

                float y = 0.5 * (2 * m_vertexManager->at(i)->y +
                                 (-1 * m_vertexManager->at(i - 1)->y + m_vertexManager->at(i + 1)->y) * u +
                                 (2 * m_vertexManager->at(i - 1)->y - 5 * m_vertexManager->at(i)->y + 4 * m_vertexManager->at(i + 1)->y - m_vertexManager->at(i + 2)->y) * u * u +
                                 (-1 * m_vertexManager->at(i - 1)->y + 3 * m_vertexManager->at(i)->y - 3 * m_vertexManager->at(i + 1)->y + m_vertexManager->at(i + 2)->y) * u * u * u);

                glVertex2f(x , y);
            }
        }
        glEnd();
    }
}

void Spline::drawVertexModeSelect(int index)
{
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
    glEnd();
}

void Spline::save(QDataStream *out)
{
//    QString name("Spline");
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

bool Spline::completeModel ()
{
    return true;
}
