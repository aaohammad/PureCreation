#include "state-functions.h"

StateFunctions * StateFunctions::m_stateFunctions = 0;
StateFunctions * StateFunctions::getInstance ()
{
	if(!m_stateFunctions)
		m_stateFunctions = new StateFunctions();
	return m_stateFunctions;
}

void StateFunctions::setCurrentMousePosition (float x, float y, float z)
{
	this->curX = x;
	this->curY = y;
	this->curZ = z;
}

void StateFunctions::setCurrentMousePositionOfPerspective (float x, float y, float z)
{
	this->curPX = x;
	this->curPY = y;
	this->curPZ = z;
}

void StateFunctions::circleMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::circleMouseMoved ()
{
	float radius = sqrt( pow(curX- preX, 2) + pow(curY - preY, 2) + pow(curZ - preZ, 2));
	Circle *tempCircle = new Circle(preX, preY, preZ, radius);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempCircle);
}

void StateFunctions::circleMouseReleased()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::ellipseMousePressed()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::ellipseMouseMoved ()
{
	float centerOfEllipseY = (curY + preY) / 2;
	float centerOfEllipseZ = (curZ + preZ) / 2;
	float centerOfEllipseX = (curX + preX) / 2;
	if(curY < 0.001f && curY > -0.001f)
	{
		float widthOfEllipse = fabs(curX - preX) / 2;
		float heightOfEllipse = fabs(curZ - preZ) / 2;
		Ellipse *tempEllipse = new Ellipse(centerOfEllipseX, centerOfEllipseY, centerOfEllipseZ, widthOfEllipse, heightOfEllipse);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempEllipse);
	}
	else if(curX < 0.001f && curX > -0.001f)
	{
		float widthOfEllipse = fabs(curY - preY) / 2;
		float heightOfEllipse = fabs(curZ- preZ) / 2;
		Ellipse *tempEllipse = new Ellipse(centerOfEllipseX, centerOfEllipseY, centerOfEllipseZ, widthOfEllipse, heightOfEllipse);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempEllipse);
	}
	else if(curZ < 0.001f && curZ > -0.001f)
	{
		float widthOfEllipse = fabs(curX - preX) / 2;
		float heightOfEllipse = fabs(curY- preY) / 2;
		Ellipse *tempEllipse = new Ellipse(centerOfEllipseX, centerOfEllipseY, centerOfEllipseZ, widthOfEllipse, heightOfEllipse);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempEllipse);
	}
}

void StateFunctions::ellipseMouseReleased()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::rectangleMousePressed()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::rectangleMouseMoved ()
{
	float minX, minZ, minY, maxX, maxY, maxZ;
	if(preX <= curX)
	{
		minX = preX;
		maxX = curX;
	}
	else
	{
		minX = curX;
		maxX = preX;
	}
	if(preY <= curY)
	{
		minY = preY;
		maxY = curY;
	}
	else
	{
		minY = curY;
		maxY = preY;
	}
	if(preZ <= curZ)
	{
		minZ = preZ;
		maxZ = curZ;
	}
	else
	{
		minZ = curZ;
		maxZ = preZ;
	}
	Rectangle * tempRectangle = new Rectangle(minX, minY, minZ, maxX, maxY, maxZ);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempRectangle);
}

void StateFunctions::rectangleMouseReleased()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::bezierInitialize ()
{
	VertexManager * tempVertexManager = new VertexManager();
	Vector * vector = new Vector(curX, curY, curZ);
	tempVertexManager->append (vector);
	Bezier * tempBezier = new Bezier(tempVertexManager);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempBezier);
}

void StateFunctions::bezierMouseMoved ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->last ()->replace (vector);
}

void StateFunctions::bezierMousePressed ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->append (vector);
}

void StateFunctions::bezierEnterKeyPressed ()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::splineInitialize ()
{
	VertexManager * tempVertexManager = new VertexManager();
	Vector * vector = new Vector(curX, curY, curZ);
	tempVertexManager->append (vector);
	Spline * tempSpline = new Spline(tempVertexManager);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempSpline);
}

void StateFunctions::splineMouseMoved ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->last ()->replace (vector);
}

void StateFunctions::splineMousePressed ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->append (vector);
}

void StateFunctions::splineEnterKeyPressed()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::lineInitialize ()
{
	VertexManager * tempVertexManager = new VertexManager();
	Vector * vector = new Vector(curX, curY, curZ);
	tempVertexManager->append (vector);
	Line * tempLine = new Line(tempVertexManager);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempLine);
}

void StateFunctions::lineMousePressed ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->append (vector);
}

void StateFunctions::lineMouseMoved ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->last ()->replace (vector);
}

void StateFunctions::lineEnterKeyPressed()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::polygonInitialize ()
{
	VertexManager * tempVertexManager = new VertexManager();
	Vector * vector = new Vector(curX, curY, curZ);
	tempVertexManager->append (vector);
	Polygon * tempPolygon = new Polygon(tempVertexManager);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempPolygon);
}

