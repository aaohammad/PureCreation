#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "model.h"

class Ellipse : public Model
{
public:
	Ellipse(float x, float y, float z, float width, float height);
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

#endif // ELLIPSE_H
