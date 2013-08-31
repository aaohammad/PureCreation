#include "circle.h"

Circle::Circle(float xCenter, float yCenter, float radius)
{
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->radius = radius;
    centerX = xCenter;
    centerY = yCenter;

    vertexManager = new VertexManager();
    edgeManager = new EdgeManager();

    float x, y;
    for(float ngl = 0; ngl <= 6.3/*2pi*/; ngl += 0.1)
    {
        x = xCenter + sin(ngl) * radius;
        y = yCenter + cos(ngl) * radius;
        Vector vector(x, y);
        vertexManager->append(vector);
    }

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
    ae = new Ui::Form;
    this->type = CircleType;
}

void Circle::drawEdgeSelectMode()
{

}

void Circle::drawFaceSelectMode()
{

}

void Circle::drawObjectSelectMode()
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
    if(selected)
    {
        glPushMatrix();
        glLineStipple(1, 0x0F0F);
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        for(float tempAngle = 0; tempAngle < 6.3; tempAngle += 0.1)
        {
            glVertex2f(xCenter + sin(tempAngle) * radius, yCenter + cos(tempAngle) * radius);
        }
        glEnd();
        glPopMatrix();
    }
    glColor3f(color->redF(), color->greenF(), color->blueF());
    if(!isFilled)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_LINE_STRIP);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_POLYGON);
    }
    for(float angle = 0; angle <= 6.3/*2pi*/; angle += 0.1)
    {
        glVertex2f(xCenter + sin(angle) * radius, yCenter + cos(angle) * radius);
    }
    glEnd();

    //to pop matrix
    glPopMatrix();
}

void Circle::drawVertexSelectMode()
{

}

void Circle::save(QTextStream *out)
{
    QString temp("circle");
    (*out) << temp;
    temp = "\t";
    (*out) << temp;
    (*out) << QString::number(xCenter);
    (*out) << temp;
    (*out) << QString::number(yCenter);
    (*out) << temp;
    (*out) << QString::number(radius);
    (*out) << temp;
    char f = 'f';
    QString colorString;
    colorString = QString::number(color->redF(), f, 6);
    (*out) << colorString;
    (*out) << temp;
    colorString = QString::number(color->greenF(), f, 6);
    (*out) << colorString;
    (*out) << temp;
    colorString = QString::number(color->blueF(), f, 6);
    (*out) << colorString;
    (*out) << temp;
    (*out) << QString::number(iD);
    (*out) << temp;
    (*out) << QString::number(groupID);
    (*out) << temp;
    (*out) << QString::number(xTranslate);
    (*out) << temp;
    (*out) << QString::number(yTranslate);
    (*out) << temp;
    (*out) << QString::number(xScale);
    (*out) << temp;
    (*out) << QString::number(yScale);
    (*out) << temp;
    (*out) << QString::number(angle);
    temp = "\n";
    (*out) << temp;
}

void Circle::showAttribute()
{
    dialog = new QDialog();
    ae->setupUi(dialog);
    connect(ae->circle_OK, SIGNAL(clicked()), this, SLOT(changeAttributes()));
    connect(ae->circlecolor_button, SIGNAL(clicked()), this, SLOT(changeColorAE()));

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
    ae->circlecolor_button->setStyleSheet(colorString_QString);

    aEcolor.setGreenF(this->color->greenF());
    aEcolor.setRedF(this->color->redF());
    aEcolor.setBlueF(this->color->blueF());

    ae->xtranslate_lineEdit->setText(QString::number(xTranslate));
    ae->yTranslate_lineEdit->setText(QString::number(yTranslate));
    ae->xScale_lineEdit->setText(QString::number(xScale));
    ae->yScale_lineEdit->setText(QString::number(yScale));
    ae->rotate_lineEdit->setText(QString::number(angle));
    ae->xCenter_lineEdit->setText(QString::number(xCenter));
    ae->yCenter_lineEdit->setText(QString::number(yCenter));
    ae->radius_lineEdit->setText(QString::number(radius));


    if(isFilled)
        ae->checkBoxFilled->setChecked(true);
    else ae->checkBoxFilled->setChecked(false);
    dialog->exec();
}

void Circle::reflect(float m, float n)
{
    float xp = (xCenter / m + yCenter - n) * (m / (m * m + 1));
    float yp = m * xp + n;
    xCenter = 2 * xp - xCenter;
    yCenter = 2 * yp - yCenter;
    centerX = xCenter;
    centerY = yCenter;
}

void Circle::changeAttributes()
{
    color->setRedF(aEcolor.redF());
    color->setGreenF(aEcolor.greenF());
    color->setBlueF(aEcolor.blueF());

    xTranslate = ae->xtranslate_lineEdit->text().toFloat();
    yTranslate = ae->yTranslate_lineEdit->text().toFloat();
    xScale = ae->xScale_lineEdit->text().toFloat();
    yScale = ae->yScale_lineEdit->text().toFloat();
    angle = ae->rotate_lineEdit->text().toFloat();

    xCenter = ae->xCenter_lineEdit->text().toFloat();
    yCenter = ae->yCenter_lineEdit->text().toFloat();
    radius = ae->radius_lineEdit->text().toFloat();

    if(ae->checkBoxFilled->isChecked())
    {
        isFilled = true;
    }
    else
    {
        isFilled = false;
    }
    delete dialog;
}

void Circle::changeColorAE()
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
    ae->circlecolor_button->setStyleSheet(colorString_QString);
}
