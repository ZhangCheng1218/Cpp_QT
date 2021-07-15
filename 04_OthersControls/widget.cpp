#include "widget.h"
#include "ui_widget.h"
#include<QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //1、stacked widget
    connect(ui->btn_scroll,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_tool,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_tab,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    //2、label显示图片和GIF
    ui->lbl_img->setPixmap(QPixmap(":/src/7.jpg"));
    //加载GIF
    QMovie *mo=new QMovie(":/src/1.gif");
    ui->lbl_gif->setMovie(mo);
    mo->start();
}

Widget::~Widget()
{
    delete ui;
}

