#include "view.h"

View::View(GLWidget *glWidget)
{
    creatToolBar();
    this->glWidget = glWidget;
    glWidget->setStyleSheet(QString::fromUtf8("border-color: rgb(122, 255, 56);"));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout *vb = new QVBoxLayout;
    vb->addWidget(toolbar);

    vb->addWidget(this->glWidget);
    mainLayout->addLayout(vb);
    setLayout(mainLayout);
    this->setFocusPolicy(Qt::StrongFocus);

    connect(drawGridAction, SIGNAL(triggered()), this, SLOT(actionTriggeredSlot()));
}

void View::creatToolBar()
{
    toolbar = new QToolBar;

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/new/prefix1/icons/grid"), QSize(), QIcon::Normal, QIcon::Off);
    drawGridAction = new QAction(this);
    drawGridAction->setIcon(icon);
    drawGridAction->setCheckable(true);
    drawGridAction->setChecked(true);
    toolbar->addAction(drawGridAction);
    toolbar->setIconSize(QSize(10,10));
}

void View::setSelected(bool selected)
{
    if(selected)
    {
        this->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 210, 100);"));
    }
    else
    {
        this->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 201, 150);"));
    }
    this->isSelected = selected;
}

bool View::getSelected()
{
    return isSelected;
}

void View::actionTriggeredSlot()
{
    QMouseEvent *e = NULL;
    emit mousePressEvent(e);    // To select this scene widget and change color to show user that this widget is selected.
}
