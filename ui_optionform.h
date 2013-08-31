/********************************************************************************
** Form generated from reading UI file 'optionform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONFORM_H
#define UI_OPTIONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_optionDialog
{
public:
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *savecheckBox;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *savespinBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelpushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *okpushButton;

    void setupUi(QDialog *optionDialog)
    {
        if (optionDialog->objectName().isEmpty())
            optionDialog->setObjectName(QString::fromUtf8("optionDialog"));
        optionDialog->resize(399, 200);
        gridLayout_2 = new QGridLayout(optionDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeWidget = new QTreeWidget(optionDialog);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/1294937325_Gnome-Document-Save-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(120, 16777215));
        treeWidget->header()->setVisible(false);

        gridLayout_2->addWidget(treeWidget, 0, 0, 2, 1);

        groupBox = new QGroupBox(optionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        savecheckBox = new QCheckBox(groupBox);
        savecheckBox->setObjectName(QString::fromUtf8("savecheckBox"));

        horizontalLayout->addWidget(savecheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        savespinBox = new QSpinBox(groupBox);
        savespinBox->setObjectName(QString::fromUtf8("savespinBox"));

        horizontalLayout->addWidget(savespinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cancelpushButton = new QPushButton(optionDialog);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));

        horizontalLayout_2->addWidget(cancelpushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        okpushButton = new QPushButton(optionDialog);
        okpushButton->setObjectName(QString::fromUtf8("okpushButton"));

        horizontalLayout_2->addWidget(okpushButton);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        retranslateUi(optionDialog);

        QMetaObject::connectSlotsByName(optionDialog);
    } // setupUi

    void retranslateUi(QDialog *optionDialog)
    {
        optionDialog->setWindowTitle(QApplication::translate("optionDialog", "Option", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("optionDialog", "Options", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("optionDialog", "Save", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("optionDialog", "Save/Load Options", 0, QApplication::UnicodeUTF8));
        savecheckBox->setText(QApplication::translate("optionDialog", "Save scene every", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("optionDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okpushButton->setText(QApplication::translate("optionDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class optionDialog: public Ui_optionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONFORM_H