void StateFunctions::polygonMouseMoved ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->last ()->replace (vector);
}

void StateFunctions::polygonMousePressed ()
{
	Vector * vector = new Vector(curX, curY, curZ);
	ModelManager::getInstance ()->getDrawingTemporaryModel ()->getVertexManager ()->append (vector);
}

void StateFunctions::polygonEnterKeyPressed()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::sphereMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::sphereMouseMoved ()
{
	float radius = sqrt( pow(curX- preX, 2) + pow(curY - preY, 2) + pow(curZ - preZ, 2));
	Sphere *tempSphere = new Sphere(preX, preY, preZ, radius);
	ModelManager::getInstance ()->setDrawingTemporaryModel (tempSphere);
}

void StateFunctions::sphereMouseReleased ()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::cubeDrawingRectangleMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::cubeDrawingRectangleMouseMoved ()
{
	float minX, minZ, minY, maxX, maxY, maxZ;
	if(preX <= curX)
	{
		minX = preX;
		maxX = curX;
	}
	else
	{
		minX = curX;
		maxX = preX;
	}
	if(preY <= curY)
	{
		minY = preY;
		maxY = curY;
	}
	else
	{
		minY = curY;
		maxY = preY;
	}
	if(preZ <= curZ)
	{
		minZ = preZ;
		maxZ = curZ;
	}
	else
	{
		minZ = curZ;
		maxZ = preZ;
	}
	if(curX < 0.001f && curX > -0.001f)
	{
		Cube *tempCube = new Cube(0.0f,
								  preY,
								  preZ,
								  0.0f,
								  fabs (minZ - maxZ),
								  fabs (minY - maxY));
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCube);
		threeDDrawingState = LengthNotSet;
	}
	else if(curY < 0.001f && curY > -0.001f)
	{
		Cube *tempCube = new Cube(preX,
								  0.0f,
								  preZ,
								  fabs (minX - maxX),
								  fabs (minZ - maxZ),
								  0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCube);
		threeDDrawingState = HeightNotSet;
	}
	else if(curZ < 0.001f && curZ > -0.001f)
	{
		Cube *tempCube = new Cube(preX,
								  preY,
								  0.0f,
								  fabs (minX - maxX),
								  0.0f,
								  fabs (minY - maxY));
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCube);
		threeDDrawingState = WidthNotSet;
	}
}

void StateFunctions::cubeGivingHeightMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::cubeGivingHeightMouseMoved ()
{
	if(threeDDrawingState == HeightNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setHeight (fabs (curZ - preZ));
	}
	else if(threeDDrawingState == WidthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setWidth (fabs (curZ - preZ));
	}
	else if(threeDDrawingState == LengthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setLength (fabs (curX - preX));
	}
}

void StateFunctions::cubeGivingHeightMouseReleased ()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::cylinderDrawingCircleMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::cylinderDrawingCircleMouseMoved ()
{
	float radius = sqrt( pow(curX- preX, 2) + pow(curY - preY, 2) + pow(curZ - preZ, 2));
	if(curX < 0.001 && curX > -0.001)
	{
		Cylinder *tempCylinder = new Cylinder(0.0f, preY, preZ, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCylinder);
		threeDDrawingState = LengthNotSet;
	}
	else if(curY < 0.01 && curY > -0.01)
	{
		Cylinder *tempCylinder = new Cylinder(preX, 0.0f, preZ, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCylinder);
		threeDDrawingState = HeightNotSet;
	}
	else if(curZ < 0.001 && curZ > -0.001)
	{
		Cylinder *tempCylinder = new Cylinder(preX, preY, 0.0f, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCylinder);
		threeDDrawingState = WidthNotSet;
	}
}

void StateFunctions::cylinderGivingHeightMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::cylinderGivingHeightMouseMoved ()
{
	if(threeDDrawingState == HeightNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setHeight (curZ - preZ);
	}
	else if(threeDDrawingState == WidthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setWidth (curZ - preZ);
	}
	else if(threeDDrawingState == LengthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setLength (curX - preX);
	}
}

void StateFunctions::cylinderGivingHeightMouseReleased ()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::coneDrawingCircleMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::coneDrawingCircleMouseMoved ()
{
	float radius = sqrt( pow(curX- preX, 2) + pow(curY - preY, 2) + pow(curZ - preZ, 2));
	if(curX < 0.001 && curX > -0.001)
	{
		Cone *tempCone = new Cone(0.0f, preY, preZ, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCone);
		threeDDrawingState = LengthNotSet;
	}
	else if(curY < 0.01 && curY > -0.01)
	{
		Cone *tempCone = new Cone(preX, 0.0f, preZ, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCone);
		threeDDrawingState = HeightNotSet;
	}
	else if(curZ < 0.001 && curZ > -0.001)
	{
		Cone *tempCone = new Cone(preX, preY, 0.0f, radius, 0.0f);
		ModelManager::getInstance ()->setDrawingTemporaryModel (tempCone);
		threeDDrawingState = WidthNotSet;
	}
}

