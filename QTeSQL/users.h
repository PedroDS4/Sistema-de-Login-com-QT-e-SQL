#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QtSql>






class User {
private:
    QString username;
    QString password;
    QString email;
    QString name;
    bool Connected;


public:

    User();
    User(const QString& username, const QString& password, const QString& email, const QString& name);
    User(const QString& username, const QString& password, const QString& email, const QString& name, const bool Connected);

    User operator=(const User& u);
    QString getUsername() const;
    QString getPassword() const;
    QString getEmail() const;
    QString getName() const;

    bool isConnected() const;

    void setUsername(const QString& username);
    void setPassword(const QString& password);
    void setEmail(const QString& email);
    void setName(const QString& name);

    void setConnected(bool connected);


    bool validUsername(QString& username);
    bool validPassword(QString& password);
    bool validEmail(QString& email);
    bool validName(QString& name);










};


#endif // USERS_H
