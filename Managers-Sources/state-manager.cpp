#include "state-manager.h"

StateManager::StateManager(Ui::MainWindow *mainWindow)
{
	//Initializations of states

	// Rectangle Drawing States Initialization
	{
		rectangleDrawingEnabledState = new QState();
		rectangleMousePressState = new QState();
		rectangleMouseMoveState = new QState();
		rectangleMouseReleaseState = new QState();
	}
	// End of Rectangle Drawing States Initialization

	// Circle Drawing Initialization
	{
		circleDrawingEnabledState = new QState();
		circleMousePressState = new QState();
		circleMouseMoveState = new QState();
		circleMouseReleaseState = new QState();
	}
	// Circle Drawing States Initialization

	// Ellipse Drawing States Initialization
	{
		ellipseDrawingEnabledState = new QState();
		ellipseMousePressState = new QState();
		ellipseMouseMoveState = new QState();
		ellipseMouseReleaseState = new QState();
	}
	// Ellipse Drawing States Initialization

	// Line Drawing States Initialization
	{
		lineInitializeState = new QState();
		lineDrawingEnabledState = new QState();
		lineMouseReleaseState = new QState();
		lineMouseMoveState = new QState();
		lineMousePressState = new QState();
		lineEnterKeyPressedState = new QState();
	}
	// End of Line Drawing States Initialization

	// Bezier Drawing States Initialization
	{
		bezierInitializeState = new QState();
		bezierDrawingEnabledState = new QState();
		bezierMouseReleaseState = new QState();
		bezierMouseMoveState = new QState();
		bezierMousePressState = new QState();
		bezierEnterKeyPressedState = new QState();
	}
	// End of Bezier Drawing States Initialization

	// Spline Drawing States Initialization
	{
		splineInitializeState = new QState();
		splineDrawingEnabledState = new QState();
		splineMouseReleaseState = new QState();
		splineMouseMoveState = new QState();
		splineMousePressState = new QState();
		splineEnterKeyPressedState = new QState();
	}
	// End of Spline Drawing States Initialization

	// Polygon Drawing States Initialization
	{
		polygonInitializeState = new QState();
		polygonDrawingEnabledState = new QState();
		polygonMouseReleaseState = new QState();
		polygonMouseMoveState = new QState();
		polygonMousePressState = new QState();
		polygonEnterKeyPressedState = new QState();
	}
	// End of Polygon Drawing States Initialization

	// Sphere Drawing State Initialization
	{
		sphereEnableState = new QState();
		sphereMousePressed = new QState();
		sphereMouseReleased = new QState();
		sphereMouseMoved = new QState();
	}
	// End of Sphere Drawing State Initialization

	// Cube Drawing State Initialization
	{
		cubeEnableState = new QState();
		cubeRectangleDrawn = new QState();
		cubeDrawingRectangleMousePressed = new QState();
		cubeGivingHeightMousePressed = new QState();
		cubeDrawingRectangleMouseMoved = new QState();
		cubeGivingHeightMouseMoved = new QState();
		cubeDrawingRectangleMouseReleased = new QState();
		cubeGivingHeightMouseReleased = new QState();
	}
	// End of Cube Drawing State Initialization

	// Cylinder Drawing State Initialization
	{
		cylinderEnableState = new QState();
		cylinderCircleDrawn = new QState();
		cylinderDrawingCircleMousePressed = new QState();
		cylinderGivingHeightMousePressed = new QState();
		cylinderDrawingCircleMouseMoved = new QState();
		cylinderGivingHeightMouseMoved = new QState();
		cylinderDrawingCircleMouseReleased = new QState();
		cylinderGivingHeightMouseReleased = new QState();
	}
	// End of Cylinder Drawing State Initialization

	// Cone Drawing State Initialization
	{
		coneEnableState = new QState();
		coneCircleDrawn = new QState();
		coneDrawingCircleMousePressed = new QState();
		coneGivingHeightMousePressed = new QState();
		coneDrawingCircleMouseMoved = new QState();
		coneGivingHeightMouseMoved = new QState();
		coneDrawingCircleMouseReleased = new QState();
		coneGivingHeightMouseReleased = new QState();
	}
	// End of Cone Drawing State Initialization

	// Select State Initialization
	{
		selectEnabledState = new QState();
		selectMouseMoveState = new QState();
		selectMousePressedState = new QState();
		selectPointState = new QState();
		selectRectangularState = new QState();
	}
	// End of Select State Initialization

	// Move State Initialization
	{
		moveEnabledState = new QState();
		moveSelectMousePressedState = new QState();
		moveSelectMouseMoveState = new QState();
		moveSelectPointState = new QState();
		moveSelectRectangularState = new QState();
		moveWhatIsUnderCursorState = new QState();
		moveXhandleUnderCursorState = new QState();
		moveYhandleUnderCursorState = new QState();
		moveZhandleUnderCursorState = new QState();
		moveXhandleMovingState = new QState();
		moveYhandleMovingState = new QState();
		moveZhandleMovingState = new QState();
		moveXhandleReleasedState = new QState();
		moveYhandleReleasedState = new QState();
		moveZhandleReleasedState = new QState();
	}
	// End of Move State Inititalization

	rotateEnabledState = new QState();
	rotateNothingSelectedState = new QState();
	rotateDiselectAllState = new QState();
	rotateSelectWhileRotate = new QState();
	rotateSelectRectangularState = new QState();
	rotateSelectModelState = new QState();
	rotateState = new QState();
	rotateMovingState = new QState();
	rotateMouseReleaseState = new QState();
	rotateMousePressedState = new QState();

	scaleEnabledState = new QState();
	scaleNothingSelectedState = new QState();
	scaleDiselectAllState = new QState();
	scaleSelectWhileScale = new QState();
	scaleSelectRectangularState = new QState();
	scaleSelectModelState = new QState();
	scaleState = new QState();
	scaleMovingState = new QState();
	scaleMouseReleaseState = new QState();
	scaleMousePressedState = new QState();

	cancelDrawing = new QState();
	this->mainWindow = mainWindow;
	glwidgets = new QList<GLWidget *>();
}

