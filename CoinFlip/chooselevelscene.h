#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playscene.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘画事件
    void paintEvent(QPaintEvent *);
    PlayScene* playScene=NULL;
signals:
    //自定义信号，只用声明，不用实现
    void chooseL();
};

#endif // CHOOSELEVELSCENE_H
