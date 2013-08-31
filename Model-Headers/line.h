#ifndef LINE_H
#define LINE_H

#include "model.h"
#include "ui_lineform.h"

class Line : public Model
{
    Q_OBJECT
public:
    Line(QList<Vector> vertices);
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
public slots:
    void changeAttributes();
    void changeColorAE();
    void vertexComboBoxChanged();
signals:
};

#endif // LINE_H
