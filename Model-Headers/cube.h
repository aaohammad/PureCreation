#ifndef CUBE_H
#define CUBE_H

#include "model.h"

class Cube : public Model
{
public:
	Cube(float x, float y, float z, float length, float width, float height);
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

#endif // CUBE_H
