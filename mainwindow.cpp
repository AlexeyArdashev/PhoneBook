#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rowNumber=-1;
    this->setWindowTitle("Телефонный справочник");
    /* Первым делом необходимо создать объект для работы с базой данных
     * и инициализировать подключение к базе данных
     * */
    db = new DataBase();
    db->connectToDataBase();

    /* Инициализируем модели для представления данных
     * с заданием названий колонок
     * */
    setupModel(BOOK,
                     QStringList()  <<trUtf8("id")
                                    << trUtf8("Фамилия")
                                         << trUtf8("Имя")
                                         << trUtf8("Телефон")

               );
    /* Инициализируем внешний вид таблицы с данными
     * */
    createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete db;
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * */
    model = new QSqlTableModel();
    model->setTable(tableName); // устанавливаем актуальную базу в модели
    model->sort(1,Qt::AscendingOrder);
    model->select(); // заполение данными
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    int count=model->columnCount();
    for(int i = 0, j = 0; i <count ; i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }


}

void MainWindow::createUI()
{

    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
  //  ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

     connect(ui->removeData, SIGNAL(clicked()), this, SLOT(on_removeAbonent()));
     this->close();
}

void MainWindow::slotUpdateModels(){

   model->sort(1,Qt::AscendingOrder);
   model->select();


}
void MainWindow::on_addAbonent(){

    DialogAddAbonent addAbonentDialog;// = new DialogAddAbonent(this);
    connect(&addAbonentDialog, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));
    addAbonentDialog.setWindowTitle(trUtf8("Добавить абонента"));
    addAbonentDialog.exec();
}

void MainWindow::on_Row(QModelIndex index){
   rowNumber=index.row();
    qDebug()<<rowNumber;
}

void MainWindow::on_removeAbonent(){
    if (rowNumber==-1) return;

    else {
     //   qDebug()<<"буду искать ID=" << rowNumber;

        model->removeRow(rowNumber);
        model->select();


    }
}
void MainWindow::slotEditRecord(QModelIndex index)
{
    /* Также создаем диалог и подключаем его сигнал завершения работы
     * к слоту обновления вида модели представления данных, но передаём
     * в качестве параметров строку записи
     * */
    DialogAddAbonent addAbonentDialog(index.row()); //= new DialogAddAbonent(index.row());
    connect(&addAbonentDialog, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));

    /* Выполняем запуск диалогового окна
     * */
    addAbonentDialog.setWindowTitle(trUtf8("Редактировать абонента"));
    addAbonentDialog.exec();
}
void MainWindow::on_findAbonent(){
   QString str="lname ='";
   str+=ui->findEdit->text();
   str+="'";
  // qDebug()<<str;
   // QString str= ui->findEdit->text();
    model->setFilter(str);
    if (model->rowCount()==0)
       {
        QMessageBox::information(0,"Внимание","Абонент не найден");
        model->setFilter("");
    }
    model->select();
}
void MainWindow::on_Reset(){
    if(ui->findEdit->text()=="") return;
    model->setFilter("");
    ui->findEdit->setText("");
}

