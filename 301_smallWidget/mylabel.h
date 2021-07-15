#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    //鼠标进入事件
    void enterEvent(QEvent *event);
    //鼠标离开事件
    void leaveEvent(QEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev) ;
    //鼠标按压事件
    void mousePressEvent(QMouseEvent *ev) ;
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev) ;
signals:

};

#endif // MYLABEL_H
