#ifndef GRAPHIC_PROJECT_MAINWINDOW_H
#define GRAPHIC_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "ui_optionform.h"
#include "colorpickerwidget.h"
#include "statemanager.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void changeEvent(QEvent *e);
    Ui::optionDialog *oDialog;
    QDialog *dialog;
    QProgressBar *progressBar;

private:
    void connections();

    Ui::MainWindow *ui;
    Glwidget *gLWidget;
//    ColorPickerWidget *colorPickerWidget;
    StateManager *stateManager;

protected slots:
    void optionDialog();
    void optionDialogAccept();
    void optionDialogReject();
    void treeWidgetItemChanged(QTreeWidgetItem*,int);
    void saveCheckBoxChanged();
    void saveLoadingSlot(int);
    void showMessageOnStatusBarSlot(QString, int);
};

#endif // GRAPHIC_PROJECT_MAINWINDOW_H
