#ifndef DIALOGADDABONENT_H
#define DIALOGADDABONENT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>

#include <database.h>
namespace Ui {
class DialogAddAbonent;
}

class DialogAddAbonent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddAbonent(int row = -1, QWidget *parent = 0);
    ~DialogAddAbonent();
private slots:
    void on_buttonBox_accepted();
signals:
    void signalReady();
private:
    Ui::DialogAddAbonent         *ui;
    QSqlTableModel              *model;
    QDataWidgetMapper           *mapper;
private:
    void setupModel();

};

#endif // DIALOGADDABONENT_H
