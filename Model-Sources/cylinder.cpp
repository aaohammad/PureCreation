#include "cylinder.h"

Cylinder::Cylinder(float x, float y, float z, float radius, float height)
{
	VertexManager * bottomCircleVertices = new VertexManager();
	VertexManager * topCircleVertices = new VertexManager();
	float tx, ty, tz;
	Vector * bottomCenter = new Vector(x, y, z);
	Vector * topCenter = new Vector(x, y, z);
	bottomCircleVertices->append (bottomCenter);
	topCircleVertices->append (topCenter);
	if(x == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			ty = y + sin(angle) * radius;
			tz = z + cos(angle) * radius;
			Vector *bottomVector = new Vector(0.0f, ty, tz);
			Vector *topVector = new Vector(0.0f, ty, tz);
			bottomCircleVertices->append (bottomVector);
			topCircleVertices->append (topVector);
		}
	}
	else if(y == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			tz = z + sin(angle) * radius;
			tx = x + cos(angle) * radius;
			Vector *bottomVector = new Vector(tx, 0.0f, tz);
			Vector *topVector = new Vector(tx, 0.0f, tz);
			bottomCircleVertices->append (bottomVector);
			topCircleVertices->append (topVector);
		}
	}
	else if(z == 0.0f)
	{
		for(float angle = 0; angle <= 2 * M_PI; angle += M_PI / 16)
		{
			ty = y + sin(angle) * radius;
			tx = x + cos(angle) * radius;
			Vector *bottomVector = new Vector(tx, ty, 0.0f);
			Vector *topVector = new Vector(tx, ty, 0.0f);
			bottomCircleVertices->append (bottomVector);
			topCircleVertices->append (topVector);
		}
	}
	for(int i = 0; i < bottomCircleVertices->size (); i++)
		m_vertexManager->append (bottomCircleVertices->at (i));
	for(int i = 0; i < topCircleVertices->size (); i++)
		m_vertexManager->append (topCircleVertices->at (i));

	for(int i = 1; i < m_vertexManager->size() / 2; i++)
	{
		if(i != 32)
		{
			Face *face = new Face(m_vertexManager->at(0), m_vertexManager->at(i), m_vertexManager->at(i + 1));
			m_faceManager->append(face);
		}
		else
		{
			Face *face = new Face(m_vertexManager->at(0), m_vertexManager->at(32), m_vertexManager->at(1));
			m_faceManager->append(face);
		}
	}
	for(int i = 34; i < m_vertexManager->size(); i++)
	{
		if(i != 65)
		{
			Face *face = new Face(m_vertexManager->at(i + 1), m_vertexManager->at(i), m_vertexManager->at(33));
			m_faceManager->append(face);
		}
		else
		{
			Face *face = new Face(m_vertexManager->at(34), m_vertexManager->at(65), m_vertexManager->at(33));
			m_faceManager->append(face);
		}
	}
	for(int i = 1; i < bottomCircleVertices->size (); i++)
	{
		if(i != bottomCircleVertices->size () - 1)
		{
			Face *face1 = new Face(bottomCircleVertices->at (i), topCircleVertices->at (i), topCircleVertices->at(i + 1));
			Face *face2 = new Face(bottomCircleVertices->at (i), topCircleVertices->at (i + 1), bottomCircleVertices->at(i + 1));
			m_faceManager->append (face1);
			m_faceManager->append (face2);
		}
		else
		{
			Face *face1 = new Face(bottomCircleVertices->at (i), topCircleVertices->at (i), topCircleVertices->at(1));
			Face *face2 = new Face(bottomCircleVertices->at (i), topCircleVertices->at (1), bottomCircleVertices->at(1));
			m_faceManager->append (face1);
			m_faceManager->append (face2);
		}
	}
}

void Cylinder::drawEdgeMode ()
{

}

void Cylinder::drawFaceMode ()
{

}

void Cylinder::drawObjectMode ()
{
	glPointSize (5);
	glBegin (GL_POINTS);
	for(int i = 0; i < m_vertexManager->size (); i++)
	{
		glVertex3f (m_vertexManager->at (i)->x, m_vertexManager->at (i)->y, m_vertexManager->at (i)->z);
	}
	glEnd();
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

void Cylinder::drawVertexMode ()
{
	glPointSize (5);
	glBegin (GL_POINTS);
	for(int i = 0; i < m_vertexManager->size (); i++)
	{
		glVertex3f (m_vertexManager->at (i)->x, m_vertexManager->at (i)->y, m_vertexManager->at (i)->z);
	}
	glEnd();
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

void Cylinder::drawEdgeModeSelect ()
{

}

void Cylinder::drawFaceModeSelect ()
{

}

void Cylinder::drawObjectModeSelect ()
{

}

void Cylinder::drawVertexModeSelect (int index)
{

}

void Cylinder::save (QDataStream *out)
{

}

bool Cylinder::completeModel ()
{
	return true;
}

void Cylinder::setHeight (float height)
{
	for(int i = 33; i < m_vertexManager->size (); i++)
	{
		m_vertexManager->at (i)->y = height;
	}
}

void Cylinder::setLength (float length)
{
	for(int i = 33; i < m_vertexManager->size (); i++)
	{
		m_vertexManager->at (i)->x = length;
	}
}

void Cylinder::setWidth (float width)
{
	for(int i = 33; i < m_vertexManager->size (); i++)
	{
		m_vertexManager->at (i)->z = width;
	}
}
