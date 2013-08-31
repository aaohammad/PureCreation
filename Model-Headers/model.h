#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QTextStream>
#include <QtOpenGL>
#include "vector.h"
#include "typeofmodel.h"
#include "vertexmanager.h"
#include "edgemanager.h"

class Model : public QObject
{
    Q_OBJECT
public:
    virtual void drawObjectSelectMode() = 0;
    virtual void drawVertexSelectMode() = 0;
    virtual void drawFaceSelectMode() = 0;
    virtual void drawEdgeSelectMode() = 0;
    virtual void save(QTextStream *out) = 0;
    virtual void showAttribute() = 0;
    virtual void reflect(float, float) = 0;

    void move(float, float);
    void resetMove();
    void scale(float, float);
    void resetScale();
    void rotate(float);
    void resetRotate();
    void open(float, float, float, float, float);
    int getGroupID();
    void setGroupID(int);
    void setColor(QColor *);
    QColor * getColor();
    void setID(int);
    int getID();
    bool getSelected();
    void setSelected(bool);
    void setMouseStatus(bool);
    bool getMouseStatus();
    void getCenter(float &, float &);
    TypeOfModel getType();
protected:
    VertexManager *vertexManager;
    EdgeManager *edgeManager;
    TypeOfModel type;
    QColor *color;
    QColor aEcolor;
    int iD;
    int groupID;
    bool selected;
    float xTranslate;
    float yTranslate;
    float xDrawingTranslation;
    float yDrawingTranslation;
    float xScale;
    float xDrawingScale;
    float yScale;
    float yDrawingScale;
    float drawingRotationAngle;
    float angle;
    bool isMouseUp;
    float centerX;
    float centerY;
public slots:
    virtual void changeAttributes() = 0;
    virtual void changeColorAE() = 0;
signals:
};

#endif // MODEL_H
