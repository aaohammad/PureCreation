#include "glwidget.h"
#include "commands.h"

Glwidget::Glwidget()
{
    /*---gluPerspective arguments---*/
    glOrthoVariable = 0.5;
    zoomFactor = 30;
    sceneTranslateX = 0.0;
    sceneTranslateY = 0.0;
    /*---gluPerspective arguments---*/

    modelManager = new ModelManager();
    undoManager = new UndoManager(modelManager);
    scaleManager = new ScaleManager(this->modelManager, this->undoManager);
    selectManager = new SelectManager(this->modelManager, this->undoManager);
    moveManager = new MoveManager(this->modelManager, this->undoManager);
    rotateManager = new RotateManager(modelManager, undoManager);


    /*---Control keys initialization---*/
    drawSquare = false;
    drawCircle = false;
    drawEllipse = false;
    drawLine = false;
    drawSpline = false;
    drawSelectionRectangle = false;
    drawBezier = false;
    drawPolygon = false;
    shiftButtonPressed = false;
    cropActionTrigered = false;
    cropEnabled  = false;
    xMove_bool = false;
    yMove_bool = false;
    xScale_bool = false;
    yScale_bool = false;
    drawgrid = true;
    insertTextEnabled = false;
    renderInsertedText = false;
    reflectionEnabled = false;
    centerOfSelectionX_double = 0.0;
    centerOfSelectionY_double = 0.0;
    widthOfSelection_double = 0.0;
    heightOfSelection_double = 0.0;
    currentColor = new QColor(Qt::black);
    textColor = new QColor(Qt::green);
    groupShortcutKey = new QShortcut(this);
    groupShortcutKey->setKey(Qt::CTRL + Qt::Key_G);
    groupId = 1;
    currentFile = NULL;
    mustSaveBeforeNewOrExit = false;
    saveTimer = new QTimer(this);
    isSaveTimerActived = true;
    saveTimerValue = 10;
    statusBarLoading = 0;

    saveTimer->singleShot(saveTimerValue * 60000, this, SLOT(saveOnTime()));
    //saveTimer->start();
    /*---Control keys initialization---*/

    /*---Perspective widget initialization functions---*/
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    setMouseTracking(true);
    /*---Perspective widget initialization functions---*/
}

void Glwidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_FLAT);
    glEnable (GL_LINE_STIPPLE);
    glClearColor(0.6, 0.6, 0.6, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Glwidget::paintGL()
{
    scene_Transformations();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(drawgrid)
        draw_Grid();
    draw_List();

    int i = 0;
    while(i != textList.size())
    {
        renderText(textList[i]->x, textList[i]->y, 0.0, textList[i]->str, *textList[i]->font);
        i++;
    }
    if(drawSquare)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        glBegin(GL_QUADS);
        glVertex3d(startPointX, startPointY, 0.0);
        glVertex3d(endPointX, startPointY, 0.0);
        glVertex3d(endPointX, endPointY, 0.0);
        glVertex3d(startPointX, endPointY, 0.0);
        glEnd();
    }
    else if(drawSelectionRectangle)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        glColor3f(0.0, 0.0, 1.0);
        glLineStipple(1, 0xF0F0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(startPointX, startPointY);
        glVertex2d(endPointX, startPointY);
        glVertex2d(endPointX, endPointY);
        glVertex2d(startPointX, endPointY);
        glEnd();
        glColor4f(0.5, 0.5, 0.0, 0.5);
        glLineStipple(1, 0xFFFF);
        glBegin(GL_QUADS);
        glVertex2d(startPointX, startPointY);
        glVertex2d(endPointX, startPointY);
        glVertex2d(endPointX, endPointY);
        glVertex2d(startPointX, endPointY);
        glEnd();
    }
    else if(drawCircle)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(startPointX, startPointY);
        float radius = sqrt( (endPointX - startPointX)*(endPointX - startPointX) + (endPointY - startPointY) * (endPointY - startPointY) );
        for(float angle = 0; angle <= 360; angle += 0.1)
        {
            glVertex2f(startPointX + sin(angle) * radius, startPointY + cos(angle) * radius);
        }
        glEnd();
    }
    else if(drawLine)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        int i = 0;
        glLineWidth(2.0);
        glBegin(GL_LINE_STRIP);
        while(i != vertices.size())
        {
            glVertex2f(vertices[i].x, vertices[i].y);
            i++;
        }
        glEnd();
    }
    else if(drawSpline)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPointSize(5);
        glLineWidth(2);
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        int i = 0;
        while(i != vertices.size())
        {
            glVertex2f(vertices[i].x, vertices[i].y);
            i++;
        }
        glEnd();
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        if(vertices.size() >= 4)
        {
            glBegin(GL_LINE_STRIP);
            for(i = 1 ; i < vertices.size() - 2 ; i++)
            {
                for(int j = 0 ; j != 20 ; j++)
                {
                    float u = (float)j / (20 - 1);
                    float x = 0.5 * (2 * vertices[i].x +
                                     (-1 * vertices[i - 1].x + vertices[i + 1].x) * u +
                                     (2 * vertices[i - 1].x - 5 * vertices[i].x + 4 * vertices[i + 1].x - vertices[i + 2].x) * u * u +
                                     (-1 * vertices[i - 1].x + 3 * vertices[i].x - 3 * vertices[i + 1].x + vertices[i + 2].x) * u * u * u);

                    float y = 0.5 * (2 * vertices[i].y +
                                     (-1 * vertices[i - 1].y + vertices[i + 1].y) * u +
                                     (2 * vertices[i - 1].y - 5 * vertices[i].y + 4 * vertices[i + 1].y - vertices[i + 2].y) * u * u +
                                     (-1 * vertices[i - 1].y + 3 * vertices[i].y - 3 * vertices[i + 1].y + vertices[i + 2].y) * u * u * u);

                    glVertex2f(x , y);
                }
            }
            glEnd();
        }
    }
    else if(drawPolygon)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        int i = 0;
        glLineWidth(2.0);
        glBegin(GL_LINE_STRIP);
        while(i != vertices.size())
        {
            glVertex2f(vertices[i].x, vertices[i].y);
            i++;
        }
        glEnd();
    }
    else if(drawBezier)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glColor3f(1.0, 1.0, 1.0);
        int i = 0;
        glLineWidth(2.0);
        glPointSize(5);
        glBegin(GL_POINTS);
        while(i != vertices.size())
        {
            glVertex2f(vertices[i].x, vertices[i].y);
            i++;
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        i = 0;
        while(i != vertices.size())
        {
            glVertex2f(vertices[i].x, vertices[i].y);
            i++;
        }
        glEnd();
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        float ctrlPoints[vertices.size()][3];
        for(int i = 0; i < vertices.size() ; i++)
        {
            ctrlPoints[i][0] = vertices[i].x;
            ctrlPoints[i][1] = vertices[i].y;
            ctrlPoints[i][2] = 0.0;
        }
        glMap1f(GL_MAP1_VERTEX_3, 0.0f, 100.0f, 3, vertices.size(), &ctrlPoints[0][0]);
        glEnable(GL_MAP1_VERTEX_3);
        glBegin(GL_LINE_STRIP);
        {
            for(int i = 0 ; i <= 100 ; i++)
            {
                glEvalCoord1f(i);
            }
        }
        glEnd();
    }
    else if(drawEllipse)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        glColor3f(currentColor->redF(), currentColor->greenF(), currentColor->blueF());
        xCenterOfEllipse = (endPointX + startPointX) / 2;
        yCenterOfEllipse = (endPointY + startPointY) / 2;
        widthOfEllipse = fabs(endPointX - startPointX) / 2;
        heightOfEllipse = fabs(endPointY - startPointY) / 2;
        glBegin(GL_POLYGON);
        for(float angle = 0; angle <= 360; angle += 0.1)
        {
            glVertex2d(xCenterOfEllipse + cos(angle) * widthOfEllipse, yCenterOfEllipse + sin(angle) * heightOfEllipse);
        }
        glEnd();
    }
    else if(cropEnabled)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        glColor4f(0.0, currentColor->greenF(), 0.0, 0.5);
        glBegin(GL_QUADS);
        glVertex3d(startPointX, startPointY, 0.0);
        glVertex3d(endPointX, startPointY, 0.0);
        glVertex3d(endPointX, endPointY, 0.0);
        glVertex3d(startPointX, endPointY, 0.0);
        glEnd();
    }
    else if(reflectionEnabled)
    {
        glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
        convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
        if(vertices.size() == 1)
        {
            glLineStipple(1, 0xFFFF);
            glBegin(GL_LINES);
            glVertex2d(vertices[0].x, vertices[0].y);
            glVertex2d(endPointX, endPointY);
            glEnd();
        }
    }

    if(controlVariable == ScaleStateActivated)
    {
        glClear(GL_DEPTH_BUFFER_BIT);
        scaleManager->drawHandle(zoomFactor);
    }
    glClear(GL_DEPTH_BUFFER_BIT);
    rotateManager->drawHandle(this->zoomFactor);
}

