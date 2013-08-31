#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>                        // Header file for Qt opengl.
#include <QWheelEvent>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QtOpenGL>
#include <cmath>
#include <QList>
#include <QMessageBox>
#include <QUndoStack>
#include "modelmanager.h"
#include "movemanager.h"
#include "undomanager.h"
#include "scalemanager.h"
#include "rotatemanager.h"
#include "selectmanager.h"
#include "model.h"
#include "square.h"
#include "circle.h"
#include "line.h"
#include "ellipse.h"
#include "bezier.h"
#include "spline.h"
#include "polygon.h"
#include "image.h"
#include "text.h"
#include "ui_commandform.h"
#include "ui_imageform.h"
#include "ui_textform.h"

class Glwidget : public QGLWidget
{
    Q_OBJECT

public:
    Glwidget();                             // Constructor Of the class.

    //---------------- Color variables ---------------
    QColor *currentColor;
    QColor *textColor;
    void activeSaveTimer(bool, int);
    void getSaveTimerAcivated(bool &, int &);
    //------------------------------------------------
private:
    ModelManager *modelManager;
    MoveManager *moveManager;
    UndoManager *undoManager;
    ScaleManager *scaleManager;
    SelectManager *selectManager;
    RotateManager *rotateManager;
    ControlVariable controlVariable;


protected:
    void initializeGL();                    // Virtual from QGLWidget. Initialization of opengl.
    void paintGL();                         // Virtual from QGLWidget. Paint commands of opengl.
    void resizeGL(int, int);
    void draw_Grid();
    void draw_List();
    void scene_Transformations();
    void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *);
    void enterEvent(QEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void disableMove();
    void convertWindowCoorToSceneCoor(float & ,float &, QPoint);
    void saveFile(const QString &fileName);

    //---------------- gluPerspective function variables ---------------

    float glOrthoVariable;
    float zoomFactor;
    float sceneTranslateX;
    float sceneTranslateY;
    float aspect;
    double xTranslateScene;
    double yTranslateScene;
    double zTranslateScene;

    //------------------------------------------------------------------
    //------------------- selection process variables ------------------
    int selectionBufferSize_int;
    double centerOfSelectionX_double;
    double centerOfSelectionY_double;
    double widthOfSelection_double;
    double heightOfSelection_double;
    //------------------------------------------------------------------
    //-------------------------- Other variables -----------------------
    float startPointX, startPointY, endPointX, endPointY;
    QPoint previousMousePosition;
    bool shiftButtonPressed;
    bool drawLine;
    bool drawPolygon;
    bool drawBezier;
    bool drawSpline;
    bool drawSquare;
    bool drawCircle;
    bool drawEllipse;
    bool drawSelectionRectangle;
    bool xMove_bool;
    bool yMove_bool;
    bool xScale_bool;
    bool yScale_bool;
    bool drawgrid;
    bool cropActionTrigered;
    bool cropEnabled;
    bool insertTextEnabled;
    bool reflectionEnabled;
    int selectedShapeId_int;
    int glWidgetWidth;
    int glWidgetHeight;
    QShortcut *groupShortcutKey;
    int groupId;
    QUndoView *undoView;
    QFile *currentFile;
    QString currentFileName;
    QList<Vector> vertices;
    QList<Vector> arcVertices;
    QList<Text *> textList;
    bool altKeyPressed;
    int coef[100];
    bool mustSaveBeforeNewOrExit;

    float xCenterOfEllipse;
    float yCenterOfEllipse;
    float widthOfEllipse;
    float heightOfEllipse;

    Ui::Commandform *commandform;
    QDialog *dialog;
    Ui::imageform *imageForm;
    QString imageFileName;
    Ui::textForm *textDialog;

    QTimer *saveTimer;
    bool isSaveTimerActived;
    int saveTimerValue;

    int statusBarLoading;

    QString *textOfInsertedText;
    QFont *fontOfInsertedText;
    float sizeOfInsertedText;
    bool renderInsertedText;
    //------------------------------------------------------------------
public slots:
    void changeCurrentColor(QColor color);
    void attributeEditor();
    void commandOperator();
    void commandOk();
    void commandCancel();
    void newScene();
    void group();
    void aboutQt();
    void aboutMe();
    void ungroup();
    void save();
    void saveAs();
    void saveOnTime();
    void open();
    void print();
    void selectAll();
    void drawGrid();
    void insert();
    void loadImage();
    void loadImageAccept();
    void loadImageReject();
    void exportImage();
    void deleteModel();
    void undo();
    void redo();
    void sendToBack();
    void bringToFront();
    void crop();
    void insertText();
    void reflection();
    void renderTextAccept();
    void renderTextReject();
    void textColorChange();
    void fontChanged(QFont);
    void fontSizeChanged(double);

    void diselectAll();

    void squareMousePressed();
    void squareMouseReleased();

    void bezierMouseReleased();
    void bezierSpaceKeyPressed();

    void circleMousePressed();
    void circleMouseReleased();

    void ellipseMousePressed();
    void ellipseMouseReleased();

    void splineMouseReleased();
    void splineSpaceKeyPressed();

    void lineMouseReleased();
    void lineSpaceKeyPressed();

    void polygonMouseReleased();
    void polygonSpaceKeyPressed();

    void rotateMousePressed();
    void rotateMouseMoved();
    void rotateMouseReleased();

    void selectMousePressed();
    void selectOnePixel();
    void selectRectangular();

    void scaleEnabled();
    void scale();
    void scaleMousePressed();
    void scaleMouseReleased();

    void moveMouseReleased();
    void moveIsSomethingUnderCursor();
    void moveIsModelSelected();
    void moveModel();

    void fillMouseReleased();

    void changeViewMouseReleased();

    void resetEverything();

signals:
    void saveloadingSignal(int);
    void showMessageOnStatusBarSignal(QString, int);

    void mousePressed();
    void mouseMoved();
    void mouseReleased();
    void spaceKeyPressed();
    void endState();
    void somethingUnderCursor();
    void nothingUnderCursor();
    void modelIsSelected();
    void modelIsNotSelected();

    void scaleHandleSelected();
};
#endif // GLWIDGET_H
