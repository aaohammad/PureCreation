/********************************************************************************
** Form generated from reading UI file 'squareform.ui'
**
** Created: Wed Jun 1 03:07:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUAREFORM_H
#define UI_SQUAREFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class Ui_square_attributeEditorForm
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *Square_lable;
    QSpacerItem *horizontalSpacer_10;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_25;
    QLabel *width_label;
    QLineEdit *width_lineEdit;
    QHBoxLayout *horizontalLayout_26;
    QLabel *height_label;
    QLineEdit *height_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *color_label;
    QPushButton *squarecolor_button;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxFilled;
    QSpacerItem *horizontalSpacer_15;
    QFrame *frame;
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
    QSpacerItem *horizontalSpacer;
    QLabel *xtranslate_label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *xtranslate_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ytranslate_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *yTranslate_lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QLabel *xScale_label_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *xScale_lineEdit;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_7;
    QLabel *yScale_label_2;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *yScale_lineEdit;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_24;
    QSpacerItem *horizontalSpacer_11;
    QLabel *angle_label;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *rotate_lineEdit;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *square_Cancel;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *square_OK;

    void setupUi(QWidget *square_attributeEditorForm)
    {
        if (square_attributeEditorForm->objectName().isEmpty())
            square_attributeEditorForm->setObjectName(QString::fromUtf8("square_attributeEditorForm"));
        square_attributeEditorForm->resize(344, 377);
        gridLayout_3 = new QGridLayout(square_attributeEditorForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        Square_lable = new QLabel(square_attributeEditorForm);
        Square_lable->setObjectName(QString::fromUtf8("Square_lable"));

        horizontalLayout_8->addWidget(Square_lable);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        frame_2 = new QFrame(square_attributeEditorForm);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        width_label = new QLabel(frame_2);
        width_label->setObjectName(QString::fromUtf8("width_label"));

        horizontalLayout_25->addWidget(width_label);

        width_lineEdit = new QLineEdit(frame_2);
        width_lineEdit->setObjectName(QString::fromUtf8("width_lineEdit"));

        horizontalLayout_25->addWidget(width_lineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        height_label = new QLabel(frame_2);
        height_label->setObjectName(QString::fromUtf8("height_label"));

        horizontalLayout_26->addWidget(height_label);

        height_lineEdit = new QLineEdit(frame_2);
        height_lineEdit->setObjectName(QString::fromUtf8("height_lineEdit"));

        horizontalLayout_26->addWidget(height_lineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_26);


        gridLayout->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        color_label = new QLabel(frame_2);
        color_label->setObjectName(QString::fromUtf8("color_label"));

        horizontalLayout_5->addWidget(color_label);

        squarecolor_button = new QPushButton(frame_2);
        squarecolor_button->setObjectName(QString::fromUtf8("squarecolor_button"));

        horizontalLayout_5->addWidget(squarecolor_button);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBoxFilled = new QCheckBox(frame_2);
        checkBoxFilled->setObjectName(QString::fromUtf8("checkBoxFilled"));

        horizontalLayout_2->addWidget(checkBoxFilled);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_15);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);

        frame = new QFrame(square_attributeEditorForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        translate_label = new QLabel(frame);
        translate_label->setObjectName(QString::fromUtf8("translate_label"));

        verticalLayout_3->addWidget(translate_label);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        scale_label = new QLabel(frame);
        scale_label->setObjectName(QString::fromUtf8("scale_label"));

        verticalLayout_4->addWidget(scale_label);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        scale_label_2 = new QLabel(frame);
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        xtranslate_label = new QLabel(frame);
        xtranslate_label->setObjectName(QString::fromUtf8("xtranslate_label"));

        horizontalLayout_9->addWidget(xtranslate_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_9);

        xtranslate_lineEdit = new QLineEdit(frame);
        xtranslate_lineEdit->setObjectName(QString::fromUtf8("xtranslate_lineEdit"));

        verticalLayout->addWidget(xtranslate_lineEdit);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        ytranslate_label = new QLabel(frame);
        ytranslate_label->setObjectName(QString::fromUtf8("ytranslate_label"));

        horizontalLayout_10->addWidget(ytranslate_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_10);

        yTranslate_lineEdit = new QLineEdit(frame);
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
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        xScale_label_2 = new QLabel(frame);
        xScale_label_2->setObjectName(QString::fromUtf8("xScale_label_2"));

        horizontalLayout_13->addWidget(xScale_label_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_13);

        xScale_lineEdit = new QLineEdit(frame);
        xScale_lineEdit->setObjectName(QString::fromUtf8("xScale_lineEdit"));

        verticalLayout_5->addWidget(xScale_lineEdit);


        horizontalLayout_11->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        yScale_label_2 = new QLabel(frame);
        yScale_label_2->setObjectName(QString::fromUtf8("yScale_label_2"));

        horizontalLayout_14->addWidget(yScale_label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_14);

        yScale_lineEdit = new QLineEdit(frame);
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

        angle_label = new QLabel(frame);
        angle_label->setObjectName(QString::fromUtf8("angle_label"));

        horizontalLayout_24->addWidget(angle_label);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_24);

        rotate_lineEdit = new QLineEdit(frame);
        rotate_lineEdit->setObjectName(QString::fromUtf8("rotate_lineEdit"));

        verticalLayout_9->addWidget(rotate_lineEdit);


        horizontalLayout_22->addLayout(verticalLayout_9);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_13);


        verticalLayout_10->addLayout(horizontalLayout_22);


        gridLayout_2->addLayout(verticalLayout_10, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        square_Cancel = new QPushButton(square_attributeEditorForm);
        square_Cancel->setObjectName(QString::fromUtf8("square_Cancel"));

        horizontalLayout->addWidget(square_Cancel);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        square_OK = new QPushButton(square_attributeEditorForm);
        square_OK->setObjectName(QString::fromUtf8("square_OK"));

        horizontalLayout->addWidget(square_OK);


        gridLayout_3->addLayout(horizontalLayout, 3, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        translate_label->setBuddy(xtranslate_lineEdit);
        scale_label->setBuddy(xtranslate_lineEdit);
        scale_label_2->setBuddy(xtranslate_lineEdit);
        xtranslate_label->setBuddy(xtranslate_lineEdit);
        ytranslate_label->setBuddy(yTranslate_lineEdit);
        xScale_label_2->setBuddy(xtranslate_lineEdit);
        yScale_label_2->setBuddy(yTranslate_lineEdit);
        angle_label->setBuddy(yTranslate_lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(square_attributeEditorForm);
        QObject::connect(squarecolor_button, SIGNAL(clicked()), square_attributeEditorForm, SLOT(colorChanged()));

        QMetaObject::connectSlotsByName(square_attributeEditorForm);
    } // setupUi

    void retranslateUi(QWidget *square_attributeEditorForm)
    {
        square_attributeEditorForm->setWindowTitle(QApplication::translate("square_attributeEditorForm", "Square Editor", 0, QApplication::UnicodeUTF8));
        Square_lable->setText(QApplication::translate("square_attributeEditorForm", "Square Attributes", 0, QApplication::UnicodeUTF8));
        width_label->setText(QApplication::translate("square_attributeEditorForm", "Width", 0, QApplication::UnicodeUTF8));
        height_label->setText(QApplication::translate("square_attributeEditorForm", "Height", 0, QApplication::UnicodeUTF8));
        color_label->setText(QApplication::translate("square_attributeEditorForm", "Color", 0, QApplication::UnicodeUTF8));
        squarecolor_button->setText(QString());
        checkBoxFilled->setText(QApplication::translate("square_attributeEditorForm", "Filled", 0, QApplication::UnicodeUTF8));
        translate_label->setText(QApplication::translate("square_attributeEditorForm", "Translate", 0, QApplication::UnicodeUTF8));
        scale_label->setText(QApplication::translate("square_attributeEditorForm", "Scale     ", 0, QApplication::UnicodeUTF8));
        scale_label_2->setText(QApplication::translate("square_attributeEditorForm", "Rotare   ", 0, QApplication::UnicodeUTF8));
        xtranslate_label->setText(QApplication::translate("square_attributeEditorForm", "x", 0, QApplication::UnicodeUTF8));
        ytranslate_label->setText(QApplication::translate("square_attributeEditorForm", "y", 0, QApplication::UnicodeUTF8));
        xScale_label_2->setText(QApplication::translate("square_attributeEditorForm", "x", 0, QApplication::UnicodeUTF8));
        yScale_label_2->setText(QApplication::translate("square_attributeEditorForm", "y", 0, QApplication::UnicodeUTF8));
        angle_label->setText(QApplication::translate("square_attributeEditorForm", "Angle", 0, QApplication::UnicodeUTF8));
        square_Cancel->setText(QApplication::translate("square_attributeEditorForm", "Cancel", 0, QApplication::UnicodeUTF8));
        square_OK->setText(QApplication::translate("square_attributeEditorForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class square_attributeEditorForm: public Ui_square_attributeEditorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUAREFORM_H
