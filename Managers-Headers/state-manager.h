#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "main-gui.h"
#include "state-functions.h"
#include "glwidget.h"
#include "select-manager.h"

class StateManager
{
public:
	StateManager(Ui::MainWindow *);
	void addGLWidget(QList<GLWidget *> * glwidgets);

private:
	Ui::MainWindow * mainWindow;
	void connections();
	void addTransitions();
	void addState();

	//State declaration
	QStateMachine stateMachine;

	QState * cancelDrawing;

	// Rectangle Drawing States
	QState *rectangleDrawingEnabledState;
	QState *rectangleMousePressState;
	QState *rectangleMouseMoveState;
	QState *rectangleMouseReleaseState;
	//END of Rectangle Drawing States

	//Circle Drawing States
	QState *circleDrawingEnabledState;
	QState *circleMousePressState;
	QState *circleMouseMoveState;
	QState *circleMouseReleaseState;
	//END of Circle Drawing States

	//Ellipse Drawing States
	QState *ellipseDrawingEnabledState;
	QState *ellipseMousePressState;
	QState *ellipseMouseMoveState;
	QState *ellipseMouseReleaseState;
	//END of Ellipse Drawing States

	//Line Drawing States
	QState *lineInitializeState;
	QState *lineDrawingEnabledState;
	QState *lineMousePressState;
	QState *lineMouseMoveState;
	QState *lineMouseReleaseState;
	QState *lineEnterKeyPressedState;
	//END of Line Drawing States

	//Bezier Drawing States
	QState *bezierInitializeState;
	QState *bezierDrawingEnabledState;
	QState *bezierMousePressState;
	QState *bezierMouseMoveState;
	QState *bezierMouseReleaseState;
	QState *bezierEnterKeyPressedState;
	//END of Bezier Drawing States

	//Spline Drawing States
	QState *splineInitializeState;
	QState *splineDrawingEnabledState;
	QState *splineMousePressState;
	QState *splineMouseMoveState;
	QState *splineMouseReleaseState;
	QState *splineEnterKeyPressedState;
	//END of Spline Drawing States

	//Polygon Drawing States
	QState *polygonInitializeState;
	QState *polygonDrawingEnabledState;
	QState *polygonMousePressState;
	QState *polygonMouseMoveState;
	QState *polygonMouseReleaseState;
	QState *polygonEnterKeyPressedState;
	//END of Polygon Drawing States

	//Sphere Drawing States
	QState * sphereEnableState;
	QState * sphereMousePressed;
	QState * sphereMouseReleased;
	QState * sphereMouseMoved;
	//End of Sphere Drawing States

	//Cube Drawing States
	QState * cubeEnableState;
	QState * cubeRectangleDrawn;
	QState * cubeDrawingRectangleMousePressed;
	QState * cubeGivingHeightMousePressed;
	QState * cubeDrawingRectangleMouseMoved;
	QState * cubeGivingHeightMouseMoved;
	QState * cubeDrawingRectangleMouseReleased;
	QState * cubeGivingHeightMouseReleased;
	//End of Cube Drawing States

	//Cylinder Drawing States
	QState * cylinderEnableState;
	QState * cylinderCircleDrawn;
	QState * cylinderDrawingCircleMousePressed;
	QState * cylinderGivingHeightMousePressed;
	QState * cylinderDrawingCircleMouseMoved;
	QState * cylinderGivingHeightMouseMoved;
	QState * cylinderDrawingCircleMouseReleased;
	QState * cylinderGivingHeightMouseReleased;
	//End of Cylinder Drawing States

	//Cone Drawing States
	QState * coneEnableState;
	QState * coneCircleDrawn;
	QState * coneDrawingCircleMousePressed;
	QState * coneGivingHeightMousePressed;
	QState * coneDrawingCircleMouseMoved;
	QState * coneGivingHeightMouseMoved;
	QState * coneDrawingCircleMouseReleased;
	QState * coneGivingHeightMouseReleased;
	//End of Cone Drawing States

	//Select States
	QState *selectEnabledState;
	QState *selectMousePressedState;
	QState *selectMouseMoveState;
	QState *selectPointState;
	QState *selectRectangularState;
	//END of Select States

	//Scale States
	QState *moveEnabledState;
	QState *moveWhatIsUnderCursorState;
	QState *moveSelectMousePressedState;
	QState *moveSelectMouseMoveState;
	QState *moveSelectPointState;
	QState *moveSelectRectangularState;
	QState *moveXhandleUnderCursorState;
	QState *moveYhandleUnderCursorState;
	QState *moveZhandleUnderCursorState;
	QState *moveXhandleMovingState;
	QState *moveYhandleMovingState;
	QState *moveZhandleMovingState;
	QState *moveXhandleReleasedState;
	QState *moveYhandleReleasedState;
	QState *moveZhandleReleasedState;
	//END of Scale States

	//Rotate States
	QState *rotateEnabledState;
	QState *rotateNothingSelectedState;
	QState *rotateDiselectAllState;
	QState *rotateSelectWhileRotate;
	QState *rotateSelectRectangularState;
	QState *rotateSelectModelState;
	QState *rotateState;
	QState *rotateMovingState;
	QState *rotateMouseReleaseState;
	QState *rotateMousePressedState;
	//END of Rotate States

	//Scale States
	QState *scaleEnabledState;
	QState *scaleNothingSelectedState;
	QState *scaleDiselectAllState;
	QState *scaleSelectWhileScale;
	QState *scaleSelectRectangularState;
	QState *scaleSelectModelState;
	QState *scaleState;
	QState *scaleMovingState;
	QState *scaleMouseReleaseState;
	QState *scaleMousePressedState;
	//END of Scale States

	//END of State declaration

	QList<GLWidget *> *glwidgets;
};

#endif // STATEMANAGER_H
