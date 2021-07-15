/********************************************************************************
** Form generated from reading UI file 'smallwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIDGET_H
#define UI_SMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmallWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spBox;
    QSlider *hoS;

    void setupUi(QWidget *SmallWidget)
    {
        if (SmallWidget->objectName().isEmpty())
            SmallWidget->setObjectName(QString::fromUtf8("SmallWidget"));
        SmallWidget->resize(278, 58);
        horizontalLayout_2 = new QHBoxLayout(SmallWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(SmallWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spBox = new QSpinBox(widget);
        spBox->setObjectName(QString::fromUtf8("spBox"));

        horizontalLayout->addWidget(spBox);

        hoS = new QSlider(widget);
        hoS->setObjectName(QString::fromUtf8("hoS"));
        hoS->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hoS);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(SmallWidget);

        QMetaObject::connectSlotsByName(SmallWidget);
    } // setupUi

    void retranslateUi(QWidget *SmallWidget)
    {
        SmallWidget->setWindowTitle(QCoreApplication::translate("SmallWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmallWidget: public Ui_SmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
