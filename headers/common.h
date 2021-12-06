#ifndef COMMON_H
#define COMMON_H

#include <QDialog>
#include <QCompleter>
#include <QMessageBox>
#include <QMainWindow>

namespace common {

extern QString SEP;

void openDialog(QDialog *dialog, const QString &stylesheetPath);

void showMsgBox(const QString &title, const QString &text,
                const QString &stylesheetPath, const QMessageBox::Icon &msgIcon, const QString &winIcon);

void openWindow(QMainWindow *window, const QString &stylesheetPath);

QString openSheet(const QString &sheetUrl);

QCompleter *dirCompleter(QWidget *parent);

} // Namespace common
#endif // COMMON_H
