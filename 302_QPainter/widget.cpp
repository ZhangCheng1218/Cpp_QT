#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QImage>
#include<QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //计时器实现自动移动
//    QTimer *timer=new QTimer(this);
//    timer->start(200);
//    connect(timer,&QTimer::timeout,[=](){
//        posx+=100;
//        update();
//    });


    ///////QPixmap绘图设备，专门为不同平台做了显示的优化/////////////////
//    QPixmap pix(200,200);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(100,100),50,50);
//    pix.save("C:/Users/Administrator/Pictures/1.jpg");

    ////////QPicture可以记录和重现绘图指令////////////////////////
//    QPainter painter;
//    QPicture pic;
//    painter.begin(&pic);
//    painter.drawEllipse(QPoint(100,100),50,50);
//    painter.end();
//    pic.save("C:/Users/Administrator/Pictures/pic.zc");
}
void Widget::paintEvent(QPaintEvent *)
{
//    //创建画家，this为画板
//    QPainter paint(this);
//    QPen pen(QColor(120,122,10));
//    pen.setWidth(2);
//    QBrush brush(QColor(255,0,0));
//    paint.setPen(pen);
//    paint.drawLine(0,0,300,300);
//    paint.drawEllipse(QPoint(100,100),100,100);
//    paint.drawText(100,100,"center");


    //////////////////////高级设置//////////////////////
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,100),100,100);
//    painter.setRenderHints(QPainter::Antialiasing);//抗锯齿，效率低
//    painter.drawEllipse(QPoint(300,100),100,100);

//    painter.drawRect(0,300,100,100);
//    painter.translate(100,0);//由给定的值平移坐标系
//    painter.save();//保存状态
//    painter.drawRect(0,300,100,100);
//    painter.translate(100,0);
//    painter.restore();//还原状态
//    painter.drawRect(0,300,100,100);
    ///////////////////////绘制资源图片/////////////////
//    QPainter painter(this);
//    if(posx>this->width())
//    {
//       posx=0;
//    }
//    painter.drawPixmap(posx,10,QPixmap(":/src/7.jpg"));

    ///////////////////////QImage可以像素级操作/////////////////////////
//    QPainter painter(this);
//    QImage img(200,200,QImage::Format_RGB32);
//    img.load(":/src/2.jpg");
//    for (int i=100;i<200;++i)
//    {
//        for (int j=100;j<200;++j)
//        {
//            img.setPixelColor(i,j,Qt::green);
//        }
//    }
//    painter.drawImage(0,0,img);

    ////////////////QPicture重现操作//////////////
    QPainter painter(this);
    QPicture pic;
    pic.load("C:/Users/Administrator/Pictures/pic.zc");
    painter.drawPicture(0,0,pic);

}
Widget::~Widget()
{
    delete ui;
}

