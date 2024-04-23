#include "registerform.h"
#include "formcontroler.h"
#include "mainwindow.h"

#include <QPushButton>

RegisterForm::RegisterForm():FormControler(){}

void RegisterForm::setMainWindow(MainWindow *mWindow)
{
    mainWindow=mWindow;
}

void RegisterForm::on_registerBtn_clicked(){
    mainWindow->show();
    form->close();
}


