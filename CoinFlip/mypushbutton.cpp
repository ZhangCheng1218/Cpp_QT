#include "mypushbutton.h"
#include<QDebug>
#include<QSize>
#include<QPropertyAnimation>
#include<QRect>
#include<QVariant>
//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    normalImgPath=normalImg;
    pressImgPath=pressImg;
    QPixmap pix;
    bool ret=pix.load(normalImgPath);
    if(!ret)
    {
        qDebug()<<"Load Img Failed!";
        return;
    }

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void MyPushButton::Zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    //设置时间间隔
    animation->setDuration(200);
    //创建起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();
}
void MyPushButton::Zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    //设置时间间隔
    animation->setDuration(200);
    //创建起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线，弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();
}
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        bool ret=pix.load(pressImgPath);
        if(!ret)
        {
            qDebug()<<"Load Img Failed!";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //其余事情仍需要交给父类处理
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"Load Img Failed!";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
