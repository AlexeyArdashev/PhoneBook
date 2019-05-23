#include "dialogaddabonent.h"
#include "ui_dialogaddabonent.h"

DialogAddAbonent::DialogAddAbonent(int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAbonent)
{
    ui->setupUi(this); //(указывается родитель чтобы объект автоматически удалился)
    setupModel();
    ui->phoneEdit->setInputMask("+99999999999");
    /* Если строка не задана, то есть равна -1,
     * тогда диалог работает по принципу создания новой записи.
     * А именно, в модель вставляется новая строка и работа ведётся с ней.
     * */
    if(row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
       mapper->toLast();
    /* В противном случае диалог настраивается на заданную запись
     * */
    } else {
        mapper->setCurrentModelIndex(model->index(row,0));
    }
}

DialogAddAbonent::~DialogAddAbonent()
{
    delete ui;
    delete model;
    delete mapper;
}

void DialogAddAbonent::setupModel()
{
    /* Инициализируем модель и делаем выборку из неё
     * */
    model = new QSqlTableModel();
    model->setTable(BOOK);
    model->sort(1,Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    /* Инициализируем mapper и привязываем
     * поля данных к объектам LineEdit
     * */
    mapper = new QDataWidgetMapper();
    mapper->setModel(model); // связать с колонками модели таблевью
    mapper->addMapping(ui->lNameEdit, 1);
    mapper->addMapping(ui->fNameEdit, 2);
    mapper->addMapping(ui->phoneEdit, 3);

    /* Ручное подтверждение изменения данных
     * через mapper
     * */
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
void DialogAddAbonent::on_buttonBox_accepted()
{
       mapper->submit();// изменения попадают в модель (вроде)
       model->submitAll();
       emit signalReady();
       this->close();
   // }
}
//
