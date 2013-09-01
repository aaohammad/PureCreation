#ifndef SPHERE_H
#define SPHERE_H

#include "model.h"

class Sphere : public Model
{
public:
	Sphere(float x, float y, float z, float radius);
	void drawObjectMode();
	void drawVertexMode();
	void drawFaceMode();
	void drawEdgeMode();
	void drawEdgeModeSelect();
	void drawFaceModeSelect();
	void drawObjectModeSelect();
	void drawVertexModeSelect(int index);
	void save(QDataStream *out);
	bool completeModel ();
	void setHeight (float){};
	void setWidth (float){};
	void setLength (float){};
};

#endif // SPHERE_H
