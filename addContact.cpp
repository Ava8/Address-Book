#include "addContact.h"
#include "ui_addContact.h"

addContact::addContact(AddressBook *holder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addContact)
{
    ab = holder;
    ui->setupUi(this);

    QRegExp rx_s("^[a-zA-Zа-яА-Я0-9_]*$");
    QValidator *val_name = new QRegExpValidator(rx_s, this);
    ui->name_edit->setValidator(val_name);
    ui->surname_edit->setValidator(val_name);

    QRegExp rx_n("^[0-9]*$");
    QValidator *val_phone= new QRegExpValidator(rx_n, this);
    ui->phone_edit->setValidator(val_phone);
}

addContact::~addContact()
{
    delete ui;
}

void addContact::on_addButton_clicked()
{
    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString phone = ui->phone_edit->text();
    QString email = ui->email_edit->text();
    QString adress = ui->adress_edit->toPlainText();
    QString note = ui->note_edit->toPlainText();


    query = new QSqlQuery;
    query->prepare("INSERT INTO userData "
                   "("
                   "user_login,"
                   "contact_name,"
                   "contact_surname, "
                   "contact_phone,"
                   "contact_mail,"
                   "contact_adress,"
                   "contact_note,"
                   "contact_photo"
                   ") "
                   "VALUES"
                   "("
                   ":login, "
                   ":name, "
                   ":surname, "
                   ":phone, "
                   ":mail, "
                   ":adress, "
                   ":note, "
                   ":photo"
                   ");");
    query->bindValue(":login", ab->user.login);
    query->bindValue(":name", name);
    query->bindValue(":surname", surname);
    query->bindValue(":phone", phone);
    query->bindValue(":mail", email);
    query->bindValue(":adress", adress);
    query->bindValue(":note", note);
    query->bindValue(":photo", imageData);

    if(!query->exec()) {
        qDebug() << "insert into userData tabel error" << endl;
    }

    ab->getContacts();
    close();
}

void addContact::on_set_image_clicked()
{
    QString set_image = QFileDialog::getOpenFileName(this,
                                                     tr("Open File"),
                                                     "C://",
                                                     "Image File (*.*)");
    Photo.load(set_image);
    QBuffer imageBuf(&imageData);
    imageBuf.open(QIODevice::WriteOnly);
    Photo.save(&imageBuf,"JPG");
}
