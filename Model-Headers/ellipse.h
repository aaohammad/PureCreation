#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "model.h"
#include "ui_squareform.h"

class Ellipse : public Model
{
    Q_OBJECT
public:
    Ellipse(float xCenter, float yCenter, float width, float height);
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
    Ui::square_attributeEditorForm *ae;
    QDialog *dialog;
//+++++++++++++++++++++++++++++++++++++++++
    float xCenter, yCenter;
    float widthOfEllipse;
    float heightOfEllipse;
public slots:
    void changeAttributes();
    void changeColorAE();
signals:
};

#endif // ELLIPSE_H
