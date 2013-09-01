#include "perspective-view.h"

PerspectiveGLWidget::PerspectiveGLWidget()
{
	controlKeyPressed = false;
	rotateScene = false;
	rotateSceneAngleAroundY = 45.0;
	rotateSceneAngleAroundX = 45.0;
	zoomScene = 15.0f;
}

void PerspectiveGLWidget::drawInformation()
{
	glDisable (GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	renderText(glWidgetWidth / 2 - 40, 20, "Perspective", fontOfOnScreenText);

	glClear(GL_DEPTH_BUFFER_BIT);
	glPushMatrix(); // modelview matrix pushing
	glLoadIdentity(); // load identity to modelview matrix
	glViewport(0, 0, glWidgetWidth / 7, glWidgetHeight / 7);
	glMatrixMode(GL_PROJECTION); // change matrix mode to projrction
	glPushMatrix(); // push current projection matrix
	glLoadIdentity(); // load identity to projection matrix
	gluPerspective(45, aspectRatio, 0.0001, 100);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -3.5);
	glRotatef(rotateSceneAngleAroundX, 1.0, 0.0, 0.0);
	glRotatef(rotateSceneAngleAroundY, 0.0, 1.0, 0.0);

	// X handle
	glColor3f(1.0, 0.0, 0.0);
	GLUquadricObj *xHandle = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	gluCylinder(xHandle, 0.05, 0.05, 1, 10, 10);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	GLUquadricObj *xCone = gluNewQuadric();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, 1);
	gluCylinder(xCone, 0.1, 0, 0.25, 10, 10);
	glPopMatrix();
	// X handle end

	// Y handle
	glColor3f(0.0, 1.0, 0.0);
	GLUquadricObj *yHandle = gluNewQuadric();
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(yHandle, 0.05, 0.05, 1, 10, 10);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	GLUquadricObj *yCone = gluNewQuadric();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, 1);
	gluCylinder(yCone, 0.1, 0, 0.25, 10, 10);
	glPopMatrix();
	// Y handle end

	// Z handle
	glColor3f(0.0, 0.0, 1.0);
	GLUquadricObj *zHandle = gluNewQuadric();
	glPushMatrix();
	gluCylinder(zHandle, 0.05, 0.05, 1, 10, 10);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	GLUquadricObj *zCone = gluNewQuadric();
	glTranslatef(0, 0, 1);
	gluCylinder(zCone, 0.1, 0, 0.25, 10, 10);
	glPopMatrix();
	// Z handle end

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable (GL_LIGHTING);
}

void PerspectiveGLWidget::drawGrid()
{
	glDisable (GL_LIGHTING);
	glCallList(levelOneGrid);
	glEnable (GL_LIGHTING);
}

void PerspectiveGLWidget::sceneTransformations()
{
	glViewport(0, 0, glWidgetWidth, glWidgetHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, aspectRatio, 1.0, 1000);  // if near clipping plane is small we have problem in depth testing.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -zoomScene);
	glTranslatef(sceneTranslateX, sceneTranslateY, 0);
	glRotatef(rotateSceneAngleAroundX, 1.0, 0.0, 0.0);
	glRotatef(rotateSceneAngleAroundY, 0.0, 1.0, 0.0);
}

void PerspectiveGLWidget::wheelEvent(QWheelEvent *e)
{
	zoomScene -= 0.01 * e->delta();
	e->ignore(); // my parent will take event too
}

