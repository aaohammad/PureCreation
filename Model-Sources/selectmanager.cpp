#include "selectmanager.h"

SelectManager::SelectManager(ModelManager *modelManager, UndoManager *undoManager)
{
    this->modelManager = modelManager;
    this->undoManager = undoManager;
    this->bufferSize = 1024;
    this->someThingSelected = false;
}

void SelectManager::pointSelection(float x, float y, GLint *viewport,
                                   float glWidgetWidth, float glWidgetHeight,
                                   float glOrthoVariable, float zoomFactor)
{
    GLuint selectBuffer[bufferSize];
    glSelectBuffer(bufferSize, selectBuffer);
    glRenderMode(GL_SELECT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glInitNames();
    glPushName(0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x, viewport[3] - y, 5.0, 5.0, viewport);
    float aspectRatio = (viewport[2]+0.0) / viewport[3];
    if (glWidgetWidth <= glWidgetHeight)
        glOrtho(-glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, -glOrthoVariable / aspectRatio  * zoomFactor, glOrthoVariable / aspectRatio  * zoomFactor, 1.0, -1.0);
    else
        glOrtho(-glOrthoVariable * aspectRatio  * zoomFactor, glOrthoVariable * aspectRatio  * zoomFactor, -glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    int i = 0;
    while(i != modelManager->size())
    {
        glLoadName(i+1);
        Model *s = modelManager->at(i);
        modelManager->at(i)->setID(i+1);
        s->drawObjectSelectMode();
        i++;
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    GLint hits = glRenderMode(GL_RENDER);
    GLuint names, *ptr;
    ptr = (GLuint *)selectBuffer;
    GLuint selectedObject = 0;
    for (int i = 0; i < hits; i++)
    {
        names = *ptr++;
        ptr++;
        ptr++;
        while(names--)
        {
            selectedObject = *ptr;
            ptr++;
        }
    }
    this->someThingSelected = false;
    for(int k = 0 ; k < modelManager->size() ; k++)
    {
        GLuint modelID = modelManager->at(k)->getID();
        if(modelID == selectedObject)
        {
            if(modelManager->at(k)->getGroupID() == 0)
            {
                modelManager->at(k)->setSelected(true);
                this->someThingSelected = true;
                this->selectedModelIndex = k;
            }
            else
            {
                for(int l = 0 ; l < modelManager->size() ; l++)
                {
                    if(modelManager->at(k)->getGroupID() == modelManager->at(l)->getGroupID())
                    {
                        modelManager->at(l)->setSelected(true);
                        this->someThingSelected = true;
                    }
                }
            }
        }
    }
}

void SelectManager::rectangualrSelection(float x1, float y1, float x2, float y2,
                                         GLint *viewport, float glWidgetWidth,
                                         float glWidgetHeight, float glOrthoVariable,
                                         float zoomFactor)
{
    GLuint selectBuffer[bufferSize];
    glSelectBuffer(bufferSize, selectBuffer);
    glRenderMode(GL_SELECT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glInitNames();
    glPushName(0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    float xCenter = (x1 + x2) / 2;
    float yCenter = (y1 + y2) / 2;
    float widthOfSelection = fabs(x1 - x2);
    float heightOfSelection = fabs(y1 - y2);
    gluPickMatrix(xCenter, viewport[3] - yCenter, widthOfSelection, heightOfSelection, viewport);
    float aspectRatio = (viewport[2]+0.0) / viewport[3];
    if (glWidgetWidth <= glWidgetHeight)
        glOrtho(-glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, -glOrthoVariable / aspectRatio  * zoomFactor, glOrthoVariable / aspectRatio  * zoomFactor, 1.0, -1.0);
    else
        glOrtho(-glOrthoVariable * aspectRatio  * zoomFactor, glOrthoVariable * aspectRatio  * zoomFactor, -glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    int i = 0;
    while(i != modelManager->size())
    {
        glLoadName(i+1);
        Model *s = modelManager->at(i);
        modelManager->at(i)->setID(i+1);
        s->drawObjectSelectMode();
        i++;
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    GLint hits = glRenderMode(GL_RENDER);
    GLuint names, *ptr;
    ptr = (GLuint *)selectBuffer;
    GLuint selectedObject = 0;
    this->someThingSelected = false;
    for (int i = 0; i < hits; i++)
    {
        names = *ptr++;
        ptr++;
        ptr++;
        while(names--)
        {
            selectedObject = *ptr;
            for(int k = 0 ; k < modelManager->size() ; k++)
            {
                GLuint temporary = modelManager->at(k)->getID();
                if(temporary == selectedObject)
                {
                    if(modelManager->at(k)->getGroupID() == 0)
                    {
                        modelManager->at(k)->setSelected(true);
                        this->someThingSelected = true;
                    }
                    else
                    {
                        for(int l = 0 ; l < modelManager->size() ; l++)
                        {
                            if(modelManager->at(k)->getGroupID() == modelManager->at(l)->getGroupID())
                            {
                                modelManager->at(l)->setSelected(true);
                                this->someThingSelected = true;
                            }
                        }
                    }
                }
            }
            ptr++;
        }
    }
}

void SelectManager::selectionInitialization()
{

}

void SelectManager::diselectAll()
{
    int i = 0;
    while(i < modelManager->size())
    {
        modelManager->at(i)->setSelected(false);
        i++;
    }
}

void SelectManager::selectAll()
{
    int i=0;
    while(i < modelManager->size())
    {
        modelManager->at(i)->setSelected(true);
        i++;
    }
}

bool SelectManager::isSomethingUnderCursor(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor)
{
    GLuint selectBuffer[bufferSize];
    glSelectBuffer(bufferSize, selectBuffer);
    glRenderMode(GL_SELECT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glInitNames();
    glPushName(0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x, viewport[3] - y, 5.0, 5.0, viewport);
    float aspectRatio = (viewport[2]+0.0) / viewport[3];
    if (glWidgetWidth <= glWidgetHeight)
        glOrtho(-glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, -glOrthoVariable / aspectRatio  * zoomFactor, glOrthoVariable / aspectRatio  * zoomFactor, 1.0, -1.0);
    else
        glOrtho(-glOrthoVariable * aspectRatio  * zoomFactor, glOrthoVariable * aspectRatio  * zoomFactor, -glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    int i = 0;
    while(i != modelManager->size())
    {
        glLoadName(i+1);
        Model *s = modelManager->at(i);
        modelManager->at(i)->setID(i+1);
        s->drawObjectSelectMode();
        i++;
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    GLint hits = glRenderMode(GL_RENDER);
    GLuint names, *ptr;
    ptr = (GLuint *)selectBuffer;
    GLuint selectedObject = 0;
    for (int i = 0; i < hits; i++)
    {
        names = *ptr++;
        ptr++;
        ptr++;
        while(names--)
        {
            selectedObject = *ptr;
            ptr++;
        }
    }
    this->someThingSelected = false;
    for(int k = 0 ; k < modelManager->size() ; k++)
    {
        GLuint modelID = modelManager->at(k)->getID();
        if(modelID == selectedObject)
        {
            if(modelManager->at(k)->getGroupID() == 0)
            {
                this->someThingSelected = true;
            }
            else
            {
                for(int l = 0 ; l < modelManager->size() ; l++)
                {
                    if(modelManager->at(k)->getGroupID() == modelManager->at(l)->getGroupID())
                    {
                        this->someThingSelected = true;
                    }
                }
            }
        }
    }
    return someThingSelected;
}

bool SelectManager::isModelUnderCursorSelected(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor)
{
    GLuint selectBuffer[bufferSize];
    glSelectBuffer(bufferSize, selectBuffer);
    glRenderMode(GL_SELECT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glInitNames();
    glPushName(0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x, viewport[3] - y, 5.0, 5.0, viewport);
    float aspectRatio = (viewport[2]+0.0) / viewport[3];
    if (glWidgetWidth <= glWidgetHeight)
        glOrtho(-glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, -glOrthoVariable / aspectRatio  * zoomFactor, glOrthoVariable / aspectRatio  * zoomFactor, 1.0, -1.0);
    else
        glOrtho(-glOrthoVariable * aspectRatio  * zoomFactor, glOrthoVariable * aspectRatio  * zoomFactor, -glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    int i = 0;
    while(i != modelManager->size())
    {
        glLoadName(i+1);
        Model *s = modelManager->at(i);
        modelManager->at(i)->setID(i+1);
        s->drawObjectSelectMode();
        i++;
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    GLint hits = glRenderMode(GL_RENDER);
    GLuint names, *ptr;
    ptr = (GLuint *)selectBuffer;
    GLuint selectedObject = 0;
    for (int i = 0; i < hits; i++)
    {
        names = *ptr++;
        ptr++;
        ptr++;
        while(names--)
        {
            selectedObject = *ptr;
            ptr++;
        }
    }
    this->someThingSelected = false;
    for(int k = 0 ; k < modelManager->size() ; k++)
    {
        GLuint modelID = modelManager->at(k)->getID();
        if(modelID == selectedObject)
        {
            if(modelManager->at(k)->getGroupID() == 0)
            {
                this->selectedModelIndex = k;
            }
            else
            {
                for(int l = 0 ; l < modelManager->size() ; l++)
                {
                    if(modelManager->at(k)->getGroupID() == modelManager->at(l)->getGroupID())
                    {
                        this->selectedModelIndex = k;
                    }
                }
            }
        }
    }
    return modelManager->at(this->selectedModelIndex)->getSelected();
}

int SelectManager::getSelectedModelIndex(float x, float y, GLint *viewport, float glWidgetWidth, float glWidgetHeight, float glOrthoVariable, float zoomFactor)
{
    this->pointSelection(x, y, viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    return this->selectedModelIndex;
}
