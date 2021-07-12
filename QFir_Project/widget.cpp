#include "widget.h"
#include<QPushButton>
#include<QDebug>
#include<mypushbutton.h>
//命名规范
//类名：首字母大写，单词与单词之间首字母大写
//函数名、变量名：首字母小写，单词与单词之间首字母大写


//快捷键
//注释  ctrl+/
//运行  ctrl+r
//编译  ctrl+b
//自动对齐  ctrl+i
//同名.h和.cpp切换 F4


//对象树
//当new在堆区的数据，如果指定的父类为   QObject或者QObject派生下来的类，不用管理内存释放问题
//对象会被放在对象树中，构造时候从父类往下，释放时候从子类往父类
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton *btn=new QPushButton;
    btn->setParent(this);
    btn->setText("firstButton");
    //该创建方法，窗口会按照btn的尺寸创建，需要重设一下窗口尺寸
    QPushButton *btn2=new QPushButton("secBtn",this);
    btn2->move(150,150);
    //    resize(600,600);
    //设置独挡大小
    setFixedSize(600,400);
    setWindowTitle(QString::fromLocal8Bit("Test Pro"));

    //对象树
    MyPushButton *myBtn=new MyPushButton;
    myBtn->setText(QString::fromLocal8Bit("MyButton"));
    myBtn->setParent(this);
    myBtn->move(50,50);

    //信号和槽    松散耦合
    //1、信号发送者---------2、发送的信号（函数地址）--------------3、信号接收者-----------------4、处理的槽函数（函数地址）
    connect(myBtn,&MyPushButton::clicked,this,&Widget::close);

}

Widget::~Widget()
{
    qDebug()<<"widget_Destructor";
}

