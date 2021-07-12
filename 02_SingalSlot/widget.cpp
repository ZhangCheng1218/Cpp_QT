#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

//老师类、学生类、下课后老师饿了，学生请吃饭；
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ls=new Teacher(this);
    xs=new Student(this);
//    //无参版本
//    connect(ls,&Teacher::hungry,xs,&Student::treat);
//    classisover();

    //有参信号和槽
    //函数指针指向地址
    void (Teacher::*lsSignal)(QString foodName)= &Teacher::hungry;
    void (Student::*xsSlot)(QString foodName)=&Student::treat;
   // connect(ls,lsSignal,xs,xsSlot);
   // classisover();

    //通过按钮调用
    QPushButton *btn=new QPushButton("myBtn",this);
    resize(500,500);
    //无参调用
    void (Teacher::*lsSignal1)(void)= &Teacher::hungry;
    void (Student::*xsSlot1)(void)=&Student::treat;
    //按钮点击信号与老师饿了信号建立连接        信号--------信号
    connect(btn,&QPushButton::clicked,ls,lsSignal1);
    //老师饿了信号与学生请客槽建立连接         信号--------槽
    connect(ls,lsSignal1,xs,xsSlot1);
    //断开信号
    //  disconnect(btn,&QPushButton::clicked,ls,lsSignal1);

    //信号可以连接信号
    //一个信号可以连接多个槽
    //多个信号可以连接同一个槽
    //信号和槽函数的的参数，必须类型一一对应
    //信号和槽的参数个数  信号的参数个数可以多余槽函数的参数，但是类型还是得一致（信号的第一个参数类型与槽第一个参数类型对应...）

    //Lambda表达式,值传递方式修改btn的text
    //[]标识符  匿名函数
    //()参数
    //{}实现体
    //mutable修饰 值传递变量，可以修改拷贝出的数据，改变不了本体
    //返回值 []()->int{};
    [=]()
    {
      btn->setText("LambdaTest");
    }();


}

void Widget::classisover()
{
    // emit ls->hungry();
    emit ls->hungry("fish");
}

Widget::~Widget()
{
    delete ui;
}

