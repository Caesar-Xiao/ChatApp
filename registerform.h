#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include "formcontroler.h"
#include <QPushButton>
#include <QLineEdit>

class MainWindow;
class RegisterForm: public FormControler
{
public:
    RegisterForm();

    void setMainWindow(MainWindow *mWindow);

private:
    MainWindow *mainWindow;
    QPushButton *registerBtn;
    QLineEdit *accountLine;
    QLineEdit *passwordLine;
    QLineEdit *checkPasswordLine;

    QString account;
    QString password;
    QString passwordChecked;

    void setEvents();
    void registerEvent();
    bool setWarning();
};

#endif // REGISTERFORM_H
