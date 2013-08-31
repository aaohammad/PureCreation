#include "modelmanager.h"

void ModelManager::insert(int index, Model *model)
{
    modelList.insert(index, model);
}

void ModelManager::removeAt(int index)
{
    modelList.removeAt(index);
}

int ModelManager::indexOf(Model *model)
{
    return modelList.indexOf(model);
}

int ModelManager::size()
{
    return modelList.size();
}

Model *ModelManager::at(int index)
{
    return modelList.at(index);
}

void ModelManager::clear()
{
    modelList.clear();
}

void ModelManager::append(Model *model)
{
    modelList.append(model);
}

void ModelManager::swap(int i, int j)
{
    modelList.swap(i, j);
}