void Glwidget::resizeGL(int width_int, int height_int)
{
    glWidgetWidth = width_int;
    glWidgetHeight = height_int;
    glViewport(0,0,width_int,height_int);
    aspect = width_int/(float)(height_int ? height_int : 1);
    scene_Transformations();
}

void Glwidget::draw_Grid()
{
    glDisable(GL_DEPTH_TEST);
    glLineStipple(1, 0xFFFF);
    glLineWidth(1.0);
    glPolygonMode(GL_FRONT, GL_LINE);
    float y = -24.0f;
    float x = -24.0f;
    if(glOrthoVariable < 50)
    {
        glColor3f(0.45f, 0.45f, 0.45f);
        for (int j = 0; j < 120 ; j++)// 120 = 24 * 5
        {
            glBegin(GL_QUAD_STRIP);
            for (int i = 0; i <= 120; i++)//120 = 24 * 5
            {
                glVertex2f(x, y);
                glVertex2f(x + 0.4f, y);
                y += 0.4f;
            }
            glEnd();
            y = -24;
            x += 0.4f;
        }
    }
    glColor3f(0.2f, 0.2f, 0.2f);
    x = y = -24.0f;
    for (int j = 0; j < 24; j++)
    {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= 24; i++)
        {
            glVertex2f(x, y);
            glVertex2f(x + 2, y);
            y += 2;
        }
        glEnd();
        y = -24;
        x += 2;
    }
    glEnable(GL_DEPTH_TEST);
}

void Glwidget::scene_Transformations()
{
    glViewport(0, 0, glWidgetWidth, glWidgetHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (glWidgetWidth <= glWidgetHeight)
        glOrtho(-glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, -glOrthoVariable / aspect  * zoomFactor, glOrthoVariable / aspect  * zoomFactor, 1.0, -1.0);
    else
        glOrtho(-glOrthoVariable * aspect  * zoomFactor, glOrthoVariable * aspect  * zoomFactor, -glOrthoVariable * zoomFactor, glOrthoVariable * zoomFactor, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(sceneTranslateX, sceneTranslateY, 0.0);
}

void Glwidget::wheelEvent(QWheelEvent *e)
{
    if(e->delta() > 0)
    {
        if(zoomFactor < 200)
        {
            zoomFactor += 1;
        }
        else
        {
            zoomFactor = 200;
        }
    }
    else if(e->delta() < 0)
    {
        if(zoomFactor >= 2)
        {
            zoomFactor -= 1;
        }
        else
        {
            zoomFactor = 1;
        }
    }
    updateGL();
}

void Glwidget::keyPressEvent(QKeyEvent *e)
{//diableing keyboard repeat in linux keyboard configuration.
    if(e->key() == Qt::Key_Space)
    {
        emit spaceKeyPressed();
    }
    if(e->key() == Qt::Key_Shift)
    {
        shiftButtonPressed = true;
        mustSaveBeforeNewOrExit = true;
        emit showMessageOnStatusBarSignal("Shift Key pressed. You can select multiple Models.", 3000);
    }
    updateGL();//Must be exist.
}

void Glwidget::enterEvent(QEvent *)
{
    setFocus();
}

void Glwidget::mouseMoveEvent(QMouseEvent *)
{
    updateGL();//must be exist.
    emit mouseMoved();
}

void Glwidget::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Shift)
    {
        shiftButtonPressed = false;
    }
}

void Glwidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(cropActionTrigered)
        {
            previousMousePosition = mapFromGlobal(QCursor::pos());
            cropEnabled = true;
            emit showMessageOnStatusBarSignal("Cropping...", 0);
        }
        emit mousePressed();
    }
    updateGL();
}

void Glwidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(cropActionTrigered)
        {
            cropEnabled = false;
            float xCenter = (startPointX + endPointX) / 2;
            float yCenter = (startPointY + endPointY) / 2;
            float width = fabs(startPointX - endPointX) / 2;
            float height = fabs(startPointY - endPointY) / 2;
            glOrthoVariable = width;
            glOrthoVariable = width;
            glOrthoVariable = height;
            glOrthoVariable = height;
            sceneTranslateX = -xCenter;
            sceneTranslateY = -yCenter;
        }
        else if(insertTextEnabled)
        {
            textDialog = new Ui::textForm;
            dialog = new QDialog;
            textDialog->setupUi(dialog);
            float x, y;
            char f = 'f';
            convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
            textDialog->xlineEdit->setText(QString::number(x, f, 2));
            textDialog->ylineEdit->setText(QString::number(y, f, 2));
            QString colorString_QString;
            QColor color(Qt::green);
            colorString_QString.append("background-color: rgb(");
            colorString_QString.append(QString::number(color.red(),10));
            colorString_QString.append(", ");
            colorString_QString.append(QString::number(color.green(),10));
            colorString_QString.append(", ");
            colorString_QString.append(QString::number(color.blue(),10));
            colorString_QString.append(");");
            textDialog->colorpushButton->setStyleSheet(colorString_QString);
            connect(textDialog->okpushButton, SIGNAL(clicked()), this, SLOT(renderTextAccept()));
            connect(textDialog->cancelpushButton, SIGNAL(clicked()), this, SLOT(renderTextReject()));
            connect(textDialog->colorpushButton, SIGNAL(clicked()), this, SLOT(textColorChange()));
            connect(textDialog->fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(fontChanged(QFont)));
            connect(textDialog->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(fontSizeChanged(double)));
            textDialog->doubleSpinBox->setValue(10);
            dialog->exec();
        }
        else if(reflectionEnabled)
        {
            convertWindowCoorToSceneCoor(startPointX, startPointY, mapFromGlobal(QCursor::pos()));
            Vector vect(startPointX, startPointY);
            vertices.append(vect);
            if(vertices.size() == 1)
            {
                emit showMessageOnStatusBarSignal("Select another point.", 0);
            }
            else if(vertices.size() == 2)
            {
                float m = (vertices[0].y - vertices[1].y) / (vertices[0].x - vertices[1].x);
                float n = -m * vertices[0].x + vertices[0].y;
                int i = 0;
                while(i != modelManager->size())
                {
                    Model *s = modelManager->at(i);
                    if(s->getSelected())
                    {
                        s->reflect(m , n);
                        mustSaveBeforeNewOrExit = true;
                    }
                    i++;
                }
                vertices.clear();
                reflectionEnabled = false;
                emit showMessageOnStatusBarSignal("Reflected successfully.", 3000);
            }
        }
        emit mouseReleased();
    }
    updateGL();
}

void Glwidget::fontSizeChanged(double size)
{
    textDialog->textEdit->setFontPointSize(size);
}

void Glwidget::fontChanged(QFont font)
{
    textDialog->textEdit->setFont(font);
}

