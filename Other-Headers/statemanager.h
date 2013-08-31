#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "ui_mainwindow.h"
#include "glwidget.h"

class StateManager
{
public:
    StateManager(Ui::MainWindow *ui, Glwidget *gLwidget);
private:
    void connections();
    void addTransitions();
    void addState();
    Ui::MainWindow *ui;
    Glwidget *gLWidget;

    //State declaration
    QStateMachine stateMachine;

    //Square Drawing States
    QState *squareDrawingEnabledState;
    QState *squareMousePressState;
    QState *squareMouseMoveState;
    QState *squareMouseReleaseState;
    //END of Square Drawing States

    //Bezier Drawing States
    QState *bezierDrawingEnabledState;
    QState *bezierMouseReleaseState;
    QState *bezierSpaceKeyPressedState;
    //END of Bezier Drawing States

    //Circle Drawing States
    QState *circleDrawingEnabledState;
    QState *circleMousePressState;
    QState *circleMouseMoveState;
    QState *circleMouseReleaseState;
    //END of Circle Drawing States

    //Ellipse Drawing States
    QState *ellipseDrawingEnabledState;
    QState *ellipseMousePressState;
    QState *ellipseMouseMoveState;
    QState *ellipseMouseReleaseState;
    //END of Ellipse Drawing States

    //Spline Drawing States
    QState *splineDrawingEnabledState;
    QState *splineMouseReleaseState;
    QState *splineSpaceKeyPressedState;
    //END of Spline Drawing States

    //Line Drawing States
    QState *lineDrawingEnabledState;
    QState *lineMouseReleaseState;
    QState *lineSpaceKeyPressedState;
    //END of Line Drawing States

    //Polygon Drawing States
    QState *polygonDrawingEnabledState;
    QState *polygonMouseReleaseState;
    QState *polygonSpaceKeyPressedState;
    //END of Polygon Drawing States

    //Rotate States
    QState *rotateEnabledState;
    QState *rotateMousePressedState;
    QState *rotateMouseMovedState;
    QState *rotateMouseReleaseState;
    //END of Rotate States

    //Select States
    QState *selectEnabledState;
    QState *selectMousePressedState;
    QState *selectMouseMoveState;
    QState *selectOnePixelState;
    QState *selectRectangularState;
    //END of Select States

    //Scale States
    QState *scaleEnabledState;
    QState *scaleNothingSelectedState;
    QState *scaleDiselectAllState;
    QState *scaleSelectWhileScale;
    QState *scaleSelectRectangularState;
    QState *scaleSelectModelState;
    QState *scaleState;
    QState *scaleMovingState;
    QState *scaleMouseReleaseState;
    QState *scaleMousePressedState;
    //END of Scale States

    //Scale States
    QState *moveEnabledState;
    QState *moveMouseMovedState;
    QState *moveSelectWhileMoveState;
    QState *moveMouseReleaseState;
    QState *moveIsSomethingUnderCursorState;
    QState *moveIsModelSelectedState;
    QState *moveNothingSelectedState;
    QState *moveDiselectAllState;
    QState *moveRectangularSelectionState;
    QState *moveSelectRectangularState;
    QState *moveSelectModelState;
    QState *moveMoveModelState;
    QState *moveReadyToMoveState;
    //END of Scale States

    //Change View States
    QState *changeViewEnabledState;
    QState *changeViewMouseReleaseState;
    //END of Change View States

    //Fill Color States
    QState *fillColorEnabledState;
    QState *fillColorMouseReleasedState;
    //END of Fill Color States

    //END of State declaration
};

#endif // STATEMANAGER_H
