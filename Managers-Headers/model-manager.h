#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "model.h"
#include <QList>

class ModelManager
{
public:
	static ModelManager * getInstance();
	void insert(int index, Model *model);
	void removeAt(int index);
	void removeLast();
	int indexOf(Model *model);
	int size();
	Model *at(int index);
	Model *last();
	void clear();
	void append(Model *model);
	void swap(int i, int j);
	bool isCompleteModel(Model *);
	void draw();
	void setDrawingTemporaryModel(Model *value);
	Model * getDrawingTemporaryModel();
	void deleteDrawingTemporaryModel();
	void commitDrawing();

private:
	ModelManager();
	QList<Model *> m_modelList;
	Model * drawingTemporaryModel;
	DrawingModes m_drawingMode;
	static ModelManager * m_modelManager;
};

#endif
