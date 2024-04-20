#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QUiLoader>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , landingWindow(new Ui::landingWindow)
{
    landingWindow->setupUi(this);

    QUiLoader uiLoader;
    QFile file(":/forms/chatwindow.ui");

    file.open(QFile::ReadOnly);
    chatWindow=uiLoader.load(&file,this);
    file.close();
}

MainWindow::~MainWindow()
{
    delete landingWindow;
}

void MainWindow::on_accountCombo_currentTextChanged(const QString &arg1)
{
    account=arg1;
}


void MainWindow::on_passwordLine_textChanged(const QString &arg1)
{
    password=arg1;
}


void MainWindow::on_landingBtn_clicked()
{
    this->close();
    chatWindow->show();
}

