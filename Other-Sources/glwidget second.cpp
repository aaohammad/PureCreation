#include "glwidget.h"
#include "commands.h"

void Glwidget::open()
{
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QString fileName = fileDialog.getOpenFileName();
    if(!fileName.isEmpty())
    {
        QFile *file;
        if(!fileName.endsWith(".ge", Qt::CaseInsensitive))
        {
            fileName.append(".ge");
        }
        if(file->exists(fileName))
        {
            file = new QFile(fileName);
            file->open(QFile::ReadOnly | QFile::Text);
            modelManager->clear();
            emit showMessageOnStatusBarSignal("Loading scene...", 0);
            int loading = 0;
            if (!fileName.isEmpty())
            {
                QTextStream *in = new QTextStream(file);
                QString str;
                while(str != "EndOfFile")
                {
                    (*in) >> str;
                    if(str == "circle")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        float xCenter;
                        float yCenter;
                        float radius;

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        xCenter = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        yCenter = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        radius = str.toFloat();

                        Circle *tempCircle = new Circle(xCenter, yCenter, radius);

                        loading += 20;
                        emit saveloadingSignal(loading);

                        color = new QColor();
                        str.clear();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempCircle->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        tempCircle->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempCircle->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempCircle->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempCircle);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading  = 0;
                    }
                    else if(str == "square")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        float x1;
                        float y1;
                        float x2;
                        float y2;

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        x1 = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        y1 = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        x2 = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        y2 = str.toFloat();

                        Square *tempSquare = new Square(x1, y1, x2, y2);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        color = new QColor();
                        str.clear();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempSquare->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        tempSquare->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempSquare->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempSquare->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempSquare);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Image")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        float width;
                        float height;
                        QString fileName;

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        width = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        height = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        fileName.append(str);

                        Image *tempImage = new Image(fileName, width, height);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        color = new QColor();
                        str.clear();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempImage->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        tempImage->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempImage->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempImage->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempImage);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Line")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        QList<Vector> tempVertices;
                        float x, y;

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        int verticesSize;
                        (*in) >> str;
                        verticesSize = str.toInt();
                        str.clear();
                        while(verticesSize)
                        {
                            (*in) >> str;
                            x = str.toFloat();
                            str.clear();
                            (*in) >> str;
                            y = str.toFloat();
                            str.clear();
                            Vector v(x, y);
                            tempVertices.append(v);
                            verticesSize--;

                            loading++;
                            emit saveloadingSignal(loading);

                        }
                        Line *tempLine = new Line(tempVertices);

                        color = new QColor();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempLine->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        tempLine->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempLine->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempLine->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempLine);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Polygon")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        QList<Vector> tempVertices;
                        float x, y;

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        int verticesSize;
                        (*in) >> str;
                        verticesSize = str.toInt();
                        str.clear();
                        while(verticesSize)
                        {
                            (*in) >> str;
                            x = str.toFloat();
                            str.clear();
                            (*in) >> str;
                            y = str.toFloat();
                            str.clear();
                            Vector v(x, y);
                            tempVertices.append(v);
                            verticesSize--;

                            loading++;
                            emit saveloadingSignal(loading);
                        }
                        Polygon *tempPolygon = new Polygon(tempVertices);

                        color = new QColor();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempPolygon->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        tempPolygon->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempPolygon->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempPolygon->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempPolygon);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Ellipse")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        float xCenter;
                        float yCenter;
                        float widthOfEllipse;
                        float heightOfEllipse;

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        xCenter = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        yCenter = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        widthOfEllipse = str.toFloat();
                        str.clear();
                        (*in) >> str;
                        heightOfEllipse = str.toFloat();

                        Ellipse *tempEllipse = new Ellipse(xCenter, yCenter, widthOfEllipse, heightOfEllipse);

                        loading += 20;
                        emit saveloadingSignal(loading);

                        color = new QColor();
                        str.clear();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempEllipse->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        tempEllipse->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempEllipse->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);


                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempEllipse->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempEllipse);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Bezier")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        QList<Vector> tempVertices;
                        float x, y;

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        int verticesSize;
                        (*in) >> str;
                        verticesSize = str.toInt();
                        str.clear();
                        while(verticesSize)
                        {
                            (*in) >> str;
                            x = str.toFloat();
                            str.clear();
                            (*in) >> str;
                            y = str.toFloat();
                            str.clear();
                            Vector v(x, y);
                            tempVertices.append(v);
                            verticesSize--;

                            loading++;
                            emit saveloadingSignal(loading);
                        }
                        Bezier *tempBezier = new Bezier(tempVertices);

                        color = new QColor();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempBezier->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        tempBezier->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempBezier->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempBezier->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempBezier);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                    else if(str == "Spline")
                    {
                        QColor *color;
                        float xTranslate;
                        float yTranslate;
                        float xScale;
                        float yScale;
                        float angle;
                        QList<Vector> tempVertices;
                        float x, y;

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        int verticesSize;
                        (*in) >> str;
                        verticesSize = str.toInt();
                        str.clear();
                        while(verticesSize)
                        {
                            (*in) >> str;
                            x = str.toFloat();
                            str.clear();
                            (*in) >> str;
                            y = str.toFloat();
                            str.clear();
                            Vector v(x, y);
                            tempVertices.append(v);
                            verticesSize--;

                            loading++;
                            emit saveloadingSignal(loading);
                        }
                        Spline *tempSpline = new Spline(tempVertices);

                        color = new QColor();
                        (*in) >> str;//red color
                        color->setRedF(str.toFloat());
                        str.clear();
                        (*in) >> str;//green
                        color->setGreenF(str.toFloat());
                        str.clear();
                        (*in) >> str;//blue
                        color->setBlueF(str.toFloat());
                        tempSpline->setColor(color);

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        tempSpline->setID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        tempSpline->setGroupID(str.toInt());

                        str.clear();
                        (*in) >> str;
                        xTranslate = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yTranslate = str.toFloat();

                        loading += 20;
                        emit saveloadingSignal(loading);

                        str.clear();
                        (*in) >> str;
                        xScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        yScale = str.toFloat();

                        str.clear();
                        (*in) >> str;
                        angle = str.toFloat();

                        tempSpline->open(xTranslate, yTranslate, xScale, yScale, angle);

                        modelManager->append(tempSpline);
                        str.clear();

                        emit saveloadingSignal(100);
                        loading = 0;
                    }
                }
            }
            QApplication::setOverrideCursor(Qt::WaitCursor);
            QApplication::restoreOverrideCursor();
            emit showMessageOnStatusBarSignal("Scene loads successfully.", 3000);
        }
        else
        {
            QMessageBox msg;
            msg.setInformativeText("File doesn't exist.");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.setDefaultButton(QMessageBox::Ok);
            msg.exec();
        }
    }
}

