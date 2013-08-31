#include "square.h"

Square::Square(float x1, float y1, float x2, float y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    centerX = (x2 - x1) / 2;
    centerY = (y2 - y1) / 2;

    vertexManager = new VertexManager();
    edgeManager = new EdgeManager();
    color = new QColor();
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
    ae = new Ui::square_attributeEditorForm;
    this->type = SquareType;
}

void Square::drawEdgeSelectMode()
{

}

void Square::drawFaceSelectMode()
{

}

void Square::drawObjectSelectMode()
{
    glClear(GL_DEPTH_BUFFER_BIT);   //This must be exist.For drawing in same z depth.
    glPushMatrix();
    if(!isMouseUp)
    {
        glTranslatef(x1 + centerX + xDrawingTranslation, y1 + centerY + yDrawingTranslation, 0.0);
        glRotatef(angle + drawingRotationAngle, 0.0, 0.0, 1.0);
        glScalef(xDrawingScale + xScale, yScale + yDrawingScale, 1.0);
    }
    else if(isMouseUp)
    {
        glTranslatef(x1 + centerX, y1 + centerY, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(xScale, yScale, 1.0);
    }
    if(selected)
    {
        glPushMatrix();
        glLineStipple(1, 0x0F0F);
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex3d((x1 > x2 ? (x1 - x2) / 2 : (x2 - x1) / 2), -(y1 > y2 ? (y1 - y2) / 2 : (y2 - y1) / 2), 0.0);
        glVertex3d((x1 > x2 ? (x1 - x2) / 2 : (x2 - x1) / 2), (y1 > y2 ? (y1 - y2) / 2 : (y2 - y1) / 2), 0.0);
        glVertex3d(-(x1 > x2 ? (x1 - x2) / 2 : (x2 - x1) / 2), (y1 > y2 ? (y1 - y2) / 2 : (y2 - y1) / 2), 0.0);
        glVertex3d(-(x1 > x2 ? (x1 - x2) / 2 : (x2 - x1) / 2), -(y1 > y2 ? (y1 - y2) / 2 : (y2 - y1) / 2), 0.0);
        glEnd();
        glLineStipple(1, 0xFFFF);
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
        glBegin(GL_QUADS);
    }
    glVertex2d(fabs((x1 - x2) / 2), -fabs((y1 - y2) / 2));
    glVertex2d(fabs((x1 - x2) / 2), fabs((y1 - y2) / 2 ));
    glVertex2d(-fabs((x1 - x2) / 2), fabs((y1 - y2) / 2));
    glVertex2d(-fabs((x1 - x2) / 2), -fabs((y1 - y2) / 2));
    glEnd();

    glPopMatrix();
}

void Square::drawVertexSelectMode()
{

}

void Square::save(QTextStream *out)
{
    QString temp("square");
    QString tab("\t");
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(x1);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(y1);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(x2);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(y2);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(color->redF());
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(color->greenF());
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(color->blueF());
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(iD);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(groupID);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(xTranslate);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(yTranslate);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(xScale);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(yScale);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(angle);
    (*out) << temp;
    tab = "\n";
    (*out) << tab;
}

void Square::showAttribute()
{
    dialog = new QDialog();
    ae->setupUi(dialog);
    connect(ae->square_OK, SIGNAL(clicked()), this, SLOT(changeAttributes()));
    connect(ae->squarecolor_button, SIGNAL(clicked()), this, SLOT(changeColorAE()));

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
    ae->squarecolor_button->setStyleSheet(colorString_QString);

    aEcolor.setGreenF(this->color->greenF());
    aEcolor.setRedF(this->color->redF());
    aEcolor.setBlueF(this->color->blueF());

    ae->xtranslate_lineEdit->setText(QString::number(xTranslate));
    ae->yTranslate_lineEdit->setText(QString::number(yTranslate));
    ae->xScale_lineEdit->setText(QString::number(xScale));
    ae->yScale_lineEdit->setText(QString::number(yScale));
    ae->rotate_lineEdit->setText(QString::number(angle));
    ae->width_lineEdit->setText(QString::number(fabs(x1 - x2)));
    ae->height_lineEdit->setText(QString::number(fabs(y1 - y2)));

    if(isFilled)
        ae->checkBoxFilled->setChecked(true);
    else ae->checkBoxFilled->setChecked(false);
    dialog->exec();
}

void Square::reflect(float m, float n)
{
    float xp = (x1 / m + y1 - n) * (m / (m * m + 1));
    float yp = m * xp + n;
    x1 = 2 * xp - x1;
    y1 = 2 * yp - y1;
    xp = (x2 / m + y2 - n) * (m / (m * m + 1));
    yp = m * xp + n;
    x2 = 2 * xp - x2;
    y2 = 2 * yp - y2;
    centerX = (x2 - x1) / 2;
    centerY = (y2 - y1) / 2;
}

void Square::changeAttributes()
{
    color->setRedF(aEcolor.redF());
    color->setGreenF(aEcolor.greenF());
    color->setBlueF(aEcolor.blueF());

    xTranslate = ae->xtranslate_lineEdit->text().toFloat();
    yTranslate = ae->yTranslate_lineEdit->text().toFloat();
    xScale = ae->xScale_lineEdit->text().toFloat();
    yScale = ae->yScale_lineEdit->text().toFloat();
    angle = ae->rotate_lineEdit->text().toFloat();
    float newWidth = ae->width_lineEdit->text().toFloat();
    float newHeight = ae->height_lineEdit->text().toFloat();
    float dif;
    if(x1 < x2 && y1 < y2)
    {
        if(newWidth < fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 += dif;
            x2 -= dif;
        }
        else if(newWidth > fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 -= dif;
            x2 += dif;
        }
        if(newHeight < fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 += dif;
            y2 -= dif;
        }
        if(newHeight > fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 -= dif;
            y2 += dif;
        }
    }
    else if(x1 > x2 && y1 < y2)
    {
        if(newWidth < fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 -= dif;
            x2 += dif;
        }
        else if(newWidth > fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 += dif;
            x2 -= dif;
        }
        if(newHeight < fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 += dif;
            y2 -= dif;
        }
        else if(newHeight > fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 -= dif;
            y2 += dif;
        }
    }
    else if(x1 < x2 && y1 > y2)
    {
        if(newWidth < fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 += dif;
            x2 -= dif;
        }
        else if(newWidth > fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 -= dif;
            x2 += dif;
        }
        if(newHeight < fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 -= dif;
            y2 += dif;
        }
        else if(newHeight > fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 += dif;
            y2 -= dif;
        }
    }
    else if(x1 > x2 && y1 > y2)
    {
        if(newWidth < fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 -= dif;
            x2 += dif;
        }
        else if(newWidth < fabs(x2 - x1))
        {
            dif = fabs(x2 - x1 - newWidth) / 2;
            x1 += dif;
            x2 -= dif;
        }
        if(newHeight < fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 -= dif;
            y2 += dif;
        }
        else if(newHeight < fabs(y2 - y1))
        {
            dif = fabs(y2 - y1 - newHeight) / 2;
            y1 += dif;
            y2 -= dif;
        }
    }
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

void Square::changeColorAE()
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
    ae->squarecolor_button->setStyleSheet(colorString_QString);
}
