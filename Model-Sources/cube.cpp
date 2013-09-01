#include "cube.h"

Cube::Cube(float x, float y, float z, float length, float width, float height)
{
	this->height = height;
	this->length = length;
	this->width = width;
	Vector *v0 = new Vector(x + length, y - height, z + width);
	Vector *v1 = new Vector(x + length, y - height, z - width);
	Vector *v2 = new Vector(x - length, y - height, z - width);
	Vector *v3 = new Vector(x - length, y - height, z + width);
	Vector *v4 = new Vector(x + length, y + height, z + width);
	Vector *v5 = new Vector(x + length, y + height, z - width);
	Vector *v6 = new Vector(x - length, y + height, z - width);
	Vector *v7 = new Vector(x - length, y + height, z + width);
	m_vertexManager->append (v0);
	m_vertexManager->append (v1);
	m_vertexManager->append (v2);
	m_vertexManager->append (v3);
	m_vertexManager->append (v4);
	m_vertexManager->append (v5);
	m_vertexManager->append (v6);
	m_vertexManager->append (v7);

	Face * f0 = new Face(v0, v4, v5);
	Face * f1 = new Face(v0, v5, v1);
	Face * f2 = new Face(v1, v5, v6);
	Face * f3 = new Face(v1, v6, v2);
	Face * f4 = new Face(v2, v6, v7);
	Face * f5 = new Face(v2, v7, v3);
	Face * f6 = new Face(v3, v7, v4);
	Face * f7 = new Face(v3, v4, v0);
	Face * f8 = new Face(v3, v2, v1);
	Face * f9 = new Face(v3, v1, v0);
	Face * f10 = new Face(v7, v6, v5);
	Face * f11 = new Face(v7, v5, v4);
	m_faceManager->append (f0);
	m_faceManager->append (f1);
	m_faceManager->append (f2);
	m_faceManager->append (f3);
	m_faceManager->append (f4);
	m_faceManager->append (f5);
	m_faceManager->append (f6);
	m_faceManager->append (f7);
	m_faceManager->append (f8);
	m_faceManager->append (f9);
	m_faceManager->append (f10);
	m_faceManager->append (f11);
}

void Cube::drawEdgeMode ()
{

}

void Cube::drawFaceMode ()
{

}

void Cube::drawObjectMode ()
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

void Cube::drawVertexMode ()
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

void Cube::drawEdgeModeSelect ()
{

}

void Cube::drawFaceModeSelect ()
{

}

void Cube::drawObjectModeSelect ()
{

}

void Cube::drawVertexModeSelect (int index)
{

}

void Cube::save (QDataStream *out)
{

}

bool Cube::completeModel ()
{
	return true;
}

void Cube::setHeight (float height)
{
	for(int i = 4; i < m_vertexManager->size (); i++)
	{
		m_vertexManager->at (i)->y = height;
	}
}

void Cube::setLength (float length)
{
	m_vertexManager->at (0)->x = length;
	m_vertexManager->at (1)->x = length;
	m_vertexManager->at (4)->x = length;
	m_vertexManager->at (5)->x = length;
}

void Cube::setWidth (float width)
{
	m_vertexManager->at (1)->z = width;
	m_vertexManager->at (2)->z = width;
	m_vertexManager->at (5)->z = width;
	m_vertexManager->at (6)->z = width;

}
