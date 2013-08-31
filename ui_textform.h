/********************************************************************************
** Form generated from reading UI file 'textform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFORM_H
#define UI_TEXTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
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

class Ui_textForm
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *colorpushButton;
    QDoubleSpinBox *doubleSpinBox;
    QFontComboBox *fontComboBox;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLineEdit *xlineEdit;
    QLineEdit *ylineEdit;
    QPushButton *cancelpushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okpushButton;

    void setupUi(QWidget *textForm)
    {
        if (textForm->objectName().isEmpty())
            textForm->setObjectName(QString::fromUtf8("textForm"));
        textForm->resize(369, 381);
        gridLayout_3 = new QGridLayout(textForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(textForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 2);

        comboBox = new QComboBox(textForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_3->addWidget(comboBox, 1, 0, 1, 4);

        frame = new QFrame(textForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        colorpushButton = new QPushButton(frame);
        colorpushButton->setObjectName(QString::fromUtf8("colorpushButton"));
        colorpushButton->setEnabled(true);
        colorpushButton->setFlat(false);

        gridLayout_2->addWidget(colorpushButton, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_2->addWidget(doubleSpinBox, 0, 1, 1, 1);

        fontComboBox = new QFontComboBox(frame);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout_2->addWidget(fontComboBox, 0, 2, 1, 1);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(47, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 0, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        xlineEdit = new QLineEdit(frame);
        xlineEdit->setObjectName(QString::fromUtf8("xlineEdit"));

        gridLayout->addWidget(xlineEdit, 1, 1, 1, 1);

        ylineEdit = new QLineEdit(frame);
        ylineEdit->setObjectName(QString::fromUtf8("ylineEdit"));

        gridLayout->addWidget(ylineEdit, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 3);


        gridLayout_3->addWidget(frame, 2, 0, 1, 4);

        cancelpushButton = new QPushButton(textForm);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));

        gridLayout_3->addWidget(cancelpushButton, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(184, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 1, 1, 2);

        okpushButton = new QPushButton(textForm);
        okpushButton->setObjectName(QString::fromUtf8("okpushButton"));
        okpushButton->setDefault(true);

        gridLayout_3->addWidget(okpushButton, 3, 3, 1, 1);


        retranslateUi(textForm);

        QMetaObject::connectSlotsByName(textForm);
    } // setupUi

    void retranslateUi(QWidget *textForm)
    {
        textForm->setWindowTitle(QApplication::translate("textForm", "Edit Text", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("textForm", "Select text object to edit :", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("textForm", "New Text", 0, QApplication::UnicodeUTF8)
        );
        colorpushButton->setText(QString());
        label_2->setText(QApplication::translate("textForm", "x", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("textForm", "y", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("textForm", "Position", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("textForm", "Cancel", 0, QApplication::UnicodeUTF8));
        okpushButton->setText(QApplication::translate("textForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class textForm: public Ui_textForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFORM_H
