#include "chooselevelscene.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QPixmap>
#include<QPainter>
#include"mypushbutton.h"
#include<QLabel>
#include<QDebug>
#include<QTimer>
#include<QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //保持和主窗口类似
    this->setFixedSize(400,550);
    this->setWindowTitle("LevelScene");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //代码实现添加菜单栏、按钮、点击退出
    QMenuBar *bar=menuBar();
    QMenu *menu= bar->addMenu("Start");
    QAction *action= menu->addAction("Close");
    connect(action,&QAction::triggered,[=]()
    {
        this->close();

    });
    //选择关卡音效
    QSound *chooseSound =new QSound(":/res/TapButtonSound.wav",this);
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);
    //返回按钮
    MyPushButton *backBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //按下图片切换功能，重载鼠标按下释放按钮
    connect(backBtn,&QPushButton::clicked,[=](){
        backSound->play();
        //点击后，发送个信号，让主窗口捕捉，进行主窗口显示，关卡窗口隐藏的操作
        emit this->chooseL();
    });

    //绘制关卡按钮
    for(int i=0;i<20;++i)
    {
        MyPushButton *menuBtn=new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(50+i%4*80,130+i/4*80);
        //点击事件,每个按钮有各自的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //             QString str=QString("This is %1 level!").arg(i+1);
            //             qDebug()<<str;
            chooseSound->play();

            playScene =new PlayScene(i+1);
            playScene->setGeometry(this->geometry());
            this->hide();
            playScene->show();

            //捕捉PlayScene返回信号
            connect(playScene,&PlayScene::playL,[=](){
                QTimer::singleShot(200,this,[=](){
                    //点击返回后，把该窗口坐标给下一个要出现的窗口
                    this->setGeometry(playScene->geometry());

                    playScene->hide();
                    //返回后就清空掉之前进入的playScene
                    delete playScene;
                    playScene=NULL;
                    this->show();
                });
            });
        });
        //显示关卡数字
        QLabel *lbl=new QLabel(this);
        lbl->setFixedSize(menuBtn->width(),menuBtn->height());
        lbl->setText(QString::number(i+1));
        lbl->move(50+i%4*80,130+i/4*80);
        lbl->setAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
        //设置让鼠标进行穿透，51号属性
        lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //绘制背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}
