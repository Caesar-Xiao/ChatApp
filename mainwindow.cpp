#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QUiLoader>
#include <QFile>
// #include <QSqlDatabase>
// #include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , landingWindow(new Ui::landingWindow)
{
    landingWindow->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete landingWindow;
    delete chatWindow;
    delete registerWindow;
}

QWidget* MainWindow::loadForm(QString formName)
{
    QUiLoader uiLoader;

    QString fileName=":/forms/%1.ui";
    QFile file(fileName.arg(formName));

    file.open(QFile::ReadOnly);
    QWidget *window=uiLoader.load(&file,this);
    file.close();

    return window;
}

void  MainWindow::registerCheck()
{
    this->show();
    registerWindow->close();
    delete registerWindow;
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
    QString fileName="chatwindow";
    chatWindow=loadForm(fileName);

    this->close();
    chatWindow->show();
}


void MainWindow::on_registerBtn_clicked()
{
    QString fileName="registerwindow";
    registerWindow=loadForm(fileName);

    QPushButton *registerBtn=registerWindow->findChild<QPushButton *>("registerBtn");
    connect(registerBtn,&QPushButton::clicked,this,&MainWindow::registerCheck);

    this->close();
    registerWindow->show();
}

