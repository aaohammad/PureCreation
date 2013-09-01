#ifndef CONE_H
#define CONE_H

#include "model.h"

class Cone : public Model
{
public:
	Cone(float x, float y, float z, float radius, float height);
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
	void setHeight (float);
	void setWidth(float);
	void setLength(float);

private:
	float height;
	float width;
	float length;
};

#endif // CONE_H
