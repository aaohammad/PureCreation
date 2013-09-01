#ifndef POLYGON_H
#define POLYGON_H

#include "model.h"

class Polygon : public Model
{
public:
	Polygon(VertexManager *m_vertexManager);
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

#endif // POLYGON_H
