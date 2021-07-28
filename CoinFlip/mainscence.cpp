#include "mainscence.h"
#include "ui_mainscence.h"
#include<QAction>
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<QSound>
MainScence::MainScence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScence)
{
    ui->setupUi(this);
    //设置窗口大小、标题、图片
    this->setFixedSize(400,550);
    this->setWindowTitle("CoinFlip");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //关闭按钮
    connect(ui->actionClose,&QAction::triggered,[=](){

        this->close();
    });
    //开始按钮音效文件
    QSound *startSound =new QSound(":/res/TapButtonSound.wav",this);
    //自定义控件
    MyPushButton *mybtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    mybtn->setParent(this);
    mybtn->move(this->width()*0.5-mybtn->width()*0.5,this->height()*0.7);
    //创建选择关卡场景
    chooseScene=new ChooseLevelScene();
    //捕捉ChooseScene，返回信号
    connect(chooseScene,&ChooseLevelScene::chooseL,[=](){
        QTimer::singleShot(200,this,[=](){
            this->setGeometry(chooseScene->geometry());
            chooseScene->hide();
            this->show();
        });
    });

    //开始按钮
    connect(mybtn,&QPushButton::clicked,[=](){
        startSound->play();
        //按钮特效，弹起落下等
        mybtn->Zoom1();
        mybtn->Zoom2();
        //进入选择关卡按钮
        QTimer::singleShot(500,this,[=](){
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();
        });


    });



}
//重写绘画事件
void MainScence::paintEvent(QPaintEvent *)
{
    //定义画家，画背景图片
    QPainter painter(this);
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题图片（缩放0.5）
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);




}
MainScence::~MainScence()
{
    delete ui;
}

