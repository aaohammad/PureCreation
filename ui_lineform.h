/********************************************************************************
** Form generated from reading UI file 'lineform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEFORM_H
#define UI_LINEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lineForm
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *lineComboBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *xLineLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *yLineLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *widthlineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *color_label;
    QPushButton *lineColor_button;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *translate_label;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *scale_label;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QLabel *scale_label_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QLabel *xtranslate_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *xtranslate_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QLabel *ytranslate_label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *yTranslate_lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_7;
    QLabel *xScale_label_2;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *xScale_lineEdit;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_9;
    QLabel *yScale_label_2;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *yScale_lineEdit;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_24;
    QSpacerItem *horizontalSpacer_11;
    QLabel *angle_label;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *rotate_lineEdit;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *line_Cancel;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *line_OK;

    void setupUi(QWidget *lineForm)
    {
        if (lineForm->objectName().isEmpty())
            lineForm->setObjectName(QString::fromUtf8("lineForm"));
        lineForm->resize(327, 469);
        gridLayout_3 = new QGridLayout(lineForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label = new QLabel(lineForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        frame = new QFrame(lineForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineComboBox = new QComboBox(frame);
        lineComboBox->setObjectName(QString::fromUtf8("lineComboBox"));

        horizontalLayout->addWidget(lineComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        xLineLineEdit = new QLineEdit(frame);
        xLineLineEdit->setObjectName(QString::fromUtf8("xLineLineEdit"));

        horizontalLayout_2->addWidget(xLineLineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        yLineLineEdit = new QLineEdit(frame);
        yLineLineEdit->setObjectName(QString::fromUtf8("yLineLineEdit"));

        horizontalLayout_3->addWidget(yLineLineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_15->addWidget(label_5);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);

        widthlineEdit = new QLineEdit(frame);
        widthlineEdit->setObjectName(QString::fromUtf8("widthlineEdit"));

        horizontalLayout_15->addWidget(widthlineEdit);


        gridLayout->addLayout(horizontalLayout_15, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        color_label = new QLabel(frame);
        color_label->setObjectName(QString::fromUtf8("color_label"));

        horizontalLayout_7->addWidget(color_label);

        lineColor_button = new QPushButton(frame);
        lineColor_button->setObjectName(QString::fromUtf8("lineColor_button"));

        horizontalLayout_7->addWidget(lineColor_button);


        gridLayout->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_16);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_16->addWidget(label_6);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_17);


        verticalLayout_11->addLayout(horizontalLayout_16);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_8->addWidget(comboBox);

        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_8->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(frame);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_8->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(frame);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout_8->addWidget(comboBox_4);

        comboBox_5 = new QComboBox(frame);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_8->addWidget(comboBox_5);

        comboBox_6 = new QComboBox(frame);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        horizontalLayout_8->addWidget(comboBox_6);


        verticalLayout_11->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_11, 4, 0, 1, 1);


        gridLayout_3->addWidget(frame, 1, 0, 1, 1);

        frame_2 = new QFrame(lineForm);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        translate_label = new QLabel(frame_2);
        translate_label->setObjectName(QString::fromUtf8("translate_label"));

        verticalLayout_3->addWidget(translate_label);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        scale_label = new QLabel(frame_2);
        scale_label->setObjectName(QString::fromUtf8("scale_label"));

        verticalLayout_4->addWidget(scale_label);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        scale_label_2 = new QLabel(frame_2);
        scale_label_2->setObjectName(QString::fromUtf8("scale_label_2"));

        verticalLayout_7->addWidget(scale_label_2);


        verticalLayout_8->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        xtranslate_label = new QLabel(frame_2);
        xtranslate_label->setObjectName(QString::fromUtf8("xtranslate_label"));

        horizontalLayout_9->addWidget(xtranslate_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_9);

        xtranslate_lineEdit = new QLineEdit(frame_2);
        xtranslate_lineEdit->setObjectName(QString::fromUtf8("xtranslate_lineEdit"));

        verticalLayout->addWidget(xtranslate_lineEdit);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        ytranslate_label = new QLabel(frame_2);
        ytranslate_label->setObjectName(QString::fromUtf8("ytranslate_label"));

        horizontalLayout_10->addWidget(ytranslate_label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_10);

        yTranslate_lineEdit = new QLineEdit(frame_2);
        yTranslate_lineEdit->setObjectName(QString::fromUtf8("yTranslate_lineEdit"));

        verticalLayout_2->addWidget(yTranslate_lineEdit);


        horizontalLayout_12->addLayout(verticalLayout_2);


        verticalLayout_10->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);

        xScale_label_2 = new QLabel(frame_2);
        xScale_label_2->setObjectName(QString::fromUtf8("xScale_label_2"));

        horizontalLayout_13->addWidget(xScale_label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_13);

        xScale_lineEdit = new QLineEdit(frame_2);
        xScale_lineEdit->setObjectName(QString::fromUtf8("xScale_lineEdit"));

        verticalLayout_5->addWidget(xScale_lineEdit);


        horizontalLayout_11->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);

        yScale_label_2 = new QLabel(frame_2);
        yScale_label_2->setObjectName(QString::fromUtf8("yScale_label_2"));

        horizontalLayout_14->addWidget(yScale_label_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_14);

        yScale_lineEdit = new QLineEdit(frame_2);
        yScale_lineEdit->setObjectName(QString::fromUtf8("yScale_lineEdit"));

        verticalLayout_6->addWidget(yScale_lineEdit);


        horizontalLayout_11->addLayout(verticalLayout_6);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_11);

        angle_label = new QLabel(frame_2);
        angle_label->setObjectName(QString::fromUtf8("angle_label"));

        horizontalLayout_24->addWidget(angle_label);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_24);

        rotate_lineEdit = new QLineEdit(frame_2);
        rotate_lineEdit->setObjectName(QString::fromUtf8("rotate_lineEdit"));

        verticalLayout_9->addWidget(rotate_lineEdit);


        horizontalLayout_22->addLayout(verticalLayout_9);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_13);


        verticalLayout_10->addLayout(horizontalLayout_22);


        gridLayout_2->addLayout(verticalLayout_10, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame_2, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        line_Cancel = new QPushButton(lineForm);
        line_Cancel->setObjectName(QString::fromUtf8("line_Cancel"));

        horizontalLayout_6->addWidget(line_Cancel);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        line_OK = new QPushButton(lineForm);
        line_OK->setObjectName(QString::fromUtf8("line_OK"));

        horizontalLayout_6->addWidget(line_OK);


        gridLayout_3->addLayout(horizontalLayout_6, 3, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineComboBox);
        label_3->setBuddy(xLineLineEdit);
        label_4->setBuddy(yLineLineEdit);
        label_5->setBuddy(widthlineEdit);
        color_label->setBuddy(lineColor_button);
        translate_label->setBuddy(xtranslate_lineEdit);
        scale_label->setBuddy(xScale_lineEdit);
        scale_label_2->setBuddy(rotate_lineEdit);
        xtranslate_label->setBuddy(xtranslate_lineEdit);
        ytranslate_label->setBuddy(yTranslate_lineEdit);
        xScale_label_2->setBuddy(xScale_lineEdit);
        yScale_label_2->setBuddy(yScale_lineEdit);
        angle_label->setBuddy(rotate_lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(lineForm);

        QMetaObject::connectSlotsByName(lineForm);
    } // setupUi

    void retranslateUi(QWidget *lineForm)
    {
        lineForm->setWindowTitle(QApplication::translate("lineForm", "Curve or Line Editor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("lineForm", "Line Attributes", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("lineForm", "Selected vertex :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("lineForm", "x :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("lineForm", "y :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("lineForm", "Line width :", 0, QApplication::UnicodeUTF8));
        color_label->setText(QApplication::translate("lineForm", "Color :", 0, QApplication::UnicodeUTF8));
        lineColor_button->setText(QString());
        label_6->setText(QApplication::translate("lineForm", "Line continuity", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("lineForm", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("lineForm", "0", 0, QApplication::UnicodeUTF8)
        );
        translate_label->setText(QApplication::translate("lineForm", "Translate", 0, QApplication::UnicodeUTF8));
        scale_label->setText(QApplication::translate("lineForm", "Scale     ", 0, QApplication::UnicodeUTF8));
        scale_label_2->setText(QApplication::translate("lineForm", "Rotare   ", 0, QApplication::UnicodeUTF8));
        xtranslate_label->setText(QApplication::translate("lineForm", "x", 0, QApplication::UnicodeUTF8));
        ytranslate_label->setText(QApplication::translate("lineForm", "y", 0, QApplication::UnicodeUTF8));
        xScale_label_2->setText(QApplication::translate("lineForm", "x", 0, QApplication::UnicodeUTF8));
        yScale_label_2->setText(QApplication::translate("lineForm", "y", 0, QApplication::UnicodeUTF8));
        angle_label->setText(QApplication::translate("lineForm", "Angle", 0, QApplication::UnicodeUTF8));
        line_Cancel->setText(QApplication::translate("lineForm", "Cancel", 0, QApplication::UnicodeUTF8));
        line_OK->setText(QApplication::translate("lineForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lineForm: public Ui_lineForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEFORM_H
