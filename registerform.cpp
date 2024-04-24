#include "registerform.h"
#include "formcontroler.h"
#include "mainwindow.h"

#include <QPushButton>

RegisterForm::RegisterForm():FormControler(){}

void RegisterForm::setMainWindow(MainWindow *mWindow)
{
    mainWindow=mWindow;
    setEvents();
}

void RegisterForm::setEvents(){
    registerBtn=form->findChild<QPushButton*>("registerBtn");

    QObject::connect(registerBtn,&QPushButton::clicked,mainWindow,
                     [this](){
                         this->mainWindow->show();
                         this->form->close();
                     });
}