void Glwidget::renderTextAccept()
{
    textOfInsertedText = new QString(textDialog->textEdit->toPlainText());
    fontOfInsertedText = new QFont(textDialog->fontComboBox->currentFont());
    sizeOfInsertedText = textDialog->doubleSpinBox->value();
    Text *tempText = new Text(*textOfInsertedText, textDialog->xlineEdit->text().toFloat(),
                              textDialog->ylineEdit->text().toFloat(), sizeOfInsertedText, *fontOfInsertedText);
    undoManager->addModel(tempText);
    textList.append(tempText);
    delete dialog;
    delete textOfInsertedText;
    delete fontOfInsertedText;
}

void Glwidget::textColorChange()
{
    QColor color;
    color.setGreenF(this->textColor->greenF());
    color.setRedF(this->textColor->redF());
    color.setBlueF(this->textColor->blueF());
    QColorDialog *colordialog_QColorDialog = new QColorDialog;
    colordialog_QColorDialog->setCurrentColor(color);
    int resultCode = colordialog_QColorDialog->exec();
    if (resultCode == QDialog::Accepted)
        color = colordialog_QColorDialog->selectedColor();
    delete colordialog_QColorDialog;
    QString colorString_QString;
    colorString_QString.append("background-color: rgb(");
    colorString_QString.append(QString::number(color.red(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(color.green(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(color.blue(),10));
    colorString_QString.append(");");
    textDialog->colorpushButton->setStyleSheet(colorString_QString);
    textColor->setGreenF(color.greenF());
    textColor->setRedF(color.redF());
    textColor->setBlueF(color.blueF());
    textDialog->textEdit->setTextColor(*textColor);
}

void Glwidget::renderTextReject()
{
    delete dialog;
}

void Glwidget::diselectAll()
{
    selectManager->diselectAll();
    updateGL();
    drawSelectionRectangle = false;
    emit endState();
}

void Glwidget::selectAll()
{
    selectManager->selectAll();
    drawLine = false;
    drawSpline = false;
    cropActionTrigered = false;
    insertTextEnabled = false;
    reflectionEnabled = false;
    updateGL();
    emit showMessageOnStatusBarSignal("All Models selected.", 3000);
}

void Glwidget::draw_List()
{
    int i = 0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        s->drawObjectSelectMode();
        i++;
    }
}

void Glwidget::convertWindowCoorToSceneCoor(float &x, float &y, QPoint point_on_viewport)
{
    int viewport[4];
    double modelviewMatrix[16];
    double projectionMatrix[16];
    double wx1, wy1, wz1;
    double wx2, wy2, wz2;
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelviewMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
    int realY = viewport[3] - point_on_viewport.y() + 1;
    gluUnProject(point_on_viewport.x(), realY, 0.0, modelviewMatrix, projectionMatrix, viewport, &wx1, &wy1, &wz1);
    gluUnProject(point_on_viewport.x(), realY, 1.0, modelviewMatrix, projectionMatrix, viewport, &wx2, &wy2, &wz2);
    float line_dir_1, line_dir_2, line_dir_3, length;
    line_dir_1 = wx2 - wx1;
    line_dir_2 = wy2 - wy1;
    line_dir_3 = wz2 - wz1;

    length = sqrt(line_dir_1 * line_dir_1 + line_dir_2 * line_dir_2 + line_dir_3 * line_dir_3);
    line_dir_1 = line_dir_1 / length;
    line_dir_2 = line_dir_2 / length;
    line_dir_3 = line_dir_3 / length;

    float d = (-wz1) / (line_dir_3);

    x = (d * line_dir_1 + wx1);
    y = (d * line_dir_2 + wy1);
}

void Glwidget::deleteModel()
{
    int i = 0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            undoManager->deleteModel(s);
            i--;
        }
        i++;
    }
    mustSaveBeforeNewOrExit = true;
    updateGL();
    emit showMessageOnStatusBarSignal("Delete success.", 3000);
}

void Glwidget::redo()
{
    undoManager->redo();
    mustSaveBeforeNewOrExit = true;
    updateGL();
    emit showMessageOnStatusBarSignal("Redo success.", 3000);
}

void Glwidget::undo()
{
    undoManager->undo();
    mustSaveBeforeNewOrExit = true;
    updateGL();
    emit showMessageOnStatusBarSignal("Undo success.", 3000);
}

void Glwidget::group()
{
    int i=0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            s->setGroupID(groupId);
        }
        i++;
    }
    groupId++;
    emit showMessageOnStatusBarSignal("Group success.", 3000);
}

