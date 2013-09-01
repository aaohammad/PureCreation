#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include "ui_debug-console.h"

class Debuger
{
public:
    static Debuger * getInstance();
    void showMsg(QString msg);    // show text on debuger
    void attachToParentAndShow(QWidget * parent);

private:
    Debuger();
    static Debuger * m_debuger;
    Ui::DebugConsole *m_debugConsole;

};

#endif // DEBUGWINDOW_H
