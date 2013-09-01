#include "debuger.h"

Debuger * Debuger::m_debuger = 0;
Debuger * Debuger::getInstance ()
{
    if(!m_debuger)
        m_debuger = new Debuger();
    return m_debuger;
}

Debuger::Debuger()
{
    m_debugConsole = new Ui::DebugConsole();
}

void Debuger::showMsg (QString msg)
{
    m_debugConsole->msg_TextEditor->append (msg);
}

void Debuger::attachToParentAndShow (QWidget *parent)
{
    QWidget *widget = new QWidget(parent, Qt::Window);
    m_debugConsole->setupUi (widget);
    widget->setGeometry (0, 0, 0, 0);
    widget->show ();
}
