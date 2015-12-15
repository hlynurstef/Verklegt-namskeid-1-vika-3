#include "pioneerconnection.h"
#include "utilities/constants.h"
#include <cstdlib>
#include <limits>
#include <QDebug>
#include <QMessageBox>

const QString connectionName = "name1";

PioneerConnection::PioneerConnection(){

    QSqlDatabase db;
    QString dbN = "computer_science_db.sqlite";

    if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName(dbN);

            db.open();
        }

    query = QSqlQuery(db);

}

vector<Pioneer> PioneerConnection::getPioneerList(){
    // Read all information from pioneers table
    query.exec("SELECT * FROM Pioneers WHERE deleted = 'false' ");

    while(query.next()){
        Pioneer P = getPioValuesFromDB(query);
        pioneers.push_back(P);
    }
    return pioneers;
}

vector<Pioneer> PioneerConnection::getPioneerTrash(){
    // Read all information from pioneers trash
    query.exec("SELECT * FROM Pioneers WHERE deleted = 'true' ");

    vector<Pioneer> pioneerTrash;

    while(query.next()){
        Pioneer P = getPioValuesFromDB(query);
        pioneerTrash.push_back(P);
    }
    return pioneerTrash;
}

Pioneer PioneerConnection::getPioValuesFromDB(QSqlQuery query){

        //gets the pioneer values from database
    int id = query.value("id").toUInt();
    string name = query.value("name").toString().toStdString();
    string sex = query.value("sex").toString().toStdString();
    int birthYear = query.value("bYear").toUInt();
    int deathYear = query.value("dYear").toUInt();
    string description = query.value("description").toString().toStdString();
    //QByteArray outByteArray = query.value("image").toByteArray();

    Pioneer tempo(id, name, sex, birthYear, deathYear, description/*, outByteArray*/);
    return tempo;
}

void PioneerConnection::addToPioTable(Pioneer pioneer){

    string name = pioneer.getName();
    string sex = pioneer.getSex();
    int bYear = pioneer.getByear();
    int dYear = pioneer.getDyear();
    string desc = pioneer.getDescription();
    string deleted = "false";
    QByteArray image = pioneer.getImageByteArray();

    transform(sex.begin(), sex.end(), sex.begin(), ::tolower);

    query.prepare("INSERT INTO pioneers VALUES(NULL, :tempName, :tempSex, :tempBYear, :tempDYear, :tempDesc, :tempImage, :tempDeleted)");
    query.bindValue(":tempName", QString::fromStdString(name));
    query.bindValue(":tempSex", QString::fromStdString(sex));
    query.bindValue(":tempBYear", QString::number(bYear));
    if(dYear == 0){
        query.bindValue(":tempDYear", QVariant(QVariant::String));
    }
    else{
        query.bindValue(":tempDYear", QString::number(dYear));
    }
    query.bindValue(":tempDesc", QString::fromStdString(desc));
    query.bindValue(":tempDeleted", QString::fromStdString(deleted));   // Deleted
    if(image.isEmpty()){
        query.bindValue(":tempImage", QVariant(QVariant::String));
    }
    else{
        query.bindValue(":tempImage", image);       // Image BLOB value (set to NULL for now)
    }

    query.exec();

}

vector<Pioneer> PioneerConnection::getPioneerListAsc(){

    // Read all information from pioneers table and adds them to a vector in ascending order
    query.exec("SELECT * FROM Pioneers ORDER BY first_name ASC");

    while(query.next()){
        Pioneer P = getPioValuesFromDB(query);
        pioneers.push_back(P);
    }
    return pioneers;
}

vector<Pioneer> PioneerConnection::getPioneerListDesc(){

    // Read all information from pioneers table and adds them to a vector in descending order
    query.exec("SELECT * FROM Pioneers ORDER BY first_name DESC");

    while(query.next()){
        Pioneer P = getPioValuesFromDB(query);
        pioneers.push_back(P);
    }
    return pioneers;
}

// ---------------------------------------------------------------------
//                      ~ PRINT QUERY FUNCTIONS START ~
// ---------------------------------------------------------------------

