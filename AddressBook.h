#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>
#include<QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QIODevice>
#include <QPixmap>
#include <QListWidgetItem>
#include <vector>
#include "addContact.h"
#include "editContact.h"
#include "contact.h"
#include "user.h"

using namespace std;

class addContact;
class editContact;

namespace Ui {
class AddressBook;
}

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddressBook(QWidget *parent = 0);
    ~AddressBook();

    User user;
    QSqlQuery *query;

    void createTabel();
    void getContacts();
    void showContact(QListWidgetItem *item);

private slots:
    void on_addContact_clicked();

    void on_deleteBook_clicked();

    void on_contactsList_itemClicked(QListWidgetItem *item);

    void on_deleteContact_clicked();

    void on_editContact_clicked();

    void setEditDone(bool ed);

private:
    QString fio;
    Ui::AddressBook *ui;
    addContact *add;
    editContact *edit;
    bool editDone;

    void clearContactFields();
};

#endif // ADDRESSBOOK_H
