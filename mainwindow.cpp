#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , landingWindow(new Ui::landingWindow)
{
    landingWindow->setupUi(this);

    // forms
    QString formName="chatform";
    chatForm.loadForm(formName,this);

    formName="registerform";
    registerForm.loadForm(formName,this);
    registerForm.setMainWindow(this);

    // database
    sqlHelper.connect();
}

MainWindow::~MainWindow()
{
    delete landingWindow;
}

void MainWindow::on_accountCombo_currentTextChanged(const QString &arg1)
{
    account=arg1.trimmed();
}


void MainWindow::on_passwordLine_textChanged(const QString &arg1)
{
    password=arg1.trimmed();
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

