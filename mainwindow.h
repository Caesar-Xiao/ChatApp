#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chatform.h"
#include "registerform.h"
#include "mysqlhelper.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class landingWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_accountCombo_currentTextChanged(const QString &arg1);
    void on_passwordLine_textChanged(const QString &arg1);

    void on_landingBtn_clicked();

    void on_registerBtn_clicked();

private:
    Ui::landingWindow *landingWindow;

    ChartForm chatForm;
    RegisterForm registerForm;
    MySqlHelper sqlHelper;

    QString account;
    QString password;
};
#endif // MAINWINDOW_H
