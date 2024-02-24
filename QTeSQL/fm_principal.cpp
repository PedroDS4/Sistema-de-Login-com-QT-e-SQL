#include "fm_principal.h"
#include "ui_fm_principal.h"

fm_principal::fm_principal(QWidget *parent) :
    QDialog(parent),
    user(),
    ui(new Ui::fm_principal)
{
    ui->setupUi(this);
    ui->welcome_label->setText("Bem vindo, "+user.getName());

}

fm_principal::~fm_principal()
{
    delete ui;
}

void fm_principal::setUser(User u){

    this->user = u;
}

void fm_principal::Welcome(QString texto){

    this->ui->welcome_label->setText(texto);

}

