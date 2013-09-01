#ifndef THREADS_H
#define THREADS_H

#include <QThread>
#include "scene-widget.h"

class RefreshSceneThread : public QThread
{
public:
    RefreshSceneThread(SceneWidget * sceneWidget)
    {
        refreshSceneTimer = new QTimer(this);
        connect(refreshSceneTimer, SIGNAL(timeout()), sceneWidget, SLOT(updateScene()));
        refreshSceneTimer->start(33);
    }

private:
    QTimer *refreshSceneTimer;
};

#endif // THREADS_H
