#include "widget.h"

#include <QApplication>//包含一个应用程序类的头文件
/*
跨平台图形界面引擎
  优点：跨平台、接口简单、一定程度上简化了内存回收
  成功案例：linux桌面环境KDE、谷歌地图、VLC多媒体播放器
  三大基类：QWidget、QMainWindow、QDialog
*/
int main(int argc, char *argv[])//argc 命令行变量的数量，argv命令行变量的数组
{
    QApplication a(argc, argv);//a 应用程序对象，在QT中有且只有一个应用程序对象
    Widget w;//窗口对象 父类->Qwidget
    w.show();//窗口对象默认不会显示，必须用show
    return a.exec();//让应用程序对象进入消息循环机制中
}
