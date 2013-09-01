#include "rectangle.h"

Rectangle::Rectangle(float x1, float y1, float z1, float x2, float y2, float z2)
{
	if(y1 < 0.001f && y1 > -0.001f)
	{
		Vector *vect1 = new Vector(x1, 0.0, z2);
		Vector *vect2 = new Vector(x2, 0.0, z2);
		Vector *vect3 = new Vector(x2, 0.0, z1);
		Vector *vect4 = new Vector(x1, 0.0, z1);
		m_vertexManager->append (vect1);
		m_vertexManager->append (vect2);
		m_vertexManager->append (vect3);
		m_vertexManager->append (vect4);
	}
	else if(x1 < 0.001f && x1 > -0.001f)
	{
		Vector *vect1 = new Vector(0.0f, y1, z2);
		Vector *vect2 = new Vector(0.0f, y2, z2);
		Vector *vect3 = new Vector(0.0f, y2, z1);
		Vector *vect4 = new Vector(0.0f, y1, z1);
		m_vertexManager->append (vect1);
		m_vertexManager->append (vect2);
		m_vertexManager->append (vect3);
		m_vertexManager->append (vect4);
	}
	else if(z1 < 0.001f && z1 > -0.001f)
	{
		Vector *vect1 = new Vector(x1, y2, 0.0f);
		Vector *vect2 = new Vector(x2, y2, 0.0f);
		Vector *vect3 = new Vector(x2, y1, 0.0f);
		Vector *vect4 = new Vector(x1, y1, 0.0f);
		m_vertexManager->append (vect1);
		m_vertexManager->append (vect2);
		m_vertexManager->append (vect3);
		m_vertexManager->append (vect4);
	}

	Face *face1 = new Face(this->m_vertexManager->at(0), this->m_vertexManager->at(1), this->m_vertexManager->at(3));
	Face *face2 = new Face(this->m_vertexManager->at(1), this->m_vertexManager->at(2), this->m_vertexManager->at(3));
	this->m_faceManager->append(face1);
	this->m_faceManager->append(face2);
}

void Rectangle::drawEdgeMode()
{
}

void Rectangle::drawFaceMode()
{
}

void Rectangle::drawObjectMode()
{
	if(m_selected)
	{
		glColor3f(0.0, 1.0, 0.0);
		glDisable (GL_LIGHTING);
		int i = 0;
		glLineWidth (10);
		glBegin(GL_LINE_LOOP);
		while(i != m_vertexManager->size())
		{
			glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at(i)->z);
			i++;
		}
		glEnd();
		glEnable (GL_LIGHTING);
	}
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

void Rectangle::drawVertexMode()
{
	glDisable (GL_LIGHTING);
	int i = 0;
	glPointSize(5);
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
	glColor3f(0.0, 1.0, 0.0);
	i = 0;
	glBegin(GL_LINE_LOOP);
	while(i != m_vertexManager->size())
	{
		glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
		i++;
	}
	glEnd();
	glEnable (GL_LIGHTING);
	m_material->setMaterial ();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	i = 0;
	while(i != m_vertexManager->size())
	{
		glVertex3f(m_vertexManager->at(i)->x, m_vertexManager->at(i)->y, m_vertexManager->at (i)->z);
		i++;
	}
	glEnd();
}

void Rectangle::drawEdgeModeSelect()
{

}

void Rectangle::drawFaceModeSelect()
{

}

void Rectangle::drawObjectModeSelect()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	int i = 0;
	while(i != m_faceManager->size())
	{
		glVertex3f(m_faceManager->at(i)->getV1()->x, m_faceManager->at(i)->getV1()->y, m_faceManager->at(i)->getV1()->z);
		glVertex3f(m_faceManager->at(i)->getV2()->x, m_faceManager->at(i)->getV2()->y, m_faceManager->at(i)->getV2()->z);
		glVertex3f(m_faceManager->at(i)->getV3()->x, m_faceManager->at(i)->getV3()->y, m_faceManager->at(i)->getV3()->z);
		i++;
	}
	glEnd();
}

void Rectangle::drawVertexModeSelect(int index)
{
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2f(m_vertexManager->at(index)->x, m_vertexManager->at(index)->y);
	glEnd();
}

void Rectangle::save(QDataStream *out)
{
	//    QString name("Rectangle");
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

bool Rectangle::completeModel ()
{
	return true;
}
