/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <smallwidget.h>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    SmallWidget *widget;
    QPushButton *btn_set;
    QPushButton *btn_get;
    MyLabel *lbl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(543, 413);
        widget = new SmallWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 381, 51));
        btn_set = new QPushButton(Widget);
        btn_set->setObjectName(QString::fromUtf8("btn_set"));
        btn_set->setGeometry(QRect(100, 150, 75, 23));
        btn_get = new QPushButton(Widget);
        btn_get->setObjectName(QString::fromUtf8("btn_get"));
        btn_get->setGeometry(QRect(260, 150, 75, 23));
        lbl = new MyLabel(Widget);
        lbl->setObjectName(QString::fromUtf8("lbl"));
        lbl->setGeometry(QRect(60, 220, 331, 81));
        lbl->setFrameShape(QFrame::Box);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_set->setText(QCoreApplication::translate("Widget", "set", nullptr));
        btn_get->setText(QCoreApplication::translate("Widget", "get", nullptr));
        lbl->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