void Glwidget::ungroup()
{
    int i=0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected() == true)
        {
            s->setGroupID(0);
        }
        i++;
    }
    diselectAll();
    emit showMessageOnStatusBarSignal("Ungroup success.", 3000);
}

void Glwidget::save()
{
    if(!currentFile)
    {
        saveAs();
    }
    else
    {
        saveFile(currentFileName);
    }
}

void Glwidget::saveOnTime()
{
    QFile *recoveryFile = new QFile("recovery.ge");
    QString fileName = recoveryFile->fileName();
    if (!recoveryFile->open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Recent Files"),tr("Cannot write file %1:\n%2.").arg(fileName).arg(recoveryFile->errorString()));
        return;
    }
    QTextStream *out = new QTextStream(recoveryFile);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    int i = 0;
    int sceneListSize = modelManager->size();
    while(i != sceneListSize)
    {
        Model *s = modelManager->at(i);
        s->save(out);
        statusBarLoading = (i * 100) / sceneListSize;
        i++;
        emit saveloadingSignal(statusBarLoading);
    }
    QString eof("EndOfFile");
    (*out) << eof;
    emit saveloadingSignal(100);
    recoveryFile->close();
    emit saveloadingSignal(-1);
    emit showMessageOnStatusBarSignal("Current scene saved!", 3000);
    QApplication::restoreOverrideCursor();
}

void Glwidget::saveAs()
{
    currentFileName = QFileDialog::getSaveFileName();
    if (currentFileName.isEmpty())
        return;
    if(!currentFileName.endsWith(".ge", Qt::CaseInsensitive))
        currentFileName.append(".ge");
    saveFile(currentFileName);
    mustSaveBeforeNewOrExit = false;
}

