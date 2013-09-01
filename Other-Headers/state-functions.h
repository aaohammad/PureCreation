#ifndef STATEFUNCTIONS_H
#define STATEFUNCTIONS_H

#include <QObject>
#include "model-manager.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "bezier.h"
#include "spline.h"
#include "sphere.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"

class StateFunctions : public QObject
{
	Q_OBJECT
public:
	static StateFunctions * getInstance();
	void setCurrentMousePosition(float x, float y, float z);
	void setCurrentMousePositionOfPerspective(float x, float y, float z);

private:
	StateFunctions(){}
	static StateFunctions * m_stateFunctions;
	float curX, curY, curZ; //  current mouse position
	float preX, preY, preZ; //  previouse mouse position
	float curPX, curPY, curPZ; //  current mouse position of perspective
	float prePX, prePY, prePZ; //  previouse mouse position of perspective
	ThreeDDrawing threeDDrawingState;

public slots:
	void circleMousePressed();
	void circleMouseMoved();
	void circleMouseReleased();

	void ellipseMousePressed();
	void ellipseMouseMoved();
	void ellipseMouseReleased();

	void rectangleMousePressed();
	void rectangleMouseMoved();
	void rectangleMouseReleased();

	void bezierInitialize();
	void bezierMouseMoved();
	void bezierMousePressed();
	void bezierEnterKeyPressed();

	void splineInitialize();
	void splineMouseMoved();
	void splineMousePressed();
	void splineEnterKeyPressed();

	void lineInitialize();
	void lineMouseMoved();
	void lineMousePressed();
	void lineEnterKeyPressed();

	void polygonInitialize();
	void polygonMouseMoved();
	void polygonMousePressed();
	void polygonEnterKeyPressed();

	void sphereMousePressed();
	void sphereMouseMoved();
	void sphereMouseReleased();

	void cubeDrawingRectangleMousePressed ();
	void cubeDrawingRectangleMouseMoved ();
	void cubeGivingHeightMousePressed ();
	void cubeGivingHeightMouseMoved ();
	void cubeGivingHeightMouseReleased ();

	void cylinderDrawingCircleMousePressed ();
	void cylinderDrawingCircleMouseMoved ();
	void cylinderGivingHeightMousePressed ();
	void cylinderGivingHeightMouseMoved ();
	void cylinderGivingHeightMouseReleased ();

	void coneDrawingCircleMousePressed ();
	void coneDrawingCircleMouseMoved ();
	void coneGivingHeightMousePressed ();
	void coneGivingHeightMouseMoved ();
	void coneGivingHeightMouseReleased ();

	void rotateEnabled();
	void cancelDrawing();
	void rotate();
	void rotateMousePressed();
	void rotateMouseReleased();

	void scaleEnabled();
	void scale();
	void scaleMousePressed();
	void scaleMouseReleased();

	void moveMouseReleased();
	void moveIsSomethingUnderCursor();
	void moveIsModelSelected();
	void moveModel();

	void resetEverything();
	void diselectAll();
	void toggleGridDrawing();

	void changeModeToObjectMode();
	void changeModeToVertexMode();

signals:
	void endState();
};

#endif // STATEFUNCTIONS_H
