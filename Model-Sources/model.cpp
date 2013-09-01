#include "model.h"

Model::Model()
{
	this->m_vertexManager = new VertexManager();
	this->m_faceManager = new FaceManager();
	this->m_tempVertexManager = new VertexManager();
	this->m_material = new Material();
	this->m_selected = false;
	this->m_move = new Vector;
	this->m_scale = new Vector;
	this->m_rotate = new Vector;
	this->m_center = new Vector;
	this->m_preMousePosition = new Vector;
	this->m_drawingMode = ObjectMode;
}

void Model::setDrawingMode (DrawingModes drawingMode)
{
	this->m_drawingMode = drawingMode;
}

DrawingModes Model::getDrawingMode ()
{
	return m_drawingMode;
}

void Model::mousePressed(float x, float y, float z)
{
//    this->preMousePositionX = x;
//    this->preMousePositionY = y;
//    m_tempVertexManager->append(m_vertexManager);
}

void Model::moveMouseMoved(float x, float y, float z)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        m_vertexManager->at(i)->x = m_tempVertexManager->at(i)->x;
//        m_vertexManager->at(i)->y = m_tempVertexManager->at(i)->y;
//        m_vertexManager->at(i)->x += x - preMousePositionX;
//        m_vertexManager->at(i)->y += y - preMousePositionY;
//        i++;
//    }
}

void Model::move(float x, float y, float z)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        m_vertexManager->at(i)->x += x;
//        m_vertexManager->at(i)->y += y;
//        i++;
//    }
//    calculateCenter();
//    this->xMovement += x;
//    this->yMovement += y;
}

void Model::mouseReleased()
{
	m_tempVertexManager->clear();
}

void Model::scaleMouseMoved(float x, float y, float z)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        m_vertexManager->at(i)->x = m_tempVertexManager->at(i)->x;
//        m_vertexManager->at(i)->y = m_tempVertexManager->at(i)->y;
//        m_vertexManager->at(i)->x -= centerX;
//        m_vertexManager->at(i)->y -= centerY;
//        if(x != 1)
//        {
//            m_vertexManager->at(i)->x = m_vertexManager->at(i)->x * (x);
//        }
//        if(y != 1)
//        {
//            m_vertexManager->at(i)->y = m_vertexManager->at(i)->y * (y);
//        }
//        m_vertexManager->at(i)->x += centerX;
//        m_vertexManager->at(i)->y += centerY;
//        i++;
//    }
}

void Model::scale(float x, float y, float z)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        m_vertexManager->at(i)->x -= centerX;
//        m_vertexManager->at(i)->y -= centerY;
//        if(x != 1)
//        {
//            m_vertexManager->at(i)->x *= x;
//        }
//        if(y != 1)
//        {
//            m_vertexManager->at(i)->y *= y;
//        }
//        m_vertexManager->at(i)->x += centerX;
//        m_vertexManager->at(i)->y += centerY;
//        i++;
//    }
//    calculateCenter();
//    this->xScale += x;
//    this->yScale += y;
}

void Model::rotateMouseMoved(float x, float y, float z, float angle)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        m_vertexManager->at(i)->x = m_tempVertexManager->at(i)->x;
//        m_vertexManager->at(i)->y = m_tempVertexManager->at(i)->y;
//        float x = (m_vertexManager->at(i)->x - centerX) * cos(angle) - (m_vertexManager->at(i)->y - centerY) * sin(angle) + centerX;
//        float y = (m_vertexManager->at(i)->x - centerX) * sin(angle) + (m_vertexManager->at(i)->y - centerY) * cos(angle) + centerY;
//        m_vertexManager->at(i)->x = x;
//        m_vertexManager->at(i)->y = y;
//        i++;
//    }
}

void Model::rotate (float x, float y, float z, float angle)
{
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        float x = (m_vertexManager->at(i)->x - centerX) * cos(angle) - (m_vertexManager->at(i)->y - centerY) * sin(angle) + centerX;
//        float y = (m_vertexManager->at(i)->x - centerX) * sin(angle) + (m_vertexManager->at(i)->y - centerY) * cos(angle) + centerY;
//        m_vertexManager->at(i)->x = x;
//        m_vertexManager->at(i)->y = y;
//        i++;
//    }
//    calculateCenter();
//    this->angle += angle;
}

void Model::calculateCenter()
{
//    this->centerX = 0.0;
//    this->centerY = 0.0;
//    int i = 0;
//    while(i != m_vertexManager->size())
//    {
//        centerX += m_vertexManager->at(i)->x;
//        centerY += m_vertexManager->at(i)->y;
//        i++;
//    }
//    centerX /= m_vertexManager->size();
//    centerY /= m_vertexManager->size();
}

void Model::setSelectionIdentifier(int iD)
{
	this->m_selectionIdentifier = iD;
}

void Model::setSelected(bool selectoion)
{
	m_selected = selectoion;
	if(!m_selected)
	{
		for(int i = 0; i < m_vertexManager->size(); i++)
			m_vertexManager->at(i)->setSelected(false);
	}
}

void Model::getCenter (float &x, float &y, float &z)
{
}

int Model::getSelectionIdentifier()
{
	return m_selectionIdentifier;
}

bool Model::getSelected()
{
	return m_selected;
}

VertexManager * Model::getVertexManager()
{
	return m_vertexManager;
}
