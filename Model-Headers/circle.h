#ifndef CIRCLE_H
#define CIRCLE_H

#include "model.h"

class Circle : public Model
{
public:
	Circle(float x, float y, float z, float radius);
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

#endif // CIRCLE_H
