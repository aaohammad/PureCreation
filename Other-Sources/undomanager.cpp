#include "undomanager.h"

UndoManager::UndoManager(ModelManager *modelManager)
{
    this->modelManager = modelManager;
    undoStack = new QUndoStack();
}

void UndoManager::addModel(Model *model)
{
    QUndoCommand *addModelCommand = new AddModelCommand(modelManager, model);
    undoStack->push(addModelCommand);
}

void UndoManager::deleteModel(Model *model)
{
    QUndoCommand *deleteModelCommand = new DeleteModelCommand(modelManager, model);
    undoStack->push(deleteModelCommand);
}

void UndoManager::moveModel(Model *model, float x, float y)
{
    QUndoCommand *moveModelCommand = new MoveModelCommand(model, x, y);
    undoStack->push(moveModelCommand);
}

void UndoManager::rotateModel(Model *model, float angle)
{
    QUndoCommand *rotateModelCommand = new RotateModelCommand(model, angle);
    undoStack->push(rotateModelCommand);
}

void UndoManager::scaleModel(Model *model, float x, float y)
{
    QUndoCommand *scaleModelCommand = new ScaleModelCommand(model, x, y);
    undoStack->push(scaleModelCommand);
}

void UndoManager::undo()
{
    undoStack->undo();
}

void UndoManager::redo()
{
    undoStack->redo();
}
