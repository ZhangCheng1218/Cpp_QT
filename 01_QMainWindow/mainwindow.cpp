#include "mainwindow.h"
#include<QMenuBar>//菜单
#include<QToolBar>//工具栏
#include<QPushButton>//按钮
#include<QStatusBar>//状态栏
#include<QLabel>//标签
#include<QTextEdit>
#include<QDockWidget>//铆接部件

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);
    //1、菜单栏 只能最多有一个
    //菜单栏创建
    QMenuBar * bar=menuBar();
    //将菜单栏放入窗口
    setMenuBar(bar);
    //创建菜单
    QMenu * fileMenu =bar->addMenu("File");
    QMenu * editMenu =bar->addMenu("Edit");
    //创建菜单项
    fileMenu->addAction("New");
    //添加分割线
    fileMenu->addSeparator();
    fileMenu->addAction("Open");
    editMenu->addMenu("Color")->addAction("Green");
    //2、工具栏
    QToolBar * toolBar=new QToolBar(this);
    addToolBar(Qt::TopToolBarArea,toolBar);
    //设置工具栏是否可以移动，默认为true
    toolBar->setMovable(true);
    //设置禁止浮动
    toolBar->setFloatable(false);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    toolBar->addAction("Open");
    toolBar->addSeparator();
    toolBar->addAction("Close");
    //3、按钮
    QPushButton *btn =new QPushButton("MyBtn",this);
    toolBar->addWidget(btn);
    //4、状态栏 最多有一个
    QStatusBar * stbar=new QStatusBar;
    //状态栏放入窗口
    setStatusBar(stbar);
    //5、标签控件
    QLabel *lbl1=new QLabel("Lstauts",this);
    QLabel *lbl2=new QLabel("Rstauts",this);
    //标签添加到左侧
    stbar->addWidget(lbl1);
    //标签添加到右侧
    stbar->addPermanentWidget(lbl2);
    //6、记事本部件
    QTextEdit *edi=new QTextEdit(this);
    //设置到窗口中心
    setCentralWidget(edi);
    //7、铆接部件
    QDockWidget *dock =new QDockWidget(this);
    //添加到底部
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

}

MainWindow::~MainWindow()
{
}

