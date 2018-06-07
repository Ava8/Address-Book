#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QBuffer>
#include <QByteArray>
#include "AddressBook.h"

class AddressBook;

namespace Ui {
class addContact;
}

class addContact : public QWidget
{
    Q_OBJECT

public:
    explicit addContact(AddressBook *holder, QWidget *parent = 0);
    ~addContact();

    QSqlQuery *query;
    QByteArray imageData;
    QBuffer imageBuf;
    QPixmap Photo;

private slots:

    void on_addButton_clicked();

    void on_set_image_clicked();

private:
    Ui::addContact *ui;
    AddressBook *ab;
};

#endif // ADDCONTACT_H
