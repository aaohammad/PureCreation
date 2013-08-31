#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "modelmanager.h"
#include "model.h"

class AddModelCommand : public QUndoCommand
{
public:
    AddModelCommand(ModelManager *modelManager, Model *model);
    void undo();
    void redo();
private:
    int modelIndex;
    ModelManager *modelManager;
    Model *model;
};

class DeleteModelCommand : public QUndoCommand
{
public:
    DeleteModelCommand(ModelManager *modelManager, Model *model);
    void undo();
    void redo();
private:
    int modelIndex;
    ModelManager *modelManager;
    Model *model;
};

class MoveModelCommand : public QUndoCommand
{
public:
    MoveModelCommand(Model *model, float xMovement, float yMovement);
    void undo();
    void redo();
private:
    Model *model;
    float xMovement;
    float yMovement;
};

class RotateModelCommand : public QUndoCommand
{
public:
    RotateModelCommand(Model *model, float angle);
    void undo();
    void redo();
private:
    Model *model;
    float angle;
};

class ScaleModelCommand : public QUndoCommand
{
public:
    ScaleModelCommand(Model *model, float xScale, float yScale);
    void undo();
    void redo();
private:
    Model *model;
    float xScale;
    float yScale;
};

#endif // COMMANDS_H
