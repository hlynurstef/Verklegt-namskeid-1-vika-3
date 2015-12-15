#include "pioneerconnection.h"
#include "utilities/constants.h"
#include <cstdlib>
#include <limits>
#include <QDebug>

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
    query.exec("SELECT * FROM Pioneers");

    while(query.next()){
        Pioneer P = getPioValuesFromDB(query);
        pioneers.push_back(P);
    }
    return pioneers;
}

Pioneer PioneerConnection::getPioValuesFromDB(QSqlQuery query){

        //gets the pioneer values from database
    int id = query.value("id").toUInt();
    string name = query.value("name").toString().toStdString();
    string sex = query.value("sex").toString().toStdString();
    int birthYear = query.value("bYear").toUInt();
    int deathYear = query.value("dYear").toUInt();
    string description = query.value("description").toString().toStdString();
    Pioneer tempo(id, name, sex, birthYear, deathYear, description);
    return tempo;
}

void PioneerConnection::addToPioTable(Pioneer pioneer){

    string name = pioneer.getName();
    string sex = pioneer.getSex();
    int bYear = pioneer.getByear();
    int dYear = pioneer.getDyear();
    string desc = pioneer.getDescription();

    query.prepare("INSERT INTO pioneers VALUES(NULL, :tempName, :tempSex, :tempBYear, :tempDYear, :tempDesc)");
    query.bindValue(":tempName", QString::fromStdString(name));
    if(sex == "male" || sex == "Male"){
        query.bindValue(":tempSex", QString::fromStdString(constants::MALE));
    }
    else{
        query.bindValue(":tempSex", QString::fromStdString(constants::FEMALE));
    }

    query.bindValue(":tempBYear", QString::number(bYear));
    if(dYear == 0){
        query.bindValue(":tempDYear", QVariant(QVariant::String));
    }
    else{
        query.bindValue(":tempDYear", QString::number(dYear));
    }
    query.bindValue(":tempDesc", QString::fromStdString(desc));
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
        query.prepare(QString("SELECT * FROM Pioneers ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(sex != "" && dYear == ""){		// If user chooses to filter only by sex
        query.prepare(QString("SELECT * FROM Pioneers WHERE sex = :sex ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(sex == "" && dYear != ""){		// If user chooses to filter only by alive/deceased
        query.prepare(QString("SELECT * FROM Pioneers WHERE dYear " + QString::fromStdString(dYear) + " ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if (sex != "" && dYear != ""){		// If user chooses to filter by both sex and alive/deceased
        query.prepare(QString("SELECT * FROM Pioneers WHERE sex = :sex AND dYear " + QString::fromStdString(dYear) + " ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
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

        list.push_back(Pioneer(id, name, sex, birthYear, deathYear, description));
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
            query.prepare(QString("SELECT * FROM pioneers WHERE " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(sex != "" && vitalStatus == ""){		// If user chooses to filter only by sex
        query.prepare(QString("SELECT * FROM pioneers WHERE sex = :sex AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(sex == "" && vitalStatus != ""){		// If user chooses to filter only by alive/deceased
        query.prepare(QString("SELECT * FROM pioneers WHERE dYear " + QString::fromStdString(vitalStatus) + " AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if (sex != "" && vitalStatus != ""){		// If user chooses to filter by both sex and alive/deceased
        query.prepare(QString("SELECT * FROM pioneers WHERE sex = :sex AND dYear " + QString::fromStdString(vitalStatus) + " AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
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

        searchTemp.push_back(Pioneer(id, name, sex, birthYear, deathYear, description));
    }
    return searchTemp;
}

// ---------------------------------------------------------------------
//                         SEARCH FUNCTIONS END
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
//                           DELETE FUNCTIONS
// ---------------------------------------------------------------------
bool PioneerConnection::removePioneer(Pioneer pio){

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Pioneers WHERE id = " << pio.getId();

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));
    pioneers.clear();

    return success;
}

void PioneerConnection::deleteAllPioneers(){
    query.exec("DELETE FROM pioneers");
}

int PioneerConnection::getHighestId(){
    query.exec("SELECT MAX(id) FROM Pioneers");
    int highestId;

    while(query.next()){
        highestId = query.value("MAX(id)").toUInt();
    }
    return highestId;
}
