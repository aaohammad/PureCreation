#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QtOpenGL>
#include <cmath>
#include <QList>
#include <QMessageBox>
#include <QUndoStack>

#include "model-manager.h"
#include "move-manager.h"
#include "undo-manager.h"
#include "scale-manager.h"
#include "rotate-manager.h"
#include "light-manager.h"
#include "select-manager.h"

#include "state-functions.h"
#include "model.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "ellipse.h"
#include "bezier.h"
#include "spline.h"
#include "polygon.h"

class SelectManager;
class GLWidget : public QGLWidget
{
	Q_OBJECT

public:
	GLWidget();
	bool getIsMouseHere();
	void drawSelectionRectangle(float, float, bool);
	virtual void pointSelection(int, int, QList<Model *> &, QList<Vector *> &) = 0;
	virtual void rectangularSelection(int, int, int, int, QList<Model *> &, QList<Vector *> &) = 0;

protected:
	QFont fontOfOnScreenText;
	QPoint startDrawingMousePosition;
	float sceneTranslateX;
	float sceneTranslateY;
	float sceneTranslateZ;
	float sceneTranslateXMoving;
	float sceneTranslateYMoving;
	float sceneTranslateZMoving;
	float zoomFactor;
	float aspectRatio;
	int curXSelectionRectangle;
	int curYSelectionRectangle;
	bool isGridDrawingEnabled;
	bool panScene;
	int glWidgetWidth;
	int glWidgetHeight;
	bool isMouseButtonDown;
	bool isMouseHere;
	bool selectionRectangle;
	QShortcut *groupShortcutKey;

	void resizeGL(int, int);
	virtual void sceneTransformations() = 0;
	virtual void convertWindowCoorToSceneCoor(float &, float &, float &, QPoint) = 0;
	virtual void drawInformation() = 0;
	virtual void drawGrid() = 0;
	virtual void initializeGL() = 0;
	virtual void paintGL() = 0;

public slots:
	void setGridDrawing(bool value);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void wheelEvent(QWheelEvent *);
	void mousePressEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);
	void contextMenu(const QPoint &point);
	void enterEvent (QEvent *);
	void leaveEvent (QEvent *);

signals:
	void leftMouseButtonPressed ();
	void leftMouseButtonReleased ();
	void mouseMove ();
	void enterKeyPressed ();
	void endState ();
	void somethingUnderCursor ();
	void nothingUnderCursor ();
	void modelIsSelected ();
	void modelIsNotSelected ();
	void scaleHandleSelected ();
	void rotateHandleSelected ();
};
#endif // GLWIDGET_H
