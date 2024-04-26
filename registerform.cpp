#include "registerform.h"
#include "formcontroler.h"
#include "mainwindow.h"

#include <QPushButton>
#include <QMessageBox>

RegisterForm::RegisterForm():FormControler(){}

void RegisterForm::setMainWindow(MainWindow *mWindow)
{
    mainWindow=mWindow;
    setEvents();
}

void RegisterForm::setEvents(){
    registerBtn=form->findChild<QPushButton*>("registerBtn");
    accountLine=form->findChild<QLineEdit*>("accountLine");
    passwordLine=form->findChild<QLineEdit*>("passwordLine");
    checkPasswordLine=form->findChild<QLineEdit*>("checkPasswordLine");

    QObject::connect(registerBtn,&QPushButton::clicked,
                     this->form,[this](){this->registerEvent();});
    QObject::connect(accountLine,&QLineEdit::textChanged,
                     this->form,[this](){this->account=this->accountLine->text().trimmed();});
    QObject::connect(passwordLine,&QLineEdit::textChanged,
                     this->form,[this](){this->password=this->passwordLine->text().trimmed();});
    QObject::connect(checkPasswordLine,&QLineEdit::textChanged,
                     this->form,[this](){this->passwordChecked=this->checkPasswordLine->text().trimmed();});
}

void RegisterForm::registerEvent()
{
    if (!setWarning())
        return;

    mainWindow->show();
    form->close();
}

bool RegisterForm::setWarning(){
    if (account.contains(' ')){
        QMessageBox::warning(this->form,"警告","账号中存在空格，请重新输入！");
        return false;
    }
    if (password.contains(' ')){
        QMessageBox::warning(this->form,"警告","密码中存在空格，请重新输入！");
        return false;
    }
    if (password!=passwordChecked){
        QMessageBox::warning(this->form,"警告","密码与确认密码不一致，请重新输入！");
        return false;
    }

    return true;
}
