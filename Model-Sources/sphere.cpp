#include "sphere.h"

Sphere::Sphere(float px, float py, float pz, float radius)
{
	//    this->m_vertexManager->append (vertexManager);
	calculateCenter ();

	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	float phi, teta;
	float x, y, z;
	x = 0.0f + radius * sin (0.0) * cos (0.0) + px;
	y = 0.0f + radius * sin (0.0) * sin (0.0) + py;
	z = 0.0f + radius * cos (0.0) + pz;
	Vector *pole = new Vector(x, y, z);
	VertexManager *vm = new VertexManager();

	int d = 10;
	int h = 10;

	phi = M_PI / h;
	for(teta = 0; teta < 2 * M_PI; teta += M_PI / d)
	{
		x = 0.0f + radius * sin (phi) * cos (teta) + px;
		y = 0.0f + radius * sin (phi) * sin (teta) + py;
		z = 0.0f + radius * cos (phi) + pz;
		Vector * vector = new Vector(x, y, z);
		vm->append (vector);
	}
	//    FaceManager *m_faceManager = new FaceManager();
	for(int i = 0; i < vm->size (); i++)
	{
		Face *face = new Face(pole, vm->at (i), vm->at ((i + 1) % vm->size ()));
		m_faceManager->append (face);
	}

	int i;
	VertexManager *vm2 = new VertexManager();
	for(phi += M_PI / h, i = 1; phi <=  M_PI; phi += M_PI / h, i++)
	{
		if(i % 2 == 1)
		{
			for(teta = 0; teta < 2 * M_PI; teta += M_PI / d)
			{
				x = 0.0f + radius * sin (phi) * cos (teta) + px;
				y = 0.0f + radius * sin (phi) * sin (teta) + py;
				z = 0.0f + radius * cos (phi) + pz;
				Vector * vector = new Vector(x, y, z);
				vm2->append (vector);
			}
			for(int k = 0; k < vm2->size (); k++)
			{
				Face * face1 = new Face(vm->at (k), vm2->at (k), vm2->at ((k + 1) % vm->size ()));
				Face * face2 = new Face(vm->at (k), vm2->at ((k + 1) % vm2->size ()), vm->at ((k + 1) % vm2->size ()));
				m_faceManager->append (face1);
				m_faceManager->append (face2);
			}
			vm->clear ();
		}
		else
		{
			for(teta = 0; teta < 2 * M_PI; teta += M_PI / d)
			{
				x = 0.0f + radius * sin (phi) * cos (teta) + px;
				y = 0.0f + radius * sin (phi) * sin (teta) + py;
				z = 0.0f + radius * cos (phi) + pz;
				Vector * vector = new Vector(x, y, z);
				vm->append (vector);
			}
			for(int k = 0; k < vm2->size (); k++)
			{
				Face * face1 = new Face(vm2->at (k), vm->at (k), vm->at ((k + 1) % vm2->size ()));
				Face * face2 = new Face(vm2->at (k), vm->at ((k + 1) % vm->size ()), vm2->at ((k + 1) % vm->size ()));
				m_faceManager->append (face1);
				m_faceManager->append (face2);
			}
			vm2->clear ();
		}
	}

	if(vm->size () == 0)
	{
		x = 0.0f + radius * sin (M_PI) * cos (2 * M_PI) + px;
		y = 0.0f + radius * sin (M_PI) * sin (2 * M_PI) + py;
		z = 0.0f + radius * cos (M_PI) + pz;
		Vector *pole = new Vector(x, y, z);

		for(int i = 0; i < vm2->size (); i++)
		{
			Face *face = new Face(vm2->at (i), pole, vm2->at ((i + 1) % vm2->size ()));
			m_faceManager->append (face);
		}
	}
	else if(vm2->size () == 0)
	{
		x = 0.0f + radius * sin (M_PI) * cos (2 * M_PI) + px;
		y = 0.0f + radius * sin (M_PI) * sin (2 * M_PI) + py;
		z = 0.0f + radius * cos (M_PI) + pz;
		Vector *pole = new Vector(x, y, z);

		for(int i = 0; i < vm->size (); i++)
		{
			Face *face = new Face(vm->at (i), pole, vm->at ((i + 1) % vm->size ()));
			m_faceManager->append (face);
		}
	}

}

void Sphere::drawEdgeMode ()
{

}

void Sphere::drawFaceMode ()
{

}

void Sphere::drawObjectMode ()
{
	m_faceManager->calculateNormals ();

	glBegin (GL_TRIANGLES);
	for(int j = 0; j < m_faceManager->size (); j++)
	{
		glNormal3f (m_faceManager->at(j)->getV1()->getNormal ()->x, m_faceManager->at(j)->getV1()->getNormal ()->y, m_faceManager->at(j)->getV1()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV1()->x, m_faceManager->at(j)->getV1()->y, m_faceManager->at(j)->getV1()->z);
		glNormal3f (m_faceManager->at(j)->getV2()->getNormal ()->x, m_faceManager->at(j)->getV2()->getNormal ()->y, m_faceManager->at(j)->getV2()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV2()->x, m_faceManager->at(j)->getV2()->y, m_faceManager->at(j)->getV2()->z);
		glNormal3f (m_faceManager->at(j)->getV3()->getNormal ()->x, m_faceManager->at(j)->getV3()->getNormal ()->y, m_faceManager->at(j)->getV3()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV3()->x, m_faceManager->at(j)->getV3()->y, m_faceManager->at(j)->getV3()->z);
	}
	glEnd ();
}

void Sphere::drawVertexMode ()
{
	m_faceManager->calculateNormals ();
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin (GL_TRIANGLES);
	int x = m_faceManager->size ();
	for(int j = 0; j < m_faceManager->size (); j++)
	{
		glNormal3f (m_faceManager->at(j)->getV1()->getNormal ()->x, m_faceManager->at(j)->getV1()->getNormal ()->y, m_faceManager->at(j)->getV1()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV1()->x, m_faceManager->at(j)->getV1()->y, m_faceManager->at(j)->getV1()->z);
		glNormal3f (m_faceManager->at(j)->getV2()->getNormal ()->x, m_faceManager->at(j)->getV2()->getNormal ()->y, m_faceManager->at(j)->getV2()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV2()->x, m_faceManager->at(j)->getV2()->y, m_faceManager->at(j)->getV2()->z);
		glNormal3f (m_faceManager->at(j)->getV3()->getNormal ()->x, m_faceManager->at(j)->getV3()->getNormal ()->y, m_faceManager->at(j)->getV3()->getNormal ()->z);
		glVertex3f(m_faceManager->at(j)->getV3()->x, m_faceManager->at(j)->getV3()->y, m_faceManager->at(j)->getV3()->z);
	}
	glEnd ();
}

void Sphere::drawEdgeModeSelect ()
{

}

void Sphere::drawFaceModeSelect ()
{

}

void Sphere::drawObjectModeSelect ()
{

}

void Sphere::drawVertexModeSelect (int index)
{

}

void Sphere::save (QDataStream *out)
{

}

bool Sphere::completeModel ()
{
	return true;
}
