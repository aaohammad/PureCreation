#include "commands.h"

AddModelCommand::AddModelCommand(ModelManager *modelManager, Model *model)
{
    this->modelManager = modelManager;
    this->modelIndex = this->modelManager->size();
    this->model = model;
}

void AddModelCommand::undo()
{
    this->modelManager->removeAt(this->modelIndex);
}

void AddModelCommand::redo()
{
    this->modelManager->insert(this->modelIndex, this->model);
}

DeleteModelCommand::DeleteModelCommand(ModelManager *modelManager, Model *model)
{
    this->modelManager = modelManager;
    this->modelIndex = this->modelManager->indexOf(model);
    this->model = model;
}

void DeleteModelCommand::undo()
{
    this->modelManager->insert(this->modelIndex, this->model);
}

void DeleteModelCommand::redo()
{
    this->modelManager->removeAt(this->modelIndex);
}

MoveModelCommand::MoveModelCommand(Model *model, float xMovement, float yMovement)
{
    this->model = model;
    this->xMovement = xMovement;
    this->yMovement = yMovement;
}

void MoveModelCommand::undo()
{
    this->model->move(-this->xMovement, -this->yMovement);
    this->model->resetMove();
}

void MoveModelCommand::redo()
{
    this->model->move(this->xMovement, this->yMovement);
    this->model->resetMove();
}

RotateModelCommand::RotateModelCommand(Model *model, float angle)
{
    this->model = model;
    this->angle = angle;
}

void RotateModelCommand::undo()
{
    this->model->rotate(-this->angle);
    this->model->resetRotate();
}

void RotateModelCommand::redo()
{
    this->model->rotate(this->angle);
    this->model->resetRotate();
}

ScaleModelCommand::ScaleModelCommand(Model *model, float xScale, float yScale)
{
    this->model = model;
    this->xScale = xScale;
    this->yScale = yScale;
}

void ScaleModelCommand::undo()
{
    this->model->scale(-this->xScale, -this->yScale);
    this->model->resetScale();
}

void ScaleModelCommand::redo()
{
    this->model->scale(this->xScale, this->yScale);
    this->model->resetScale();
}
