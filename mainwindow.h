#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    QWidget *chatWindow;
    QWidget *registerWindow;
    QString account;
    QString password;

    QWidget* loadForm(QString formName);
    void registerCheck();
};
#endif // MAINWINDOW_H
