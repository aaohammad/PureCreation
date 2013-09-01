#include "bezier.h"

Bezier::Bezier(VertexManager *vertexManager) : Model()
{
	this->m_vertexManager->append(vertexManager);
	calculateCenter();
}

void Bezier::drawEdgeMode()
{
}

void Bezier::drawFaceMode()
{
}

void Bezier::drawObjectMode()
{
	if(m_selected)
	{
		glDisable (GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		int i = 0;
		glPointSize(8);
		glBegin(GL_POINTS);
		while(i != m_vertexManager->size())
		{
			glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
			i++;
		}
		glEnd();
		glPointSize(1);
		glColor3f(0.0, 1.0, 0.0);
		glLineWidth (2);
		glBegin(GL_LINE_STRIP);
		i = 0;
		while(i != m_vertexManager->size())
		{
			glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
			i++;
		}
		glEnd();
		glLineWidth (1);
		glEnable (GL_LIGHTING);
	}
	float ctrlPoints[m_vertexManager->size()][3];
	for(int i = 0; i < m_vertexManager->size() ; i++)
	{
		ctrlPoints[i][0] = m_vertexManager->at(i)->x;
		ctrlPoints[i][1] = m_vertexManager->at(i)->y;
		ctrlPoints[i][2] = m_vertexManager->at(i)->z;
	}
	glMap1f(GL_MAP1_VERTEX_3, 0.0f, 100.0f, 3, m_vertexManager->size(), &ctrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glBegin(GL_LINE_STRIP);
	{
		for(int i = 0 ; i <= 100 ; i++)
		{
			glEvalCoord1f(i);
		}
	}
	glEnd();
}

void Bezier::drawVertexMode()
{
	float ctrlPoints[m_vertexManager->size()][3];
	for(int i = 0; i < m_vertexManager->size() ; i++)
	{
		ctrlPoints[i][0] = m_vertexManager->at(i)->x;
		ctrlPoints[i][1] = m_vertexManager->at(i)->y;
		ctrlPoints[i][2] = m_vertexManager->at(i)->z;
	}
	glMap1f(GL_MAP1_VERTEX_3, 0.0f, 100.0f, 3, m_vertexManager->size(), &ctrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glBegin(GL_LINE_STRIP);
	{
		for(int i = 0 ; i <= 100 ; i++)
		{
			glEvalCoord1f(i);
		}
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
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

void Bezier::drawEdgeModeSelect()
{
}

void Bezier::drawFaceModeSelect()
{
}

void Bezier::drawObjectModeSelect()
{
	glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
	float ctrlPoints[m_vertexManager->size()][3];
	for(int i = 0; i < m_vertexManager->size() ; i++)
	{
		ctrlPoints[i][0] = m_vertexManager->at(i)->x;
		ctrlPoints[i][1] = m_vertexManager->at(i)->y;
		ctrlPoints[i][2] = 0.0;
	}
	glMap1f(GL_MAP1_VERTEX_3, 0.0f, 100.0f, 3, m_vertexManager->size(), &ctrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glBegin(GL_LINE_STRIP);
	{
		for(int i = 0 ; i <= 100 ; i++)
		{
			glEvalCoord1f(i);
		}
	}
	glEnd();
}

void Bezier::drawVertexModeSelect(int index)
{
	glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
	glEnd();
}

void Bezier::save(QDataStream *out)
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

bool Bezier::completeModel ()
{
	return true;
}
