#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDialog>
#include<QPushButton>


namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    //宏，很多好魔法都是用宏实现的
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;

    QPushButton *q1;
    QPushButton *q2;

};

#endif // MYWIDGET_H
