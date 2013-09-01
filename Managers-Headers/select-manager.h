#ifndef SELECTMANAGER_H
#define SELECTMANAGER_H

#include "undo-manager.h"
#include "glwidget.h"

class GLWidget;
class SelectManager : public QObject
{
	Q_OBJECT
public:
	static SelectManager * getInstance();
	void addGLWidget(QList<GLWidget *> * glwidgets);
	void setCurrentMousePosition(float x, float y);
	void diselectAll();
	void selectAll();

private:
	SelectManager();
	static SelectManager * m_selectManager;
	float curX, curY;
	float preX, preY;

	void selectionInitialization();
	QList<Model *> selectedModels;
	QList<Vector *> selectedVertices;
	QList<GLWidget *> * glwidgets;

public slots:
	void selectMousePressed();
	void selectPoint();
	void selectRectangular();
	void whatISUnderCursor();

signals:
	void endState();
	void ModelOrNothingUnderCursor();
};

#endif // SELECTMANAGER_H
