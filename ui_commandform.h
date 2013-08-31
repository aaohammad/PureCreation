/********************************************************************************
** Form generated from reading UI file 'commandform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDFORM_H
#define UI_COMMANDFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Commandform
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancel_button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ok_button;

    void setupUi(QWidget *Commandform)
    {
        if (Commandform->objectName().isEmpty())
            Commandform->setObjectName(QString::fromUtf8("Commandform"));
        Commandform->resize(600, 396);
        Commandform->setMinimumSize(QSize(600, 0));
        gridLayout = new QGridLayout(Commandform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Commandform);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Commandform);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Commandform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        textEdit = new QTextEdit(Commandform);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cancel_button = new QPushButton(Commandform);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));

        horizontalLayout_3->addWidget(cancel_button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        ok_button = new QPushButton(Commandform);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));

        horizontalLayout_3->addWidget(ok_button);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Commandform);

        QMetaObject::connectSlotsByName(Commandform);
    } // setupUi

    void retranslateUi(QWidget *Commandform)
    {
        Commandform->setWindowTitle(QApplication::translate("Commandform", "Command Insertion", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Commandform", "Enter Command Here :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Commandform", "See some examples :", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("Commandform", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">circle(xCenter, yCenter, radius)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">circle(0.0, 0.0, 10.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">square(left, top, right, bottom)</span></p>\n"
"<p style=\" m"
                        "argin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">square(-1.0, 1.0, 1.0, -1.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">ellipse(xCenter, yCenter, width, height)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">ellipse(0.0, 0.0, 10.0, 5.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">circlearc3(xfirstpoint, yfirstpoint, xsecondpoint, ysecondpoint, xthirdpoint, ythirdpoint)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">circlearc3(0.0, 0.0, 10.0, 5.0, 20.0, 0.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">circlearc2(xfirstpoint, yfirstpoint, xsecondpoint, ysecondpoint, radius)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; color:#ffffff;\">circlearc2</span><span style=\" font-size:8pt; font-weight:296;\">(0.0, 0.0, 10.0, 5.0, 10.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">line(xfirstpoint, yfirstpoint, xsecondpoint, ysecondpoint, ...)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">line(0.0, 0.0, 1.0, 1.0, 25.0, 10.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">polygon(xfirstpoint, yfirstpoint, xsecondpoint, ysecondpoint, ...)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">polygon(0.0, 0.0, 1.0, 1.0, 25.0, 10.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">bezier(xfirstCVpoint, yfirstCVpoint, xsecondCVpoint, ysecondCVpoint, ...)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-"
                        "indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">bezier(0.0, 0.0, 10.0, 10.0, -15.0, -10.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">spline(xfirstCVpoint, yfirstCVpoint, xsecondCVpoint, ysecondCVpoint, ...)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">spline(0.0, 0.0, 10.0, 10.0, -15.0, -10.0, 15.0, 0.0)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#786432;\">bspline(xfirstCVpoint, yfirstCVpoint, xsecondCVpoint, ysecondCVpoint, ...)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:10px;\"><span style=\" font-size:8pt; font-weight:296;\">bspline(0.0, 0.0, 10.0, 10.0, -15.0, -10.0)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Commandform", "Cancel", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Commandform", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Commandform: public Ui_Commandform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDFORM_H