void Glwidget::print()
{
    QPrinter printer;
    printer.setOrientation(QPrinter::Landscape);

    QPixmap pixmap = renderPixmap(glWidgetWidth, glWidgetHeight);
    QPrintDialog dialog(&printer, this);
    if(dialog.exec())
    {
        QPainter painter(&printer);
        painter.drawPixmap(0, 0, pixmap);
        emit showMessageOnStatusBarSignal("Scene printed successfully.", 3000);
    }
    else
        emit showMessageOnStatusBarSignal("Scene printed failure.", 3000);
}

void Glwidget::drawGrid()
{
    drawgrid = drawgrid ? false : true;
    emit showMessageOnStatusBarSignal("Draw grid toggeled.", 3000);
    updateGL();
}

void Glwidget::insert()
{
    imageForm = new Ui::imageform;
    dialog = new QDialog;
    imageForm->setupUi(dialog);
    connect(imageForm->loadimagepushButton, SIGNAL(clicked()), this, SLOT(loadImage()));
    connect(imageForm->okpushButton, SIGNAL(clicked()), this, SLOT(loadImageAccept()));
    connect(imageForm->cancelpushButton, SIGNAL(clicked()), this, SLOT(loadImageReject()));
    dialog->exec();
}

void Glwidget::loadImage()
{
    imageFileName = QFileDialog::getOpenFileName(this);
    if(!imageFileName.isEmpty())
    {
        QGraphicsScene *canvas = new QGraphicsScene;
        QImage img(imageFileName);
        if(!img.isNull())
        {
            QGraphicsPixmapItem *pixItem = canvas->addPixmap(QPixmap::fromImage(img).scaledToWidth(img.width()));
            pixItem->setFlag(QGraphicsItem::ItemIsMovable, true);
            imageForm->graphicsView->setScene(canvas);
            imageForm->graphicsView->show();
            imageForm->lineEdit->setText(imageFileName);
            char f = 'f';
            imageForm->widthlineEdit->setText(QString::number(img.width(), f, 2));
            imageForm->heightlineEdit->setText(QString::number(img.height(), f, 2));
        }
        else
            imageFileName.clear();
    }
}

