#include "undo-manager.h"

UndoManager * UndoManager::m_undoManager = NULL;
UndoManager * UndoManager::getInstance ()
{
    if(!m_undoManager)
        m_undoManager = new UndoManager;
    return m_undoManager;
}

UndoManager::UndoManager()
{
    this->m_undoStack = new QUndoStack();
}

void UndoManager::addModel(Model *model)
{
    QUndoCommand *addModelCommand = new AddModelCommand(model);
    m_undoStack->push(addModelCommand);
}

void UndoManager::deleteModels(QList<int> *modelsIndices)
{
    QUndoCommand *deleteModelsCommand = new DeleteModelsCommand(modelsIndices);
    m_undoStack->push(deleteModelsCommand);
}

void UndoManager::moveModel(Model *model, float x, float y)
{
    QUndoCommand *moveModelCommand = new MoveModelCommand(model, x, y);
    m_undoStack->push(moveModelCommand);
}

void UndoManager::rotateModel(Model *model, float angle)
{
    QUndoCommand *rotateModelCommand = new RotateModelCommand(model, angle);
    m_undoStack->push(rotateModelCommand);
}

void UndoManager::scaleModel(Model *model, float x, float y)
{
    QUndoCommand *scaleModelCommand = new ScaleModelCommand(model, x, y);
    m_undoStack->push(scaleModelCommand);
}

void UndoManager::undo()
{
    m_undoStack->undo();
}

void UndoManager::redo()
{
    m_undoStack->redo();
}