void StateFunctions::coneGivingHeightMousePressed ()
{
	preX = curX;
	preY = curY;
	preZ = curZ;
}

void StateFunctions::coneGivingHeightMouseMoved ()
{
	if(threeDDrawingState == HeightNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setHeight (curZ - preZ);
	}
	else if(threeDDrawingState == WidthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setWidth (curZ - preZ);
	}
	else if(threeDDrawingState == LengthNotSet)
	{
		ModelManager::getInstance ()->getDrawingTemporaryModel ()->setLength (curX - preX);
	}
}

void StateFunctions::coneGivingHeightMouseReleased ()
{
	ModelManager::getInstance ()->commitDrawing ();
	emit endState ();
}

void StateFunctions::moveIsSomethingUnderCursor()
{
//    GLint viewport[4];
//    glGetIntegerv(GL_VIEWPORT, viewport);
//    bool anyModelSelected = selectManager->isSomethingUnderCursor(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
//    if(anyModelSelected)
//        emit somethingUnderCursor();
//    else
//        emit nothingUnderCursor();
}

void StateFunctions::moveIsModelSelected()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
////    moveManager->mousePressed(x, y);

//    GLint viewport[4];
//    glGetIntegerv(GL_VIEWPORT, viewport);
//    bool isSelected = selectManager->isModelUnderCursorSelected(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
//    if(isSelected)
//    {
//            emit modelIsSelected();
//    }
//    else
//    {
//            emit modelIsNotSelected();
//    }
}

void StateFunctions::moveModel()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
////    moveManager->mouseMoved(x, y);
//    updateGL();
}

void StateFunctions::scaleEnabled()
{
//    this->whichHandleIsNowActive = ScaleStateActivated;
//    updateGL();
}

void StateFunctions::scale()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
//    scaleManager->mouseMoved(x, y);
//    updateGL(); // this line is very important
}

void StateFunctions::scaleMousePressed()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
//    if(!scaleManager->isSelected(x, y))
//    {
//        GLint viewport[4];
//        glGetIntegerv(GL_VIEWPORT, viewport);
//        bool isSomethingUnderCursor = selectManager->isSomethingUnderCursor(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
//        if(isSomethingUnderCursor)
//        {
//            emit somethingUnderCursor();
//        }
//        else
//        {
//            emit nothingUnderCursor();
//        }
//    }
//    else
//    {
//        scaleManager->mousePressed(x, y);
//        emit scaleHandleSelected();
//    }
}

void StateFunctions::scaleMouseReleased()
{
//    scaleManager->mouseReleased();
//    emit endState();
}

void StateFunctions::rotateEnabled()
{/*
	this->whichHandleIsNowActive = RotateStateActivated;
	updateGL();*/
}

void StateFunctions::rotate()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
////    rotateManager->mouseMoved(x, y);
//    updateGL(); // this line is very important
}

void StateFunctions::rotateMousePressed()
{
//    float x, y, z;
//    convertWindowCoorToSceneCoor(x, y, z, mapFromGlobal(QCursor::pos()));
//    if(!rotateManager->isSelected(x, y))
//    {
//        GLint viewport[4];
//        glGetIntegerv(GL_VIEWPORT, viewport);
//        bool isSomethingUnderCursor = selectManager->isSomethingUnderCursor(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
//        if(isSomethingUnderCursor)
//        {
//            emit somethingUnderCursor();
//        }
//        else
//        {
//            emit nothingUnderCursor();
//        }
//    }
//    else
//    {
//        rotateManager->mousePressed(x, y);
//        emit rotateHandleSelected();
//    }
}

void StateFunctions::rotateMouseReleased()
{
//    rotateManager->mouseReleased();
//    emit endState();
}

void StateFunctions::resetEverything()
{
//    this->whichHandleIsNowActive = NothingActivated;
}

void StateFunctions::cancelDrawing()
{

}

void StateFunctions::diselectAll()
{

}

void StateFunctions::toggleGridDrawing ()
{

}

void StateFunctions::changeModeToObjectMode()
{
//    this->drawingMode = ObjectMode;
//    selectManager->changeMode(ObjectMode);
//    moveManager->changeDrawingMode(ObjectMode);
//    updateGL();
}

void StateFunctions::changeModeToVertexMode()
{
//    this->drawingMode = VertexMode;
//    selectManager->changeMode(VertexMode);
//    moveManager->changeDrawingMode(VertexMode);
//    updateGL();
}

void StateFunctions::moveMouseReleased()
{
//    moveManager->mouseReleased();
}
