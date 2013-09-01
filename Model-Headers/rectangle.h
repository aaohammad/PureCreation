#ifndef SQUARE_H
#define SQUARE_H

#include "model.h"

class Rectangle : public Model
{
public:
	Rectangle(float x1, float y1, float z1, float x2, float y2, float z2);
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

#endif // SQUARE_H
