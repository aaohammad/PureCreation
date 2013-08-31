/********************************************************************************
** Form generated from reading UI file 'imageform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEFORM_H
#define UI_IMAGEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
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

class Ui_imageform
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *loadimagepushButton;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *widthlineEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *heightlineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelpushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okpushButton;

    void setupUi(QWidget *imageform)
    {
        if (imageform->objectName().isEmpty())
            imageform->setObjectName(QString::fromUtf8("imageform"));
        imageform->resize(508, 531);
        gridLayout = new QGridLayout(imageform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(imageform);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        loadimagepushButton = new QPushButton(imageform);
        loadimagepushButton->setObjectName(QString::fromUtf8("loadimagepushButton"));

        horizontalLayout_2->addWidget(loadimagepushButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(imageform);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(500, 400));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label = new QLabel(imageform);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_2 = new QLabel(imageform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        widthlineEdit = new QLineEdit(imageform);
        widthlineEdit->setObjectName(QString::fromUtf8("widthlineEdit"));
        widthlineEdit->setReadOnly(false);

        verticalLayout->addWidget(widthlineEdit);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_3 = new QLabel(imageform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        heightlineEdit = new QLineEdit(imageform);
        heightlineEdit->setObjectName(QString::fromUtf8("heightlineEdit"));
        heightlineEdit->setReadOnly(false);

        verticalLayout_2->addWidget(heightlineEdit);


        horizontalLayout_5->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelpushButton = new QPushButton(imageform);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));

        horizontalLayout->addWidget(cancelpushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okpushButton = new QPushButton(imageform);
        okpushButton->setObjectName(QString::fromUtf8("okpushButton"));

        horizontalLayout->addWidget(okpushButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(widthlineEdit);
        label_2->setBuddy(widthlineEdit);
        label_3->setBuddy(heightlineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(imageform);

        QMetaObject::connectSlotsByName(imageform);
    } // setupUi

    void retranslateUi(QWidget *imageform)
    {
        imageform->setWindowTitle(QApplication::translate("imageform", "Image Insertion", 0, QApplication::UnicodeUTF8));
        loadimagepushButton->setText(QApplication::translate("imageform", "Load Image", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("imageform", "Image Size :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("imageform", "Width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("imageform", "Height", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("imageform", "Cancel", 0, QApplication::UnicodeUTF8));
        okpushButton->setText(QApplication::translate("imageform", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imageform: public Ui_imageform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEFORM_H
