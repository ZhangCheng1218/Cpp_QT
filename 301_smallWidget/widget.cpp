#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QString>
#include<QTimer>//定时器类，比价好使
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
    id1= startTimer(1000);
    id2=startTimer(2000);

    //定时器类实现0.5s数字加一
    QTimer *timer1=new QTimer(this);
    timer1->start(500);
    connect(timer1,&QTimer::timeout,[=](){
        static int num=0;
        ui->lblTimer_3->setText(QString::number(num++));
    });
    //点击按钮暂停
    connect(ui->btn_stop,&QPushButton::clicked,[=](){
        timer1->stop();
    });

}
void Widget::timerEvent(QTimerEvent * ev)
{
    if(ev->timerId()==id1)
    {
        static int num=0;
        ui->lblTimer->setText(QString::number(num++));
    }
    if(ev->timerId()==id2)
    {
        static int num2=0;
        ui->lblTimer_2->setText(QString::number(num2++));
    }
}
Widget::~Widget()
{
    delete ui;
}

