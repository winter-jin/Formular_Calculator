#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置字体
    QFont ft;
    ft.setPointSize(14);
    ui->label_x1->setFont(ft);
    ui->label_x2->setFont(ft);
    ui->label_x3->setFont(ft);
    ui->label_y1->setFont(ft);
    ui->label_y2->setFont(ft);
    ui->label_y3->setFont(ft);
    ui->label_z1->setFont(ft);
    ui->label_z2->setFont(ft);
    ui->label_z3->setFont(ft);

    //设置文字内容
    ui->label_x1->setText("X");
    ui->label_x2->setText("X");
    ui->label_x3->setText("X");
    ui->label_y1->setText("Y");
    ui->label_y2->setText("Y");
    ui->label_y3->setText("Y");
    ui->label_z1->setText("Z=");
    ui->label_z2->setText("Z=");
    ui->label_z3->setText("Z=");
    ui->x_result->setText("X=");
    ui->y_result->setText("Y=");
    ui->z_result->setText("Z=");
}

void MainWindow::on_pushButton_clicked()
{
    //int flag =0
    int a1 = ui->lineEdit_x1->text().toInt();
    int a2 = ui->lineEdit_x2->text().toInt();
    int a3 = ui->lineEdit_x3->text().toInt();
    int b1 = ui->lineEdit_y1->text().toInt();
    int b2 = ui->lineEdit_y2->text().toInt();
    int b3 = ui->lineEdit_y3->text().toInt();
    int c1 = ui->lineEdit_z1->text().toInt();
    int c2 = ui->lineEdit_z2->text().toInt();
    int c3 = ui->lineEdit_z3->text().toInt();
    int d1 = ui->lineEdit_equal1->text().toInt();
    int d2 = ui->lineEdit_equal2->text().toInt();
    int d3 = ui->lineEdit_equal3->text().toInt();
    //利用crammer法则
    double D = a1*b2*c3 + b1*c2*a3 + a2*b3*c1 - a3*b2*c1 - a2*b1*c3 - a1*c2*b3;
    if(D == 0.0)
    {
        ui->x_value->setText(QString::fromLocal8Bit("无解"));
        ui->y_value->setText(QString::fromLocal8Bit("无解"));
        ui->z_value->setText(QString::fromLocal8Bit("无解"));
    }
    else
    {
        double Dx = d1*b2*c3 + b1*c2*d3 + c1*d2*b3 - d3*b2*c1 - b3*c2*d1 - d2*b1*c3;
        double Dy = a1*d2*c3 + d1*c2*a3 + a2*d3*c1 - a3*d2*c1 - a2*d1*c3 - a1*d3*c2;
        double Dz = a1*b2*d3 + b1*d2*a3 + a2*b3*d1 - a3*b2*d1 - a2*b1*d3 - a1*b3*d2;
        ui->x_value->setText(QString::number(Dx/D, 10, 4));
        ui->y_value->setText(QString::number(Dy/D, 10, 4));
        ui->z_value->setText(QString::number(Dz/D, 10, 4));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}