void PerspectiveGLWidget::mouseMoveEvent(QMouseEvent *)
{
	if(panScene)
	{
		if(startDrawingMousePosition.x() > mapFromGlobal(QCursor::pos()).x())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			sceneTranslateX -= 0.5f;
		}
		else if(startDrawingMousePosition.x() < mapFromGlobal(QCursor::pos()).x())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			sceneTranslateX += 0.5f;
		}
		if(startDrawingMousePosition.y() > mapFromGlobal(QCursor::pos()).y())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			sceneTranslateY += 0.5f;
		}
		else if(startDrawingMousePosition.y() < mapFromGlobal(QCursor::pos()).y())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			sceneTranslateY -= 0.5f;
		}
	}
	if(rotateScene)
	{
		if(startDrawingMousePosition.x() > mapFromGlobal(QCursor::pos()).x())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			rotateSceneAngleAroundY -= 2.0f;
		}
		else if(startDrawingMousePosition.x() < mapFromGlobal(QCursor::pos()).x())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			rotateSceneAngleAroundY += 2.0f;
		}
		if(startDrawingMousePosition.y() > mapFromGlobal(QCursor::pos()).y())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			rotateSceneAngleAroundX -= 2.0f;
		}
		else if(startDrawingMousePosition.y() < mapFromGlobal(QCursor::pos()).y())
		{
			startDrawingMousePosition = mapFromGlobal(QCursor::pos());
			rotateSceneAngleAroundX += 2.0f;
		}
	}
	emit mouseMove ();
	if(isMouseButtonDown)
	{
		float x, y, z;
		float xp, yp, zp;
		convertWindowCoorToSceneCoor (x, y, z, mapFromGlobal (QCursor::pos ()));
		convertWindowCoorToSceneThreeDimentionalCoor (xp, yp, zp, mapFromGlobal (QCursor::pos ()));
		StateFunctions::getInstance ()->setCurrentMousePosition (x, y, z);
		StateFunctions::getInstance ()->setCurrentMousePositionOfPerspective (xp, yp, zp);
		SelectManager::getInstance ()->setCurrentMousePosition (mapFromGlobal (QCursor::pos ()).x (), mapFromGlobal (QCursor::pos ()).y ());
	}
}

void PerspectiveGLWidget::mousePressEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
	{
		isMouseButtonDown = true;
		//  Send mouse position to state function class
		float x, y, z;
		float xp, yp, zp;
		convertWindowCoorToSceneCoor (x, y, z, mapFromGlobal (QCursor::pos ()));
		convertWindowCoorToSceneThreeDimentionalCoor (xp, yp, zp, mapFromGlobal (QCursor::pos ()));
		StateFunctions::getInstance ()->setCurrentMousePosition (x, y, z);
		StateFunctions::getInstance ()->setCurrentMousePositionOfPerspective (xp, yp, zp);
		SelectManager::getInstance ()->setCurrentMousePosition(mapFromGlobal (QCursor::pos ()).x (), mapFromGlobal (QCursor::pos ()).y ());
		emit leftMouseButtonPressed();
	}
	if(e->button() == Qt::MidButton && controlKeyPressed)
	{
		startDrawingMousePosition = mapFromGlobal(QCursor::pos());
		panScene = true;
		setCursor(Qt::ClosedHandCursor);
	}
	else if(e->button() == Qt::MidButton)
	{
		startDrawingMousePosition = mapFromGlobal(QCursor::pos());
		rotateScene = true;
		setCursor(Qt::SizeAllCursor);
	}
	e->ignore(); // my parent will take event too
}

void PerspectiveGLWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
	{
		isMouseButtonDown = false;
		//  Send mouse position to state function class
		float x, y, z;
		convertWindowCoorToSceneCoor (x, y, z, mapFromGlobal (QCursor::pos ()));
		StateFunctions::getInstance ()->setCurrentMousePosition (x, y, z);
		emit leftMouseButtonReleased ();
	}
	if(e->button() == Qt::MidButton)
	{
		if(controlKeyPressed)
		{
			panScene = false;
			controlKeyPressed = false;
			sceneTranslateX += sceneTranslateXMoving;
			sceneTranslateY += sceneTranslateYMoving;
			sceneTranslateXMoving = 0.0;
			sceneTranslateYMoving = 0.0;
			setCursor(Qt::ArrowCursor);
		}
		else if(rotateScene)
		{
			// rotation finnished
			rotateScene = false;
			setCursor(Qt::ArrowCursor);
		}
	}
	e->ignore ();
}

void PerspectiveGLWidget::keyPressEvent(QKeyEvent *e)
{
	//diableing keyboard repeat in linux keyboard configuration.
	if(e->key() == Qt::Key_Return)
	{
		emit enterKeyPressed();
	}
	if(e->key() == Qt::Key_Control)
	{
		controlKeyPressed = true;
	}
	e->ignore();
}

