#include "mypushbutton.h"
#include<QDebug>//打印信息

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "mypushbutton_Constructor" ;
}
MyPushButton::~MyPushButton()
{
    qDebug() << "mypushbutton_Destructor" ;
}
