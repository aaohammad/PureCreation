#ifndef TEXT_H
#define TEXT_H

#include "model.h"
class Text : public Model
{
    Q_OBJECT
public:
    Text(QString, float x, float y, float size, QFont);
/*************************************************/
    void drawEdgeSelectMode();
    void drawFaceSelectMode();
    void drawObjectSelectMode();
    void drawVertexSelectMode();
    void save(QTextStream *out);
    void showAttribute();
    void reflect(float, float);

    QString str;
    float x;
    float y;
    float size;
    QFont *font;
/*************************************************/
private:
/*************************************************/
/*************************************************/
public slots:
    void changeAttributes();
    void changeColorAE();
signals:
};

#endif // TEXT_H
