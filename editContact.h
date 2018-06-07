#ifndef EDITCONTACT_H
#define EDITCONTACT_H

#include <QWidget>
#include <QCloseEvent>
#include "AddressBook.h"
#include "contact.h"

class AddressBook;

namespace Ui {
class editContact;
}

class editContact : public QWidget
{
    Q_OBJECT

public:
    explicit editContact(AddressBook *holder, QWidget *parent = 0);
    ~editContact();

    QSqlQuery *query;
    QByteArray imageData;
    QBuffer imageBuf;
    QPixmap Photo;

    void editContactWindow(QString name,
                           QString surname,
                           QString phone,
                           QString email,
                           QString adress,
                           QString note);

signals:
    void editDone(bool);

private slots:

    void on_editButton_clicked();

    void on_set_image_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::editContact *ui;
    AddressBook *ab;
    Contact old;
};

#endif // EDITCONTACT_H
