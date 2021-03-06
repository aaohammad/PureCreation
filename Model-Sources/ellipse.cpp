#include "ellipse.h"

Ellipse::Ellipse(float x, float y, float z, float width, float height) : Model()
{
	if(y < 0.001f && y > -0.001f)
	{
		Vector *center = new Vector(x, 0.0f, z);
		m_vertexManager->append (center);
		float tx, tz;
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			tx = x + sin(angle) * width;
			tz = z + cos(angle) * height;
			Vector *vector = new Vector(tx, 0.0f, tz);
			m_vertexManager->append (vector);
		}
	}
	else if(x < 0.001f && x > -0.001f)
	{
		Vector *center = new Vector(0.0f, y, z);
		m_vertexManager->append (center);
		float ty, tz;
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			ty = y + sin(angle) * width;
			tz = z + cos(angle) * height;
			Vector *vector = new Vector(0.0f, ty, tz);
			m_vertexManager->append (vector);
		}
	}
	else if(z < 0.001f && z > -0.001f)
	{
		Vector *center = new Vector(x, y, 0.0f);
		m_vertexManager->append (center);
		float tx, ty;
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			tx = x + sin(angle) * width;
			ty = y + cos(angle) * height;
			Vector *vector = new Vector(tx, ty, 0.0f);
			m_vertexManager->append (vector);
		}
	}

	for(int i = 1; i < this->m_vertexManager->size(); i++)
	{
		if(i != 32)
		{
			Face *face = new Face(this->m_vertexManager->at(0), this->m_vertexManager->at(i + 1), this->m_vertexManager->at(i));
			this->m_faceManager->append(face);
		}
		else
		{
			Face *face = new Face(this->m_vertexManager->at(0), this->m_vertexManager->at(1), this->m_vertexManager->at(32));
			this->m_faceManager->append(face);
		}
	}
}

void Ellipse::drawEdgeMode()
{
}

void Ellipse::drawFaceMode()
{
}

void Ellipse::drawObjectMode()
{
	if(m_selected)
	{
		glColor3f(0.0, 1.0, 0.0);
		int i = 1;
		glBegin(GL_LINE_LOOP);
		while(i != m_vertexManager->size())
		{
			glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
			i++;
		}
		glEnd();
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	int i = 0;
	m_faceManager->calculateNormals ();
	while(i != m_faceManager->size())
	{
		glNormal3f (m_faceManager->at(i)->getV1()->getNormal ()->x, m_faceManager->at(i)->getV1()->getNormal ()->y, m_faceManager->at(i)->getV1()->getNormal ()->z);
		glVertex3f(m_faceManager->at(i)->getV1()->x, m_faceManager->at(i)->getV1()->y, m_faceManager->at(i)->getV1()->z);
		glNormal3f (m_faceManager->at(i)->getV2()->getNormal ()->x, m_faceManager->at(i)->getV2()->getNormal ()->y, m_faceManager->at(i)->getV2()->getNormal ()->z);
		glVertex3f(m_faceManager->at(i)->getV2()->x, m_faceManager->at(i)->getV2()->y, m_faceManager->at(i)->getV2()->z);
		glNormal3f (m_faceManager->at(i)->getV3()->getNormal ()->x, m_faceManager->at(i)->getV3()->getNormal ()->y, m_faceManager->at(i)->getV3()->getNormal ()->z);
		glVertex3f(m_faceManager->at(i)->getV3()->x, m_faceManager->at(i)->getV3()->y, m_faceManager->at(i)->getV3()->z);
		i++;
	}
	glEnd();
}

void Ellipse::drawVertexMode()
{
	glColor3f(0.0, 1.0, 0.0);
	int i = 1;
	glBegin(GL_LINE_LOOP);
	while(i != m_vertexManager->size())
	{
		glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
		i++;
	}
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	i = 0;
	while(i != m_faceManager->size())
	{
		glVertex3f(m_faceManager->at(i)->getV1()->x, m_faceManager->at(i)->getV1()->y, m_faceManager->at (i)->getV1 ()->z);
		glVertex3f(m_faceManager->at(i)->getV2()->x, m_faceManager->at(i)->getV2()->y, m_faceManager->at (i)->getV2 ()->z);
		glVertex3f(m_faceManager->at(i)->getV3()->x, m_faceManager->at(i)->getV3()->y, m_faceManager->at (i)->getV3 ()->z);
		i++;
	}
	glEnd();

	glClear(GL_DEPTH_BUFFER_BIT);
	i = 1;
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

void Ellipse::drawEdgeModeSelect()
{

}

void Ellipse::drawFaceModeSelect()
{

}

void Ellipse::drawObjectModeSelect()
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

void Ellipse::drawVertexModeSelect(int index)
{
	glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
	glEnd();
}

void Ellipse::save(QDataStream *out)
{
//    QString name("Ellipse");
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

bool Ellipse::completeModel ()
{

}
