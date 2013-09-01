#ifndef FRONTSCENE_H
#define FRONTSCENE_H

#include "glwidget.h"

class FrontGLWidget : public GLWidget
{
	Q_OBJECT

public:
	void sceneTransformations();
	void pointSelection (int, int, QList<Model *> &, QList<Vector *> &);
	void rectangularSelection (int, int, int, int, QList<Model *> &, QList<Vector *> &);

private:
	void drawInformation();
	void drawGrid();
	void initializeGL();
	void paintGL();
	void convertWindowCoorToSceneCoor (float &, float &, float &, QPoint);

	GLuint levelOneGrid;
	float glOrthoVariable;
};

#endif // FRONTSCENE_H
