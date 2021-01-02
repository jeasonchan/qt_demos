#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //使用类成员对象的方式设置一个按钮，最佳实践其实就是通过增加成员对象来增加元素
    //但是，最佳实践是设置对象指针，而不是一个类对象,且不需要自己在析构函数中手动管理delete
    this->q1=new QPushButton();
    this->q1->setText("button_1号");
    this->q1->setParent(this);

    //设置第二个按钮
    q2=new QPushButton("button_2",this);
    //左上角微起点，x为横向
    q2->move(100,300);
    q2->resize(200,50);


    //设置当前的窗口
    this->resize(600,600);
    this->setFixedSize(600,600);
    this->setWindowTitle("window_title");
}

MyWidget::~MyWidget()
{
    delete ui;
}
