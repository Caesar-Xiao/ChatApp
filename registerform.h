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

private:
    MainWindow *mainWindow;
    QPushButton *registerBtn;

    void setEvents();
};

#endif // REGISTERFORM_H