void StateManager::addGLWidget (QList<GLWidget *> * glwidgets)
{
	this->glwidgets->clear ();
	for(int i = 0; i < glwidgets->size (); i++)
	{
		this->glwidgets->append (glwidgets->at (i));
	}

	//Defining state transitions
	addTransitions();
	//Adding states to state machine
	addState();

	//Set initial state to move enabled state
	stateMachine.setInitialState(selectEnabledState);
	//Start state machine
	stateMachine.start();

	//Connect states to appropriate functions
	connections();
}

void StateManager::connections()
{
	// Rectangle States connection with functions
	{
		QObject::connect (rectangleDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (rectangleDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect (rectangleMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rectangleMousePressed()));
		QObject::connect (rectangleMouseReleaseState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rectangleMouseReleased()));
		QObject::connect (rectangleMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rectangleMouseMoved()));
	}

	// Circle States connection with functions
	{
		QObject::connect (circleDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (circleDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect (circleMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(circleMousePressed()));
		QObject::connect (circleMouseReleaseState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(circleMouseReleased()));
		QObject::connect (circleMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(circleMouseMoved()));
	}

	// Ellipse States connection with functions
	{
		QObject::connect(ellipseDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect(ellipseDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect(ellipseMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(ellipseMousePressed()));
		QObject::connect(ellipseMouseReleaseState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(ellipseMouseReleased()));
		QObject::connect (ellipseMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(ellipseMouseMoved()));
	}

	// Line States connection with functions
	{
		QObject::connect (lineDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (lineDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect (lineMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(lineMousePressed()));
		QObject::connect (lineEnterKeyPressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(lineEnterKeyPressed()));
		QObject::connect (lineInitializeState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(lineInitialize()));
		QObject::connect (lineMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(lineMouseMoved()));
	}

	// Bezier States connection with functions
	{
		QObject::connect (bezierDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (bezierDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect (bezierMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(bezierMousePressed()));
		QObject::connect (bezierEnterKeyPressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(bezierEnterKeyPressed()));
		QObject::connect (bezierInitializeState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(bezierInitialize()));
		QObject::connect (bezierMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(bezierMouseMoved()));
	}

	// Spline States connection with functions
	{
		QObject::connect (splineDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (splineDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
		QObject::connect (splineMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(splineMousePressed()));
		QObject::connect (splineEnterKeyPressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(splineEnterKeyPressed()));
		QObject::connect (splineInitializeState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(splineInitialize()));
		QObject::connect (splineMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(splineMouseMoved()));
	}

	// Polygon States connection with functions
	{
		QObject::connect (polygonDrawingEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (polygonMousePressState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(polygonMousePressed()));
		QObject::connect (polygonEnterKeyPressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(polygonEnterKeyPressed()));
		QObject::connect (polygonInitializeState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(polygonInitialize()));
		QObject::connect (polygonMouseMoveState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(polygonMouseMoved()));
	}

	// Sphere States connection with functions
	{
		QObject::connect (sphereEnableState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (sphereMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(sphereMousePressed()));
		QObject::connect (sphereMouseReleased, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(sphereMouseReleased()));
		QObject::connect (sphereMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(sphereMouseMoved()));
	}

	// Cube States connection with functions
	{
		QObject::connect (cubeEnableState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (cubeDrawingRectangleMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cubeDrawingRectangleMousePressed()));
		QObject::connect (cubeDrawingRectangleMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cubeDrawingRectangleMouseMoved()));
		QObject::connect (cubeGivingHeightMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cubeGivingHeightMousePressed()));
		QObject::connect (cubeGivingHeightMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cubeGivingHeightMouseMoved()));
		QObject::connect (cubeGivingHeightMouseReleased, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cubeGivingHeightMouseReleased()));
	}

	// Cylinder States connection with functions
	{
		QObject::connect (cylinderEnableState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (cylinderDrawingCircleMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cylinderDrawingCircleMousePressed()));
		QObject::connect (cylinderDrawingCircleMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cylinderDrawingCircleMouseMoved()));
		QObject::connect (cylinderGivingHeightMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cylinderGivingHeightMousePressed()));
		QObject::connect (cylinderGivingHeightMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cylinderGivingHeightMouseMoved()));
		QObject::connect (cylinderGivingHeightMouseReleased, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(cylinderGivingHeightMouseReleased()));
	}

	// Cone States connection with functions
	{
		QObject::connect (coneEnableState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (coneDrawingCircleMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(coneDrawingCircleMousePressed()));
		QObject::connect (coneDrawingCircleMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(coneDrawingCircleMouseMoved()));
		QObject::connect (coneGivingHeightMousePressed, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(coneGivingHeightMousePressed()));
		QObject::connect (coneGivingHeightMouseMoved, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(coneGivingHeightMouseMoved()));
		QObject::connect (coneGivingHeightMouseReleased, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(coneGivingHeightMouseReleased()));
	}

	//Selection States connection with functions
	{
		QObject::connect (selectEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (selectMousePressedState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectMousePressed()));
		QObject::connect (selectPointState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectPoint()));
		QObject::connect (selectRectangularState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectRectangular()));
	}

	//Moving States connection with functions
	{
		QObject::connect (moveEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
		QObject::connect (moveWhatIsUnderCursorState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(whatISUnderCursor()));
		QObject::connect (moveSelectMousePressedState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectMousePressed()));
		QObject::connect (moveSelectPointState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectPoint()));
		QObject::connect (moveSelectRectangularState, SIGNAL(entered()), SelectManager::getInstance (), SLOT(selectRectangular()));
	}

	//Rotation States connection with functions
//	QObject::connect(rotateEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
//	QObject::connect(rotateEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rotateEnabled()));
//	QObject::connect(rotateMousePressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rotateMousePressed()));
//	QObject::connect(rotateNothingSelectedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectMousePressed()));
//	QObject::connect(rotateDiselectAllState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
//	QObject::connect(rotateSelectRectangularState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectRectangular()));
//	QObject::connect(rotateSelectModelState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectOnePixel()));
//	QObject::connect(rotateMovingState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rotate()));
//	QObject::connect(rotateMouseReleaseState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(rotateMouseReleased()));

	//Scaling States connection with functions
//	QObject::connect(scaleEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(resetEverything()));
//	QObject::connect(scaleEnabledState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(scaleEnabled()));
//	QObject::connect(scaleMousePressedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(scaleMousePressed()));
//	QObject::connect(scaleNothingSelectedState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectMousePressed()));
//	QObject::connect(scaleDiselectAllState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(diselectAll()));
//	QObject::connect(scaleSelectRectangularState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectRectangular()));
//	QObject::connect(scaleSelectModelState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(selectOnePixel()));
//	QObject::connect(scaleMovingState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(scale()));
//	QObject::connect(scaleMouseReleaseState, SIGNAL(entered()), StateFunctions::getInstance (), SLOT(scaleMouseReleased()));
}

void StateManager::addTransitions()
{
	// Global adding Transitions
	{
		selectEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->square_toolButton, SIGNAL(clicked()), rectangleDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		lineDrawingEnabledState->addTransition (mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		lineDrawingEnabledState->addTransition (mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		coneEnableState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		cubeEnableState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		cylinderEnableState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		lineDrawingEnabledState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		moveEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		rotateEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		scaleEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		sphereEnableState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		splineDrawingEnabledState->addTransition (mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);

		selectEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		bezierDrawingEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		circleDrawingEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		coneEnableState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		cubeEnableState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		cylinderEnableState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		ellipseDrawingEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		lineDrawingEnabledState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		moveEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		polygonDrawingEnabledState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		rotateEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		scaleEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		splineDrawingEnabledState->addTransition (mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);
		rectangleDrawingEnabledState->addTransition(mainWindow->sphere_toolButton, SIGNAL(clicked()), sphereEnableState);

		selectEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		bezierDrawingEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		circleDrawingEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		coneEnableState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		cylinderEnableState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		ellipseDrawingEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		lineDrawingEnabledState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		moveEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		polygonDrawingEnabledState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		rotateEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		scaleEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		sphereEnableState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		splineDrawingEnabledState->addTransition (mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);
		rectangleDrawingEnabledState->addTransition(mainWindow->cube_toolButton, SIGNAL(clicked()), cubeEnableState);

		selectEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		bezierDrawingEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		circleDrawingEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		coneEnableState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		cubeEnableState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		ellipseDrawingEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		lineDrawingEnabledState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		moveEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		polygonDrawingEnabledState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		rotateEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		scaleEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		sphereEnableState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		splineDrawingEnabledState->addTransition (mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);
		rectangleDrawingEnabledState->addTransition(mainWindow->cylinder_toolButton, SIGNAL(clicked()), cylinderEnableState);

		selectEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		bezierDrawingEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		circleDrawingEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		cubeEnableState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		cylinderEnableState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		ellipseDrawingEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		lineDrawingEnabledState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		moveEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		polygonDrawingEnabledState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		rotateEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		scaleEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		sphereEnableState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		splineDrawingEnabledState->addTransition (mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);
		rectangleDrawingEnabledState->addTransition(mainWindow->cone_toolButton, SIGNAL(clicked()), coneEnableState);

		bezierDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		coneEnableState->addTransition (mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		cubeEnableState->addTransition (mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		cylinderEnableState->addTransition (mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		moveEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		rotateEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		scaleEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		sphereEnableState->addTransition (mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->selection_toolButton, SIGNAL(clicked()), selectEnabledState);

		selectEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		coneEnableState->addTransition (mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		cubeEnableState->addTransition (mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		cylinderEnableState->addTransition (mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		rotateEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		scaleEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		sphereEnableState->addTransition (mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);

		selectEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		moveEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		scaleEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		sphereEnableState->addTransition (mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);

		selectEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		bezierDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		circleDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		ellipseDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		lineDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		moveEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		polygonDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		rotateEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		sphereEnableState->addTransition (mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		splineDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
		rectangleDrawingEnabledState->addTransition(mainWindow->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
	}

	// State Transitions of Rectangle
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			rectangleDrawingEnabledState->addTransition(glw, SIGNAL(leftMouseButtonPressed()), rectangleMousePressState);
			rectangleMousePressState->addTransition(glw, SIGNAL(mouseMove()), rectangleMouseMoveState);
			rectangleMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), rectangleDrawingEnabledState);
			rectangleMouseMoveState->addTransition(glw, SIGNAL(mouseMove()), rectangleMouseMoveState);
			rectangleMouseMoveState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), rectangleMouseReleaseState);
			rectangleMouseReleaseState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of circle
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			circleDrawingEnabledState->addTransition(glw, SIGNAL(leftMouseButtonPressed()), circleMousePressState);
			circleMousePressState->addTransition(glw, SIGNAL(mouseMove()), circleMouseMoveState);
			circleMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), circleDrawingEnabledState);
			circleMouseMoveState->addTransition(glw, SIGNAL(mouseMove()), circleMouseMoveState);
			circleMouseMoveState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), circleMouseReleaseState);
			circleMouseReleaseState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Ellipse
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			ellipseDrawingEnabledState->addTransition(glw, SIGNAL(leftMouseButtonPressed()), ellipseMousePressState);
			ellipseMousePressState->addTransition(glw, SIGNAL(mouseMove()), ellipseMouseMoveState);
			ellipseMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), ellipseDrawingEnabledState);
			ellipseMouseMoveState->addTransition(glw, SIGNAL(mouseMove()), ellipseMouseMoveState);
			ellipseMouseMoveState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), ellipseMouseReleaseState);
			ellipseMouseReleaseState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Line
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			lineDrawingEnabledState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), lineInitializeState);
			lineInitializeState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), lineMouseReleaseState);
			lineInitializeState->addTransition (glw, SIGNAL(mouseMove()), lineMouseMoveState);
			lineMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), lineMouseMoveState);
			lineMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), lineMouseReleaseState);
			lineMouseReleaseState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), lineMousePressState);
			lineMousePressState->addTransition(glw, SIGNAL(mouseMove()), lineMouseMoveState);
			lineMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), lineMouseReleaseState);
			lineMouseReleaseState->addTransition (glw, SIGNAL(enterKeyPressed()), lineEnterKeyPressedState);
			lineEnterKeyPressedState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Bezier
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			bezierDrawingEnabledState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), bezierInitializeState);
			bezierInitializeState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), bezierMouseReleaseState);
			bezierInitializeState->addTransition (glw, SIGNAL(mouseMove()), bezierMouseMoveState);
			bezierMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), bezierMouseMoveState);
			bezierMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), bezierMouseReleaseState);
			bezierMouseReleaseState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), bezierMousePressState);
			bezierMousePressState->addTransition(glw, SIGNAL(mouseMove()), bezierMouseMoveState);
			bezierMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), bezierMouseReleaseState);
			bezierMouseReleaseState->addTransition (glw, SIGNAL(enterKeyPressed()), bezierEnterKeyPressedState);
			bezierEnterKeyPressedState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Spline
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			splineDrawingEnabledState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), splineInitializeState);
			splineInitializeState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), splineMouseReleaseState);
			splineInitializeState->addTransition (glw, SIGNAL(mouseMove()), splineMouseMoveState);
			splineMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), splineMouseMoveState);
			splineMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), splineMouseReleaseState);
			splineMouseReleaseState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), splineMousePressState);
			splineMousePressState->addTransition(glw, SIGNAL(mouseMove()), splineMouseMoveState);
			splineMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), splineMouseReleaseState);
			splineMouseReleaseState->addTransition (glw, SIGNAL(enterKeyPressed()), splineEnterKeyPressedState);
			splineEnterKeyPressedState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Polygon
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			polygonDrawingEnabledState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), polygonInitializeState);
			polygonInitializeState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), polygonMouseReleaseState);
			polygonInitializeState->addTransition (glw, SIGNAL(mouseMove()), polygonMouseMoveState);
			polygonMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), polygonMouseMoveState);
			polygonMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), polygonMouseReleaseState);
			polygonMouseReleaseState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), polygonMousePressState);
			polygonMousePressState->addTransition(glw, SIGNAL(mouseMove()), polygonMouseMoveState);
			polygonMousePressState->addTransition(glw, SIGNAL(leftMouseButtonReleased()), polygonMouseReleaseState);
			polygonMouseReleaseState->addTransition (glw, SIGNAL(enterKeyPressed()), polygonEnterKeyPressedState);
			polygonEnterKeyPressedState->addTransition(StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Sphere
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			sphereEnableState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), sphereMousePressed);
			sphereMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), sphereMouseReleased);
			sphereMousePressed->addTransition (glw, SIGNAL(mouseMove()), sphereMouseMoved);
			sphereMouseMoved->addTransition (glw, SIGNAL(mouseMove()), sphereMouseMoved);
			sphereMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), sphereMouseReleased);
			sphereMouseReleased->addTransition (StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Cube
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			cubeEnableState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), cubeDrawingRectangleMousePressed);
			cubeDrawingRectangleMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cancelDrawing);
			cubeDrawingRectangleMousePressed->addTransition (glw, SIGNAL(mouseMove()), cubeDrawingRectangleMouseMoved);
			cubeDrawingRectangleMouseMoved->addTransition (glw, SIGNAL(mouseMove()), cubeDrawingRectangleMouseMoved);
			cubeDrawingRectangleMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cubeRectangleDrawn);
			cubeRectangleDrawn->addTransition (glw, SIGNAL(leftMouseButtonPressed()), cubeGivingHeightMousePressed);
			cubeGivingHeightMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cubeGivingHeightMouseReleased);
			cubeGivingHeightMousePressed->addTransition (glw, SIGNAL(mouseMove()), cubeGivingHeightMouseMoved);
			cubeGivingHeightMouseMoved->addTransition (glw, SIGNAL(mouseMove()), cubeGivingHeightMouseMoved);
			cubeGivingHeightMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cubeGivingHeightMouseReleased);
			cubeGivingHeightMouseReleased->addTransition (StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Cylinder
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			cylinderEnableState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), cylinderDrawingCircleMousePressed);
			cylinderDrawingCircleMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cancelDrawing);
			cylinderDrawingCircleMousePressed->addTransition (glw, SIGNAL(mouseMove()), cylinderDrawingCircleMouseMoved);
			cylinderDrawingCircleMouseMoved->addTransition (glw, SIGNAL(mouseMove()), cylinderDrawingCircleMouseMoved);
			cylinderDrawingCircleMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cylinderCircleDrawn);
			cylinderCircleDrawn->addTransition (glw, SIGNAL(leftMouseButtonPressed()), cylinderGivingHeightMousePressed);
			cylinderGivingHeightMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cylinderGivingHeightMouseReleased);
			cylinderGivingHeightMousePressed->addTransition (glw, SIGNAL(mouseMove()), cylinderGivingHeightMouseMoved);
			cylinderGivingHeightMouseMoved->addTransition (glw, SIGNAL(mouseMove()), cylinderGivingHeightMouseMoved);
			cylinderGivingHeightMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cylinderGivingHeightMouseReleased);
			cylinderGivingHeightMouseReleased->addTransition (StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Cone
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			coneEnableState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), coneDrawingCircleMousePressed);
			coneDrawingCircleMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), cancelDrawing);
			coneDrawingCircleMousePressed->addTransition (glw, SIGNAL(mouseMove()), coneDrawingCircleMouseMoved);
			coneDrawingCircleMouseMoved->addTransition (glw, SIGNAL(mouseMove()), coneDrawingCircleMouseMoved);
			coneDrawingCircleMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), coneCircleDrawn);
			coneCircleDrawn->addTransition (glw, SIGNAL(leftMouseButtonPressed()), coneGivingHeightMousePressed);
			coneGivingHeightMousePressed->addTransition (glw, SIGNAL(leftMouseButtonReleased()), coneGivingHeightMouseReleased);
			coneGivingHeightMousePressed->addTransition (glw, SIGNAL(mouseMove()), coneGivingHeightMouseMoved);
			coneGivingHeightMouseMoved->addTransition (glw, SIGNAL(mouseMove()), coneGivingHeightMouseMoved);
			coneGivingHeightMouseMoved->addTransition (glw, SIGNAL(leftMouseButtonReleased()), coneGivingHeightMouseReleased);
			coneGivingHeightMouseReleased->addTransition (StateFunctions::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	// State Transitions of Selection
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			selectEnabledState->addTransition (glw, SIGNAL(leftMouseButtonPressed()), selectMousePressedState);
			selectMousePressedState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), selectPointState);
			selectMousePressedState->addTransition (glw, SIGNAL(mouseMove()), selectMouseMoveState);
			selectMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), selectMouseMoveState);
			selectMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), selectRectangularState);
			selectRectangularState->addTransition (SelectManager::getInstance (), SIGNAL(endState()), selectEnabledState);
			selectPointState->addTransition (SelectManager::getInstance (), SIGNAL(endState()), selectEnabledState);
		}
	}

	//State transitions of Moving
	{
		for(int i = 0; i < glwidgets->size (); i++)
		{
			GLWidget * glw = glwidgets->at (i);
			moveEnabledState->addTransition(glw, SIGNAL(leftMouseButtonPressed()), moveWhatIsUnderCursorState);
			moveWhatIsUnderCursorState->addTransition (SelectManager::getInstance (), SIGNAL(ModelOrNothingUnderCursor()), moveSelectMousePressedState);
			moveSelectMousePressedState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), moveSelectPointState);
			moveSelectMousePressedState->addTransition (glw, SIGNAL(mouseMove()), moveSelectMouseMoveState);
			moveSelectMouseMoveState->addTransition (glw, SIGNAL(mouseMove()), moveSelectMouseMoveState);
			moveSelectMouseMoveState->addTransition (glw, SIGNAL(leftMouseButtonReleased()), moveSelectRectangularState);
			moveSelectRectangularState->addTransition (SelectManager::getInstance (), SIGNAL(endState()), moveEnabledState);
			moveSelectPointState->addTransition (SelectManager::getInstance (), SIGNAL(endState()), moveEnabledState);
