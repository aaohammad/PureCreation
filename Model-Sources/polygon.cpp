#include "polygon.h"

Polygon::Polygon(QList<Vector> vertices)
{
    vertexManager = new VertexManager();
    edgeManager = new EdgeManager();
    this->vertexManager->append(vertices);
    this->centerX = 0.0;
    this->centerY = 0.0;
    int i = 0;
    while(i != vertexManager->size())
    {
        centerX += vertexManager->at(i).x;
        centerY += vertexManager->at(i).y;
        i++;
    }
    centerX /= vertexManager->size();
    centerY /= vertexManager->size();

    color = new QColor(100, 255, 100, 255);
    iD = 0;
    groupID = 0;
    selected = false;
    xTranslate = 0.0;
    xDrawingTranslation = 0.0;
    yTranslate = 0.0;
    yDrawingTranslation = 0.0;
    xScale = 1.0;
    xDrawingScale = 0.0;
    yScale = 1.0;
    yDrawingScale = 0.0;
    drawingRotationAngle = 0.0;
    angle = 0.0;
    isMouseUp = true;
    isFilled = true;
    ae = new Ui::lineForm();
    lineContinuity = "FFFFFF";
    lineWidth = 2.0;
    this->type = PolygonType;
}

void Polygon::drawEdgeSelectMode()
{

}

void Polygon::drawFaceSelectMode()
{

}

void Polygon::drawObjectSelectMode()
{
    glPushMatrix();
    //between push matrix
    glClear(GL_DEPTH_BUFFER_BIT);//This must be exist.For drawing in same z depth.
    if(!isMouseUp)
    {
        glTranslatef(centerX + xDrawingTranslation, centerY + yDrawingTranslation, 0.0);
        glRotatef(angle + drawingRotationAngle, 0.0, 0.0, 1.0);
        glScalef(xDrawingScale + xScale, 1.0, 1.0);
        glScalef(1.0, yScale + yDrawingScale, 1.0);
        glTranslatef(-(centerX + xDrawingTranslation), -(centerY + yDrawingTranslation), 0.0);
        glTranslatef(xTranslate + xDrawingTranslation, 0.0, 0.0);
        glTranslatef(0.0, yTranslate + yDrawingTranslation, 0.0);
    }
    else if(isMouseUp)
    {
        glTranslatef(centerX, centerY, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(xScale, 1.0, 1.0);
        glScalef(1.0, yScale, 1.0);
        glTranslatef(-centerX, -centerY, 0.0);
        glTranslatef(xTranslate, 0.0, 0.0);
        glTranslatef(0.0, yTranslate, 0.0);
    }
    glLineWidth(lineWidth);
    float lineStipple = 0;

    lineStipple += findIndex(lineContinuity.at(5).toAscii()) * 1;
    lineStipple += findIndex(lineContinuity.at(4).toAscii()) * pow(16, 1);
    lineStipple += findIndex(lineContinuity.at(3).toAscii()) * pow(16, 2);
    lineStipple += findIndex(lineContinuity.at(2).toAscii()) * pow(16, 3);
    lineStipple += findIndex(lineContinuity.at(1).toAscii()) * pow(16, 4);
    lineStipple += findIndex(lineContinuity.at(0).toAscii()) * pow(16, 5);
    if(selected)
    {
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineStipple(1, 0xF0F0);
        int i = 0;
        glBegin(GL_LINE_LOOP);
        while(i != vertexManager->size())
        {
            glVertex2f(vertexManager->at(i).x, vertexManager->at(i).y);
            i++;
        }
        glEnd();
        glLineStipple(1, lineStipple);
        glPopMatrix();
    }
    glColor3f(color->redF(), color->greenF(), color->blueF());
    if(!isFilled)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_LINE_LOOP);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_POLYGON);
    }

    //glLineStipple(1, lineStipple);
    int i = 0;
    //glLineWidth(2.0);
    while(i != vertexManager->size())
    {
        glVertex2f(vertexManager->at(i).x, vertexManager->at(i).y);
        i++;
    }
    glEnd();

    //to pop matrix
    glPopMatrix();
}

