#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>

double drandom(double, double);
bool between(double, double, double);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    QMessageBox messageBox;

    int a = 5;
    int b = 6;
    int r = 1;
    int d = 2;

    int count = ui->lineEdit->text().toInt();
    int successResult = 0;
    double expected = 0;
    double result = 0;

    if (!count)
    {
        messageBox.setText("Введите целое число.");
        messageBox.exec();
    }

    for (int i = 0; i < count; ++i)
    {
        double x = drandom(0, b);
        double y = drandom(0, a);

        if (between(r, b-r, x-d/2)
            && between(r, b-r, x+d/2)
            && between(r, a-r, y-d/2)
            && between(r, a-r, y+d/2))
        {
            ++successResult;
        }
    }

    expected = (double)1/15;
    result = (double)successResult/count;

    ui->resultLabel->setText(QString::number(successResult)
                             + " удачных экспериментов из "
                             + QString::number(count)
                             + "\n"
                             + "аналитичнское решение: "
                             + QString::number(expected)
                             + "\n"
                             + "экспериментальное решение: "
                             + QString::number(result)
                             + "\n"
                             + "погрешность: "
                             + QString::number(expected - result));
}

double drandom(double a, double b)
{
    return a+(b-a)*(double)rand()/RAND_MAX;
}

bool between(double x, double y, double z)
{
    if (x > y)
    {
        double t = y;
        y = x;
        x = t;
    }

    return x <= z && z <= y;
}
