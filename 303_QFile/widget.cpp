#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString filePath=QFileDialog::getOpenFileName(this,"Open File","C:\\Users\\Administrator\\Documents");
       ui->lineEdit->setText(filePath);
        QFile fl(filePath);
        fl.open(QIODevice::ReadOnly);
        QByteArray line;
        while(!fl.atEnd())
        {
            line+=fl.readLine();
        }
        ui->textEdit->setText(line);
        fl.close();
        //追加形式写入
//        fl.open(QIODevice::Append);
//        fl.write("abaabaababa");
//        fl.close();
        //后缀名
        QFileInfo info(filePath);
        qDebug()<<"suffix:"<<info.suffix();
        qDebug()<<"Created Time:"<<info.created().toString("yyyy/MM/dd HH:mm:ss");
    });
    //

}

Widget::~Widget()
{
    delete ui;
}

