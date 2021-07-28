#include "mycoin.h"
#include<QPixmap>
#include<QDebug>
MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}
MyCoin::MyCoin(QString btnimg)
{
    QPixmap pix;
    bool ret= pix.load(btnimg);
    if(!ret)
    {
        qDebug()<<"Load btnimg Failed!";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    //初始化QTimer
    this->timer1=new QTimer;
    this->timer2=new QTimer;
    //监听翻转信号,知道timer.stop才结束---金币翻银币
    connect(timer1,&QTimer::timeout,[=](){
        QString strCoinPath=QString(":/res/Coin000%1").arg(this->min++);
        QPixmap pix;
        bool ret= pix.load(strCoinPath);
        if(!ret)
        {
            qDebug()<<"Load TurnFlag Failed!";
            return;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min >this->max){
            this->min=1;
            this->animaFlag=false;
            timer1->stop();
        }
    });
    //监听翻转信号,知道timer.stop才结束---银币翻金币
    connect(timer2,&QTimer::timeout,[=](){
        QString strCoinPath=QString(":/res/Coin000%1").arg(this->max--);
        QPixmap pix;
        bool ret= pix.load(strCoinPath);
        if(!ret)
        {
            qDebug()<<"Load TurnFlag Failed!";
            return;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min >this->max){
            this->max=8;
            this->animaFlag=false;
            timer2->stop();
        }
    });
}
void MyCoin::TurnFlag()
{

    if(this->coinFlag)
    {
        this->animaFlag=true;
        timer1->start(50);
        this->coinFlag=false;

    }
    else
    {
         this->animaFlag=true;
        timer2->start(50);
        this->coinFlag=true;
    }
}
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    //如果动画在运行或者全为金币，就不管这次点击
    if(this->animaFlag || this->coinAllFlag)
    {
        return;
    }
    else//动画不在运行，就交给父类正常处理
    {
        QPushButton::mousePressEvent(e);
    }
}
