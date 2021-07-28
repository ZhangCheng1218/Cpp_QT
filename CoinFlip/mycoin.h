#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnimg);
    //定义硬币的一些属性，记录位置用
    int posX;
    int posY;
    bool coinFlag;//0是银币1是金币
    bool coinAllFlag=false;//标志是否全部为金币,true为全部金币
    //定义Timer用于翻金币动画显示
    QTimer* timer1;
    QTimer* timer2;
    //定义翻转事件
    void TurnFlag();
    //硬币尾标，1-8就是金币翻到银币
    int min=1;
    int max=8;
    //动画运行标志，放置狂点鼠标，动画没运行完又开始新的动画
    //同时需要重写鼠标按下事件
    bool animaFlag=false;
    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // MYCOIN_H