void Glwidget::loadImageAccept()
{
    if(imageFileName.isEmpty())
    {
        QMessageBox msg;
        msg.setInformativeText("Can't load image.");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        if(imageFileName != imageForm->lineEdit->text())
        {
            QMessageBox msg;
            msg.setText("Error Occured!");
            msg.setInformativeText("Showed image address is :\t" + imageFileName + "\n" +
                                   "Entered address is :\n" + imageForm->lineEdit->text());
            msg.setStandardButtons(QMessageBox::Ok);
            msg.setDefaultButton(QMessageBox::Ok);
            msg.exec();
        }
        else
        {
            bool widthCorrect;
            bool heightCorrect;
            float width = imageForm->widthlineEdit->text().toFloat(&widthCorrect);
            float height = imageForm->heightlineEdit->text().toFloat(&heightCorrect);
            Image *tempImage = new Image(imageFileName, width, height);
            if(widthCorrect && heightCorrect && width >=0 && height >= 0)
            {
                undoManager->addModel(tempImage);
                updateGL();
                delete dialog;
                emit showMessageOnStatusBarSignal("Image loads successfully.", 3000);
            }
            else
            {
                QMessageBox msg;
                msg.setText("Entered width and/or height is not correct.");
                msg.setStandardButtons(QMessageBox::Ok);
                msg.setDefaultButton(QMessageBox::Ok);
                msg.exec();
            }
        }
    }
}

void Glwidget::loadImageReject()
{
    delete dialog;
    emit showMessageOnStatusBarSignal("Loading image rejected.", 3000);
}

void Glwidget::exportImage()
{
    QImage img;
    img = grabFrameBuffer(false);
    if(img.save("sceneImage.bmp"))
    {
        QString currentFileName = QFileDialog::getSaveFileName(this, "Export Image", 0,"Image(*.png*.jpg*.jpg*.bmp");
        if (currentFileName.isEmpty())
        {
            QMessageBox msg;
            msg.setText("Please try again.");
            msg.setInformativeText("Can't export image.");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.setDefaultButton(QMessageBox::Ok);
            msg.exec();
            return;
        }
        img.save(currentFileName);
        emit showMessageOnStatusBarSignal("Image exported successfully.", 3000);
    }

}

void Glwidget::newScene()
{
    if(!mustSaveBeforeNewOrExit)
    {
        modelManager->clear();
        currentFile = NULL;
        currentFileName.clear();
        updateGL();
        emit showMessageOnStatusBarSignal("New scene created.", 3000);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Cancel)
        {
            modelManager->clear();
            updateGL();
        }
        else
        {
            save();
        }
    }
}

void Glwidget::attributeEditor()
{
    int i = 0, counter = 0;
    while(i != modelManager->size())
    {
        Model *temp = modelManager->at(i);
        if(temp->getSelected())
        {
            counter++;
        }
        i++;
    }
    if(counter != 1)
    {
        QMessageBox msg;
        msg.setText("Please select ONE Model to edit.");
        msg.exec();
    }
    else
    {
        i = 0;
        while(i != modelManager->size())
        {
            Model *temp = modelManager->at(i);
            if(temp->getSelected())
            {
                temp->showAttribute();
            }
            i++;
        }
    }
}

void Glwidget::commandOperator()
{
    commandform = new Ui::Commandform();
    dialog = new QDialog;
    commandform->setupUi(dialog);
    connect(commandform->ok_button, SIGNAL(clicked()), this, SLOT(commandOk()));
    connect(commandform->cancel_button, SIGNAL(clicked()), this, SLOT(commandCancel()));
    dialog->exec();
}

