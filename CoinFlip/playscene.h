#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int num);
    int levelNum;
    //重写绘画事件
    void paintEvent(QPaintEvent *);
    //每关对应金币银币的数组
    int coinArray[4][4];
    //实现周围硬币跟着翻转，需要有个记录硬币的数组
    MyCoin* coinPosArray[4][4];
    //胜利标志判断
    bool isWin=true;
signals:
    //自定义信号，只用声明，不用实现
    void playL();
};

#endif // PLAYSCENE_H
