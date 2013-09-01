#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "bezier.h"
#include "spline.h"
#include "sphere.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"
#include "model-manager.h"
#include "show-information.h"

class CommandLine
{
public:
	static CommandLine * getInstance();
	void executeCommand(QString cmd);

private:
	CommandLine(){}
	static CommandLine * m_commandLine;
};

#endif // COMMANDLINE_H
