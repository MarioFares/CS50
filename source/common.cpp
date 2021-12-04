#include "headers/common.h"

#include <QFile>
#include <QDialog>
#include <QProcess>
#include <QFileInfo>
#include <QMessageBox>
#include <QMainWindow>
#include <QErrorMessage>
#include <QCompleter>
#include <QAbstractItemView>
#include <QFileSystemModel>

namespace common {

QString SEP = "|";

QString openSheet(const QString &sheetUrl)
{
    QFile file(sheetUrl);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    return styleSheet;
}

void openDialog(QDialog *dialog, const QString &stylesheetPath)
{
    dialog->setStyleSheet(common::openSheet(stylesheetPath));
    dialog->ensurePolished();
    dialog->setFixedSize(dialog->size());
    dialog->exec();
}

void showMsgBox(const QString &title, const QString &text, const QString &stylesheetPath,
                const QMessageBox::Icon &msgIcon, const QString &winIcon)
{
    QMessageBox box;
    box.setText(text);
    box.setWindowTitle(title);
    box.setStyleSheet(common::openSheet(stylesheetPath));
    box.setIcon(msgIcon);
    box.setWindowIcon(QIcon(winIcon));
    box.ensurePolished();
    box.exec();
}

void showErrorMsg(const QString &title, const QString &message, const QString &stylesheetPath)
{
    QErrorMessage msg;
    msg.showMessage(message);
    msg.setWindowTitle(title);
    msg.setStyleSheet(common::openSheet(stylesheetPath));
    msg.ensurePolished();
    msg.exec();
}

void openWindow(QMainWindow *window, const QString &stylesheetPath)
{
    window->setStyleSheet(common::openSheet(stylesheetPath));
    window->ensurePolished();
    window->show();
}

QCompleter *dirCompleter(QWidget *parent)
{
    auto *dirCompleter = new QCompleter(parent);
    dirCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    dirCompleter->setCompletionMode(QCompleter::PopupCompletion);
    QAbstractItemView *popup = dirCompleter->popup();
    popup->setStyleSheet(common::openSheet(":/styles/style.qss"));
    auto *model = new QFileSystemModel(dirCompleter);
    model->setRootPath("/");
    model->sort(0, Qt::DescendingOrder);
    dirCompleter->setModel(model);

    return dirCompleter;
}

} // Namespace common