void PerspectiveGLWidget::initializeGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glEnable (GL_LINE_STIPPLE);
	glClearColor(0.6, 0.6, 0.6, 1.0);

	// level 1 grid display list
	levelOneGrid = glGenLists(1);
	glNewList(levelOneGrid, GL_COMPILE);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for(int i = -40; i <= 40; i += 10)
	{
		glVertex3f(i, -0.1f, -40);
		glVertex3f(i, -0.1f, 40);

		glVertex3f(40, -0.1f,i);
		glVertex3f(-40, -0.1f,i);
	}
	glEnd();
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_LINES);
	for(int i = -40; i <= 40; i += 1)
	{
		glVertex3f(i, -0.1f,-40);
		glVertex3f(i, -0.1f,40);

		glVertex3f(40, -0.1f,i);
		glVertex3f(-40, -0.1f,i);
	}
	glEnd();
	glEndList();

}

void PerspectiveGLWidget::convertWindowCoorToSceneCoor(float &x, float &y, float &z, QPoint point_on_viewport)
{
	sceneTransformations();
	int viewport[4];
	double modelviewMatrix[16];
	double projectionMatrix[16];
	double wx1, wy1, wz1;
	double wx2, wy2, wz2;
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelviewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	int realY = viewport[3] - point_on_viewport.y();
	gluUnProject(point_on_viewport.x(), realY, 0.0, modelviewMatrix, projectionMatrix, viewport, &wx1, &wy1, &wz1);
	gluUnProject(point_on_viewport.x(), realY, 1.0, modelviewMatrix, projectionMatrix, viewport, &wx2, &wy2, &wz2);
	float line_dir_1, line_dir_2, line_dir_3, length;
	line_dir_1 = wx2 - wx1;
	line_dir_2 = wy2 - wy1;
	line_dir_3 = wz2 - wz1;

	length = sqrt(line_dir_1 * line_dir_1 + line_dir_2 * line_dir_2 + line_dir_3 * line_dir_3);
	line_dir_1 = line_dir_1 / length;
	line_dir_2 = line_dir_2 / length;
	line_dir_3 = line_dir_3 / length;

	float d = (-wy1) / (line_dir_2); // important : here because we have y as the up vector we use wy1 to calculate d.

	x = (d * line_dir_1 + wx1);
	y = 0.0f;
	z = (d * line_dir_3 + wz1);
}

void PerspectiveGLWidget::convertWindowCoorToSceneThreeDimentionalCoor (float &x, float &y, float &z, QPoint point_on_viewport)
{
	x = fabs ((float)point_on_viewport.x () / 10.0f);
	y = fabs ((float)point_on_viewport.y () / 10.0f);
	z = fabs ((float)point_on_viewport.y () / 10.0f);
}

