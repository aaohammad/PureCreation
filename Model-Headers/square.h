#ifndef SQUARE_H
#define SQUARE_H

#include "model.h"
#include "ui_squareform.h"

class Square : public Model
{
    Q_OBJECT
public:
    Square(float x1, float y1, float x2, float y2);
/*************************************************/
    void drawEdgeSelectMode();
    void drawFaceSelectMode();
    void drawObjectSelectMode();
    void drawVertexSelectMode();
    void save(QTextStream *out);
    void showAttribute();
    void reflect(float, float);
/*************************************************/
private:
/*************************************************/
    bool isFilled;
    Ui::square_attributeEditorForm *ae;
    QDialog *dialog;
/*************************************************/
    float x1;
    float y1;
    float x2;
    float y2;
public slots:
    void changeAttributes();
    void changeColorAE();
signals:
};

#endif // SQUARE_H
