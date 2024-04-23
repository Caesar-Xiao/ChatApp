#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>

// #include <QSqlDatabase>
// #include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , landingWindow(new Ui::landingWindow)
{
    landingWindow->setupUi(this);

    QString formName="chatform";
    chatForm.loadForm(formName,this);

    formName="registerform";
    registerForm.loadForm(formName,this);
    registerForm.setMainWindow(this);
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
    chatForm.show();
}


void MainWindow::on_registerBtn_clicked()
{
    this->close();
    registerForm.show();
}

