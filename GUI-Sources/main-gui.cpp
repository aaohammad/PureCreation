#include "main-gui.h"

MainGUI::MainGUI()
{
	Debuger::getInstance ()->attachToParentAndShow (this);  // To show debuger console.

	mainWindow = new Ui::MainWindow();
	mainWindow->setupUi(this);
	ShowInformation::getInstance ()->setTarget (mainWindow->infoLineEdit);
	sceneWidget = new SceneWidget();
	stateManager = new StateManager(mainWindow);
	stateManager->addGLWidget (sceneWidget->getGLWidgets ());
	SelectManager::getInstance ()->addGLWidget (sceneWidget->getGLWidgets ());
	mainWindow->glwidget_gridLayout->addWidget (sceneWidget, 0, 1, 1, 1);
	mainWindow->actionObject_Mode->setChecked(true);
	refreshSceneThread = new RefreshSceneThread(sceneWidget);
	refreshSceneThread->start();
	connections();
}

SceneWidget * MainGUI::getSceneWidget ()
{
	return sceneWidget;
}

Ui::MainWindow * MainGUI::getMainWindow ()
{
	return mainWindow;
}

void MainGUI::optionDialog()
{
//    oDialog = new Ui::optionDialog;
//    dialog = new QDialog;
//    oDialog->setupUi(dialog);
//    int timerValue;
//    bool timerStatus;
//    gLWidget->getSaveTimerAcivated(timerStatus, timerValue);
//    if(timerStatus)
//    {
//        oDialog->savecheckBox->setChecked(true);
//        oDialog->savespinBox->setValue(timerValue);
//        oDialog->savespinBox->setMinimum(1);
//    }
//    else
//    {
//        oDialog->savecheckBox->setChecked(false);
//        oDialog->savespinBox->setMinimum(0);
//        oDialog->savespinBox->setMaximum(0);
//    }
//    connect(oDialog->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(treeWidgetItemChanged(QTreeWidgetItem*,int)));
//    connect(oDialog->okpushButton, SIGNAL(clicked()), this, SLOT(optionDialogAccept()));
//    connect(oDialog->cancelpushButton,SIGNAL(clicked()), this, SLOT(optionDialogReject()));
//    connect(oDialog->savecheckBox, SIGNAL(toggled(bool)), this, SLOT(saveCheckBoxChanged()));
//    dialog->exec();
}

void MainGUI::optionDialogReject()
{
}

void MainGUI::optionDialogAccept()
{
//    if(oDialog->treeWidget->currentItem()->text(0) == "Save")
//    {
//        if(oDialog->savecheckBox->isChecked())
//        {
//            gLWidget->activeSaveTimer(true, oDialog->savespinBox->value());
//        }
//        else
//        {
//            gLWidget->activeSaveTimer(false, -1);
//        }
//    }
//    delete dialog;
}

void MainGUI::treeWidgetItemChanged(QTreeWidgetItem *, int)
{
}

void MainGUI::saveCheckBoxChanged()
{
}

void MainGUI::saveLoadingSlot(int value)
{
	if(value != -1)
	{
		mainWindow->progressBar->setValue(value);
	}
	else
		mainWindow->progressBar->reset();
}

void MainGUI::connections()
{
	connect (mainWindow->executeCommandPushButton, SIGNAL(clicked()), this, SLOT(sendCommandToCommandLine()));
}

void MainGUI::sendCommandToCommandLine ()
{
	CommandLine::getInstance ()->executeCommand (mainWindow->commandLineEdit->text ());
}
