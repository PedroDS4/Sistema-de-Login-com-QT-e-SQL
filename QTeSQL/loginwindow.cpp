#include "loginwindow.h"
#include "fm_create_account.h"
#include "ui_loginwindow.h"





LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , BancoDeDados(QSqlDatabase::addDatabase("QSQLITE"))
    , U()
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    BancoDeDados.setDatabaseName("D:/Users/Administrator/Desktop/Projetos/QTeSQL/Banco de dados/storage.db");
    if(!BancoDeDados.open()){
        ui->label->setText("Não foi possível abrir o banco de dados");
    }else{
        ui->label->setText("banco de dados aberto com sucesso");
    }

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_btn_login_clicked()
{
    QString username = ui->txt_username->text();
    QString senha = ui->txt_senha->text();

    if(!BancoDeDados.isOpen()){

        qDebug()<<"Banco de dados não esta aberto";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        if (query.value(2) == senha) {
            // Usuário autenticado
            this->close();
            fm_principal f_principal;


            U.setUsername(QString(query.value(1).toString()));
            U.setPassword(QString(query.value(2).toString()));
            U.setEmail(QString(query.value(3).toString()));
            U.setName(QString(query.value(4).toString()));

            f_principal.setModal(true);

            f_principal.setUser(U);

            f_principal.exec();
            f_principal.Welcome("Bem vindo, "+f_principal.user.getName());


        } else {
            ui->label_4->setText("Senha Inválida");
        }
    } else {
        ui->label_4->setText("Usuário não cadastrado");
        ui->txt_username->clear();
        ui->txt_senha->clear();
        ui->txt_username->setFocus();
    }

}





void LoginWindow::on_commandLinkButton_clicked()
{
    this->close();
    fm_create_account create_account;
    create_account.exec();
}

