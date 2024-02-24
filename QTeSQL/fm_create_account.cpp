#include "fm_create_account.h"
#include "ui_fm_create_account.h"
#include "users.h"
#include "users.cpp"

fm_create_account::fm_create_account(QWidget *parent) :
    QDialog(parent),
    BancoDeDados(QSqlDatabase::addDatabase("QSQLITE")),
    U(),
    ui(new Ui::fm_create_account)
{
    ui->setupUi(this);
    BancoDeDados.setDatabaseName("D:/Users/Administrator/Desktop/Projetos/QTeSQL/Banco de dados/storage.db");
    if(!BancoDeDados.open()){
        qDebug()<<("Não foi possível abrir o banco de dados");
    }else{
        qDebug()<<("banco de dados aberto com sucesso");
    }
}

fm_create_account::~fm_create_account()
{
    delete ui;
}





void fm_create_account::on_btn_create_account_clicked()
{
    QString username = ui->line_username->text();
    QString email = ui->line_email->text();
    QString password = ui->line_password->text();
    QString name = ui->line_name->text();

    if(validUsername(username)){
        U.setUsername(username);
    }else{
        ui->Erro_label->setText("Usuário precisa ter mais de 5 caracteres e não pode conter espaços");
        return;
    }

    if(validPassword(password)){
        U.setPassword(password);
    }else{
        ui->Erro_label->setText("Senha precisa ter mais de 5 caracteres");
        return;
    }

    if(validEmail(email)){
        U.setEmail(email);
    }else{
        ui->Erro_label->setText("Email inválido");
        return;
    }


    if(validName(name)){
        U.setName(name);
    }else{
        ui->Erro_label->setText("Nome não pode conter números");
        return;
    }


    if(!BancoDeDados.isOpen()){

        qDebug()<<"Banco de dados não esta aberto";
        return;
    }



    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, email, name) VALUES (:username, :password, :email, :name)");
    query.bindValue(":username", U.getUsername());
    query.bindValue(":password", U.getPassword());
    query.bindValue(":email", U.getEmail());
    query.bindValue(":name", U.getName());

    if(query.exec()){
        U.setConnected(true);
        this->close();
        fm_principal f_principal;
        f_principal.setModal(true);
        f_principal.exec();
    }
    else{
        ui->Erro_label->setText("Usuário já existe");
    }






}


