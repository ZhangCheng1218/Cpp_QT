#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>//包含头文件  QWidget窗口类

class Widget : public QWidget
{
    Q_OBJECT//宏 允许类中使用信号和槽机制

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
