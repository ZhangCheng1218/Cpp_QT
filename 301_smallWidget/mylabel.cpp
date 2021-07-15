#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪，只要鼠标移动就能捕捉到，而不需要点击着移动
    setMouseTracking(true);
}
void MyLabel::enterEvent(QEvent *event)
{
    qDebug()<<"mouse is coming!";

}
void MyLabel::leaveEvent(QEvent *event)
{

    qDebug()<<"mouse is leaved!";
}
//鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //移动是状态，需要用buttons()和&操作符来确认操作，用button()无法判断持续的状态，会存在左右键都点这移动的实际情况
    //实现左键移动打印
//    if(ev->buttons() & Qt::LeftButton)
//    {
        qDebug()<<"mouse is moving!";

//    }

}
//鼠标按压事件
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    //只左键按压，打印内容
    if(ev->button()==Qt::LeftButton)
    {
        QString str=QString("mouse is pressing! X= %1 , Y= %2, globalX= %3, globalY= %4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str.toUtf8().data();
    }

}
//鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"mouse is released!";

}
