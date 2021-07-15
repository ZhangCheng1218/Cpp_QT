#include "smallwidget.h"
#include "ui_smallwidget.h"
#include<QSpinBox>
SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //数字改变对应滑块移动
    void(QSpinBox:: * vac)(int)  =&QSpinBox::valueChanged;
    connect(ui->spBox,vac,ui->hoS,&QSlider::setValue);
    //滑块移动对应数字变化
    connect(ui->hoS,&QSlider::valueChanged,ui->spBox,&QSpinBox::setValue);

}
void SmallWidget::setNum(int num)
{
    ui->spBox->setValue(num);
}

int SmallWidget::getNum()
{
  return  ui->spBox->value();
}
SmallWidget::~SmallWidget()
{
    delete ui;
}
