#include <vector.h>

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->isSelected = false;
	this->selectionIdentifier = -1;
	this->normalList = new QList<Vector *>();
}

void Vector::setSelectionIdentifier(int iD)
{
	this->selectionIdentifier = iD;
}

int Vector::getID()
{
	return this->selectionIdentifier;
}

void Vector::setSelected(bool isSelected)
{
	this->isSelected = isSelected;
}

bool Vector::getSelection()
{
	return this->isSelected;
}

void Vector::move(float x, float y)
{
	this->x = xTemp;
	this->y = yTemp;
	this->x += x - firstX;
	this->y += y - firstY;
}

void Vector::mousePressed(float x, float y)
{
	xTemp = this->x;
	yTemp = this->y;
	firstX = x;
	firstY = y;
}

void Vector::replace (Vector *vector)
{
	this->x = vector->x;
	this->y = vector->y;
	this->z = vector->z;
}

void Vector::calculateNormal ()
{
	this->normal[0] = 0.0f;
	this->normal[1] = 0.0f;
	this->normal[2] = 0.0f;
	for(int i = 0; i < normalList->size (); i++)
	{
		this->normal[0] += normalList->at (i)->x;
		this->normal[1] += normalList->at (i)->y;
		this->normal[2] += normalList->at (i)->z;
	}
	this->normal[0] /= normalList->size ();
	this->normal[1] /= normalList->size ();
	this->normal[2] /= normalList->size ();
}

void Vector::appendNormal (Vector *normal)
{
	this->normalList->append (normal);
}

Vector * Vector::getNormal ()
{
	calculateNormal ();
	Vector *vector = new Vector(this->normal[0], this->normal[1], this->normal[2]);
	return vector;
}
