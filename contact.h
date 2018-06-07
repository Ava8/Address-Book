#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>

class Contact
{
public:
    QString name;
    QString surname;
    QString phone;
    QString mail;
    QString adress;
    QString note;
    QPixmap photo;
    Contact(QString name, QString surname,
            QString phone, QString mail, QString adress,
            QString note,
            QPixmap photo);

    Contact();
    ~Contact();
};

#endif // CONTACT_H
