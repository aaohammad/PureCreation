#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *perspective_widget_layout = new QGridLayout(ui->scenewidget);
    QGLFormat qglfrmt;
    gLWidget = new Glwidget();
    perspective_widget_layout->addWidget(gLWidget);
    setLayout(perspective_widget_layout);
    ui->actionDraw_Grid->setChecked(true);
    progressBar = new QProgressBar(this);
    progressBar->setMaximumHeight(16);
    progressBar->setMaximumWidth(200);
    progressBar->setRange(0, 100);
    ui->statusBar->addPermanentWidget(progressBar);
    connections();
    stateManager = new StateManager(this->ui, this->gLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::optionDialog()
{
    oDialog = new Ui::optionDialog;
    dialog = new QDialog;
    oDialog->setupUi(dialog);
    int timerValue;
    bool timerStatus;
    gLWidget->getSaveTimerAcivated(timerStatus, timerValue);
    if(timerStatus)
    {
        oDialog->savecheckBox->setChecked(true);
        oDialog->savespinBox->setValue(timerValue);
        oDialog->savespinBox->setMinimum(1);
    }
    else
    {
        oDialog->savecheckBox->setChecked(false);
        oDialog->savespinBox->setMinimum(0);
        oDialog->savespinBox->setMaximum(0);
    }
    connect(oDialog->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(treeWidgetItemChanged(QTreeWidgetItem*,int)));
    connect(oDialog->okpushButton, SIGNAL(clicked()), this, SLOT(optionDialogAccept()));
    connect(oDialog->cancelpushButton,SIGNAL(clicked()), this, SLOT(optionDialogReject()));
    connect(oDialog->savecheckBox, SIGNAL(toggled(bool)), this, SLOT(saveCheckBoxChanged()));
    dialog->exec();
}

void MainWindow::optionDialogReject()
{
    delete dialog;
}

void MainWindow::optionDialogAccept()
{
    if(oDialog->treeWidget->currentItem()->text(0) == "Save")
    {
        if(oDialog->savecheckBox->isChecked())
        {
            gLWidget->activeSaveTimer(true, oDialog->savespinBox->value());
        }
        else
        {
            gLWidget->activeSaveTimer(false, -1);
        }
    }
    delete dialog;
}

void MainWindow::treeWidgetItemChanged(QTreeWidgetItem *, int)
{
}

void MainWindow::saveCheckBoxChanged()
{
    if(oDialog->savecheckBox->isChecked())
    {
        oDialog->savespinBox->setMinimum(1);
        oDialog->savespinBox->setMaximum(999);
    }
    else
    {
        oDialog->savespinBox->setMinimum(0);
        oDialog->savespinBox->setMaximum(0);
    }
}

void MainWindow::saveLoadingSlot(int value)
{
    if(value != -1)
    {
        progressBar->setValue(value);
    }
    else
        progressBar->reset();
}

void MainWindow::showMessageOnStatusBarSlot(QString msg, int time)
{
    ui->statusBar->showMessage(msg, time);
}

void MainWindow::connections()
{
    connect(ui->colorWidget->colorPickerWidget->colorTriangle, SIGNAL(colorChanged(QColor)), gLWidget, SLOT(changeCurrentColor(QColor)));
    connect(gLWidget, SIGNAL(showMessageOnStatusBarSignal(QString,int)), this, SLOT(showMessageOnStatusBarSlot(QString,int)));
    connect(gLWidget, SIGNAL(saveloadingSignal(int)), this, SLOT(saveLoadingSlot(int)));
    connect(ui->action_Group, SIGNAL(triggered()), gLWidget, SLOT(group()));
    connect(ui->action_Ungroup, SIGNAL(triggered()), gLWidget, SLOT(ungroup()));
    connect(ui->action_Save, SIGNAL(triggered()), gLWidget, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), gLWidget, SLOT(saveAs()));
    connect(ui->action_Open, SIGNAL(triggered()), gLWidget, SLOT(open()));
    connect(ui->action_Print, SIGNAL(triggered()), gLWidget, SLOT(print()));
    connect(ui->actionInsert, SIGNAL(triggered()), gLWidget, SLOT(insert()));
    connect(ui->actionDraw_Grid, SIGNAL(changed()), gLWidget, SLOT(drawGrid()));
    connect(ui->action_Export, SIGNAL(triggered()), gLWidget, SLOT(exportImage()));
    connect(ui->action_New, SIGNAL(triggered()), gLWidget, SLOT(newScene()));
    connect(ui->attributeEditor, SIGNAL(triggered()), gLWidget, SLOT(attributeEditor()));
    connect(ui->actionDelete, SIGNAL(triggered()), gLWidget, SLOT(deleteModel()));
    connect(ui->actionRedo, SIGNAL(triggered()), gLWidget, SLOT(redo()));
    connect(ui->actionUndo, SIGNAL(triggered()), gLWidget, SLOT(undo()));
    connect(ui->actionCommand, SIGNAL(triggered()), gLWidget, SLOT(commandOperator()));
    connect(ui->actionSelect_All, SIGNAL(triggered()), gLWidget, SLOT(selectAll()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), gLWidget, SLOT(aboutQt()));
    connect(ui->actionAbout_me, SIGNAL(triggered()), gLWidget, SLOT(aboutMe()));
    connect(ui->action_Option, SIGNAL(triggered()), this, SLOT(optionDialog()));
    connect(ui->actionBring_To_Front, SIGNAL(triggered()), gLWidget, SLOT(bringToFront()));
    connect(ui->actionSend_To_Back, SIGNAL(triggered()), gLWidget, SLOT(sendToBack()));
    connect(ui->actionCrop, SIGNAL(triggered()), gLWidget, SLOT(crop()));
    connect(ui->text_toolButton, SIGNAL(clicked()), gLWidget, SLOT(insertText()));
    connect(ui->actionReflection, SIGNAL(triggered()), gLWidget, SLOT(reflection()));
}