void Glwidget::saveFile(const QString &fileName)
{
    QFile *file = new QFile(fileName);
    if (!file->open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Recent Files"),tr("Cannot write file %1:\n%2.").arg(fileName).arg(file->errorString()));
        return;
    }
    currentFile = file;
    currentFileName = fileName;
    QTextStream *out = new QTextStream(file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    int i = 0;
    int sceneListSize = modelManager->size();
    while(i != sceneListSize)
    {
        Model *s = modelManager->at(i);
        s->save(out);
        statusBarLoading = (i * 100) / sceneListSize;
        i++;
        emit saveloadingSignal(statusBarLoading);
    }
    QString eof("EndOfFile");
    (*out) << eof;
    emit saveloadingSignal(100);
    file->close();
    emit saveloadingSignal(-1);
    emit showMessageOnStatusBarSignal("Current scene saved!", 3000);
    QApplication::restoreOverrideCursor();
}

void Glwidget::changeCurrentColor(QColor color)
{
    currentColor->setRedF(color.redF());
    currentColor->setGreenF(color.greenF());
    currentColor->setBlueF(color.blueF());
    int i=0;
    while(i != modelManager->size())
    {
        Model *s = modelManager->at(i);
        if(s->getSelected())
        {
            s->setColor(currentColor);
            emit showMessageOnStatusBarSignal("Color changed.", 3000);
        }
        i++;
    }
    updateGL();
}

void Glwidget::squareMousePressed()
{
    drawSquare = true;
    previousMousePosition = mapFromGlobal(QCursor::pos());
    emit showMessageOnStatusBarSignal("Drawing Square...", 0);
}

void Glwidget::squareMouseReleased()
{
    drawSquare = false;
    Square *tempSquare = new Square(startPointX, startPointY, endPointX, endPointY);
    tempSquare->setColor(currentColor);
    undoManager->addModel(tempSquare);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Square created.", 3000);
    emit endState();
}

void Glwidget::bezierMouseReleased()
{
    drawBezier = true;
    convertWindowCoorToSceneCoor(startPointX, startPointY, mapFromGlobal(QCursor::pos()));
    Vector vect(startPointX, startPointY);
    vertices.append(vect);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Drawing Bezier...(Press \"space\" to finish.)", 0);
}

void Glwidget::bezierSpaceKeyPressed()
{
    drawBezier = false;
    Bezier *tempBezier = new Bezier(vertices);
    tempBezier->setColor(currentColor);
    undoManager->addModel(tempBezier);
    vertices.clear();
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Bezier created.", 3000);
    emit endState();
}

void Glwidget::circleMousePressed()
{
    drawCircle = true;
    previousMousePosition = mapFromGlobal(QCursor::pos());
    emit showMessageOnStatusBarSignal("Drawing Circle...", 0);
}

void Glwidget::circleMouseReleased()
{
    drawCircle = false;
    float radius = sqrt( (endPointX - startPointX)*(endPointX - startPointX) + (endPointY - startPointY) * (endPointY - startPointY) );
    Circle *tempCircle = new Circle(startPointX, startPointY, radius);
    tempCircle->setColor(currentColor);
    undoManager->addModel(tempCircle);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Circle created.", 3000);
    emit endState();
}

void Glwidget::ellipseMousePressed()
{
    drawEllipse = true;
    previousMousePosition = mapFromGlobal(QCursor::pos());
    emit showMessageOnStatusBarSignal("Drawing Ellipse...", 0);
}

void Glwidget::ellipseMouseReleased()
{
    drawEllipse = false;
    convertWindowCoorToSceneCoor(startPointX, startPointY, previousMousePosition);
    convertWindowCoorToSceneCoor(endPointX, endPointY, mapFromGlobal(QCursor::pos()));
    xCenterOfEllipse = (endPointX + startPointX) / 2;
    yCenterOfEllipse = (endPointY + startPointY) / 2;
    widthOfEllipse = fabs(endPointX - startPointX) / 2;
    heightOfEllipse = fabs(endPointY - startPointY) / 2;
    Ellipse *tempEllipse = new Ellipse(xCenterOfEllipse, yCenterOfEllipse, widthOfEllipse, heightOfEllipse);
    tempEllipse->setColor(currentColor);
    undoManager->addModel(tempEllipse);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Ellipse created.", 3000);
    emit endState();
}

void Glwidget::splineMouseReleased()
{
    drawSpline = true;
    convertWindowCoorToSceneCoor(startPointX, startPointY, mapFromGlobal(QCursor::pos()));
    Vector vect(startPointX, startPointY);
    vertices.append(vect);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Drawing Spline...(Press \"space\" to finish.)", 0);
}

void Glwidget::splineSpaceKeyPressed()
{
    drawSpline = false;
    Spline *tempSpline = new Spline(vertices);
    tempSpline->setColor(currentColor);
    undoManager->addModel(tempSpline);
    vertices.clear();
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Spline created.", 3000);
    emit endState();
}

void Glwidget::lineMouseReleased()
{
    drawLine = true;
    convertWindowCoorToSceneCoor(startPointX, startPointY, mapFromGlobal(QCursor::pos()));
    Vector vect(startPointX, startPointY);
    vertices.append(vect);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Drawing Line...(Press \"space\" to finish.)", 0);
}

void Glwidget::lineSpaceKeyPressed()
{
    drawLine = false;
    Line *tempLine = new Line(vertices);
    tempLine->setColor(currentColor);
    undoManager->addModel(tempLine);
    vertices.clear();
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Line created.", 3000);
    emit endState();
}

void Glwidget::polygonMouseReleased()
{
    drawPolygon = true;
    convertWindowCoorToSceneCoor(startPointX, startPointY, mapFromGlobal(QCursor::pos()));
    Vector vect(startPointX, startPointY);
    vertices.append(vect);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Drawing Polygon...(Press \"space\" to finish.)", 0);
}

void Glwidget::polygonSpaceKeyPressed()
{
    drawPolygon = false;
    Polygon *tempPolygon = new Polygon(vertices);
    tempPolygon->setColor(currentColor);
    undoManager->addModel(tempPolygon);
    vertices.clear();
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Polygon created.", 3000);
    emit endState();
}

void Glwidget::rotateMousePressed()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    rotateManager->mousePressed(x, y);
    emit showMessageOnStatusBarSignal("Rotating...", 0);
}

