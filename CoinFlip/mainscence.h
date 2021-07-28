#ifndef MAINSCENCE_H
#define MAINSCENCE_H

#include <QMainWindow>
#include "chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScence; }
QT_END_NAMESPACE

class MainScence : public QMainWindow
{
    Q_OBJECT

public:
    MainScence(QWidget *parent = nullptr);
    ~MainScence();
    //重载绘图事件
    void paintEvent(QPaintEvent *);
    ChooseLevelScene * chooseScene=NULL;

private:
    Ui::MainScence *ui;
};
#endif // MAINSCENCE_H
