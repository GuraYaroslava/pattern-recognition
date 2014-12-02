#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include <QMessageBox>

int GetTicketCost(int);
void GetRandomTickets(int&, int&, int&);

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

    int count = ui->lineEdit->text().toInt();
    int successResult = 0;
    double expected = 0;
    double result = 0;

    if (!count)
    {
        messageBox.setText("Введите целое число.");
        messageBox.exec();
    }

    if (ui->aButton->isChecked())
    {
        for (int i = 0; i < count; ++i)
        {
            int firstTicket = rand()%10+1;
            int secondTicket = rand()%10+1;
            int thirdTicket = rand()%10+1;

            GetRandomTickets(firstTicket, secondTicket, thirdTicket);

            if (GetTicketCost(firstTicket) == GetTicketCost(secondTicket)
                || GetTicketCost(firstTicket) == GetTicketCost(thirdTicket)
                || GetTicketCost(secondTicket) == GetTicketCost(thirdTicket))
            {
                ++successResult;
            }
        }

        expected = (double)3/4;
        result = ((double)(successResult))/count;
    }
    else if (ui->bButton->isChecked())
    {
        for (int i = 0; i < count; ++i)
        {
            int firstTicket = rand()%10+1;
            int secondTicket = rand()%10+1;
            int thirdTicket = rand()%10+1;

            GetRandomTickets(firstTicket, secondTicket, thirdTicket);

            if (GetTicketCost(firstTicket)
                + GetTicketCost(secondTicket)
                + GetTicketCost(thirdTicket)
                == 7)
            {
                ++successResult;
            }
        }
        expected = (double)7/24;
        result = (double)successResult/count;
    }
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
                             + QString::number((expected - result)));
}

int GetTicketCost(int ticket)
{
    int result = 0;

    switch (ticket) {
    case 1:
        result = 1;
        break;
    case 2:
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    case 4:
        result = 1;
        break;
    case 5:
        result = 1;
        break;
    case 6:
        result = 3;
        break;
    case 7:
        result = 3;
        break;
    case 8:
        result = 3;
        break;
    case 9:
        result = 5;
        break;
    case 10:
        result = 5;
        break;
    default:
        break;
    }

    return result;
}

void GetRandomTickets(int &firstTicket, int &secondTicket, int &thirdTicket)
{
    while (firstTicket == secondTicket
           || firstTicket == thirdTicket
           || secondTicket == thirdTicket)
    {
        firstTicket = rand()%10+1;
        secondTicket = rand()%10+1;
        thirdTicket = rand()%10+1;
    }
}
