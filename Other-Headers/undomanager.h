#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H

#include <QUndoStack>
#include "commands.h"
#include "model.h"

class UndoManager
{
public:
    UndoManager(ModelManager *modelManager);
    void addModel(Model *model);
    void deleteModel(Model *model);
    void moveModel(Model *model, float x, float y);
    void rotateModel(Model *model, float angle);
    void scaleModel(Model *model, float x, float y);
    void undo();
    void redo();
private:
    ModelManager *modelManager;
    QUndoStack *undoStack;

};

#endif // UNDOMANAGER_H
