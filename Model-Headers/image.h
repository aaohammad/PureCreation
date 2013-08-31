#ifndef IMAGE_H
#define IMAGE_H

#include "model.h"

class Image : public Model
{
    Q_OBJECT
public:
    Image(QString, float, float);
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
    QDialog *dialog;
//+++++++++++++++++++++++++++++++++++++++++
    QImage image;
    QImage openGLImage;
    QString fileName;
    float x1;
    float y1;
    float x2;
    float y2;
    float width;
    float height;
public slots:
    void changeAttributes();
    void changeColorAE();
    void loadImageReject();
signals:
};

#endif // IMAGE_H