void PerspectiveGLWidget::paintGL()
{
	sceneTransformations();
	LightManager::getInstance ()->enableLighting ();
	LightManager::getInstance ()->doLight ();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(isGridDrawingEnabled)
		drawGrid();
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	ModelManager::getInstance ()->draw ();

	glDisable (GL_LIGHTING);
	GLUquadricObj *sphere=NULL;
	glLineWidth (3);
	glPushMatrix ();
	glTranslatef (10, 10, 10);
	glColor3f (1.0, 1.0, 1.0);
	sphere = gluNewQuadric();
	gluSphere(sphere, 0.15, 20, 20);
	glBegin (GL_LINES);
	glVertex3f (0, 0.3, 0);
	glVertex3f (0, -0.3, 0);
	glVertex3f (0.3, 0, 0);
	glVertex3f (-0.3, 0, 0);
	glVertex3f (0, 0, 0.3);
	glVertex3f (0, 0, -0.3);
	glVertex3f (0.1, 0.1, 0.1);
	glVertex3f (-0.1, -0.1, -0.1);
	glVertex3f (0.1, 0.1, -0.1);
	glVertex3f (-0.1, -0.1, 0.1);
	glVertex3f (-0.1, 0.1, -0.1);
	glVertex3f (0.1, -0.1, 0.1);
	glVertex3f (-0.1, 0.1, 0.1);
	glVertex3f (0.1, -0.1, -0.1);
	glEnd ();
	glEnable (GL_LIGHTING);
	glLineWidth (1);
	glPopMatrix ();
	if(selectionRectangle)
	{
		glDisable (GL_LIGHTING);
		glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		float finishDrawingPositionX = mapFromGlobal (QCursor::pos ()).x ();
		float finishDrawingPositionZ = mapFromGlobal (QCursor::pos ()).y ();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, glWidgetWidth, glWidgetHeight, 0.0, 1.0, -1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt (0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glColor3f(1.0, 1.0, 1.0);
		glLineStipple(1, 0xF0F0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(curXSelectionRectangle, curYSelectionRectangle);
		glVertex2f(finishDrawingPositionX, curYSelectionRectangle);
		glVertex2f(finishDrawingPositionX, finishDrawingPositionZ);
		glVertex2f(curXSelectionRectangle, finishDrawingPositionZ);
		glEnd();
		glLineStipple(1, 0xFFFF);
		glColor4f(0.5, 0.5, 0.0, 0.5);
		glBegin(GL_QUADS);
		glVertex2f(curXSelectionRectangle, curYSelectionRectangle);
		glVertex2f(finishDrawingPositionX, curYSelectionRectangle);
		glVertex2f(finishDrawingPositionX, finishDrawingPositionZ);
		glVertex2f(curXSelectionRectangle, finishDrawingPositionZ);
		glEnd();
		glDisable (GL_LIGHTING);
	}
	drawInformation();
}

void PerspectiveGLWidget::pointSelection (int x, int y, QList<Model *> &selectedModels, QList<Vector *> &selectedVertices)
{
	GLuint selectBuffer[1024];
	glSelectBuffer(1024, selectBuffer);
	glRenderMode(GL_SELECT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glInitNames();
	glPushName(0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	gluPickMatrix(x, viewport[3] - y, 10.0, 10.0, viewport);
	gluPerspective(45, aspectRatio, 1.0, 1000);
	int i = 0;
	while(i != ModelManager::getInstance ()->size ())
	{
		if(ModelManager::getInstance ()->at (i)->getDrawingMode () == ObjectMode)
		{
			glLoadName(i + 1);
			Model *s = ModelManager::getInstance ()->at(i);
			ModelManager::getInstance ()->at(i)->setSelectionIdentifier(i + 1);
			s->drawObjectModeSelect();
			i++;
		}
		else if(ModelManager::getInstance ()->at (i)->getDrawingMode () == VertexMode)
		{
			int i = 0;
			int j = 0;
			while(j != ModelManager::getInstance ()->size())
			{
				int vertexCount = ModelManager::getInstance ()->at(j)->getVertexManager()->size();
				for(int k = 0; k < vertexCount; k++)
				{
					glLoadName(i + 1);
					ModelManager::getInstance ()->at(j)->getVertexManager()->at(k)->setSelectionIdentifier(i + 1);
					ModelManager::getInstance ()->at(j)->drawVertexModeSelect(k);
					i++;
				}
				j++;
			}
		}
	}
	GLint hits = glRenderMode(GL_RENDER);
	GLuint names, *ptr;
	ptr = (GLuint *)selectBuffer;
	GLuint selectedObject = 0;
	for (int i = 0; i < hits; i++)
	{
		names = *ptr++;
		ptr++;
		ptr++;
		while(names--)
		{
			selectedObject = *ptr;
			ptr++;
		}
	}
	for(int k = 0 ; k < ModelManager::getInstance ()->size() ; k++)
	{
		if(ModelManager::getInstance ()->at (k)->getDrawingMode () == ObjectMode)
		{
			GLuint modelID = ModelManager::getInstance ()->at(k)->getSelectionIdentifier();
			if(modelID == selectedObject)
			{
				selectedModels.append (ModelManager::getInstance ()->at(k));
			}
		}
		else if(ModelManager::getInstance ()->at (i)->getDrawingMode () == VertexMode)
		{
			int j = 0;
			while(j != ModelManager::getInstance ()->size())
			{
				int vertexCount = ModelManager::getInstance ()->at(j)->getVertexManager()->size();
				for(int k = 0; k < vertexCount; k++)
				{
					if(selectedObject == (GLuint)ModelManager::getInstance ()->at(j)->getVertexManager()->at(k)->getID())
					{
						selectedVertices.append (ModelManager::getInstance ()->at(j)->getVertexManager()->at(k));
					}
				}
				j++;
			}
		}
	}
}

void PerspectiveGLWidget::rectangularSelection (int preX, int preY, int curX, int curY, QList<Model *> &selectedModels, QList<Vector *> &selectedVertices)
{
	GLuint selectBuffer[1024];
	glSelectBuffer(1024, selectBuffer);
	glRenderMode(GL_SELECT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glInitNames();
	glPushName(0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float xCenter = (preX + curX) / 2;
	float yCenter = (preY + curY) / 2;
	float widthOfSelection = fabs(preX - curX);
	if(widthOfSelection < 5)
		widthOfSelection = 5;
	float heightOfSelection = fabs(preY - curY);
	if(heightOfSelection < 5)
		heightOfSelection = 5;
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	gluPickMatrix(xCenter, viewport[3] - yCenter, widthOfSelection, heightOfSelection, viewport);
	gluPerspective(45, aspectRatio, 1.0, 1000);
	int i = 0;
	while(i != ModelManager::getInstance ()->size ())
	{
		if(ModelManager::getInstance ()->at (i)->getDrawingMode () == ObjectMode)
		{
			glLoadName(i + 1);
			Model *s = ModelManager::getInstance ()->at(i);
			ModelManager::getInstance ()->at(i)->setSelectionIdentifier(i + 1);
			s->drawObjectModeSelect();
			i++;
		}
		else if(ModelManager::getInstance ()->at (i)->getDrawingMode () == VertexMode)
		{
			int t = 0;
			int j = 0;
			while(j != ModelManager::getInstance ()->size())
			{
				int vertexCount = ModelManager::getInstance ()->at(j)->getVertexManager()->size();
				for(int k = 0; k < vertexCount; k++)
				{
					glLoadName(t + 1);
					ModelManager::getInstance ()->at(j)->getVertexManager()->at(k)->setSelectionIdentifier(t + 1);
					ModelManager::getInstance ()->at(j)->drawVertexModeSelect(k);
					t++;
				}
				j++;
			}
		}
	}
	GLint hits = glRenderMode(GL_RENDER);
	GLuint names, *ptr;
	ptr = (GLuint *)selectBuffer;
	GLuint selectedObject = 0;
	for (int i = 0; i < hits; i++)
	{
		names = *ptr++;
		ptr++;
		ptr++;
		while(names--)
		{
			selectedObject = *ptr;
			for(int k = 0 ; k < ModelManager::getInstance ()->size() ; k++)
			{
				if(ModelManager::getInstance ()->at (k)->getDrawingMode () == ObjectMode)
				{
					GLuint modelID = ModelManager::getInstance ()->at(k)->getSelectionIdentifier();
					if(modelID == selectedObject)
					{
						selectedModels.append (ModelManager::getInstance ()->at(k));
					}
				}
				else if(ModelManager::getInstance ()->at (k)->getDrawingMode () == VertexMode)
				{
					int j = 0;
					while(j != ModelManager::getInstance ()->size())
					{
						int vertexCount = ModelManager::getInstance ()->at(j)->getVertexManager()->size();
						for(int k = 0; k < vertexCount; k++)
						{
							if(selectedObject == (GLuint)ModelManager::getInstance ()->at(j)->getVertexManager()->at(k)->getID())
							{
								selectedVertices.append (ModelManager::getInstance ()->at(j)->getVertexManager()->at(k));
							}
						}
						j++;
					}
				}
				ptr++;
			}
		}
	}
}
