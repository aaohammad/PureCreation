#ifndef CIRCLE_H
#define CIRCLE_H

#include "model.h"
#include "ui_circleform.h"

class Circle : public Model
{
    Q_OBJECT
public:
    Circle(float xCenter, float yCenter, float radius);
//+++++++++++++++++++++++++++++++++++++++
    void drawEdgeSelectMode();
    void drawFaceSelectMode();
    void drawObjectSelectMode();
    void drawVertexSelectMode();
    void save(QTextStream *out);
    void showAttribute();
    void reflect(float, float);
//++++++++++++++++++++++++++++++++++++++++
private:
//++++++++++++++++++++++++++++++++++++++++
    bool isFilled;
    Ui::Form *ae;
    QDialog *dialog;
//+++++++++++++++++++++++++++++++++++++++++
    float xCenter;
    float yCenter;
    float radius;
public slots:
    void changeAttributes();
    void changeColorAE();
signals:
};

#endif // CIRCLE_H
