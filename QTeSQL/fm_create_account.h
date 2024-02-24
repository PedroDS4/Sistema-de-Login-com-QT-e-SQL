#ifndef FM_CREATE_ACCOUNT_H
#define FM_CREATE_ACCOUNT_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "fm_principal.h"
#include "users.h"


namespace Ui {
class fm_create_account;
}

class fm_create_account : public QDialog
{
    Q_OBJECT

public:
    explicit fm_create_account(QWidget *parent = nullptr);
    ~fm_create_account();
    QSqlDatabase BancoDeDados;
    User U;

private slots:
    void on_btn_create_account_clicked();

private:
    Ui::fm_create_account *ui;
};

#endif // FM_CREATE_ACCOUNT_H
