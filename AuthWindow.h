#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QMainWindow>
#include<QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "RegistWindow.h"
#include "AddressBook.h"


namespace Ui {
class AuthWindow;
}

class AuthWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = 0);
    ~AuthWindow();

    QSqlQuery *query;
    bool createConnection();
    void createTabel();
    bool authUser(QString login, QString password);

private slots:
    void on_enter_clicked();

    void on_registration_clicked();

private:
    Ui::AuthWindow *ui;
    RegistWindow *regist;
    AddressBook *ab;

};

#endif // AUTHWINDOW_H
