#ifndef BEZIER_H
#define BEZIER_H

#include "model.h"
#include "ui_lineform.h"

class Bezier : public Model
{
    Q_OBJECT
public:
    Bezier(QList<Vector> vertices);
//+++++++++++++++++++++++++++++++++++++++
    void drawEdgeSelectMode();
    void drawFaceSelectMode();
    void drawObjectSelectMode();
    void drawVertexSelectMode();
    void save(QTextStream *out);
    void showAttribute();
    void reflect(float, float);

    int findIndex(char);
//++++++++++++++++++++++++++++++++++++++++
private:
//++++++++++++++++++++++++++++++++++++++++
    Ui::lineForm *ae;
    QDialog *dialog;
    QString lineContinuity;
    float lineWidth;
//+++++++++++++++++++++++++++++++++++++++++
    float coef[100];
public slots:
    void changeAttributes();
    void changeColorAE();
    void vertexComboBoxChanged();
signals:
};

#endif // BEZIER_H