vector<Pioneer> PioneerConnection::printQueryPioneers(string sex, string dYear, string orderCol, string order){

    // sex can be: "male" or "female"
    // dYear can be: "IS NULL" or "IS NOT NULL"
    // orderCol can be: "name", "bYear", "dYear"

    vector<Pioneer> list;

    if(sex == "" && dYear == ""){			// If user doesn't choose any filters / wants entire list
        query.prepare(QString("SELECT * FROM Pioneers WHERE deleted = 'false' ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(sex != "" && dYear == ""){		// If user chooses to filter only by sex
        query.prepare(QString("SELECT * FROM Pioneers WHERE deleted = 'false' AND sex = :sex ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(sex == "" && dYear != ""){		// If user chooses to filter only by alive/deceased
        query.prepare(QString("SELECT * FROM Pioneers WHERE deleted = 'false' AND dYear " + QString::fromStdString(dYear) + " ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if (sex != "" && dYear != ""){		// If user chooses to filter by both sex and alive/deceased
        query.prepare(QString("SELECT * FROM Pioneers WHERE deleted = 'false' AND sex = :sex AND dYear " + QString::fromStdString(dYear) + " ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    query.bindValue(":sex",QString::fromStdString(sex));

    query.exec();

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string sex = query.value("sex").toString().toStdString();
        int birthYear = query.value("bYear").toUInt();
        int deathYear = query.value("dYear").toUInt();
        string description = query.value("description").toString().toStdString();
        QByteArray image = query.value("image").toByteArray();

        list.push_back(Pioneer(id, name, sex, birthYear, deathYear, description /*image*/));
    }

    return list;
}


// ---------------------------------------------------------------------
//                      ~ PRINT QUERY FUNCTIONS END ~
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
//                            SEARCH FUNCTIONS
// ---------------------------------------------------------------------
vector<Pioneer> PioneerConnection::searchPio(string searchWord, string searchBy, string sex, string vitalStatus, string orderBy, string direction){
    vector<Pioneer> searchTemp;

    if(sex == "" && vitalStatus == ""){			// If user doesn't choose any filters / wants entire list
            query.prepare(QString("SELECT * FROM pioneers WHERE deleted = 'false' AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(sex != "" && vitalStatus == ""){		// If user chooses to filter only by sex
        query.prepare(QString("SELECT * FROM pioneers WHERE deleted = 'false' AND sex = :sex AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(sex == "" && vitalStatus != ""){		// If user chooses to filter only by alive/deceased
        query.prepare(QString("SELECT * FROM pioneers WHERE deleted = 'false'  AND dYear " + QString::fromStdString(vitalStatus) + " AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if (sex != "" && vitalStatus != ""){		// If user chooses to filter by both sex and alive/deceased
        query.prepare(QString("SELECT * FROM pioneers WHERE deleted = 'false' AND sex = :sex AND dYear " + QString::fromStdString(vitalStatus) + " AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }

    query.bindValue(":word", QString::fromStdString(searchWord));
    query.bindValue(":sex", QString::fromStdString(sex));
    query.exec();

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string sex = query.value("sex").toString().toStdString();
        int birthYear = query.value("bYear").toUInt();
        int deathYear = query.value("dYear").toUInt();
        string description = query.value("description").toString().toStdString();
        QByteArray image = query.value("image").toByteArray();

        searchTemp.push_back(Pioneer(id, name, sex, birthYear, deathYear, description/*, image*/));
    }
    return searchTemp;
}

// ---------------------------------------------------------------------
//                         SEARCH FUNCTIONS END
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
//                           DELETE FUNCTIONS
// ---------------------------------------------------------------------
void PioneerConnection::removePioneer(){

    query.prepare("DELETE FROM Pioneers WHERE deleted = 'true'");
    query.exec();
}

void PioneerConnection::deleteAllPioneers(){
    query.exec("DELETE FROM pioneers");
}
// ---------------------------------------------------------------------
//                          DELETE FUNCTIONS END
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
//                             EDIT FUNCTIONS
// ---------------------------------------------------------------------

void PioneerConnection::pioneerToTrash(Pioneer pio){

    int id = pio.getId();
    string name = pio.getName();
    string sex = pio.getSex();
    int bYear = pio.getByear();
    int dYear = pio.getDyear();
    string desc = pio.getDescription();
    string deleted = "true";

    string bYearString = to_string(bYear);
    string dYearString = to_string(dYear);
    string idString = to_string(id);

    QString editId = QString::fromStdString(idString);
    QString editName = QString::fromStdString(name);
    QString editSex = QString::fromStdString(sex);
    QString editByear = QString::fromStdString(bYearString);
    QString editDyear = QString::fromStdString(dYearString);
    QString editDesc = QString::fromStdString(desc);
    QString editDeleted = QString::fromStdString(deleted);

    query.prepare("UPDATE pioneers SET id = "+ editId +", name = '"+ editName +"', sex = '"+ editSex +"', bYear = "+ editByear +", dYear = "+ editDyear +", description = '"+ editDesc+"', deleted = '"+ editDeleted+"' WHERE id = "+ editId +"");
    query.exec();
}

void PioneerConnection::editPioneer(Pioneer pio){

    int id = pio.getId();
    string name = pio.getName();
    string sex = pio.getSex();
    int bYear = pio.getByear();
    int dYear = pio.getDyear();
    string desc = pio.getDescription();
    string deleted = "false";
    QByteArray image = pio.getImageByteArray();

    string bYearString = to_string(bYear);
    string dYearString = to_string(dYear);
    string idString = to_string(id);

    QString editId = QString::fromStdString(idString);
    QString editName = QString::fromStdString(name);
    QString editSex = QString::fromStdString(sex);
    QString editByear = QString::fromStdString(bYearString);
    QString editDyear = QString::fromStdString(dYearString);
    QString editDesc = QString::fromStdString(desc);
    QString editDeleted = QString::fromStdString(deleted);

    query.prepare("UPDATE pioneers SET id = "+ editId +", name = '"+ editName +"', sex = '"+ editSex +"', bYear = "+ editByear +", dYear = "+ editDyear +", description = '"+ editDesc+"', deleted = '"+ editDeleted+"' WHERE id = "+ editId +"");
    query.exec();

}

int PioneerConnection::getHighestId(){
    query.exec("SELECT MAX(id) FROM Pioneers");
    int highestId;

    while(query.next()){
        highestId = query.value("MAX(id)").toUInt();
    }
    return highestId;
}
