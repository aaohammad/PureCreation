#include "front-view.h"
#include "debuger.h"

void FrontGLWidget::drawInformation()
{
	glDisable (GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	renderText(glWidgetWidth / 2 - 40, 20, "Front", fontOfOnScreenText);
	glClear(GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-glWidgetWidth, glWidgetWidth, -glWidgetHeight, glWidgetHeight, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(-glWidgetWidth + 20, -glWidgetHeight + 20, 0.0);
	glLineWidth(2);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-10, 10);
	glVertex2d(10, 10);
	glVertex2d(10, -10);
	glVertex2d(-10, -10);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(-10, 90);
	glVertex2f(0.0, 100);
	glVertex2f(10, 90);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 100);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	renderText(-6, 110, 0, "Z", fontOfOnScreenText);

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(90, 10);
	glVertex2f(100, 0.0);
	glVertex2f(90, -10);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(100.0, 0.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	renderText(110, -6, 0, "Y", fontOfOnScreenText);

	glLineWidth(1);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable (GL_LIGHTING);
}

void FrontGLWidget::drawGrid()
{
	glDisable (GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glCallList(levelOneGrid);
	glEnable(GL_DEPTH_TEST);
	glEnable (GL_LIGHTING);
}

void FrontGLWidget::sceneTransformations()
{
	glViewport(0, 0, glWidgetWidth, glWidgetHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (glWidgetWidth <= glWidgetHeight)
		glOrtho(-zoomFactor, zoomFactor, -zoomFactor / aspectRatio, zoomFactor / aspectRatio, 1000.0f, -1000.0f);
	else
		glOrtho(-aspectRatio * zoomFactor, aspectRatio * zoomFactor, -zoomFactor, zoomFactor, 1000.0f, -1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-1000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, sceneTranslateYMoving, sceneTranslateZMoving);
	glTranslatef(0.0, sceneTranslateY, sceneTranslateZ);
}

void FrontGLWidget::initializeGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);
	glEnable (GL_LINE_STIPPLE);
	glClearColor(0.6, 0.6, 0.6, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	LightManager::getInstance ()->enableLighting ();
	LightManager::getInstance ()->doLight ();

	// level 1 grid display list
	levelOneGrid = glGenLists(1);
	glNewList(levelOneGrid, GL_COMPILE);
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_LINES);
	for(int i = -80; i <= 80; i += 1)
	{
		glVertex3f(0, i, -80);
		glVertex3f(0, i, 80);

		glVertex3f(0, 80, i);
		glVertex3f(0, -80, i);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for(int i = -80; i <= 80; i += 5)
	{
		glVertex3f(0, i, -80);
		glVertex3f(0, i, 80);

		glVertex3f(0, 80, i);
		glVertex3f(0, -80, i);
	}
	glEnd();
	glEndList();
}

void FrontGLWidget::paintGL()
{
	sceneTransformations();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(isGridDrawingEnabled)
		drawGrid();
	ModelManager::getInstance ()->draw ();
	if(selectionRectangle)
	{
		glDisable (GL_LIGHTING);
		glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		float startDrawingPositionX;
		float startDrawingPositionY;
		float startDrawingPositionZ;
		float finishDrawingPositionX;
		float finishDrawingPositionY;
		float finishDrawingPositionZ;
		convertWindowCoorToSceneCoor(startDrawingPositionX, startDrawingPositionY, startDrawingPositionZ, QPoint(curXSelectionRectangle, curYSelectionRectangle));
		convertWindowCoorToSceneCoor(finishDrawingPositionX, finishDrawingPositionY, finishDrawingPositionZ, mapFromGlobal(QCursor::pos()));
		glColor3f(1.0, 1.0, 1.0);
		glLineStipple(1, 0xF0F0);
		glBegin(GL_LINE_LOOP);
		glVertex3d(0.0f, startDrawingPositionY, startDrawingPositionZ);
		glVertex3d(0.0f, finishDrawingPositionY, startDrawingPositionZ);
		glVertex3d(0.0f, finishDrawingPositionY, finishDrawingPositionZ);
		glVertex3d(0.0f, startDrawingPositionY, finishDrawingPositionZ);
		glEnd();
		glLineStipple(1, 0xFFFF);
		glColor4f(0.5, 0.5, 0.0, 0.5);
		glBegin(GL_QUADS);
		glVertex3d(0.0f, startDrawingPositionY, startDrawingPositionZ);
		glVertex3d(0.0f, finishDrawingPositionY, startDrawingPositionZ);
		glVertex3d(0.0f, finishDrawingPositionY, finishDrawingPositionZ);
		glVertex3d(0.0f, startDrawingPositionY, finishDrawingPositionZ);
		glEnd();
		glEnable (GL_LIGHTING);
	}
	drawInformation();
}

void FrontGLWidget::convertWindowCoorToSceneCoor (float &x, float &y, float &z, QPoint point_on_viewport)
{
	sceneTransformations();
	int viewport[4];
	double modelviewMatrix[16];
	double projectionMatrix[16];
	double wx1, wy1, wz1;
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelviewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	int realY = viewport[3] - point_on_viewport.y() + 1;
	gluUnProject(point_on_viewport.x(), realY, 0.0, modelviewMatrix, projectionMatrix, viewport, &wx1, &wy1, &wz1);
	x = wx1;
	y = wy1;
	z = wz1;
}

void FrontGLWidget::pointSelection (int x, int y, QList<Model *> &selectedModels, QList<Vector *> &selectedVertices)
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
	if (glWidgetWidth <= glWidgetHeight)
		glOrtho(-zoomFactor, zoomFactor, -aspectRatio  * zoomFactor, aspectRatio  * zoomFactor, 1000.0f, -1000.0f);
	else
		glOrtho(-aspectRatio  * zoomFactor, aspectRatio  * zoomFactor, -zoomFactor, zoomFactor, 1000.0f, -1000.0f);
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
			break;
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

void FrontGLWidget::rectangularSelection (int preX, int preY, int curX, int curY, QList<Model *> &selectedModels, QList<Vector *> &selectedVertices)
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
	if (glWidgetWidth <= glWidgetHeight)
		glOrtho(-zoomFactor, zoomFactor, -aspectRatio  * zoomFactor, aspectRatio  * zoomFactor, 1000.0f, -1000.0f);
	else
		glOrtho(-aspectRatio  * zoomFactor, aspectRatio  * zoomFactor, -zoomFactor, zoomFactor, 1000.0f, -1000.0f);
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
