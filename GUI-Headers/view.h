#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "glwidget.h"

class View : public QWidget
{
    Q_OBJECT
public:
    View(GLWidget *glWidget);
    void setSelected(bool);
    bool getSelected();

private:
    void creatToolBar();

    QAction *drawGridAction;
    QToolBar *toolbar;
    GLWidget *glWidget;
    bool isSelected;

public slots:
    void actionTriggeredSlot();

signals:
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);

};

#endif // VIEW_H
