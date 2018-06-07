#include "editContact.h"
#include "ui_editContact.h"

editContact::editContact(AddressBook *holder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editContact)
{
    ab = holder;
    ui->setupUi(this);
    query = new QSqlQuery;

    QRegExp rx_s("^[a-zA-Zа-яА-Я0-9_]*$");
    QValidator *val_name = new QRegExpValidator(rx_s, this);
    ui->name_edit->setValidator(val_name);
    ui->surname_edit->setValidator(val_name);

    QRegExp rx_n("^[0-9]*$");
    QValidator *val_phone= new QRegExpValidator(rx_n, this);
    ui->phone_edit->setValidator(val_phone);
}

editContact::~editContact()
{
    delete ui;
    delete query;
}

void editContact::editContactWindow(QString name,
                                   QString surname,
                                   QString phone,
                                   QString email,
                                   QString adress,
                                   QString note)
{
    ui->name_edit->setText(name);
    ui->surname_edit->setText(surname);
    ui->phone_edit->setText(phone);
    ui->email_edit->setText(email);
    ui->adress_edit->setText(adress);
    ui->note_edit->setText(note);

    old.name = name;
    old.surname = surname;
    old.phone = phone;
    old.mail = email;
    old.adress = adress;
    old.note = note;
}


void editContact::on_editButton_clicked()
{
    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString phone = ui->phone_edit->text();
    QString email = ui->email_edit->text();
    QString adress = ui->adress_edit->toPlainText();
    QString note = ui->note_edit->toPlainText();

    qDebug() << "old: " << old.name << " " << old.surname << " " <<
                old.phone << " " << old.mail << " " <<
                old.adress << " " << old.note;
    qDebug() << "new: " << name << " " << surname << " " <<
                phone << " " << email << " " <<
                adress << " " << note;

    query->prepare("UPDATE userData SET "
                   "contact_name = :nname, "
                   "contact_surname = :nsname, "
                   "contact_phone = :nphone, "
                   "contact_mail = :nmail, "
                   "contact_adress = :nadress, "
                   "contact_note = :nnote, "
                   "contact_photo = :nphoto "
                   "WHERE user_login = :login "
                   "AND contact_name = :oname "
                   "AND contact_surname = :osname;");
    query->bindValue(":nname", name);
    query->bindValue(":nsname", surname);
    query->bindValue(":nphone", phone);
    query->bindValue(":nmail", email);
    query->bindValue(":nadress", adress);
    query->bindValue(":nnote", note);
    query->bindValue(":nphoto", imageData);
    query->bindValue(":login", ab->user.login);
    query->bindValue(":oname", old.name);
    query->bindValue(":osname", old.surname);
    if (!query->exec()) {
        qDebug() << query->lastError();
    }

    ab->getContacts();
    emit editDone(true);
    close();
}

void editContact::on_set_image_clicked()
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

void editContact::closeEvent(QCloseEvent *event)
 {
 emit editDone(true);
 event->accept();
 }
