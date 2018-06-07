#include "contact.h"

Contact::Contact(QString name, QString surname,
                 QString phone,
                 QString mail,
                 QString adress,
                 QString note,
                 QPixmap photo)
{
    this->name = name;
    this->surname = surname;
    this->phone = phone;
    this->mail = mail;
    this->adress = adress;
    this->note = note;
    this->photo = photo;
}
Contact::Contact() { }
Contact::~Contact() { }
