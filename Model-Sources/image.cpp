#include "image.h"

Image::Image(QString fileName, float width, float height)
{
    image.load(fileName);
    this->fileName.append(fileName);
    openGLImage = QGLWidget::convertToGLFormat(image);
    this->x1 = -width / 20;
    this->y1 = height / 20;
    this->x2 = width / 20;
    this->y2 = -height / 20;
    this->width = width;
    this->height = height;
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
    this->type = ImageType;
}

void Image::drawEdgeSelectMode()
{

}

void Image::drawFaceSelectMode()
{

}

void Image::drawObjectSelectMode()
{
    glPushMatrix();
    glClear(GL_DEPTH_BUFFER_BIT);   //This must be exist.For drawing in same z depth.
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if(selected)
    {
        glPushMatrix();
        glLineStipple(1, 0x0F0F);
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
        glEnd();
        glLineStipple(1, 0xFFFF);
        glPopMatrix();
    }
    glColor3f(1.0, 1.0, 1.0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, openGLImage.width(), openGLImage.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, openGLImage.bits());

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 1.0); glVertex2f(x1, y1);
    glTexCoord2f(1.0, 1.0); glVertex2f(x2, y1);
    glTexCoord2f(1.0, 0.0); glVertex2f(x2, y2);
    glTexCoord2f(0.0, 0.0); glVertex2f(x1, y2);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Image::drawVertexSelectMode()
{

}

void Image::save(QTextStream *out)
{
    QString temp("Image");
    QString tab("\t");
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(width);
    (*out) << temp;
    (*out) << tab;
    temp = QString::number(height);
    (*out) << temp;
    (*out) << tab;
    temp = fileName;
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

void Image::showAttribute()
{
}

void Image::loadImageReject()
{
    delete dialog;
}

void Image::reflect(float m, float n)
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

void Image::changeAttributes()
{
}

void Image::changeColorAE()
{
    //image doesn't have color
}
