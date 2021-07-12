#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{
    qDebug() << "treat!";
}
void Student::treat(QString foodName)
{
    //qstring 输出带引号，转成char *;
    //先转成utf8,再转char *;
    qDebug() << "treat:"<<foodName.toUtf8().data();
}
