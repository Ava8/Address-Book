#ifndef REGISTWINDOW_H
#define REGISTWINDOW_H

#include <QWidget>
#include<QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "AddressBook.h"

namespace Ui {
class RegistWindow;
}

class RegistWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistWindow(QWidget *parent = 0);
    ~RegistWindow();

    QSqlQuery *query;
    bool registration(QString login, QString password);

private slots:
    void on_regist_clicked();

private:
    Ui::RegistWindow *ui;
    AddressBook *ab;
};

#endif // REGISTWINDOW_H
