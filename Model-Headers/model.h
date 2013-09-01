#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QTextStream>
#include <QtOpenGL>
#include "vector.h"
#include "enumerations.h"
#include "vertex-manager.h"
#include "edge-manager.h"
#include "material.h"

class Model : public QObject
{
public:
	Model();
	virtual void drawObjectMode() = 0;
	virtual void drawVertexMode() = 0;
	virtual void drawFaceMode() = 0;
	virtual void drawEdgeMode() = 0;
	virtual void drawObjectModeSelect() = 0;
	virtual void drawVertexModeSelect(int index) = 0;
	virtual void drawFaceModeSelect() = 0;
	virtual void drawEdgeModeSelect() = 0;
	virtual void save(QDataStream *out) = 0;
	virtual bool completeModel() = 0;
	virtual void setHeight(float) = 0;
	virtual void setWidth(float) = 0;
	virtual void setLength(float) = 0;
	void setDrawingMode(DrawingModes drawingMode);
	DrawingModes getDrawingMode();

	//move
	void moveMouseMoved(float x, float y, float z);
	void move(float x, float y, float z);
	//scale
	void scaleMouseMoved(float x, float y, float z);
	void scale(float x, float y, float z);
	//rotate
	void rotateMouseMoved(float x, float y, float z, float angle);
	void rotate(float x, float y, float z, float angle);

	void calculateCenter();
	void mouseReleased();
	void mousePressed(float x, float y, float z);

	// getters & setters
	void setSelectionIdentifier(int value);
	int getSelectionIdentifier();
	void setSelected(bool value);
	bool getSelected();
	void getCenter(float &x, float &y, float &z);
	VertexManager * getVertexManager();

protected:
	VertexManager *m_vertexManager;
	VertexManager *m_tempVertexManager;
	FaceManager *m_faceManager;
	Material *m_material;
	Vector * m_move;
	Vector * m_scale;
	Vector * m_rotate;
	Vector * m_center;
	Vector * m_preMousePosition;
	int m_selectionIdentifier;
	bool m_selected;
	DrawingModes m_drawingMode;
};

#endif // MODEL_H