//			moveWhatIsUnderCursorState->addTransition (SelectManager::getInstance (), SIGNAL(MovingHandleXUnderCursor()), moveXhandleUnderCursorState);
//			moveWhatIsUnderCursorState->addTransition (SelectManager::getInstance (), SIGNAL(MovingHandleYUnderCursor()), moveYhandleUnderCursorState);
//			moveWhatIsUnderCursorState->addTransition (SelectManager::getInstance (), SIGNAL(MovingHandleZUnderCursor()), moveZhandleUnderCursorState);
//			moveXhandleUnderCursorState->addTransition (glw, SIGNAL(mouseMove()), moveXhandleMovingState);
//			moveYhandleUnderCursorState->addTransition (glw, SIGNAL(mouseMove()), moveYhandleMovingState);
//			moveZhandleUnderCursorState->addTransition (glw, SIGNAL(mouseMove()), moveZhandleMovingState);
//			moveXhandleMovingState->addTransition (glw, SIGNAL(mouseMove()), moveXhandleMovingState);
//			moveYhandleMovingState->addTransition (glw, SIGNAL(mouseMove()), moveYhandleMovingState);
//			moveZhandleMovingState->addTransition (glw, SIGNAL(mouseMove()), moveZhandleMovingState);
//			moveXhandleMovingState->addTransition (glw, SIGNAL(leftMouseReleassed()), moveXhandleReleasedState);
//			moveYhandleMovingState->addTransition (glw, SIGNAL(leftMouseReleassed()), moveYhandleReleasedState);
//			moveZhandleMovingState->addTransition (glw, SIGNAL(leftMouseReleassed()), moveZhandleReleasedState);
		}
	}

	// State Transitions of Rotation
	{
	}

	//State transitions of Scaling
	{
	}
}

