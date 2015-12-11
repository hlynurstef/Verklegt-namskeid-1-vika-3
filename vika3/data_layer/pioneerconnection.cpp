#include "pioneerconnection.h"
#include <cstdlib>
#include <limits>

PioneerConnection::PioneerConnection(){

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE", "name1");
    QString dbN = "computer_science_db.sqlite";
    db.setDatabaseName(dbN);
    db.open();
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

void PioneerConnection::addToPioTable(vector<Pioneer>& list){

        // Takes vector of pioneers that should be added to the SQL database
        // and adds them.

    for (unsigned int i = 0; i < list.size(); i++){
        Pioneer tempList = list[i];

        string name = tempList.getName();
        string sex = tempList.getSex();
        int bYear = tempList.getByear();
        int dYear = tempList.getDyear();
        string desc = tempList.getDescription();

        string bYearString;
        ostringstream convert;
        convert << bYear;
        bYearString = convert.str();

        string dYearString;
        ostringstream convert2;
        convert2 << dYear;
        dYearString = convert2.str();

        query.prepare("INSERT INTO pioneers VALUES(NULL, :tempName, :tempSex, :tempBYear, :tempDYear, :tempDesc)");
        query.bindValue(":tempName", QString::fromStdString(name));
        query.bindValue(":tempSex", QString::fromStdString(sex));
        query.bindValue(":tempBYear", QString::fromStdString(bYearString));
        query.bindValue(":tempDYear", QString::fromStdString(dYearString));
        query.bindValue(":tempDesc", QString::fromStdString(desc));
        query.exec();

    }
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
vector<Pioneer> PioneerConnection::searchPio(string searchWord, int input){
    vector<Pioneer> searchTemp;

    if(input == 1){
        // Search by name
        query.prepare(QString("SELECT * FROM pioneers WHERE name LIKE '%'||:word||'%';"));
    }
    else if(input == 2){
        // Search by year of birth
        query.prepare(QString("SELECT * FROM pioneers WHERE bYear LIKE '%'||:word||'%';"));
    }
    else if(input == 3){
        // Search by year of death
        query.prepare(QString("SELECT * FROM pioneers WHERE dYear LIKE '%'||:word||'%';"));
    }
    else if(input == 4){
        // Search by description
        query.prepare(QString("SELECT * FROM pioneers WHERE description LIKE '%'||:word||'%';"));
    }

    query.bindValue(":word", QString::fromStdString(searchWord));
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

    //QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Students WHERE id = " << pio.getId();

    bool success = query.exec(QString::fromStdString(sqlQuery.str()));

    return success;
}

void PioneerConnection::deleteAllPioneers(){
    query.exec("DELETE FROM pioneers");
}
