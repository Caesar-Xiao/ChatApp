#ifndef FORMCONTROLER_H
#define FORMCONTROLER_H

#include <QWidget>
#include <QPushButton>

class FormControler
{
public:
    FormControler();
    ~FormControler();

    void loadForm(QString formName, QWidget *mainWindow);
    void show();
    void close();

protected:
    QWidget *form;
};

#endif // FORMCONTROLER_H
