#include "playscene.h"
#include<QPainter>
#include<QMenu>
#include<QMenuBar>
#include"mypushbutton.h"
#include<QLabel>
#include<QFont>
#include<QPixmap>
#include"mycoin.h"
#include"dataconfig.h"
#include<QPropertyAnimation>
#include<QSound>
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}
PlayScene::PlayScene(int num)
{
    this->levelNum=num;
    //保持和主窗口类似
    this->setFixedSize(400,550);
    this->setWindowTitle("PlayScene");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //代码实现添加菜单栏、按钮、点击退出
    QMenuBar *bar=menuBar();
    QMenu *menu= bar->addMenu("Start");
    QAction *action= menu->addAction("Close");
    connect(action,&QAction::triggered,[=]()
    {
        this->close();

    });
    //音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);
    QSound*coinFlipSound=new QSound(":/res/ConFlipSound.wav",this);
    QSound*winSound=new QSound(":/res/LevelWinSound.wav",this);
    //返回按钮
    MyPushButton *backBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //按下图片切换功能，重载鼠标按下释放按钮
    connect(backBtn,&QPushButton::clicked,[=](){

        //点击后，发送个信号，让主窗口捕捉，进行主窗口显示，关卡窗口隐藏的操作
        backSound->play();
        emit this->playL();
    });
    //显示第几关
    QLabel *lbl=new QLabel(this);
    QFont font;
    font.setFamily("");
    font.setPointSize(20);
    lbl->setFont(font);
    QString str1=QString("Level: %1").arg(this->levelNum);
    lbl->setText(str1);
    lbl->setGeometry(30,this->height()-50,120,50);
    //胜利图片资源准备
    QPixmap pixWin;
    QLabel *lblWin =new QLabel(this);
    pixWin.load(":/res/LevelCompletedDialogBg.png");
    lblWin->setPixmap(pixWin);
    lblWin->setGeometry(0,0,pixWin.width(),pixWin.height());
    lblWin->move(this->width()*0.5-lblWin->width()*0.5,-lblWin->height());

    //显示金币背景图
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;j++)
        {
            QPixmap pix;
            pix.load(":/res/BoardNode.png");
            QLabel * lbl_back=new QLabel(this);
            lbl_back->setGeometry(0,0,pix.width(),pix.height());
            lbl_back->setPixmap(pix);
            lbl_back->move(100+i*50,200+j*50);
            //从dataconfig.cpp取出每关的数组
            dataConfig confiCoin;
            this->coinArray[i][j]=confiCoin.mData[this->levelNum][i][j];
            QString strCoin;
            if(this->coinArray[i][j]==1)
            {
                strCoin=":/res/Coin0001.png";
            }
            else
            {
                strCoin=":/res/Coin0008.png";
            }
            MyCoin *coin =new MyCoin(strCoin);
            coin->setParent(this);
            coin->move(104+i*50,204+j*50);

            //记录硬币XY位置及硬币是金币还是银币
            coin->posX=i;
            coin->posY=j;
            coin->coinFlag=coinArray[i][j];
            //记录硬币
            this->coinPosArray[i][j]=coin;


            //点击硬币，触发翻转
            connect(coin,&MyCoin::clicked,[=](){
                //防止在胜利时候又快速点击了其他硬币，默认规定成一次只能点一个硬币
                //当前翻转完成再能点击其他硬币

                for (int i=0;i<4;++i)
                {
                    for (int j=0;j<4;++j)
                    {
                        this->coinPosArray[i][j]->coinAllFlag=true;
                    }
                }
                coinFlipSound->play();
                coin->TurnFlag();
                this->coinArray[i][j]=this->coinArray[i][j]==1?0:1;
                QTimer::singleShot(300,this,[=](){
                    //右侧硬币是否可以翻转,从0开始的
                    if(coin->posX+1<=3)
                    {
                        this->coinPosArray[coin->posX+1][coin->posY]->TurnFlag();
                        this->coinArray[i][j]=this->coinArray[coin->posX+1][coin->posY]==1?0:1;
                    }
                    //左侧硬币是否可以翻转
                    if(coin->posX-1>=0)
                    {
                        this->coinPosArray[coin->posX-1][coin->posY]->TurnFlag();
                        this->coinArray[i][j]=this->coinArray[coin->posX-1][coin->posY]==1?0:1;
                    }
                    //上方硬币是否可以翻转
                    if(coin->posY-1>=0)
                    {
                        this->coinPosArray[coin->posX][coin->posY-1]->TurnFlag();
                        this->coinArray[i][j]=this->coinArray[coin->posX][coin->posY-1]==1?0:1;
                    }
                    //下方硬币是否可以翻转
                    if(coin->posY+1<=3)
                    {
                        this->coinPosArray[coin->posX][coin->posY+1]->TurnFlag();
                        this->coinArray[i][j]=this->coinArray[coin->posX][coin->posY+1]==1?0:1;
                    }
                    //硬币翻完后，判断是否胜利
                    this->isWin=true;
                    for (int i=0;i<4;++i)
                    {
                        for (int j=0;j<4;++j)
                        {
                            if(this->coinPosArray[i][j]->coinFlag==0)
                            {
                                this->isWin=false;
                                //没有胜利就再允许翻转金币
                                for (int i=0;i<4;++i)
                                {
                                    for (int j=0;j<4;++j)
                                    {
                                        this->coinPosArray[i][j]->coinAllFlag=false;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    //胜利了
                    if(this->isWin)
                    {
                        for (int i=0;i<4;++i)
                        {
                            for (int j=0;j<4;++j)
                            {
                                this->coinPosArray[i][j]->coinAllFlag=true;
                            }
                        }
                        winSound->play();
                        //显示胜利图片
                        //创建动画对象
                        QPropertyAnimation * animation=new QPropertyAnimation(lblWin,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        //创建起始位置
                        animation->setStartValue(QRect(lblWin-> x(),lblWin->y(),lblWin->width(),lblWin->height()));
                        //创建结束位置
                        animation->setEndValue(QRect(lblWin->x(),lblWin->y()+120,lblWin->width(),lblWin->height()));
                        //设置缓和曲线，弹跳效果
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //开始执行动画
                        animation->start();
                    }
                });
            });
        }

    }


}
void PlayScene::paintEvent(QPaintEvent *)
{
    //绘制背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}
