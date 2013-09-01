#ifndef PERSPECTIVESCENE_H
#define PERSPECTIVESCENE_H

#include "glwidget.h"

class PerspectiveGLWidget : public GLWidget
{
	Q_OBJECT

public:
	PerspectiveGLWidget();
	void sceneTransformations();
	void pointSelection (int, int, QList<Model *> &, QList<Vector *> &);
	void rectangularSelection (int, int, int, int, QList<Model *> &, QList<Vector *> &);

private:
	void drawInformation();
	void drawGrid();
	void initializeGL();
	void paintGL();
	void convertWindowCoorToSceneCoor(float &, float &, float &, QPoint);
	void convertWindowCoorToSceneThreeDimentionalCoor(float &, float &, float &, QPoint);

	GLuint levelZeroGrid;
	GLuint levelOneGrid;
	bool controlKeyPressed;
	bool rotateScene;
	float rotateSceneAngleAroundY;
	float rotateSceneAngleAroundX;
	float zoomScene;


public slots:
	void wheelEvent(QWheelEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);
	void mouseReleaseEvent(QMouseEvent *);
};

#endif // PERSPECTIVESCENE_H
