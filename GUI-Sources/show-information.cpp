#include "show-information.h"

ShowInformation * ShowInformation::m_showInformation = 0;
ShowInformation * ShowInformation::getInstance ()
{
	if(!m_showInformation)
		m_showInformation = new ShowInformation();
	return m_showInformation;
}

void ShowInformation::setTarget (QLineEdit *target)
{
	this->m_target = target;
}

void ShowInformation::show (QString msg)
{
	this->m_target->setText (msg);
}
