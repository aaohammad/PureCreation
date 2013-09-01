#ifndef BEZIER_H
#define BEZIER_H

#include "model.h"

class Bezier : public Model
{
public:
	Bezier(VertexManager *m_vertexManager);
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

#endif // BEZIER_H
