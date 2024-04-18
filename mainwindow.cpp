#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::landingWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountCombo_currentTextChanged(const QString &arg1)
{
    account=arg1;
}


void MainWindow::on_passwordLine_textChanged(const QString &arg1)
{
    password=arg1;
}

