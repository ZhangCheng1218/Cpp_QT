#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获取数字
    connect(ui->btn_get,&QPushButton::clicked,[=](){

       int nu= ui->widget->getNum();
       qDebug()<<nu;
    });
    //设置数字
    connect(ui->btn_set,&QPushButton::clicked,[=](){

        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

