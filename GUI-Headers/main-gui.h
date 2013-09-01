#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include "ui_optionform.h"
#include "threads.h"
#include "ui_mainwindow.h"
#include "debuger.h"
#include "scene-widget.h"
#include "state-manager.h"
#include "command-line.h"
#include "show-information.h"

namespace Ui {
	class MainWindow;
}

class StateManager;

class MainGUI : public QMainWindow
{
	Q_OBJECT

public:
	MainGUI();
	SceneWidget * getSceneWidget();
	Ui::MainWindow * getMainWindow();

private:
	void connections();
	Ui::MainWindow *mainWindow;
	SceneWidget *sceneWidget;
	StateManager *stateManager;
	RefreshSceneThread *refreshSceneThread;

public slots:
	void optionDialog();
	void optionDialogAccept();
	void optionDialogReject();
	void treeWidgetItemChanged(QTreeWidgetItem*,int);
	void saveCheckBoxChanged();
	void saveLoadingSlot(int);
	void sendCommandToCommandLine();

signals:
	void executeCommand (QString);
};

#endif // MAINGUI_H
