#include "formcontroler.h"
#include <QUiLoader>
#include <QFile>

FormControler::FormControler(){}

FormControler::~FormControler(){
    delete form;
    form=nullptr;
}

void FormControler::loadForm(QString formName, QWidget *mainWindow)
{
    QUiLoader uiLoader;

    QString fileName=":/forms/%1.ui";
    QFile file(fileName.arg(formName));

    file.open(QFile::ReadOnly);
    form=uiLoader.load(&file,mainWindow);
    file.close();

    QMetaObject::connectSlotsByName(form);
}

void FormControler::show()
{
    form->show();
}

void FormControler::close()
{
    form->close();
}
