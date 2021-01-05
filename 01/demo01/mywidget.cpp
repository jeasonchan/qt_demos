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
  //    this->q1->setText(QString::fromLocal8Bit("button_1号"));  根据源文件的编码，将入参的字面转为8位unicode
  //    this->q1->setText("button_1号");  直接使用原生的
  this->q1->setText(QString::fromUtf8("button_1号"));  //根据utf8规则，将入参转为unicode码

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


  //设置第三个按钮，关闭当前窗口
  q3=new QPushButton(QString::fromUtf8("关闭窗口"),this);
  q3->move(200,500);

  //QT5中建议使用该种使用函数地址的重载形式，QT4中无该重载
  connect(q3,&QPushButton::clicked,this,&QWidget::close);

  //QT4中只能使用该种，无类型检查和补全提示，感觉很垃圾……
  //connect(q3,SIGNAL(clicked(bool)),this,SLOT(close()));


}

MyWidget::~MyWidget()
{
  delete ui;
}
