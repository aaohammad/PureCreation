#include "statemanager.h"

StateManager::StateManager(Ui::MainWindow *ui, Glwidget *gLWidget)
{
    this->ui = ui;
    this->gLWidget = gLWidget;

    squareDrawingEnabledState  = new QState();
    squareMousePressState = new QState();
    squareMouseMoveState = new QState();
    squareMouseReleaseState  = new QState();

    bezierDrawingEnabledState = new QState();
    bezierMouseReleaseState = new QState();
    bezierSpaceKeyPressedState = new QState();

    circleDrawingEnabledState = new QState();
    circleMouseMoveState = new QState();
    circleMousePressState = new QState();
    circleMouseReleaseState = new QState();

    ellipseDrawingEnabledState = new QState();
    ellipseMouseMoveState = new QState();
    ellipseMousePressState = new QState();
    ellipseMouseReleaseState = new QState();

    splineDrawingEnabledState = new QState();
    splineMouseReleaseState = new QState();
    splineSpaceKeyPressedState = new QState();

    lineDrawingEnabledState = new QState();
    lineMouseReleaseState = new QState();
    lineSpaceKeyPressedState = new QState();

    polygonDrawingEnabledState = new QState();
    polygonMouseReleaseState = new QState();
    polygonSpaceKeyPressedState = new QState();

    rotateEnabledState = new QState();
    rotateMouseMovedState = new QState();
    rotateMousePressedState = new QState();
    rotateMouseReleaseState = new QState();

    selectEnabledState = new QState();
    selectMouseMoveState = new QState();
    selectMousePressedState = new QState();
    selectOnePixelState = new QState();
    selectRectangularState = new QState();

    scaleEnabledState = new QState();
    scaleNothingSelectedState = new QState();
    scaleDiselectAllState = new QState();
    scaleSelectWhileScale = new QState();
    scaleSelectRectangularState = new QState();
    scaleSelectModelState = new QState();
    scaleState = new QState();
    scaleMovingState = new QState();
    scaleMouseReleaseState = new QState();
    scaleMousePressedState = new QState();

    moveEnabledState = new QState();
    moveMouseMovedState = new QState();
    moveSelectWhileMoveState = new QState();
    moveMouseReleaseState = new QState();
    moveIsSomethingUnderCursorState = new QState();
    moveIsModelSelectedState = new QState();
    moveNothingSelectedState = new QState();
    moveDiselectAllState = new QState();
    moveRectangularSelectionState = new QState();
    moveSelectRectangularState = new QState();
    moveSelectModelState = new QState();
    moveMoveModelState = new QState();
    moveReadyToMoveState = new QState();

    changeViewEnabledState = new QState();
    changeViewMouseReleaseState = new QState();

    fillColorEnabledState = new QState();
    fillColorMouseReleasedState = new QState();

    addTransitions();
    addState();

    stateMachine.setInitialState(selectEnabledState);
    stateMachine.start();

    connections();
}

