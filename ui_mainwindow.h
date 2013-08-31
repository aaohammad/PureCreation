/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "colorwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *actionRecent_Doc_uments;
    QAction *action_Save;
    QAction *actionSave_As;
    QAction *action_Export;
    QAction *action_Print;
    QAction *actionE_xit;
    QAction *action_Group;
    QAction *action_Ungroup;
    QAction *attributeEditor;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDelete;
    QAction *actionCommand;
    QAction *actionDraw_Grid;
    QAction *actionInsert;
    QAction *actionSelect_All;
    QAction *actionAbout_Qt;
    QAction *actionAbout_me;
    QAction *action_Option;
    QAction *actionBring_To_Front;
    QAction *actionSend_To_Back;
    QAction *actionCrop;
    QAction *actionReflection;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QToolBox *toolBox;
    QWidget *twod_drawing_tabPage;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QToolButton *selection_toolButton;
    QToolButton *moveSelected_toolButton;
    QToolButton *scaleSelected_toolButton;
    QToolButton *rotateSelected_toolButton;
    QToolButton *zoom_toolButton;
    QFrame *line;
    QToolButton *square_toolButton;
    QToolButton *circle_toolButton;
    QToolButton *ellipse_toolButton;
    QToolButton *line_toolButton;
    QToolButton *polygon_toolButton;
    QToolButton *bezier_toolButton;
    QToolButton *spline_toolButton;
    QToolButton *text_toolButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    ColorWidget *colorWidget;
    QSpacerItem *verticalSpacer;
    QWidget *scenewidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menu_Edit;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(869, 630);
        MainWindow->setMouseTracking(true);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/9048.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/new"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon1);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/open"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon2);
        actionRecent_Doc_uments = new QAction(MainWindow);
        actionRecent_Doc_uments->setObjectName(QString::fromUtf8("actionRecent_Doc_uments"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/1294938623_My documents.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecent_Doc_uments->setIcon(icon3);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/save"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon4);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/save as"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon5);
        action_Export = new QAction(MainWindow);
        action_Export->setObjectName(QString::fromUtf8("action_Export"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/export"), QSize(), QIcon::Normal, QIcon::Off);
        action_Export->setIcon(icon6);
        action_Print = new QAction(MainWindow);
        action_Print->setObjectName(QString::fromUtf8("action_Print"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icons/print"), QSize(), QIcon::Normal, QIcon::Off);
        action_Print->setIcon(icon7);
        actionE_xit = new QAction(MainWindow);
        actionE_xit->setObjectName(QString::fromUtf8("actionE_xit"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/icons/exit"), QSize(), QIcon::Normal, QIcon::Off);
        actionE_xit->setIcon(icon8);
        action_Group = new QAction(MainWindow);
        action_Group->setObjectName(QString::fromUtf8("action_Group"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/icons/group"), QSize(), QIcon::Normal, QIcon::Off);
        action_Group->setIcon(icon9);
        action_Ungroup = new QAction(MainWindow);
        action_Ungroup->setObjectName(QString::fromUtf8("action_Ungroup"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/icons/ungroup"), QSize(), QIcon::Normal, QIcon::Off);
        action_Ungroup->setIcon(icon10);
        attributeEditor = new QAction(MainWindow);
        attributeEditor->setObjectName(QString::fromUtf8("attributeEditor"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/icons/attribute editor"), QSize(), QIcon::Normal, QIcon::Off);
        attributeEditor->setIcon(icon11);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/icons/undo"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon12);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/icons/redo"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon13);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/icons/delete"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon14);
        actionCommand = new QAction(MainWindow);
        actionCommand->setObjectName(QString::fromUtf8("actionCommand"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/icons/command"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommand->setIcon(icon15);
        actionDraw_Grid = new QAction(MainWindow);
        actionDraw_Grid->setObjectName(QString::fromUtf8("actionDraw_Grid"));
        actionDraw_Grid->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/icons/grid"), QSize(), QIcon::Normal, QIcon::Off);
        actionDraw_Grid->setIcon(icon16);
        actionInsert = new QAction(MainWindow);
        actionInsert->setObjectName(QString::fromUtf8("actionInsert"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/icons/image"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert->setIcon(icon17);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/1301224667_Gnome-Edit-Select-All-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon18);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAbout_me = new QAction(MainWindow);
        actionAbout_me->setObjectName(QString::fromUtf8("actionAbout_me"));
        action_Option = new QAction(MainWindow);
        action_Option->setObjectName(QString::fromUtf8("action_Option"));
        actionBring_To_Front = new QAction(MainWindow);
        actionBring_To_Front->setObjectName(QString::fromUtf8("actionBring_To_Front"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/icons/bring to front"), QSize(), QIcon::Normal, QIcon::Off);
        actionBring_To_Front->setIcon(icon19);
        actionSend_To_Back = new QAction(MainWindow);
        actionSend_To_Back->setObjectName(QString::fromUtf8("actionSend_To_Back"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix1/icons/send to back"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend_To_Back->setIcon(icon20);
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QString::fromUtf8("actionCrop"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix1/icons/crop"), QSize(), QIcon::Normal, QIcon::Off);
        actionCrop->setIcon(icon21);
        actionReflection = new QAction(MainWindow);
        actionReflection->setObjectName(QString::fromUtf8("actionReflection"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/prefix1/icons/reflect"), QSize(), QIcon::Normal, QIcon::Off);
        actionReflection->setIcon(icon22);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(150, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolBox = new QToolBox(frame);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 10, 191, 531));
        toolBox->setStyleSheet(QString::fromUtf8(""));
        twod_drawing_tabPage = new QWidget();
        twod_drawing_tabPage->setObjectName(QString::fromUtf8("twod_drawing_tabPage"));
        twod_drawing_tabPage->setGeometry(QRect(0, 0, 181, 494));
        gridLayout_2 = new QGridLayout(twod_drawing_tabPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selection_toolButton = new QToolButton(twod_drawing_tabPage);
        selection_toolButton->setObjectName(QString::fromUtf8("selection_toolButton"));
        QFont font;
        font.setPointSize(7);
        selection_toolButton->setFont(font);
        selection_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/new/prefix1/icons/pointer"), QSize(), QIcon::Normal, QIcon::Off);
        selection_toolButton->setIcon(icon23);
        selection_toolButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        gridLayout->addWidget(selection_toolButton, 0, 0, 1, 1);

        moveSelected_toolButton = new QToolButton(twod_drawing_tabPage);
        moveSelected_toolButton->setObjectName(QString::fromUtf8("moveSelected_toolButton"));
        moveSelected_toolButton->setFont(font);
        moveSelected_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/new/prefix1/icons/move"), QSize(), QIcon::Normal, QIcon::Off);
        moveSelected_toolButton->setIcon(icon24);
        moveSelected_toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(moveSelected_toolButton, 0, 1, 1, 1);

        scaleSelected_toolButton = new QToolButton(twod_drawing_tabPage);
        scaleSelected_toolButton->setObjectName(QString::fromUtf8("scaleSelected_toolButton"));
        scaleSelected_toolButton->setFont(font);
        scaleSelected_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/new/prefix1/icons/scale"), QSize(), QIcon::Normal, QIcon::Off);
        scaleSelected_toolButton->setIcon(icon25);
        scaleSelected_toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(scaleSelected_toolButton, 0, 2, 1, 1);

        rotateSelected_toolButton = new QToolButton(twod_drawing_tabPage);
        rotateSelected_toolButton->setObjectName(QString::fromUtf8("rotateSelected_toolButton"));
        rotateSelected_toolButton->setFont(font);
        rotateSelected_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/new/prefix1/icons/rotate"), QSize(), QIcon::Normal, QIcon::Off);
        rotateSelected_toolButton->setIcon(icon26);
        rotateSelected_toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(rotateSelected_toolButton, 0, 3, 1, 1);

        zoom_toolButton = new QToolButton(twod_drawing_tabPage);
        zoom_toolButton->setObjectName(QString::fromUtf8("zoom_toolButton"));
        QFont font1;
        font1.setPointSize(6);
        font1.setBold(false);
        font1.setWeight(50);
        zoom_toolButton->setFont(font1);
        zoom_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        zoom_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/new/prefix1/icons/change view"), QSize(), QIcon::Normal, QIcon::Off);
        zoom_toolButton->setIcon(icon27);
        zoom_toolButton->setIconSize(QSize(16, 16));
        zoom_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(zoom_toolButton, 0, 4, 1, 1);

        line = new QFrame(twod_drawing_tabPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 5);

        square_toolButton = new QToolButton(twod_drawing_tabPage);
        square_toolButton->setObjectName(QString::fromUtf8("square_toolButton"));
        square_toolButton->setFont(font1);
        square_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        square_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/new/prefix1/icons/square"), QSize(), QIcon::Normal, QIcon::Off);
        square_toolButton->setIcon(icon28);
        square_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(square_toolButton, 2, 0, 1, 1);

        circle_toolButton = new QToolButton(twod_drawing_tabPage);
        circle_toolButton->setObjectName(QString::fromUtf8("circle_toolButton"));
        circle_toolButton->setFont(font1);
        circle_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        circle_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/new/prefix1/icons/circle"), QSize(), QIcon::Normal, QIcon::Off);
        circle_toolButton->setIcon(icon29);
        circle_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(circle_toolButton, 2, 1, 1, 1);

        ellipse_toolButton = new QToolButton(twod_drawing_tabPage);
        ellipse_toolButton->setObjectName(QString::fromUtf8("ellipse_toolButton"));
        ellipse_toolButton->setFont(font1);
        ellipse_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        ellipse_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/new/prefix1/icons/ellipse"), QSize(), QIcon::Normal, QIcon::Off);
        ellipse_toolButton->setIcon(icon30);
        ellipse_toolButton->setIconSize(QSize(16, 16));
        ellipse_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(ellipse_toolButton, 2, 2, 1, 1);

        line_toolButton = new QToolButton(twod_drawing_tabPage);
        line_toolButton->setObjectName(QString::fromUtf8("line_toolButton"));
        line_toolButton->setFont(font1);
        line_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        line_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/new/prefix1/icons/line"), QSize(), QIcon::Normal, QIcon::Off);
        line_toolButton->setIcon(icon31);
        line_toolButton->setIconSize(QSize(16, 16));
        line_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(line_toolButton, 2, 3, 1, 1);

        polygon_toolButton = new QToolButton(twod_drawing_tabPage);
        polygon_toolButton->setObjectName(QString::fromUtf8("polygon_toolButton"));
        polygon_toolButton->setFont(font1);
        polygon_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        polygon_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/new/prefix1/icons/polygon"), QSize(), QIcon::Normal, QIcon::Off);
        polygon_toolButton->setIcon(icon32);
        polygon_toolButton->setIconSize(QSize(16, 16));
        polygon_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(polygon_toolButton, 2, 4, 1, 1);

        bezier_toolButton = new QToolButton(twod_drawing_tabPage);
        bezier_toolButton->setObjectName(QString::fromUtf8("bezier_toolButton"));
        bezier_toolButton->setFont(font1);
        bezier_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        bezier_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/new/prefix1/icons/bezier"), QSize(), QIcon::Normal, QIcon::Off);
        bezier_toolButton->setIcon(icon33);
        bezier_toolButton->setIconSize(QSize(16, 16));
        bezier_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(bezier_toolButton, 3, 0, 1, 1);

        spline_toolButton = new QToolButton(twod_drawing_tabPage);
        spline_toolButton->setObjectName(QString::fromUtf8("spline_toolButton"));
        spline_toolButton->setFont(font1);
        spline_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        spline_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/new/prefix1/icons/spline"), QSize(), QIcon::Normal, QIcon::Off);
        spline_toolButton->setIcon(icon34);
        spline_toolButton->setIconSize(QSize(16, 16));
        spline_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(spline_toolButton, 3, 1, 1, 1);

        text_toolButton = new QToolButton(twod_drawing_tabPage);
        text_toolButton->setObjectName(QString::fromUtf8("text_toolButton"));
        text_toolButton->setFont(font1);
        text_toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        text_toolButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/new/prefix1/icons/text"), QSize(), QIcon::Normal, QIcon::Off);
        text_toolButton->setIcon(icon35);
        text_toolButton->setIconSize(QSize(16, 16));
        text_toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(text_toolButton, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 2);

        line_2 = new QFrame(twod_drawing_tabPage);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 5);

        colorWidget = new ColorWidget(twod_drawing_tabPage);
        colorWidget->setObjectName(QString::fromUtf8("colorWidget"));

        gridLayout->addWidget(colorWidget, 5, 0, 1, 5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 5);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        toolBox->addItem(twod_drawing_tabPage, QString::fromUtf8("2D Drawing"));

        gridLayout_5->addWidget(frame, 0, 0, 1, 1);

        scenewidget = new QWidget(centralWidget);
        scenewidget->setObjectName(QString::fromUtf8("scenewidget"));

        gridLayout_5->addWidget(scenewidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 21));
        menuBar->setStyleSheet(QString::fromUtf8(""));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_File->setStyleSheet(QString::fromUtf8(""));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Edit->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addSeparator();
        menu_File->addAction(action_Save);
        menu_File->addAction(actionSave_As);
        menu_File->addSeparator();
        menu_File->addAction(action_Export);
        menu_File->addSeparator();
        menu_File->addAction(action_Print);
        menu_File->addAction(actionE_xit);
        menu_Help->addAction(actionAbout_me);
        menu_Help->addAction(actionAbout_Qt);
        menu_Edit->addAction(actionRedo);
        menu_Edit->addAction(actionUndo);
        menu_Edit->addAction(actionSend_To_Back);
        menu_Edit->addAction(actionBring_To_Front);
        menu_Edit->addAction(actionSelect_All);
        menu_Edit->addAction(actionDelete);
        menu_Edit->addAction(actionCommand);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionDraw_Grid);
        menu_Edit->addAction(actionInsert);
        menu_Edit->addAction(action_Group);
        menu_Edit->addAction(action_Ungroup);
        menu_Edit->addAction(actionCrop);
        menu_Edit->addAction(attributeEditor);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Option);
        toolBar->addAction(action_New);
        toolBar->addAction(action_Open);
        toolBar->addSeparator();
        toolBar->addAction(action_Save);
        toolBar->addAction(actionSave_As);
        toolBar->addAction(action_Print);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addAction(actionSend_To_Back);
        toolBar->addAction(actionBring_To_Front);
        toolBar->addAction(action_Group);
        toolBar->addAction(action_Ungroup);
        toolBar->addAction(actionReflection);
        toolBar->addAction(actionSelect_All);
        toolBar->addAction(actionDelete);
        toolBar->addSeparator();
        toolBar->addAction(actionDraw_Grid);
        toolBar->addSeparator();
        toolBar->addAction(attributeEditor);
        toolBar->addAction(actionCommand);
        toolBar->addAction(actionInsert);
        toolBar->addAction(action_Export);
        toolBar->addAction(actionCrop);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pure Creation", 0, QApplication::UnicodeUTF8));
        action_New->setText(QApplication::translate("MainWindow", "&New", 0, QApplication::UnicodeUTF8));
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0, QApplication::UnicodeUTF8));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionRecent_Doc_uments->setText(QApplication::translate("MainWindow", "Recent Doc&uments", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save &As...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSave_As->setStatusTip(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        action_Export->setText(QApplication::translate("MainWindow", "&Export", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_Export->setStatusTip(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Export->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        action_Print->setText(QApplication::translate("MainWindow", "&Print", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_Print->setStatusTip(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Print->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionE_xit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionE_xit->setStatusTip(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Group->setText(QApplication::translate("MainWindow", "&Group", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_Group->setStatusTip(QApplication::translate("MainWindow", "Group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Group->setShortcut(QApplication::translate("MainWindow", "Shift+G", 0, QApplication::UnicodeUTF8));
        action_Ungroup->setText(QApplication::translate("MainWindow", "&Ungroup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_Ungroup->setStatusTip(QApplication::translate("MainWindow", "Ungroup", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Ungroup->setShortcut(QApplication::translate("MainWindow", "Shift+U", 0, QApplication::UnicodeUTF8));
        attributeEditor->setText(QApplication::translate("MainWindow", "Attribute Edittor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        attributeEditor->setStatusTip(QApplication::translate("MainWindow", "Attribute Edittor", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        attributeEditor->setShortcut(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionUndo->setStatusTip(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDelete->setStatusTip(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionCommand->setText(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCommand->setToolTip(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCommand->setStatusTip(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCommand->setShortcut(QApplication::translate("MainWindow", "Shift+C", 0, QApplication::UnicodeUTF8));
        actionDraw_Grid->setText(QApplication::translate("MainWindow", "Draw Grid", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDraw_Grid->setToolTip(QApplication::translate("MainWindow", "Show Grid", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDraw_Grid->setStatusTip(QApplication::translate("MainWindow", "Show Grid", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionDraw_Grid->setShortcut(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
        actionInsert->setText(QApplication::translate("MainWindow", "Insert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionInsert->setToolTip(QApplication::translate("MainWindow", "Insert Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionInsert->setStatusTip(QApplication::translate("MainWindow", "Insert Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionInsert->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSelect_All->setToolTip(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelect_All->setStatusTip(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSelect_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAbout_Qt->setStatusTip(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAbout_me->setText(QApplication::translate("MainWindow", "About me!", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbout_me->setToolTip(QApplication::translate("MainWindow", "About me!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAbout_me->setStatusTip(QApplication::translate("MainWindow", "About me!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Option->setText(QApplication::translate("MainWindow", "&Option", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Option->setToolTip(QApplication::translate("MainWindow", "Option", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Option->setStatusTip(QApplication::translate("MainWindow", "Option", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBring_To_Front->setText(QApplication::translate("MainWindow", "Bring To Front", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBring_To_Front->setToolTip(QApplication::translate("MainWindow", "Bring To Front", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBring_To_Front->setStatusTip(QApplication::translate("MainWindow", "Bring To Front", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBring_To_Front->setShortcut(QApplication::translate("MainWindow", "Shift+F", 0, QApplication::UnicodeUTF8));
        actionSend_To_Back->setText(QApplication::translate("MainWindow", "Send To Back", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSend_To_Back->setToolTip(QApplication::translate("MainWindow", "Send To Back", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSend_To_Back->setStatusTip(QApplication::translate("MainWindow", "Send To Back", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSend_To_Back->setShortcut(QApplication::translate("MainWindow", "Shift+B", 0, QApplication::UnicodeUTF8));
        actionCrop->setText(QApplication::translate("MainWindow", "Crop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCrop->setToolTip(QApplication::translate("MainWindow", "Crop", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCrop->setStatusTip(QApplication::translate("MainWindow", "Crop", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCrop->setShortcut(QApplication::translate("MainWindow", "Shift+C", 0, QApplication::UnicodeUTF8));
        actionReflection->setText(QApplication::translate("MainWindow", "Reflection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionReflection->setToolTip(QApplication::translate("MainWindow", "Reflection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionReflection->setStatusTip(QApplication::translate("MainWindow", "Reflection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionReflection->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selection_toolButton->setToolTip(QApplication::translate("MainWindow", "Select Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        selection_toolButton->setStatusTip(QApplication::translate("MainWindow", "Select Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        selection_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        moveSelected_toolButton->setToolTip(QApplication::translate("MainWindow", "Move Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        moveSelected_toolButton->setStatusTip(QApplication::translate("MainWindow", "Move Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        moveSelected_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        scaleSelected_toolButton->setToolTip(QApplication::translate("MainWindow", "Scale Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        scaleSelected_toolButton->setStatusTip(QApplication::translate("MainWindow", "Scale Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        scaleSelected_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        rotateSelected_toolButton->setToolTip(QApplication::translate("MainWindow", "Rotate Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rotateSelected_toolButton->setStatusTip(QApplication::translate("MainWindow", "Rotate Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rotateSelected_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        zoom_toolButton->setToolTip(QApplication::translate("MainWindow", "Change View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        zoom_toolButton->setStatusTip(QApplication::translate("MainWindow", "Change View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        zoom_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        square_toolButton->setToolTip(QApplication::translate("MainWindow", "Square Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        square_toolButton->setStatusTip(QApplication::translate("MainWindow", "Square Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        square_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        circle_toolButton->setToolTip(QApplication::translate("MainWindow", "Circle Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        circle_toolButton->setStatusTip(QApplication::translate("MainWindow", "Circle Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        circle_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        ellipse_toolButton->setToolTip(QApplication::translate("MainWindow", "Ellipse Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ellipse_toolButton->setStatusTip(QApplication::translate("MainWindow", "Ellipse Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        ellipse_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        line_toolButton->setToolTip(QApplication::translate("MainWindow", "Line Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        line_toolButton->setStatusTip(QApplication::translate("MainWindow", "Line Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        line_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        polygon_toolButton->setToolTip(QApplication::translate("MainWindow", "Polygon Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        polygon_toolButton->setStatusTip(QApplication::translate("MainWindow", "Polygon Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        polygon_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        bezier_toolButton->setToolTip(QApplication::translate("MainWindow", "Bezier Curve Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        bezier_toolButton->setStatusTip(QApplication::translate("MainWindow", "Bezier Curve Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        bezier_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        spline_toolButton->setToolTip(QApplication::translate("MainWindow", "Spline Curve Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spline_toolButton->setStatusTip(QApplication::translate("MainWindow", "Spline Curve Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        spline_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        text_toolButton->setToolTip(QApplication::translate("MainWindow", "Text Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        text_toolButton->setStatusTip(QApplication::translate("MainWindow", "Text Tool", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        text_toolButton->setText(QString());
        toolBox->setItemText(toolBox->indexOf(twod_drawing_tabPage), QApplication::translate("MainWindow", "2D Drawing", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
