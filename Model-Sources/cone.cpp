#include "cone.h"

Cone::Cone(float x, float y, float z, float radius, float height)
{
	float tx, ty, tz;
	Vector * bottomCenter = new Vector(x, y, z);
	Vector * top = new Vector(x, y, z);
	m_vertexManager->append (top);
	m_vertexManager->append (bottomCenter);
	if(x == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			ty = y + sin(angle) * radius;
			tz = z + cos(angle) * radius;
			Vector *bottomVector = new Vector(0.0f, ty, tz);
			m_vertexManager->append (bottomVector);
		}
	}
	else if(y == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			tz = z + sin(angle) * radius;
			tx = x + cos(angle) * radius;
			Vector *bottomVector = new Vector(tx, 0.0f, tz);
			m_vertexManager->append (bottomVector);
		}
	}
	else if(z == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			ty = y + sin(angle) * radius;
			tx = x + cos(angle) * radius;
			Vector *bottomVector = new Vector(tx, ty, 0.0f);
			m_vertexManager->append (bottomVector);
		}
	}

	for(int i = 2; i < m_vertexManager->size(); i++)
	{
		if(i != 33)
		{
			Face *face = new Face(m_vertexManager->at(1), m_vertexManager->at(i), m_vertexManager->at(i + 1));
			m_faceManager->append(face);
		}
		else
		{
			Face *face = new Face(m_vertexManager->at(1), m_vertexManager->at(33), m_vertexManager->at(2));
			m_faceManager->append(face);
		}
	}
	for(int i = 2; i < m_vertexManager->size (); i++)
	{
		if(i != m_vertexManager->size () - 1)
		{
			Face *face1 = new Face(m_vertexManager->at (i), m_vertexManager->at (0), m_vertexManager->at (i + 1));
			m_faceManager->append (face1);
		}
		else
		{
			Face *face1 = new Face(m_vertexManager->at (i), m_vertexManager->at (0), m_vertexManager->at (2));
			m_faceManager->append (face1);
		}
	}
}

void Cone::drawEdgeMode ()
{

}

void Cone::drawFaceMode ()
{

}

void Cone::drawObjectMode ()
{
	m_material->setMaterial ();
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

void Cone::drawVertexMode ()
{
	m_material->setMaterial ();
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
	glDisable (GL_LIGHTING);
	glColor3f (1.0f, 1.0f, 1.0f);
	glPointSize (5);
	glBegin (GL_POINTS);
	for(int i = 0; i < m_vertexManager->size (); i++)
	{
		glVertex3f (m_vertexManager->at (i)->x, m_vertexManager->at (i)->y, m_vertexManager->at (i)->z);
	}
	glEnd();
	glEnable (GL_LIGHTING);
}

void Cone::drawEdgeModeSelect ()
{

}

void Cone::drawFaceModeSelect ()
{

}

void Cone::drawObjectModeSelect ()
{

}

void Cone::drawVertexModeSelect (int index)
{

}

void Cone::save (QDataStream *out)
{

}

bool Cone::completeModel ()
{
	return true;
}

void Cone::setHeight (float height)
{
	m_vertexManager->at (0)->y = height;
}

void Cone::setLength (float length)
{
	m_vertexManager->at (0)->x = length;
}

void Cone::setWidth (float width)
{
	m_vertexManager->at (0)->z = width;
}

