#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include "perspective-view.h"
#include "side-view.h"
#include "top-view.h"
#include "front-view.h"
#include "view.h"

class SceneWidget : public QWidget
{
    Q_OBJECT

public:
    SceneWidget();
    QList<GLWidget *> * getGLWidgets();

private:
    void layoutWidget();    // Layout the scene widget.
    void connections();

    TopGLWidget *topGLWidget;
    PerspectiveGLWidget *perspectiveGLWidget;
    FrontGLWidget *frontGLWidget;
    SideGLWidget *sideGLWidget;
    View *topView;
    View *perspectiveView;
    View *frontView;
    View *sideView;
    bool isFourView;
    bool isPerspectiveView;
    bool isTopView;
    bool isSideView;
    bool isFrontView;
    QList<GLWidget *> * glwidgets;

    QGridLayout *gridLayout;
    QSplitter *fatherSplitter;
    QSplitter *childSplitter1;
    QSplitter *childSplitter2;

public slots:
    void updateScene();
    void keyPressEvent(QKeyEvent *);
    void frontViewSelectedSlot();
    void sideViewSelectedSlot();
    void topViewSelectedSlot();
    void perspectiveViewSelectedSlot();

};

#endif // SCENEWIDGET_H
