#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <database.h>
#include "dialogaddabonent.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_addAbonent();
    void on_Row(QModelIndex index); // просто присваивает rowNumber номер строки в таблице
    void slotUpdateModels(); //
    void on_removeAbonent();
    void slotEditRecord(QModelIndex index); // ркдактирование записи
    void on_findAbonent();
    void on_Reset(); // сброс фильтра

private:
    Ui::MainWindow *ui;
    DataBase                    *db;
    QSqlTableModel              *model;
    int rowNumber;  // записывается индекс выделенной строки

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // MAINWINDOW_H
