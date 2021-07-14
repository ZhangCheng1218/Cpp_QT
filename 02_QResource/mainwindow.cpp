#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>//对话框
#include<QDebug>
#include<QMessageBox>//消息对话框
#include<QColorDialog>//颜色对话框
#include<QFileDialog>//文件对话框
#include<QFontDialog>//文字对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1、把资源文件拷贝到项目下
    //2、右键项目，添加sourcesfile
    //3、把项目目录下资源添加到.qrc中
    //4、使用如下
    ui->actionNew->setIcon(QIcon(":/src/1.jpg"));
    ui->actionOpen->setIcon(QIcon(":/src/2.jpg"));

    //点击新建按钮弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=]()
    {
        //1、对话框分类
        //①模态对话框----阻塞----不可以对其他窗口进行操作
        //②非模态对话框----------可以对其他窗口进行操作
        //模态对话框
//        QDialog dia(this);
//        dia.resize(300,300);
//        dia.setWindowTitle("Modal Dialog");
//        dia.exec();
//        qDebug()<<"Modal Dialog!";

        //非模态对话框，需要创建在堆区
//        QDialog* dia=new QDialog(this);
//        dia->resize(300,300);
//        dia->setWindowTitle("Non-Modal Dialog!");
//        dia->show();
//        //放置沙雕重复点导致堆区内存泄漏,关掉dialog就释放掉堆区dia;
//        dia->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug()<<"Non-Modal Dialog!";


        //2、消息对话框
        //紧急错误！
//        QMessageBox::critical(this,"critical","Error!");
        //消息
//        QMessageBox::information(this,"information","info");
        //问题
//        if (QMessageBox::Ok==(QMessageBox::question(this,"Question","question",QMessageBox::Ok | QMessageBox::No,QMessageBox::No)))
//        {
//            qDebug()<<"Click Ok btn!";

//        }
        //警告
//        QMessageBox::warning(this,"Warning","Warning!\nDon't stand here!");

        //3、颜色对话框
//        QColor co=   QColorDialog::getColor(QColor(0,255,0));
//        qDebug()<<" r= "<<co.red()<<" g= "<<co.green()<<" b= "<<co.blue();
        //4、文件对话框
//       QString str= QFileDialog::getOpenFileName(this,"a","C:/Users/Administrator/Pictures/src");
//       qDebug()<<str;
        //5、字体对话框
//        bool flag;
//        QFont qf= QFontDialog::getFont(&flag,QFont("Calibri",36));
//        //字体、字号、加粗、倾斜
//        qDebug()<<qf.family()<<qf.pointSize()<<qf.bold()<<qf.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

