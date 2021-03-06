#include "headers/addbookdialog.h"
#include "ui_addbookdialog.h"

#include "headers/queries.h"
#include "headers/common.h"

#include <QFileDialog>

addBookDialog::addBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBookDialog)
{
    ui->setupUi(this);
    ui->textPath->setCompleter(common::dirCompleter(this));
}

addBookDialog::~addBookDialog()
{
    delete ui;
}

void addBookDialog::on_buttonCancel_clicked()
{
    close();
}

void addBookDialog::on_buttonClear_clicked()
{
    ui->textName->clear();
    ui->textFolder->clear();
    ui->textAuthor->clear();
    ui->textGenre->clear();
    ui->textTags->clear();
    ui->textSize->clear();
    ui->textExtension->clear();
    ui->textPath->clear();
    ui->textPages->clear();
}

void addBookDialog::on_buttonBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), "/", tr("All Files (*.*)"));

    QFileInfo file(filePath);
    ui->textName->setText(file.completeBaseName());
    ui->textExtension->setText("." + file.suffix());
    ui->textFolder->setText(file.dir().dirName());
    ui->textPath->setText(file.absoluteFilePath());
    // Size returned in bytes
    ui->textSize->setText(QString::number(file.size()));
    ui->textPages->setText(0);
}

void addBookDialog::on_buttonAdd_clicked()
{
    QString name = ui->textName->text();
    QString folder = ui->textFolder->text();
    QString genre = ui->textGenre->text();
    QString path = ui->textPath->text();
    QString author = ui->textAuthor->text();
    quint32 pages = ui->textPages->text().toUInt();
    quint64 size = ui->textSize->text().toULongLong();
    QString ext = ui->textExtension->text();
    QString tags = ui->textTags->text();

    QFileInfo file(path);
    if (file.exists() && file.isFile())
    {
        queries::insertBooksQuery(name, path, folder, ext, size,
                                  pages, tags, genre, author);
        common::showMsgBox("Success!", "Ebook successfully added.",
                           ":/styles/style.qss", QMessageBox::Information,
                           ":/icons/books_icon.png");
    }
    else
    {
        common::showMsgBox("Path Error!", "File path not valid!", ":/styles/style.qss", QMessageBox::Warning, ":/icons/books_icon.png");
    }
}

