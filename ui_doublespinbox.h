/********************************************************************************
** Form generated from reading UI file 'doublespinbox.ui'
**
** Created: Thu May 26 16:30:10 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLESPINBOX_H
#define UI_DOUBLESPINBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleSpinBox
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *redDoubleSpinBox;
    QDoubleSpinBox *greenDoubleSpinBox;
    QDoubleSpinBox *blueDoubleSpinBox;

    void setupUi(QWidget *DoubleSpinBox)
    {
        if (DoubleSpinBox->objectName().isEmpty())
            DoubleSpinBox->setObjectName(QString::fromUtf8("DoubleSpinBox"));
        DoubleSpinBox->resize(66, 91);
        gridLayout = new QGridLayout(DoubleSpinBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        redDoubleSpinBox = new QDoubleSpinBox(DoubleSpinBox);
        redDoubleSpinBox->setObjectName(QString::fromUtf8("redDoubleSpinBox"));
        redDoubleSpinBox->setDecimals(0);
        redDoubleSpinBox->setMaximum(255);

        gridLayout->addWidget(redDoubleSpinBox, 0, 0, 1, 1);

        greenDoubleSpinBox = new QDoubleSpinBox(DoubleSpinBox);
        greenDoubleSpinBox->setObjectName(QString::fromUtf8("greenDoubleSpinBox"));
        greenDoubleSpinBox->setDecimals(0);
        greenDoubleSpinBox->setMaximum(255);

        gridLayout->addWidget(greenDoubleSpinBox, 1, 0, 1, 1);

        blueDoubleSpinBox = new QDoubleSpinBox(DoubleSpinBox);
        blueDoubleSpinBox->setObjectName(QString::fromUtf8("blueDoubleSpinBox"));
        blueDoubleSpinBox->setDecimals(0);
        blueDoubleSpinBox->setMaximum(255);

        gridLayout->addWidget(blueDoubleSpinBox, 2, 0, 1, 1);


        retranslateUi(DoubleSpinBox);

        QMetaObject::connectSlotsByName(DoubleSpinBox);
    } // setupUi

    void retranslateUi(QWidget *DoubleSpinBox)
    {
        DoubleSpinBox->setWindowTitle(QApplication::translate("DoubleSpinBox", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DoubleSpinBox: public Ui_DoubleSpinBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLESPINBOX_H