void StateManager::connections()
{
    QObject::connect(squareDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(squareMousePressState, SIGNAL(entered()), gLWidget, SLOT(squareMousePressed()));
    QObject::connect(squareMouseMoveState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(squareMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(squareMouseReleased()));

    QObject::connect(bezierDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(bezierMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(bezierMouseReleased()));
    QObject::connect(bezierMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(bezierSpaceKeyPressedState, SIGNAL(entered()), gLWidget, SLOT(bezierSpaceKeyPressed()));

    QObject::connect(circleDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(circleMousePressState, SIGNAL(entered()), gLWidget, SLOT(circleMousePressed()));
    QObject::connect(circleMouseMoveState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(circleMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(circleMouseReleased()));

    QObject::connect(ellipseDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(ellipseMousePressState, SIGNAL(entered()), gLWidget, SLOT(ellipseMousePressed()));
    QObject::connect(ellipseMouseMoveState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(ellipseMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(ellipseMouseReleased()));

    QObject::connect(splineDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(splineMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(splineMouseReleased()));
    QObject::connect(splineMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(splineSpaceKeyPressedState, SIGNAL(entered()), gLWidget, SLOT(splineSpaceKeyPressed()));

    QObject::connect(lineDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(lineMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(lineMouseReleased()));
    QObject::connect(lineMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(lineSpaceKeyPressedState, SIGNAL(entered()), gLWidget, SLOT(lineSpaceKeyPressed()));

    QObject::connect(polygonDrawingEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(polygonMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(polygonMouseReleased()));
    QObject::connect(polygonMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(polygonSpaceKeyPressedState, SIGNAL(entered()), gLWidget, SLOT(polygonSpaceKeyPressed()));

    QObject::connect(rotateMousePressedState, SIGNAL(entered()), gLWidget, SLOT(rotateMousePressed()));
    QObject::connect(rotateMouseMovedState, SIGNAL(entered()), gLWidget, SLOT(rotateMouseMoved()));
    QObject::connect(rotateMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(rotateMouseReleased()));

    QObject::connect(selectMousePressedState, SIGNAL(entered()), gLWidget, SLOT(selectMousePressed()));
    QObject::connect(selectMouseMoveState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(selectOnePixelState, SIGNAL(entered()), gLWidget, SLOT(selectOnePixel()));
    QObject::connect(selectRectangularState, SIGNAL(entered()), gLWidget, SLOT(selectRectangular()));

    QObject::connect(scaleEnabledState, SIGNAL(entered()), gLWidget, SLOT(scaleEnabled()));
    QObject::connect(scaleMousePressedState, SIGNAL(entered()), gLWidget, SLOT(scaleMousePressed()));
    QObject::connect(scaleNothingSelectedState, SIGNAL(entered()), gLWidget, SLOT(selectMousePressed()));
    QObject::connect(scaleDiselectAllState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(scaleSelectWhileScale, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(scaleSelectRectangularState, SIGNAL(entered()), gLWidget, SLOT(selectRectangular()));
    QObject::connect(scaleSelectModelState, SIGNAL(entered()), gLWidget, SLOT(selectOnePixel()));
    QObject::connect(scaleMovingState, SIGNAL(entered()), gLWidget, SLOT(scale()));
    QObject::connect(scaleMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(scaleMouseReleased()));

    QObject::connect(moveIsSomethingUnderCursorState, SIGNAL(entered()), gLWidget, SLOT(moveIsSomethingUnderCursor()));
    QObject::connect(moveIsModelSelectedState, SIGNAL(entered()), gLWidget, SLOT(moveIsModelSelected()));
    QObject::connect(moveMoveModelState, SIGNAL(entered()), gLWidget, SLOT(moveModel()));
    QObject::connect(moveMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(moveMouseReleased()));
    QObject::connect(moveSelectModelState, SIGNAL(entered()), gLWidget, SLOT(selectOnePixel()));
    QObject::connect(moveDiselectAllState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(moveNothingSelectedState, SIGNAL(entered()), gLWidget, SLOT(selectMousePressed()));
    QObject::connect(moveSelectWhileMoveState, SIGNAL(entered()), gLWidget, SLOT(updateGL()));
    QObject::connect(moveRectangularSelectionState, SIGNAL(entered()), gLWidget, SLOT(selectRectangular()));

    QObject::connect(changeViewEnabledState, SIGNAL(entered()), gLWidget, SLOT(diselectAll()));
    QObject::connect(changeViewMouseReleaseState, SIGNAL(entered()), gLWidget, SLOT(changeViewMouseReleased()));

    QObject::connect(fillColorMouseReleasedState, SIGNAL(entered()), gLWidget, SLOT(fillMouseReleased()));
}

void StateManager::addTransitions()
{
    selectEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    moveEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    rotateEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    scaleEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->square_toolButton, SIGNAL(clicked()), squareDrawingEnabledState);
    squareDrawingEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), squareMousePressState);
    squareMousePressState->addTransition(gLWidget, SIGNAL(mouseMoved()), squareMouseMoveState);
    squareMousePressState->addTransition(gLWidget, SIGNAL(mouseReleased()), squareDrawingEnabledState);
    squareMouseMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), squareMouseMoveState);
    squareMouseMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), squareMouseReleaseState);
    squareMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    moveEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    rotateEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    scaleEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->bezier_toolButton, SIGNAL(clicked()), bezierDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), bezierMouseReleaseState);
    bezierMouseReleaseState->addTransition(gLWidget, SIGNAL(mouseReleased()), bezierMouseReleaseState);
    bezierMouseReleaseState->addTransition(gLWidget, SIGNAL(spaceKeyPressed()), bezierSpaceKeyPressedState);
    bezierSpaceKeyPressedState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    moveEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    rotateEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    scaleEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->circle_toolButton, SIGNAL(clicked()), circleDrawingEnabledState);
    circleDrawingEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), circleMousePressState);
    circleMousePressState->addTransition(gLWidget, SIGNAL(mouseMoved()), circleMouseMoveState);
    circleMouseMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), circleMouseMoveState);
    circleMousePressState->addTransition(gLWidget, SIGNAL(mouseReleased()), circleDrawingEnabledState);
    circleMouseMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), circleMouseReleaseState);
    circleMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    moveEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    rotateEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    scaleEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->ellipse_toolButton, SIGNAL(clicked()), ellipseDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), ellipseMousePressState);
    ellipseMousePressState->addTransition(gLWidget, SIGNAL(mouseMoved()), ellipseMouseMoveState);
    ellipseMouseMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), ellipseMouseMoveState);
    ellipseMousePressState->addTransition(gLWidget, SIGNAL(mouseReleased()), ellipseDrawingEnabledState);
    ellipseMouseMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), ellipseMouseReleaseState);
    ellipseMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    moveEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    rotateEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    scaleEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->spline_toolButton, SIGNAL(clicked()), splineDrawingEnabledState);
    splineDrawingEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), splineMouseReleaseState);
    splineMouseReleaseState->addTransition(gLWidget, SIGNAL(mouseReleased()), splineMouseReleaseState);
    splineMouseReleaseState->addTransition(gLWidget, SIGNAL(spaceKeyPressed()), splineSpaceKeyPressedState);
    splineSpaceKeyPressedState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    moveEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    rotateEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    scaleEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->line_toolButton, SIGNAL(clicked()), lineDrawingEnabledState);
    lineDrawingEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), lineMouseReleaseState);
    lineMouseReleaseState->addTransition(gLWidget, SIGNAL(mouseReleased()), lineMouseReleaseState);
    lineMouseReleaseState->addTransition(gLWidget, SIGNAL(spaceKeyPressed()), lineSpaceKeyPressedState);
    lineSpaceKeyPressedState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    bezierDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    changeViewEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    circleDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    fillColorEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    lineDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    moveEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    rotateEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    scaleEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    splineDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    squareDrawingEnabledState->addTransition(ui->polygon_toolButton, SIGNAL(clicked()), polygonDrawingEnabledState);
    polygonDrawingEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), polygonMouseReleaseState);
    polygonMouseReleaseState->addTransition(gLWidget, SIGNAL(mouseReleased()), polygonMouseReleaseState);
    polygonMouseReleaseState->addTransition(gLWidget, SIGNAL(spaceKeyPressed()), polygonSpaceKeyPressedState);
    polygonSpaceKeyPressedState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    bezierDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    changeViewEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    circleDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    fillColorEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    lineDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    moveEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    polygonDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    scaleEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    splineDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    squareDrawingEnabledState->addTransition(ui->rotateSelected_toolButton, SIGNAL(clicked()), rotateEnabledState);
    rotateEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), rotateMousePressedState);
    rotateMousePressedState->addTransition(gLWidget, SIGNAL(mouseReleased()), rotateEnabledState);
    rotateMousePressedState->addTransition(gLWidget, SIGNAL(mouseMoved()), rotateMouseMovedState);
    rotateMouseMovedState->addTransition(gLWidget, SIGNAL(mouseMoved()), rotateMouseMovedState);
    rotateMouseMovedState->addTransition(gLWidget, SIGNAL(mouseReleased()), rotateMouseReleaseState);
    rotateMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), rotateEnabledState);

    bezierDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    circleDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    changeViewEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    fillColorEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    lineDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    moveEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    rotateEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    polygonDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    scaleEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    splineDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    squareDrawingEnabledState->addTransition(ui->selection_toolButton, SIGNAL(clicked()), selectEnabledState);
    selectEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), selectMousePressedState);
    selectMousePressedState->addTransition(gLWidget, SIGNAL(mouseReleased()), selectOnePixelState);
    selectMousePressedState->addTransition(gLWidget, SIGNAL(mouseMoved()), selectMouseMoveState);
    selectMouseMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), selectMouseMoveState);
    selectMouseMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), selectRectangularState);
    selectOnePixelState->addTransition(gLWidget, SIGNAL(endState()), selectEnabledState);
    selectRectangularState->addTransition(gLWidget, SIGNAL(endState()), selectEnabledState);

    selectEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    bezierDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    changeViewEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    circleDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    fillColorEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    lineDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    moveEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    polygonDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    rotateEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    splineDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    squareDrawingEnabledState->addTransition(ui->scaleSelected_toolButton, SIGNAL(clicked()), scaleEnabledState);
    scaleEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), scaleMousePressedState);
    scaleMousePressedState->addTransition(gLWidget, SIGNAL(nothingUnderCursor()), scaleNothingSelectedState);
    scaleNothingSelectedState->addTransition(gLWidget, SIGNAL(mouseMoved()), scaleSelectWhileScale);
    scaleSelectWhileScale->addTransition(gLWidget, SIGNAL(mouseMoved()), scaleSelectWhileScale);
    scaleSelectWhileScale->addTransition(gLWidget, SIGNAL(mouseReleased()), scaleSelectRectangularState);
    scaleSelectRectangularState->addTransition(gLWidget, SIGNAL(endState()), scaleEnabledState);
    scaleNothingSelectedState->addTransition(gLWidget, SIGNAL(mouseReleased()), scaleDiselectAllState);
    scaleDiselectAllState->addTransition(gLWidget, SIGNAL(endState()), scaleEnabledState);
    scaleMousePressedState->addTransition(gLWidget, SIGNAL(somethingUnderCursor()), scaleSelectModelState);
    scaleSelectModelState->addTransition(gLWidget, SIGNAL(mouseReleased()), scaleEnabledState);
    scaleMousePressedState->addTransition(gLWidget, SIGNAL(scaleHandleSelected()), scaleMovingState);
    scaleMovingState->addTransition(gLWidget, SIGNAL(mouseMoved()), scaleMovingState);
    scaleMovingState->addTransition(gLWidget, SIGNAL(mouseReleased()), scaleMouseReleaseState);
    scaleMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), scaleEnabledState);

    selectEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    bezierDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    changeViewEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    circleDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    fillColorEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    lineDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    polygonDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    rotateEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    scaleEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    splineDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    squareDrawingEnabledState->addTransition(ui->moveSelected_toolButton, SIGNAL(clicked()), moveEnabledState);
    moveEnabledState->addTransition(gLWidget, SIGNAL(mousePressed()), moveIsSomethingUnderCursorState);
    moveIsSomethingUnderCursorState->addTransition(gLWidget, SIGNAL(somethingUnderCursor()), moveIsModelSelectedState);
    moveIsModelSelectedState->addTransition(gLWidget, SIGNAL(modelIsSelected()), moveReadyToMoveState);
    moveReadyToMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), moveMoveModelState);
    moveMoveModelState->addTransition(gLWidget, SIGNAL(mouseMoved()), moveMoveModelState);
    moveMoveModelState->addTransition(gLWidget, SIGNAL(mouseReleased()), moveMouseReleaseState);
    moveMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);
    moveReadyToMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), moveEnabledState);
    moveIsModelSelectedState->addTransition(gLWidget, SIGNAL(modelIsNotSelected()), moveSelectModelState);
    moveSelectModelState->addTransition(gLWidget, SIGNAL(endState()), moveReadyToMoveState);
    moveIsSomethingUnderCursorState->addTransition(gLWidget, SIGNAL(nothingUnderCursor()), moveNothingSelectedState);
    moveNothingSelectedState->addTransition(gLWidget, SIGNAL(mouseReleased()), moveDiselectAllState);
    moveDiselectAllState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);
    moveNothingSelectedState->addTransition(gLWidget, SIGNAL(mouseMoved()), moveSelectWhileMoveState);
    moveSelectWhileMoveState->addTransition(gLWidget, SIGNAL(mouseMoved()), moveSelectWhileMoveState);
    moveSelectWhileMoveState->addTransition(gLWidget, SIGNAL(mouseReleased()), moveRectangularSelectionState);
    moveRectangularSelectionState->addTransition(gLWidget, SIGNAL(endState()), moveEnabledState);

    selectEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    bezierDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    circleDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    fillColorEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    lineDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    moveEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    polygonDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    rotateEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    scaleEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    splineDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    squareDrawingEnabledState->addTransition(ui->zoom_toolButton, SIGNAL(clicked()), changeViewEnabledState);
    changeViewEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), changeViewMouseReleaseState);
    changeViewMouseReleaseState->addTransition(gLWidget, SIGNAL(endState()), changeViewEnabledState);

    selectEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    bezierDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    changeViewEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    circleDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    ellipseDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    lineDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    moveEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    polygonDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    rotateEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    scaleEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    splineDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    squareDrawingEnabledState->addTransition(ui->colorWidget->colorPickerWidget->fillColor, SIGNAL(clicked()), fillColorEnabledState);
    fillColorEnabledState->addTransition(gLWidget, SIGNAL(mouseReleased()), fillColorMouseReleasedState);
    fillColorMouseReleasedState->addTransition(gLWidget, SIGNAL(endState()), fillColorEnabledState);
}