void Polygon::drawVertexSelectMode()
{

}

void Polygon::save(QTextStream *out)
{
    QString temp("Polygon");
    QString tab("\t");
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(vertexManager->size());
    (*out) << temp;
    (*out) << tab;
    int i = 0;
    char f = 'f';
    while(i != vertexManager->size())
    {
        temp = QString::number(vertexManager->at(i).x, f, 6);
        (*out) << temp;
        (*out) << tab;
        temp = QString::number(vertexManager->at(i).y, f, 6);
        (*out) << temp;
        (*out) << tab;
        i++;
    }
    temp = QString::number(color->redF(), f, 6);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(color->greenF(), f, 6);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(color->blueF(), f, 6);
    (*out) << temp;
    (*out) << tab;
    (*out) << QString::number(iD);
    (*out) << tab;
    (*out) << QString::number(groupID);
    (*out) << tab;
    (*out) << QString::number(xTranslate);
    (*out) << tab;
    (*out) << QString::number(yTranslate);
    (*out) << tab;
    (*out) << QString::number(xScale);
    (*out) << tab;
    (*out) << QString::number(yScale);
    (*out) << tab;
    (*out) << QString::number(angle);
    tab = "\n";
    (*out) << tab;
}

void Polygon::showAttribute()
{
    dialog = new QDialog();
    ae->setupUi(dialog);
    connect(ae->line_OK, SIGNAL(clicked()), this, SLOT(changeAttributes()));
    connect(ae->lineColor_button, SIGNAL(clicked()), this, SLOT(changeColorAE()));
    connect(ae->lineComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(vertexComboBoxChanged()));

    QColor color;
    color.setGreenF(this->color->greenF());
    color.setRedF(this->color->redF());
    color.setBlueF(this->color->blueF());
    QString colorString_QString;
    colorString_QString.append("background-color: rgb(");
    colorString_QString.append(QString::number(color.red(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(color.green(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(color.blue(),10));
    colorString_QString.append(");");
    ae->lineColor_button->setStyleSheet(colorString_QString);

    char f = 'f';
    ae->xLineLineEdit->setText(QString::number(vertexManager->at(0).x, f, 5));
    ae->yLineLineEdit->setText(QString::number(vertexManager->at(0).y, f, 5));

    aEcolor.setGreenF(this->color->greenF());
    aEcolor.setRedF(this->color->redF());
    aEcolor.setBlueF(this->color->blueF());

    ae->widthlineEdit->setText(QString::number(lineWidth, f, 5));

    int i = 0;
    while(i != vertexManager->size())
    {
        ae->lineComboBox->insertItem(i, QString::number(i, 10));
        i++;
    }

    ae->xtranslate_lineEdit->setText(QString::number(xTranslate));
    ae->yTranslate_lineEdit->setText(QString::number(yTranslate));
    ae->xScale_lineEdit->setText(QString::number(xScale));
    ae->yScale_lineEdit->setText(QString::number(yScale));
    ae->rotate_lineEdit->setText(QString::number(angle));

    ae->comboBox->setCurrentIndex(15 - findIndex(lineContinuity.at(0).toAscii()));
    ae->comboBox_2->setCurrentIndex(15 - findIndex(lineContinuity.at(1).toAscii()));
    ae->comboBox_3->setCurrentIndex(15 - findIndex(lineContinuity.at(2).toAscii()));
    ae->comboBox_4->setCurrentIndex(15 - findIndex(lineContinuity.at(3).toAscii()));
    ae->comboBox_5->setCurrentIndex(15 - findIndex(lineContinuity.at(4).toAscii()));
    ae->comboBox_6->setCurrentIndex(15 - findIndex(lineContinuity.at(5).toAscii()));


    dialog->exec();
}

void Polygon::reflect(float m, float n)
{
    int i = 0;
    QList<Vector> tempVertices;
    float xz, yz;
    while(i != vertexManager->size())
    {
        float xp = (vertexManager->at(i).x / m + vertexManager->at(i).y - n) * (m / (m * m + 1));
        float yp = m * xp + n;
        xz = 2 * xp - vertexManager->at(i).x;
        yz = 2 * yp - vertexManager->at(i).y;
        Vector vect(xz, yz);
        tempVertices.append(vect);
        i++;
    }
    vertexManager->clear();
    vertexManager->append(tempVertices);
    i = 0;
    while(i != vertexManager->size())
    {
        centerX += vertexManager->at(i).x;
        centerY += vertexManager->at(i).y;
        i++;
    }
    centerX /= vertexManager->size();
    centerY /= vertexManager->size();
}

int Polygon::findIndex(char ch)
{
    switch(ch)
    {
    case 'F':
        return 15;
        break;
    case 'E':
        return 14;
        break;
    case 'D':
        return 13;
        break;
    case 'C':
        return 12;
        break;
    case 'B':
        return 11;
        break;
    case 'A':
        return 10;
        break;
    case '9':
        return 9;
        break;
    case '8':
        return 8;
        break;
    case '7':
        return 7;
        break;
    case '6':
        return 6;
        break;
    case '5':
        return 5;
        break;
    case '4':
        return 4;
        break;
    case '3':
        return 3;
        break;
    case '2':
        return 2;
        break;
    case '1':
        return 1;
        break;
    case '0':
        return 0;
        break;
    }
    return -1;
}

void Polygon::changeAttributes()
{
    color->setRedF(aEcolor.redF());
    color->setGreenF(aEcolor.greenF());
    color->setBlueF(aEcolor.blueF());

    xTranslate = ae->xtranslate_lineEdit->text().toFloat();
    yTranslate = ae->yTranslate_lineEdit->text().toFloat();
    xScale = ae->xScale_lineEdit->text().toFloat();
    yScale = ae->yScale_lineEdit->text().toFloat();
    angle = ae->rotate_lineEdit->text().toFloat();

    vertexManager->at(ae->lineComboBox->currentIndex()).x = ae->xLineLineEdit->text().toFloat();
    vertexManager->at(ae->lineComboBox->currentIndex()).y = ae->yLineLineEdit->text().toFloat();

    lineWidth = ae->widthlineEdit->text().toFloat();

    lineContinuity.clear();
    lineContinuity.append(ae->comboBox->currentText().toAscii());
    lineContinuity.append(ae->comboBox_2->currentText().toAscii());
    lineContinuity.append(ae->comboBox_3->currentText().toAscii());
    lineContinuity.append(ae->comboBox_4->currentText().toAscii());
    lineContinuity.append(ae->comboBox_5->currentText().toAscii());
    lineContinuity.append(ae->comboBox_6->currentText().toAscii());

    delete dialog;
}

void Polygon::changeColorAE()
{
    QColorDialog *colordialog_QColorDialog = new QColorDialog;
    colordialog_QColorDialog->setCurrentColor(aEcolor);
    int resultCode = colordialog_QColorDialog->exec();
    if (resultCode == QDialog::Accepted)
        aEcolor = colordialog_QColorDialog->selectedColor();
    delete colordialog_QColorDialog;
    QString colorString_QString;
    colorString_QString.append("background-color: rgb(");
    colorString_QString.append(QString::number(aEcolor.red(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(aEcolor.green(),10));
    colorString_QString.append(", ");
    colorString_QString.append(QString::number(aEcolor.blue(),10));
    colorString_QString.append(");");
    ae->lineColor_button->setStyleSheet(colorString_QString);
}

void Polygon::vertexComboBoxChanged()
{
    char f = 'f';
    ae->xLineLineEdit->setText(QString::number(vertexManager->at(ae->lineComboBox->currentIndex()).x, f, 5));
    ae->yLineLineEdit->setText(QString::number(vertexManager->at(ae->lineComboBox->currentIndex()).y, f, 5));
}
