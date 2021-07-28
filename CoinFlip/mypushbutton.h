#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg,QString pressImg="");
    QString normalImgPath;
    QString pressImgPath;
    //向下跳
    void Zoom1();
    //向上跳
    void Zoom2();
    //鼠标按下
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

};

#endif // MYPUSHBUTTON_H
