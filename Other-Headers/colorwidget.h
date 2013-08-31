#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QtGui/QWidget>
#include "colorpickerwidget.h"

class ColorWidget : public QWidget
{
    Q_OBJECT

public:
    ColorWidget(QWidget *parent = 0);
    ColorPickerWidget *colorPickerWidget;

private:
    QGridLayout *gridLayout;
};

#endif
