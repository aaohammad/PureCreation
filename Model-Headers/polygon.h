#ifndef POLYGON_H
#define POLYGON_H

#include "model.h"
#include "ui_lineform.h"

class Polygon : public Model
{
    Q_OBJECT
public:
    Polygon(QList<Vector> vertices);
//+++++++++++++++++++++++++++++++++++++++
    void drawEdgeSelectMode();
    void drawFaceSelectMode();
    void drawObjectSelectMode();
    void drawVertexSelectMode();

    void move(float x, float y);
    void resetMove();
    void scale(float x, float y);
    void resetScale();
    void rotate(float);
    void resetRotate();
    void save(QTextStream *out);
    void showAttribute();
    void reflect(float, float);
    int findIndex(char);
//++++++++++++++++++++++++++++++++++++++++
private:
//++++++++++++++++++++++++++++++++++++++++
    bool isFilled;
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

#endif // POLYGON_H
