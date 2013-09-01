#ifndef SPLINE_H
#define SPLINE_H

#include "model.h"

class Spline : public Model
{
public:
	Spline(VertexManager *m_vertexManager);
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

private:
	float coef[100];
};

#endif // SPLINE_H