void StateManager::addState()
{
    stateMachine.addState(squareDrawingEnabledState);
    stateMachine.addState(squareMousePressState);
    stateMachine.addState(squareMouseMoveState);
    stateMachine.addState(squareMouseReleaseState);

    stateMachine.addState(bezierDrawingEnabledState);
    stateMachine.addState(bezierSpaceKeyPressedState);
    stateMachine.addState(bezierMouseReleaseState);

    stateMachine.addState(circleDrawingEnabledState);
    stateMachine.addState(circleMouseMoveState);
    stateMachine.addState(circleMousePressState);
    stateMachine.addState(circleMouseReleaseState);

    stateMachine.addState(ellipseDrawingEnabledState);
    stateMachine.addState(ellipseMouseMoveState);
    stateMachine.addState(ellipseMousePressState);
    stateMachine.addState(ellipseMouseReleaseState);

    stateMachine.addState(splineDrawingEnabledState);
    stateMachine.addState(splineSpaceKeyPressedState);
    stateMachine.addState(splineMouseReleaseState);

    stateMachine.addState(lineDrawingEnabledState);
    stateMachine.addState(lineSpaceKeyPressedState);
    stateMachine.addState(lineMouseReleaseState);

    stateMachine.addState(polygonDrawingEnabledState);
    stateMachine.addState(polygonSpaceKeyPressedState);
    stateMachine.addState(polygonMouseReleaseState);

    stateMachine.addState(rotateEnabledState);
    stateMachine.addState(rotateMouseMovedState);
    stateMachine.addState(rotateMousePressedState);
    stateMachine.addState(rotateMouseReleaseState);

    stateMachine.addState(selectEnabledState);
    stateMachine.addState(selectMouseMoveState);
    stateMachine.addState(selectMousePressedState);
    stateMachine.addState(selectOnePixelState);
    stateMachine.addState(selectRectangularState);

    stateMachine.addState(scaleEnabledState);
    stateMachine.addState(scaleNothingSelectedState);
    stateMachine.addState(scaleDiselectAllState);
    stateMachine.addState(scaleSelectWhileScale);
    stateMachine.addState(scaleSelectRectangularState);
    stateMachine.addState(scaleSelectModelState);
    stateMachine.addState(scaleState);
    stateMachine.addState(scaleMovingState);
    stateMachine.addState(scaleMouseReleaseState);
    stateMachine.addState(scaleMousePressedState);

    stateMachine.addState(moveEnabledState);
    stateMachine.addState(moveMouseMovedState);
    stateMachine.addState(moveSelectWhileMoveState);
    stateMachine.addState(moveMouseReleaseState);
    stateMachine.addState(moveIsSomethingUnderCursorState);
    stateMachine.addState(moveIsModelSelectedState);
    stateMachine.addState(moveNothingSelectedState);
    stateMachine.addState(moveDiselectAllState);
    stateMachine.addState(moveRectangularSelectionState);
    stateMachine.addState(moveSelectRectangularState);
    stateMachine.addState(moveSelectModelState);
    stateMachine.addState(moveMoveModelState);
    stateMachine.addState(moveReadyToMoveState);

    stateMachine.addState(changeViewEnabledState);
    stateMachine.addState(changeViewMouseReleaseState);

    stateMachine.addState(fillColorEnabledState);
    stateMachine.addState(fillColorMouseReleasedState);
}
