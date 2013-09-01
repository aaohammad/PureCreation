#ifndef SHOWINFORMATION_H
#define SHOWINFORMATION_H

#include <QLineEdit>

class ShowInformation
{
public:
	static ShowInformation * getInstance();
	void setTarget(QLineEdit *);
	void show(QString);

private:
	ShowInformation(){}
	static ShowInformation * m_showInformation;
	QLineEdit * m_target;
};

#endif // SHOWINFORMATION_H
