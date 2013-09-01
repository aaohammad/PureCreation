#include "select-manager.h"

SelectManager * SelectManager::m_selectManager;
SelectManager * SelectManager::getInstance ()
{
	if(!m_selectManager)
		m_selectManager = new SelectManager();
	return m_selectManager;
}

SelectManager::SelectManager()
{
	glwidgets = new QList<GLWidget *>();
}

void SelectManager::addGLWidget (QList<GLWidget *> * glwidgets)
{
	this->glwidgets->clear ();
	for(int i = 0; i < glwidgets->size (); i++)
	{
		this->glwidgets->append (glwidgets->at (i));
	}
}

void SelectManager::setCurrentMousePosition (float x, float y)
{
	curX = x;
	curY = y;
}

void SelectManager::selectPoint()
{
	for(int i = 0; i < glwidgets->size (); i++)
	{
		if(glwidgets->at (i)->getIsMouseHere ())
		{
			glwidgets->at (i)->drawSelectionRectangle (curX, curY, false);
			bool anyModelSelected = false;
			bool anyVertexSelected = false;
			selectedModels.clear ();
			selectedVertices.clear ();
			glwidgets->at (i)->pointSelection (curX, curY, selectedModels, selectedVertices);
			for(int i = 0; i < selectedModels.size (); i++)
			{
				selectedModels.at (i)->setSelected (true);
				anyModelSelected = true;
			}
			for(int i = 0; i < selectedVertices.size (); i++)
			{
				selectedVertices.at (i)->setSelected (true);
				anyVertexSelected = true;
			}
			if(!anyModelSelected)
				diselectAll ();
			break;
		}
	}
	emit endState ();
}

void SelectManager::diselectAll()
{
	int i = 0;
	while(i < ModelManager::getInstance ()->size())
	{
		ModelManager::getInstance ()->at(i)->setSelected(false);
		i++;
	}
}

void SelectManager::selectAll()
{
	int i=0;
	while(i < ModelManager::getInstance ()->size())
	{
		ModelManager::getInstance ()->at(i)->setSelected(true);
		i++;
	}
}

void SelectManager::selectMousePressed()
{
	for(int i = 0; i < glwidgets->size (); i++)
	{
		if(glwidgets->at (i)->getIsMouseHere ())
		{
			glwidgets->at (i)->drawSelectionRectangle (curX, curY, true);
			break;
		}
	}
	preX = curX;
	preY = curY;
}

void SelectManager::selectRectangular()
{
	for(int i = 0; i < glwidgets->size (); i++)
	{
		if(glwidgets->at (i)->getIsMouseHere ())
		{
			glwidgets->at (i)->drawSelectionRectangle (curX, curY, false);
			bool anyModelSelected = false;
			bool anyVertexSelected = false;
			selectedModels.clear ();
			selectedVertices.clear ();
			glwidgets->at (i)->rectangularSelection (preX, preY, curX, curY, selectedModels, selectedVertices);
			for(int i = 0; i < selectedModels.size (); i++)
			{
				selectedModels.at (i)->setSelected (true);
				anyModelSelected = true;
			}
			for(int i = 0; i < selectedVertices.size (); i++)
			{
				selectedVertices.at (i)->setSelected (true);
				anyVertexSelected = true;
			}
			if(!anyModelSelected)
				diselectAll ();
			break;
		}
	}
	emit endState();
}

void SelectManager::whatISUnderCursor ()
{
	for(int i = 0; i < glwidgets->size (); i++)
	{
		if(glwidgets->at (i)->getIsMouseHere ())
		{
			selectedModels.clear ();
			selectedVertices.clear ();
			glwidgets->at (i)->pointSelection (curX, curY, selectedModels, selectedVertices);
//			if(selectedModels.size () != 0 || selectedVertices.size () != 0)
				emit ModelOrNothingUnderCursor ();
			break;
		}
	}
}