void StateManager::addState()
{
	//Adding states to state machine

	// Rectangle States
	{
		stateMachine.addState(rectangleDrawingEnabledState);
		stateMachine.addState(rectangleMousePressState);
		stateMachine.addState(rectangleMouseMoveState);
		stateMachine.addState(rectangleMouseReleaseState);
	}
	// End of Rectangle States

	// Circle States
	{
		stateMachine.addState(circleDrawingEnabledState);
		stateMachine.addState(circleMousePressState);
		stateMachine.addState(circleMouseMoveState);
		stateMachine.addState(circleMouseReleaseState);
	}
	// End of Circle States

	// Ellipse States
	{
		stateMachine.addState(ellipseDrawingEnabledState);
		stateMachine.addState(ellipseMousePressState);
		stateMachine.addState(ellipseMouseMoveState);
		stateMachine.addState(ellipseMouseReleaseState);
	}
	// End of Ellipse States

	// Line States
	{
		stateMachine.addState (lineInitializeState);
		stateMachine.addState (lineDrawingEnabledState);
		stateMachine.addState (lineMouseReleaseState);
		stateMachine.addState (lineMouseMoveState);
		stateMachine.addState (lineMousePressState);
		stateMachine.addState (lineEnterKeyPressedState);
	}
	// End of Line States

	// Bezier States
	{
		stateMachine.addState (bezierInitializeState);
		stateMachine.addState (bezierDrawingEnabledState);
		stateMachine.addState (bezierMouseReleaseState);
		stateMachine.addState (bezierMouseMoveState);
		stateMachine.addState (bezierMousePressState);
		stateMachine.addState (bezierEnterKeyPressedState);
	}
	// End of Bezier States

	// Spline States
	{
		stateMachine.addState (splineInitializeState);
		stateMachine.addState (splineDrawingEnabledState);
		stateMachine.addState (splineMouseReleaseState);
		stateMachine.addState (splineMouseMoveState);
		stateMachine.addState (splineMousePressState);
		stateMachine.addState (splineEnterKeyPressedState);
	}
	// End of Spline States

	// Polygon States
	{
		stateMachine.addState (polygonInitializeState);
		stateMachine.addState (polygonDrawingEnabledState);
		stateMachine.addState (polygonMouseReleaseState);
		stateMachine.addState (polygonMouseMoveState);
		stateMachine.addState (polygonMousePressState);
		stateMachine.addState (polygonEnterKeyPressedState);
	}
	// End of Polygon States

	// Sphere States
	{
		stateMachine.addState (sphereEnableState);
		stateMachine.addState (sphereMousePressed);
		stateMachine.addState (sphereMouseReleased);
		stateMachine.addState (sphereMouseMoved);
	}
	// End of Sphere States

	// Cube States
	{
		stateMachine.addState (cubeEnableState);
		stateMachine.addState (cubeRectangleDrawn);
		stateMachine.addState (cubeDrawingRectangleMousePressed);
		stateMachine.addState (cubeGivingHeightMousePressed);
		stateMachine.addState (cubeDrawingRectangleMouseMoved);
		stateMachine.addState (cubeGivingHeightMouseMoved);
		stateMachine.addState (cubeDrawingRectangleMouseReleased);
		stateMachine.addState (cubeGivingHeightMouseReleased);
	}
	// End of Cube States

	// Cylinder States
	{
		stateMachine.addState (cylinderEnableState);
		stateMachine.addState (cylinderCircleDrawn);
		stateMachine.addState (cylinderDrawingCircleMousePressed);
		stateMachine.addState (cylinderGivingHeightMousePressed);
		stateMachine.addState (cylinderDrawingCircleMouseMoved);
		stateMachine.addState (cylinderGivingHeightMouseMoved);
		stateMachine.addState (cylinderDrawingCircleMouseReleased);
		stateMachine.addState (cylinderGivingHeightMouseReleased);
	}
	// End of Cylinder States

	// Cone States
	{
		stateMachine.addState (coneEnableState);
		stateMachine.addState (coneCircleDrawn);
		stateMachine.addState (coneDrawingCircleMousePressed);
		stateMachine.addState (coneGivingHeightMousePressed);
		stateMachine.addState (coneDrawingCircleMouseMoved);
		stateMachine.addState (coneGivingHeightMouseMoved);
		stateMachine.addState (coneDrawingCircleMouseReleased);
		stateMachine.addState (coneGivingHeightMouseReleased);
	}
	// End of Cone States

	// Select States
	{
		stateMachine.addState (selectEnabledState);
		stateMachine.addState (selectMouseMoveState);
		stateMachine.addState (selectMousePressedState);
		stateMachine.addState (selectPointState);
		stateMachine.addState (selectRectangularState);
	}
	// End of Select States

	// Move States
	{
		stateMachine.addState(moveEnabledState);
		stateMachine.addState(moveSelectMousePressedState);
		stateMachine.addState(moveSelectMouseMoveState);
		stateMachine.addState(moveSelectPointState);
		stateMachine.addState(moveSelectRectangularState);
		stateMachine.addState(moveWhatIsUnderCursorState);
		stateMachine.addState(moveXhandleUnderCursorState);
		stateMachine.addState(moveYhandleUnderCursorState);
		stateMachine.addState(moveZhandleUnderCursorState);
		stateMachine.addState(moveXhandleMovingState);
		stateMachine.addState(moveYhandleMovingState);
		stateMachine.addState(moveZhandleMovingState);
		stateMachine.addState(moveXhandleReleasedState);
		stateMachine.addState(moveYhandleReleasedState);
		stateMachine.addState(moveZhandleReleasedState);
	}
	// End Of Move States

	stateMachine.addState(rotateEnabledState);
	stateMachine.addState(rotateNothingSelectedState);
	stateMachine.addState(rotateDiselectAllState);
	stateMachine.addState(rotateSelectWhileRotate);
	stateMachine.addState(rotateSelectRectangularState);
	stateMachine.addState(rotateSelectModelState);
	stateMachine.addState(rotateState);
	stateMachine.addState(rotateMovingState);
	stateMachine.addState(rotateMouseReleaseState);
	stateMachine.addState(rotateMousePressedState);

	stateMachine.addState(scaleEnabledState);
	stateMachine.addState(scaleNothingSelectedState);
	stateMachine.addState(scaleDiselectAllState);
	stateMachine.addState(scaleSelectWhileScale);
	stateMachine.addState(scaleSelectRectangularState);
	stateMachine.addState(scaleSelectModelState);
	stateMachine.addState(scaleState);
	stateMachine.addState(scaleMovingState);
	stateMachine.addState(scaleMouseReleaseState);
	stateMachine.addState(scaleMousePressedState);

	stateMachine.addState (cancelDrawing);
}
