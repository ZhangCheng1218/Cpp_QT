#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRadioButton>
#include<QDebug>
#include<QCheckBox>
#include<QListWidget>
#include<QStringList>
#include<QTreeWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1、RadioBtn
//    connect(ui->rbtn_wm,&QRadioButton::clicked,[=](){
//        qDebug()<<"women";
//    });

    //2、CheckBox
//    connect(ui->cboxOK,&QCheckBox::stateChanged,[=](int ba){

//         qDebug()<<ba;
//    });

    //3、ListWidget
    //一行内容
//    QListWidgetItem * list =new QListWidgetItem("what the fuck!");
//    //将上述内容放入listwidget中
//    ui->listWidget->addItem(list);
//    //文字居中
//    list->setTextAlignment(Qt::AlignHCenter);

//    QStringList lists;
//    lists<<"WTF"<<"IMF";
//    ui->listWidget->addItems(lists);
    //4、TreeWidget
//    //设置头标签
//    ui->treeWidget->setHeaderLabels(QStringList()<<"Heros"<<"Description");
//    //创建根节点
//    QTreeWidgetItem *it1=new QTreeWidgetItem(QStringList()<<"Wei");
//    QTreeWidgetItem *it2=new QTreeWidgetItem(QStringList()<<"Shu");
//    QTreeWidgetItem *it3=new QTreeWidgetItem(QStringList()<<"Wu");
//    //放到树控件上
//    ui->treeWidget->addTopLevelItem(it1);
//    ui->treeWidget->addTopLevelItem(it2);
//    ui->treeWidget->addTopLevelItem(it3);

//    QTreeWidgetItem * it1_child=new QTreeWidgetItem(QStringList()<<"Caocao"<<"I would rather negative people of the world, I can not bear people of the world");
//    it1->addChild(it1_child);
    //5、TableWidget
    //设置行列
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Name"<<"Age"<<"Sex");
    //设置正文
    QStringList namelist;
    namelist<<"Tom"<<"Jerry"<<"White"<<"Harry"<<"Herrt";


    for (int i=0;i<5;++i)
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem("male"));

    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

