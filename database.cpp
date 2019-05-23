#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(DATABASE_NAME).exists()){ // бд находится в текущем каталоге с файлами проета
        restoreDataBase();
    } else {
        openDataBase();
    }
}
/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createDeviceTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}
/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     *
соединение с базой данных (2 уровень М.Шлее) */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME); // имя компьютера на кот размещена бд
    db.setDatabaseName( DATABASE_NAME); // имя БД
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы устройств в базе данных
 * */
bool DataBase::createDeviceTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    // QSqlQuery используетя для выполнения комманд sql после установления соединения
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " BOOK " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            BOOK_LNAME       " VARCHAR(50)   ,"
                            BOOK_FNAME       " VARCHAR(50)   ,"
                            BOOK_PHONE       " VARCHAR(20)    "
                        " )"
                    )){


        qDebug() << "DataBase: error of create " << BOOK;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

