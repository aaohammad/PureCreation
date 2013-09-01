#include "glwidget.h"

GLWidget::GLWidget()
{
	fontOfOnScreenText.setFamily("FreeMono");
	fontOfOnScreenText.setBold(true);

	sceneTranslateX = 0.0f;
	sceneTranslateY = 0.0f;
	sceneTranslateZ = 0.0f;
	sceneTranslateXMoving = 0.0f;
	sceneTranslateYMoving = 0.0f;
	sceneTranslateZMoving = 0.0f;
	zoomFactor = 16.0f;

	Light *defaultLight = new Light(DirectionalLight);
	LightManager::getInstance ()->append (defaultLight);
	LightManager::getInstance ()->enableLighting ();
	LightManager::getInstance ()->doLight ();

	isGridDrawingEnabled = true;
	panScene = false;
	isMouseButtonDown = false;
	selectionRectangle = false;

	groupShortcutKey = new QShortcut(this);
	groupShortcutKey->setKey(Qt::CTRL + Qt::Key_G);

	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking(true);

	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void GLWidget::contextMenu(const QPoint &point)
{
	QMenu *menu = new QMenu;
	menu->addAction(tr("Test Item"));
	menu->exec(this->mapToGlobal(point));
}

void GLWidget::resizeGL(int width, int height)
{
	glWidgetWidth = width;
	glWidgetHeight = height;
	aspectRatio = width / (float)(height ? height : 1);
}

void GLWidget::enterEvent (QEvent *)
{
	setFocus();
	isMouseHere = true;
}

void GLWidget::leaveEvent (QEvent *)
{
	isMouseHere = false;
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
	if(e->key() == Qt::Key_Return)
	{
		emit enterKeyPressed();
	}
	e->ignore();
}

void GLWidget::wheelEvent(QWheelEvent *e)
{
	if(e->delta() > 0)
	{
		if(zoomFactor < 100)
		{
			zoomFactor += 1;
		}
		else
		{
			zoomFactor = 100;
		}
	}
	else if(e->delta() < 0)
	{
		if(zoomFactor >= 4)
		{
			zoomFactor -= 1;
		}
		else
		{
			zoomFactor = 3;
		}
	}
	e->ignore(); // my parent will take event too
}

void GLWidget::mousePressEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
	{
		isMouseButtonDown = true;
		//  Send mouse position to state function class
		float x, y, z;
		convertWindowCoorToSceneCoor (x, y, z, mapFromGlobal (QCursor::pos ()));
		StateFunctions::getInstance ()->setCurrentMousePosition (x, y, z);
		SelectManager::getInstance ()->setCurrentMousePosition(mapFromGlobal (QCursor::pos ()).x (), mapFromGlobal (QCursor::pos ()).y ());
		emit leftMouseButtonPressed();
	}
	if(e->button() == Qt::MidButton)
	{
		startDrawingMousePosition = mapFromGlobal(QCursor::pos());
		panScene = true;
		setCursor(Qt::ClosedHandCursor);
	}
	e->ignore(); // my parent will take event too
}

void GLWidget::mouseMoveEvent(QMouseEvent *)
{
	if(panScene)
	{
		float x1, y1, z1;
		convertWindowCoorToSceneCoor(x1, y1, z1, startDrawingMousePosition);
		float x2, y2, z2;
		convertWindowCoorToSceneCoor(x2, y2, z2, mapFromGlobal(QCursor::pos()));
		sceneTranslateXMoving = -(x1 - x2);
		sceneTranslateYMoving = -(y1 - y2);
		sceneTranslateZMoving = -(z1 - z2);
	}
	if(isMouseButtonDown)
	{
		float x, y, z;
		convertWindowCoorToSceneCoor (x, y, z, mapFromGlobal (QCursor::pos ()));
		StateFunctions::getInstance ()->setCurrentMousePosition (x, y, z);
		SelectManager::getInstance ()->setCurrentMousePosition (mapFromGlobal (QCursor::pos ()).x (), mapFromGlobal (QCursor::pos ()).y ());
	}
	emit mouseMove ();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *e)
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
		if(panScene)
		{
			panScene = false;
			sceneTranslateX += sceneTranslateXMoving;
			sceneTranslateY += sceneTranslateYMoving;
			sceneTranslateZ += sceneTranslateZMoving;
			sceneTranslateXMoving = 0.0;
			sceneTranslateYMoving = 0.0;
			sceneTranslateZMoving = 0.0;
			setCursor(Qt::ArrowCursor);
		}
	}
}

//void GLWidget::convertWindowCoorToSceneCoor(float &x, float &y, float &z, QPoint point_on_viewport)
//{
////    sceneTransformations();
////    int viewport[4];
////    double modelviewMatrix[16];
////    double projectionMatrix[16];
////    double wx1, wy1, wz1;
////    glGetIntegerv(GL_VIEWPORT, viewport);
////    glGetDoublev(GL_MODELVIEW_MATRIX, modelviewMatrix);
////    glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
////    int realY = viewport[3] - point_on_viewport.y() + 1;
////    gluUnProject(point_on_viewport.x(), realY, 0.0, modelviewMatrix, projectionMatrix, viewport, &wx1, &wy1, &wz1);
////    x = wx1;
////    y = wy1;
////    z = wz1;
//}

void GLWidget::setGridDrawing(bool value)
{
	isGridDrawingEnabled = value;
}

bool GLWidget::getIsMouseHere ()
{
	return isMouseHere;
}

void GLWidget::drawSelectionRectangle (float x, float y, bool selectionRectangle)
{
	this->selectionRectangle = selectionRectangle;
	if(selectionRectangle)
	{
		curXSelectionRectangle = x;
		curYSelectionRectangle = y;
	}
}
