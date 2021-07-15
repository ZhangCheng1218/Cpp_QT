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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QToolBox *toolBox;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *btn_scroll;
    QPushButton *btn_tool;
    QPushButton *btn_tab;
    QLabel *lbl_img;
    QLabel *lbl_gif;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(556, 455);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 541, 141));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 241, 111));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -106, 222, 215));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        toolBox = new QToolBox(page_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(60, 30, 331, 81));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 331, 16));
        toolBox->addItem(page_3, QString::fromUtf8("\345\220\214\344\272\213"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 314, 16));
        toolBox->addItem(page_4, QString::fromUtf8("\345\256\266\344\272\272"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        toolBox->addItem(page_5, QString::fromUtf8("\351\231\214\347\224\237\344\272\272"));
        stackedWidget->addWidget(page_2);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(100, 10, 281, 91));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(page_6);
        btn_scroll = new QPushButton(Widget);
        btn_scroll->setObjectName(QString::fromUtf8("btn_scroll"));
        btn_scroll->setGeometry(QRect(30, 180, 75, 23));
        btn_tool = new QPushButton(Widget);
        btn_tool->setObjectName(QString::fromUtf8("btn_tool"));
        btn_tool->setGeometry(QRect(160, 180, 75, 23));
        btn_tab = new QPushButton(Widget);
        btn_tab->setObjectName(QString::fromUtf8("btn_tab"));
        btn_tab->setGeometry(QRect(330, 180, 75, 23));
        lbl_img = new QLabel(Widget);
        lbl_img->setObjectName(QString::fromUtf8("lbl_img"));
        lbl_img->setGeometry(QRect(10, 210, 241, 241));
        lbl_gif = new QLabel(Widget);
        lbl_gif->setObjectName(QString::fromUtf8("lbl_gif"));
        lbl_gif->setGeometry(QRect(280, 210, 271, 231));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(2);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "\345\220\214\344\272\213", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("Widget", "\345\256\266\344\272\272", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("Widget", "\351\231\214\347\224\237\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", " \347\231\276\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\350\260\267\346\255\214", nullptr));
        btn_scroll->setText(QCoreApplication::translate("Widget", "scroll", nullptr));
        btn_tool->setText(QCoreApplication::translate("Widget", "tool", nullptr));
        btn_tab->setText(QCoreApplication::translate("Widget", " tab", nullptr));
        lbl_img->setText(QCoreApplication::translate("Widget", "lbl_img", nullptr));
        lbl_gif->setText(QCoreApplication::translate("Widget", "lbl_img", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
