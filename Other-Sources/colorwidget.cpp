#include "colorwidget.h"

ColorWidget::ColorWidget(QWidget *parent) :
    QWidget(parent)
{
    gridLayout = new QGridLayout();
    colorPickerWidget = new ColorPickerWidget();
    gridLayout->addWidget(colorPickerWidget);
    setLayout(gridLayout);
}
