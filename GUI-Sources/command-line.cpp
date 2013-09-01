#include "command-line.h"

CommandLine * CommandLine::m_commandLine = 0;
CommandLine * CommandLine::getInstance ()
{
	if(!m_commandLine)
		m_commandLine = new CommandLine();
	return m_commandLine;
}

void CommandLine::executeCommand(QString cmd)
{
	if(!cmd.isEmpty())
	{
		cmd.toLower();
		QStringList list = cmd.split("(", QString::SkipEmptyParts);
		if(list.count() != 2)
		{
			ShowInformation::getInstance ()->show (QString("Structural error! -> e.g ( ") + QString("command is not 'model + (' )"));
			return;
		}
		QString whichModel = list.at(0);
		QString arguments = list.at(1);
		list.clear();
		list = arguments.split(")"); // arguments list
		if(list.count() != 2)
		{
			ShowInformation::getInstance ()->show (QString("Error in closing parenthesis! -> e.g ( ") + QString("circle(1)) )"));
			return;
		}
		arguments = list.at(0);
		if(whichModel == "circle")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() != 1)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("circle(1, 2)) )"));
				return;
			}
			bool canConvertStringToNumber;
			Circle *tempCircle = new Circle(0.0f,
											0.0f,
											0.0f,
											((QString)arg.at(0)).toFloat(&canConvertStringToNumber));
			if(canConvertStringToNumber == false)
			{
				ShowInformation::getInstance ()->show (QString("Entered argument is not number! -> e.g ( ") + QString("circle(a)) )"));
				return;
			}
			ShowInformation::getInstance ()->show (QString("Circle created! -> ") + QString("circle(") + arg.at(0) + QString(")"));
			ModelManager::getInstance ()->append (tempCircle);
			return;
		}
		else if(whichModel == "rectangle")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() != 2)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("rectangle(1)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered argument is not number! -> e.g ( ") + QString("rectangle(1,a)) )"));
					return;
				}
				i++;
			}
			Rectangle *tempRectangle = new Rectangle(-(((QString)arg.at(0)).toFloat()) / 2,
													 0.0f,
													 -(((QString)arg.at(1)).toFloat()) / 2,
													 (((QString)arg.at(0)).toFloat()) / 2,
													 0.0f,
													 (((QString)arg.at(1)).toFloat()) / 2);
			ShowInformation::getInstance ()->show (QString("Rectangle created! -> ") + QString("rectangle(") + arg.at(0) + QString(",") + arg.at (1) + QString(")"));
			ModelManager::getInstance ()->append (tempRectangle);
			return;
		}
		else if(whichModel == "ellipse")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() != 2)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("ellipse(1)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered arguments are not number! -> e.g ( ") + QString("ellipse(a)) )"));
					return;
				}
				i++;
			}
			Ellipse *tempEllipse = new Ellipse(0.0f,
											   0.0f,
											   0.0f,
											   ((QString)arg.at(0)).toFloat(),
											   ((QString)arg.at(1)).toFloat());
			ShowInformation::getInstance ()->show (QString("Ellipse created! -> ") + QString("ellipse(") + arg.at(0) + QString(",") + arg.at (1) + QString(")"));
			ModelManager::getInstance ()->append (tempEllipse);
			return;
		}
		else if(whichModel == "line")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() < 4 || arg.count() % 2 != 0)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("line(1,2,3)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered arguments are not number! -> e.g ( ") + QString("line(1,2,3,a)) )"));
					return;
				}
				i++;
			}
			i = 0;
			VertexManager *vertices = new VertexManager;
			while(i != arg.count())
			{
				Vector *vect = new Vector(((QString)arg.at(i++)).toFloat(), ((QString)arg.at(i++)).toFloat());
				vertices->append(vect);
			}
			Line *tempLine = new Line(vertices);
			ShowInformation::getInstance ()->show (QString("Line created!"));
			ModelManager::getInstance ()->append (tempLine);
		}
		else if(whichModel == "polygon")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() < 9 || arg.count() % 3 != 0)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("polygon(1,2,3,4,5,6,7,8)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered arguments are not number! -> e.g ( ") + QString("polygon(1,2,3,a)) )"));
					return;
				}
				i++;
			}
			i = 0;
			VertexManager *vertices = new VertexManager;
			while(i != arg.count())
			{
				float x = ((QString)arg.at(i++)).toFloat();
				float y = ((QString)arg.at(i++)).toFloat();
				float z = ((QString)arg.at(i++)).toFloat();
				Vector *vect = new Vector(x, y, z);
				vertices->append(vect);
			}
			Polygon *tempPolygon = new Polygon(vertices);
			ShowInformation::getInstance ()->show (QString("polygon created!"));
			ModelManager::getInstance ()->append (tempPolygon);
		}
		else if(whichModel == "bezier")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() < 6 || arg.count() % 3 != 0)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("bezier(1,2,3,4,5)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered arguments are not number! -> e.g ( ") + QString("bezier(1,2,3,a)) )"));
					return;
				}
				i++;
			}
			i = 0;
			VertexManager *vertices = new VertexManager;
			while(i != arg.count())
			{
				float x = ((QString)arg.at(i++)).toFloat();
				float y = ((QString)arg.at(i++)).toFloat();
				float z = ((QString)arg.at(i++)).toFloat();
				Vector *vect = new Vector(x, y, z);
				vertices->append(vect);
			}
			Bezier *tempBezier = new Bezier(vertices);
			ShowInformation::getInstance ()->show (QString("Bezier created!"));
			ModelManager::getInstance ()->append (tempBezier);
		}
		else if(whichModel == "spline")
		{
			QStringList arg = arguments.split(",");
			if(arg.count() < 12 || arg.count() % 3 != 0)
			{
				ShowInformation::getInstance ()->show (QString("Arguments are not enough! -> e.g ( ") + QString("spline(1,2,3,4,5)) )"));
				return;
			}
			int i = 0;
			bool canConvertStringToNumber;
			while(i != arg.length())
			{
				((QString)arg.at(i)).toFloat(&canConvertStringToNumber);
				if(!canConvertStringToNumber)
				{
					ShowInformation::getInstance ()->show (QString("Entered arguments are not number! -> e.g ( ") + QString("spline(1,2,3,a)) )"));
					return;
				}
				i++;
			}
			i = 0;
			VertexManager *vertices = new VertexManager;
			while(i != arg.count())
			{
				float x = ((QString)arg.at(i++)).toFloat();
				float y = ((QString)arg.at(i++)).toFloat();
				float z = ((QString)arg.at(i++)).toFloat();
				Vector *vect = new Vector(x, y, z);
				vertices->append(vect);
			}
			Spline *tempSpline = new Spline(vertices);
			ShowInformation::getInstance ()->show (QString("Spline created!"));
			ModelManager::getInstance ()->append (tempSpline);
		}
		else
		{
			ShowInformation::getInstance ()->show (QString("Model not found"));
			return;
		}
	}
}
