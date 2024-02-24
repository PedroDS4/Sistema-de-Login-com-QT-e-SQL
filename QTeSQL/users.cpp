
#include <QString>
#include <QtSql>
#include "users.h"
#include <QCoreApplication>
#include <QDebug>


User::User(): username(""),password(""),email(""),name(""){

}

User::User(const QString& username, const QString& password, const QString& email, const QString& name):username(username),password(password),email(email),name(name),Connected(false){

}

User::User(const QString& username, const QString& password, const QString& email, const QString& name, const bool Connected):username(username),password(password),email(email),name(name),Connected(Connected){

}

User User::operator=(const User& u){

    if(this!=&u){
        this->username = u.username;
        this->password = u.password;
        this->email = u.email;
        this->name = u.name;
    }

    return *this;


}

QString User::getUsername() const{
    return this->username;
}

QString User::getPassword() const{
    return this->password;
}

QString User::getEmail() const{
    return this->email;
}

QString User::getName() const{
    return this->name;
}

bool User::isConnected() const{
    return this->Connected;
}

void User::setUsername(const QString& username){

    this->username = username;
}

void User::setPassword(const QString& password){

    this->password = password;
}


void User::setEmail(const QString& email){

    this->email = email;
}


void User::setName(const QString& name){

    this->name = name;
}

void User::setConnected(bool connected){
    this->Connected =  connected;
}


bool validUsername(QString& username){
    if(username.contains(" ") || username.length()<6) return false;
    return true;
}

bool validPassword(QString& password){
    if(password.length()<5) return false;
    return true;
}

bool validEmail(QString& email){
    if(!email.contains("@") || email.length()<5) return false;
    return true;
}

bool validName(QString& name){
    static QRegularExpression regex("\\d");
    if(name.contains(regex)) return false;
            return true;
}






