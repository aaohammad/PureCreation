#ifndef SCALEMANAGER_H
#define SCALEMANAGER_H

#include "model-manager.h"
#include "undo-manager.h"

class ScaleManager : public QObject
{
    Q_OBJECT
public:
    static ScaleManager * getInstance();
    void mousePressed(float x, float y);
    void mouseMoved(float x, float y);
    void mouseReleased();
    void drawHandle(float zoomFactor);
    bool isSelected(float x, float y);

private:
    ScaleManager();
    static ScaleManager * m_scaleManager;
    float xCenter, yCenter, zoomFactor;
    bool scaleXY;
    bool scaleX;
    bool scaleY;
    float preX;
    float preY;
    float curX;
    float curY;
};

#endif // SCALEMANAGER_H