void Glwidget::commandOk()
{
    QString command = commandform->lineEdit->text();
    int error = 0;
    bool convertion = true;
    if(!command.isEmpty())
    {
        command.toLower();
        QStringList list = command.split("(", QString::SkipEmptyParts);
        if(list.count() != 2)
        {
            error = 1;
        }
        if(error == 0)
        {
            QString whichModel = list.at(0);
            QString arguments = list.at(1);
            list.clear();
            list = arguments.split(")", QString::SkipEmptyParts);
            if(list.count() != 1)
            {
                error = 1;
            }
            if(error == 0)
            {
                arguments = list.at(0);
                if(whichModel == "circle")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() != 3)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        Circle *tempCircle = new Circle(((QString)arg.at(0)).toFloat(&convertion), ((QString)arg.at(1)).toFloat(&convertion), ((QString)arg.at(2)).toFloat(&convertion));
                        if(convertion)
                        {
                            tempCircle->setColor(currentColor);
                            undoManager->addModel(tempCircle);
                            mustSaveBeforeNewOrExit = true;
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "square")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() != 4)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        Square *tempSquare = new Square(((QString)arg.at(0)).toFloat(&convertion),
                                                        ((QString)arg.at(1)).toFloat(&convertion),
                                                        ((QString)arg.at(2)).toFloat(&convertion),
                                                        ((QString)arg.at(3)).toFloat(&convertion));
                        if(convertion)
                        {
                            tempSquare->setColor(currentColor);
                            undoManager->addModel(tempSquare);
                            mustSaveBeforeNewOrExit = true;
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "ellipse")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() != 4)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        Ellipse *tempEllipse = new Ellipse(((QString)arg.at(0)).toFloat(&convertion),
                                                           ((QString)arg.at(1)).toFloat(&convertion),
                                                           ((QString)arg.at(2)).toFloat(&convertion),
                                                           ((QString)arg.at(3)).toFloat(&convertion));
                        if(convertion)
                        {
                            tempEllipse->setColor(currentColor);
                            undoManager->addModel(tempEllipse);
                            mustSaveBeforeNewOrExit = true;
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "line")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() < 4 || arg.count() % 2 != 0)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        int i = 0;
                        vertices.clear();
                        while(i != arg.count())
                        {
                            Vector vect(((QString)arg.at(i++)).toFloat(&convertion), ((QString)arg.at(i++)).toFloat(&convertion));
                            if(convertion)
                            {
                                vertices.append(vect);
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(convertion)
                        {
                            Line *tempLine = new Line(vertices);
                            tempLine->setColor(currentColor);
                            undoManager->addModel(tempLine);
                            mustSaveBeforeNewOrExit = true;
                            vertices.clear();
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "polygon")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() < 6 || arg.count() % 2 != 0)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        int i = 0;
                        vertices.clear();
                        while(i != arg.count())
                        {
                            Vector vect(((QString)arg.at(i++)).toFloat(&convertion), ((QString)arg.at(i++)).toFloat(&convertion));
                            if(convertion)
                            {
                                vertices.append(vect);
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(convertion)
                        {
                            Polygon *tempPolygon = new Polygon(vertices);
                            tempPolygon->setColor(currentColor);
                            undoManager->addModel(tempPolygon);
                            mustSaveBeforeNewOrExit = true;
                            vertices.clear();
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "bezier")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() < 4 || arg.count() % 2 != 0)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        int i = 0;
                        vertices.clear();
                        while(i != arg.count())
                        {
                            Vector vect(((QString)arg.at(i++)).toFloat(&convertion), ((QString)arg.at(i++)).toFloat(&convertion));
                            if(convertion)
                            {
                                vertices.append(vect);
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(convertion)
                        {
                            Bezier *tempBezier = new Bezier(vertices);
                            tempBezier->setColor(currentColor);
                            undoManager->addModel(tempBezier);
                            mustSaveBeforeNewOrExit = true;
                            vertices.clear();
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else if(whichModel == "spline")
                {
                    QStringList arg = arguments.split(",", QString::SkipEmptyParts);
                    if(arg.count() < 8)
                    {
                        error = 1;
                    }
                    if(error == 0)
                    {
                        int i = 0;
                        vertices.clear();
                        while(i != arg.count())
                        {
                            Vector vect(((QString)arg.at(i++)).toFloat(&convertion), ((QString)arg.at(i++)).toFloat(&convertion));
                            if(convertion)
                            {
                                vertices.append(vect);
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(convertion)
                        {
                            Spline *tempSpline = new Spline(vertices);
                            tempSpline->setColor(currentColor);
                            undoManager->addModel(tempSpline);
                            mustSaveBeforeNewOrExit = true;
                            vertices.clear();
                            emit showMessageOnStatusBarSignal("Command: " + command + " executed.", 3000);
                        }
                    }
                }
                else
                {
                    QMessageBox msg;
                    msg.setDetailedText("Please write your command same as samples.");
                    msg.setText("Your entered command is wrong!");
                    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                    msg.setDefaultButton(QMessageBox::Ok);
                    if(msg.exec() == QMessageBox::Cancel)
                    {
                        delete dialog;
                        emit showMessageOnStatusBarSignal("Error on Command Window", 3000);
                    }
                }
            }
        }
    }
    else
    {
        QMessageBox msg;
        msg.setDetailedText("Please write your command same as samples.");
        msg.setText("You entered NOTHING!");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Ok);
        if(msg.exec() == QMessageBox::Cancel)
        {
            delete dialog;
            emit showMessageOnStatusBarSignal("Error on Command Window", 3000);
        }
    }
    if(error != 0 || !convertion)
    {
        QMessageBox msg;
        msg.setDetailedText("Please write your command same as samples.");
        msg.setText("Your entered command is wrong!");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Ok);
        if(msg.exec() == QMessageBox::Cancel)
        {
            delete dialog;
            emit showMessageOnStatusBarSignal("Error on Command Window.", 3000);
        }
    }
    updateGL();
}

void Glwidget::commandCancel()
{
    delete dialog;
    emit showMessageOnStatusBarSignal("Canceling command...", 1000);
}

void Glwidget::aboutQt()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void Glwidget::aboutMe()
{
    QMessageBox::about(this, tr("About Me"), "The <b>Pure Creation</b> is 2D editing application.");
}

void Glwidget::activeSaveTimer(bool isActive, int value)
{
    isSaveTimerActived = isActive;
    saveTimerValue = value;
    if(!isSaveTimerActived)
    {
        saveTimer->stop();
        emit showMessageOnStatusBarSignal("Save timer stoped.", 3000);
    }
    else
    {
        saveTimer->singleShot(saveTimerValue * 60000, this, SLOT(saveOnTime()));
        saveTimer->start();
        emit showMessageOnStatusBarSignal("Save timer started.", 3000);
    }

}

void Glwidget::getSaveTimerAcivated(bool &status, int &value)
{
    status = isSaveTimerActived;
    value = saveTimerValue;
}

void Glwidget::sendToBack()
{
    int i = 0, counter = 0;
    while(i != modelManager->size())
    {
        Model *temp = modelManager->at(i);
        if(temp->getSelected())
        {
            counter++;
        }
        i++;
    }
    if(counter != 1)
    {
        QMessageBox msg;
        msg.setText("Please select ONE Model to edit.");
        msg.exec();
    }
    else
    {
        i = 0;
        while(i != modelManager->size())
        {
            Model *temp = modelManager->at(i);
            if(temp->getSelected())
            {
                if(i > 0)
                {
                    modelManager->swap(i, i - 1);
                    mustSaveBeforeNewOrExit = true;
                    break;
                }
            }
            i++;
        }
    }
    updateGL();
    emit showMessageOnStatusBarSignal("Selected Model sent one step backward.", 3000);
}

void Glwidget::bringToFront()
{
    int i = 0, counter = 0;
    while(i != modelManager->size())
    {
        Model *temp = modelManager->at(i);
        if(temp->getSelected())
        {
            counter++;
        }
        i++;
    }
    if(counter != 1)
    {
        QMessageBox msg;
        msg.setText("Please select ONE Model to edit.");
        msg.exec();
    }
    else
    {
        i = 0;
        while(i != modelManager->size())
        {
            Model *temp = modelManager->at(i);
            if(temp->getSelected())
            {
                if(i < modelManager->size() - 1)
                {
                    modelManager->swap(i + 1, i);
                    mustSaveBeforeNewOrExit = true;
                    break;
                }
            }
            i++;
        }
    }
    updateGL();
    emit showMessageOnStatusBarSignal("Selected Model brought one step forward.", 3000);
}

void Glwidget::crop()
{
    diselectAll();

    drawLine = false;
    drawBezier = false;
    drawPolygon = false;
    drawSpline = false;
    cropActionTrigered = true;
    insertTextEnabled = false;
    reflectionEnabled = false;
    emit showMessageOnStatusBarSignal("\"Crop\": Draw rectangle on scene to crop.", 0);
}

void Glwidget::insertText()
{
    diselectAll();

    drawLine = false;

    drawBezier = false;
    drawPolygon = false;

    drawSpline = false;

    cropActionTrigered = false;
    insertTextEnabled = true;
    reflectionEnabled = false;
    emit showMessageOnStatusBarSignal("\"Text\": Click on scene to insert text.", 0);
}

void Glwidget::reflection()
{

    drawLine = false;

    drawBezier = false;
    drawPolygon = false;

    drawSpline = false;

    cropActionTrigered = false;
    insertTextEnabled = false;
    int i = 0, counter = 0;
    while(i != modelManager->size())
    {
        Model *temp = modelManager->at(i);
        if(temp->getSelected())
        {
            counter++;
        }
        i++;
    }
    if(counter != 0)
    {
        reflectionEnabled = true;
        emit showMessageOnStatusBarSignal("\"Reflection\": Select first point to continue.", 0);
    }
    else
    {
        QMessageBox msg;
        msg.setText("Please select the Model(s) to edit.");
        msg.exec();
    }
}