void Glwidget::rotateMouseMoved()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    rotateManager->mouseMoved(x, y);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Rotating...", 0);
}

void Glwidget::rotateMouseReleased()
{
    rotateManager->mouseReleased();
    emit endState();
}

void Glwidget::selectMousePressed()
{
    drawSelectionRectangle = true;
    previousMousePosition = mapFromGlobal(QCursor::pos());
    emit showMessageOnStatusBarSignal("Selecting...", 0);
}

void Glwidget::selectOnePixel()
{
    drawSelectionRectangle = false;
    if(!shiftButtonPressed)
    {
        selectManager->diselectAll();
    }
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    selectManager->pointSelection(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    moveManager->mousePressed(x, y);
    emit endState();
}

void Glwidget::selectRectangular()
{
    drawSelectionRectangle = false;
    if(!shiftButtonPressed)
         selectManager->diselectAll();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    selectManager->rectangualrSelection(previousMousePosition.x(), previousMousePosition.y(),
                                        mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(),
                                        viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    emit endState();
}

//void Glwidget::scaleMouseMoved()
//{
//    float x, y;
//    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
//    scaleManager->mouseMoved(x, y);
//    mustSaveBeforeNewOrExit = true;
//    emit showMessageOnStatusBarSignal("Scaling...", 0);
//}

void Glwidget::moveMouseReleased()
{
    moveManager->mouseReleased();
    emit endState();
}

void Glwidget::changeViewMouseReleased()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    sceneTranslateX = -x;
    sceneTranslateY = -y;
    emit endState();
    emit showMessageOnStatusBarSignal("View changed successfully.", 3000);
}

void Glwidget::fillMouseReleased()
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    int selectedModelIndex = selectManager->getSelectedModelIndex(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    modelManager->at(selectedModelIndex)->setColor(currentColor);
    mustSaveBeforeNewOrExit = true;
    emit showMessageOnStatusBarSignal("Color filled successfully.", 3000);
    emit endState();
}

void Glwidget::moveIsSomethingUnderCursor()
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    bool anyModelSelected = selectManager->isSomethingUnderCursor(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    if(anyModelSelected)
        emit somethingUnderCursor();
    else
        emit nothingUnderCursor();
}

void Glwidget::moveIsModelSelected()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    moveManager->mousePressed(x, y);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    bool isSelected = selectManager->isModelUnderCursorSelected(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
    if(isSelected)
        emit modelIsSelected();
    else
        emit modelIsNotSelected();
}

void Glwidget::moveModel()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    moveManager->mouseMoved(x, y);
    mustSaveBeforeNewOrExit = true;
    updateGL();
    emit showMessageOnStatusBarSignal("Moving...", 0);
}

void Glwidget::scaleEnabled()
{
    this->controlVariable = ScaleStateActivated;
    updateGL();
}

void Glwidget::scale()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    scaleManager->mouseMoved(x, y);
}

void Glwidget::scaleMousePressed()
{
    float x, y;
    convertWindowCoorToSceneCoor(x, y, mapFromGlobal(QCursor::pos()));
    if(!scaleManager->isSelected(x, y))
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        bool isSomethingUnderCursor = selectManager->isSomethingUnderCursor(mapFromGlobal(QCursor::pos()).x(), mapFromGlobal(QCursor::pos()).y(), viewport, glWidgetWidth, glWidgetHeight, glOrthoVariable, zoomFactor);
        if(isSomethingUnderCursor)
        {
            emit somethingUnderCursor();
        }
        else
        {
            emit nothingUnderCursor();
        }
    }
    else
    {
        scaleManager->mousePressed(x, y);
        emit scaleHandleSelected();
        emit showMessageOnStatusBarSignal("Scaling...", 0);
    }
}

void Glwidget::scaleMouseReleased()
{
    scaleManager->mouseReleased();
    emit endState();
}

void Glwidget::resetEverything()
{
    this->controlVariable = NothingActivated;
}
