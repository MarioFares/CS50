#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void refreshComboBox(QComboBox *comboBox);

    void refreshFolders();

    void refreshAuthors();

    void refreshGenres();

    void refreshSearches();

    double changeBookSizeUnit(double size, const QString &unit);

    void showContextMenu(const QPoint&);

    void trayClicked(QSystemTrayIcon::ActivationReason r);

    void deleteListItem();

    void openFolder();

    void on_buttonAddBooks_clicked();

    void on_buttonSearchString_clicked();

    void on_buttonClearCriteria_clicked();

    void on_buttonDetailsClear_clicked();

    void on_buttonSortSearch_clicked();

    void on_actionResetEbooks_triggered();

    void changeWidgetVisibility(QWidget *widget, QAction *action);

    void on_actionHideSearchBar_triggered();

    void on_actionHideDetailsSection_triggered();

    void on_buttonAddBook_clicked();

    void on_buttonClearSearch_clicked();

    void on_buttonSearchCriteria_clicked();

    void on_ebooksListWidget_itemClicked(QListWidgetItem *item);

    void on_buttonDetailsRestore_clicked();

    void on_buttonDetailsUpdate_clicked();

    void on_buttonSaveCriteria_clicked();

    void on_buttonSearchLoad_clicked();

    void on_actionCleanEbooks_triggered();

    void on_ebooksListWidget_itemSelectionChanged();

    void on_actionFullscreen_triggered();

    void on_ebooksListWidget_itemActivated(QListWidgetItem *item);

    void on_buttonSizeCriteria_clicked();

    void on_actionHideRightFrame_triggered();

    void on_actionHideUtilities_triggered();

    void on_actionHideLeftFrame_triggered();

    void extSelectionSetup(const QString &title, const QString &prompt, QWidget *widget);

    void on_buttonExtensions_clicked();

    void on_buttonFolder_clicked();

    void on_buttonAuthor_clicked();

    void on_buttonGenre_clicked();

    void on_buttonTags_clicked();

    void on_buttonSizeUnit_clicked();

    void on_actionMinimizeTray_triggered();

    void on_actionResetTags_triggered();

    void on_actionResetSearches_triggered();

    void on_actionResetDatabase_triggered();

    void on_actionWindowTop_triggered();

private:
    Ui::MainWindow *ui;
    Qt::SortOrder SORT;
    QHash<QString, quint32> sizeConvFactors;
    QHash<QString, QString> sizeUnits;
};
#endif // MAINWINDOW_H
