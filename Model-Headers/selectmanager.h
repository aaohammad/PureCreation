#ifndef SELECTMANAGER_H
#define SELECTMANAGER_H

#include "modelmanager.h"
#include "undomanager.h"

class SelectManager
{
public:
    SelectManager(ModelManager *modelManager, UndoManager *undoManager);
    void pointSelection(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor);
    void rectangualrSelection(float x1, float y1, float x2, float y2, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor);
    void diselectAll();
    void selectAll();
    bool isSomethingUnderCursor(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor);
    bool isModelUnderCursorSelected(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor);
    int getSelectedModelIndex(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor);
private:
    void selectionInitialization();

    int bufferSize;
    bool someThingSelected;
    int selectedModelIndex;
    ModelManager *modelManager;
    UndoManager *undoManager;
};

#endif // SELECTMANAGER_H
