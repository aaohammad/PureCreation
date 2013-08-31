#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "model.h"
#include <QList>

class ModelManager
{
private:
    QList<Model *> modelList;
public:
    void insert(int index, Model *model);
    void removeAt(int index);
    int indexOf(Model *model);
    int size();
    Model *at(int index);
    void clear();
    void append(Model *model);
    void swap(int i, int j);
};

#endif
