#include "scene-widget.h"

SceneWidget::SceneWidget()
{
    topGLWidget = new TopGLWidget();
    perspectiveGLWidget = new PerspectiveGLWidget();
    frontGLWidget = new FrontGLWidget();
    sideGLWidget = new SideGLWidget();

    frontView = new View(frontGLWidget);
    sideView = new View(sideGLWidget);
    topView = new View(topGLWidget);
    perspectiveView = new View(perspectiveGLWidget);

    frontView->setSelected(false);
    sideView->setSelected(false);
    topView->setSelected(false);
    perspectiveView->setSelected(true);

    isFourView = true;
    isPerspectiveView = false;
    isTopView = false;
    isSideView = false;
    isFrontView = false;

    glwidgets = new QList<GLWidget *>();
    glwidgets->append (perspectiveGLWidget);
    glwidgets->append (topGLWidget);
    glwidgets->append (frontGLWidget);
    glwidgets->append (sideGLWidget);

    layoutWidget();
    connections();
}

QList<GLWidget *> * SceneWidget::getGLWidgets ()
{
    return glwidgets;
}

void SceneWidget::layoutWidget()
{
    gridLayout = new QGridLayout(this);
    fatherSplitter = new QSplitter(this);
    fatherSplitter->setOrientation(Qt::Vertical);
    childSplitter1 = new QSplitter(fatherSplitter);
    childSplitter2 = new QSplitter(fatherSplitter);
    childSplitter1->addWidget(topView);
    childSplitter1->addWidget(perspectiveView);
    childSplitter2->addWidget(frontView);
    childSplitter2->addWidget(sideView);
    gridLayout->addWidget(fatherSplitter, 0, 0, 1, 1);
    this->setLayout(gridLayout);
}

void SceneWidget::connections()
{
    connect(frontView, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(frontViewSelectedSlot()));
    connect(sideView, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(sideViewSelectedSlot()));
    connect(topView, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(topViewSelectedSlot()));
    connect(perspectiveView, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(perspectiveViewSelectedSlot()));

    connect(frontView, SIGNAL(wheelEvent(QWheelEvent*)), this, SLOT(frontViewSelectedSlot()));
    connect(sideView, SIGNAL(wheelEvent(QWheelEvent*)), this, SLOT(sideViewSelectedSlot()));
    connect(topView, SIGNAL(wheelEvent(QWheelEvent*)), this, SLOT(topViewSelectedSlot()));
    connect(perspectiveView, SIGNAL(wheelEvent(QWheelEvent*)), this, SLOT(perspectiveViewSelectedSlot()));
}

void SceneWidget::updateScene()
{
    if(isFourView)
    {
        perspectiveGLWidget->updateGL();
        topGLWidget->updateGL();
        frontGLWidget->updateGL();
        sideGLWidget->updateGL();
    }
    else
    {
        if(isPerspectiveView)
        {
            perspectiveGLWidget->updateGL();
        }
        else if(isTopView)
        {
            topGLWidget->updateGL();
        }
        else if(isSideView)
        {
            sideGLWidget->updateGL();
        }
        else if(isFrontView)
        {
            frontGLWidget->updateGL();
        }
    }
}

void SceneWidget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Space)
    {
        if(isFourView)
        {
            if(frontView->getSelected())
            {
                sideView->setHidden(true);
                topView->setHidden(true);
                perspectiveView->setHidden(true);
                childSplitter1->hide();
                isPerspectiveView = false;
                isTopView = false;
                isSideView = false;
                isFrontView = true;
            }
            else if(sideView->getSelected())
            {
                frontView->setHidden(true);
                topView->setHidden(true);
                perspectiveView->setHidden(true);
                childSplitter1->hide();
                isPerspectiveView = false;
                isTopView = false;
                isSideView = true;
                isFrontView = false;
            }
            else if(topView->getSelected())
            {
                frontView->setHidden(true);
                sideView->setHidden(true);
                perspectiveView->setHidden(true);
                childSplitter2->hide();
                isPerspectiveView = false;
                isTopView = true;
                isSideView = false;
                isFrontView = false;
            }
            else if(perspectiveView->getSelected())
            {
                frontView->setHidden(true);
                sideView->setHidden(true);
                topView->setHidden(true);
                childSplitter2->hide();
                isPerspectiveView = true;
                isTopView = false;
                isSideView = false;
                isFrontView = false;
            }
            isFourView = false;
        }
        else
        {
            if(frontView->getSelected())
            {
                sideView->setHidden(false);
                topView->setHidden(false);
                perspectiveView->setHidden(false);
            }
            else if(sideView->getSelected())
            {
                frontView->setHidden(false);
                topView->setHidden(false);
                perspectiveView->setHidden(false);
            }
            else if(topView->getSelected())
            {
                frontView->setHidden(false);
                sideView->setHidden(false);
                perspectiveView->setHidden(false);
            }
            else if(perspectiveView->getSelected())
            {
                frontView->setHidden(false);
                sideView->setHidden(false);
                topView->setHidden(false);
            }
            childSplitter1->show();
            childSplitter2->show();
            isFourView = true;
            isPerspectiveView = false;
            isTopView = false;
            isSideView = false;
            isFrontView = false;
        }
    }
}

void SceneWidget::frontViewSelectedSlot()
{
    frontView->setSelected(true);
    sideView->setSelected(false);
    topView->setSelected(false);
    perspectiveView->setSelected(false);
}

void SceneWidget::sideViewSelectedSlot()
{
    frontView->setSelected(false);
    sideView->setSelected(true);
    topView->setSelected(false);
    perspectiveView->setSelected(false);
}

void SceneWidget::topViewSelectedSlot()
{
    frontView->setSelected(false);
    sideView->setSelected(false);
    topView->setSelected(true);
    perspectiveView->setSelected(false);
}

void SceneWidget::perspectiveViewSelectedSlot()
{
    frontView->setSelected(false);
    sideView->setSelected(false);
    topView->setSelected(false);
    perspectiveView->setSelected(true);
}
