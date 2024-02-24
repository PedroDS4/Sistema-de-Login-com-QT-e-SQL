#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "fm_principal.h"
#include "users.h"



QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    QSqlDatabase BancoDeDados;
    User U;

private slots:
    void on_btn_login_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
