#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include "formcontroler.h"
#include <QPushButton>

class MainWindow;
class RegisterForm: public FormControler
{
public:
    RegisterForm();


    void setMainWindow(MainWindow *mWindow);

private slots:
    void on_registerBtn_clicked();

private:
    MainWindow *mainWindow;
};

#endif // REGISTERFORM_H
