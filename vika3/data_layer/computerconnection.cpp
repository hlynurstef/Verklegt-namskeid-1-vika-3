#include "computerconnection.h"
#include <QDebug>

ComputerConnection::ComputerConnection()
{
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase("QSQLITE", "name2");
    QString dbName = "computer_science_db.sqlite";
    db2.setDatabaseName(dbName);
    db2.open();
    query2 = QSqlQuery(db2);
}

vector<Computer> ComputerConnection::getComputerList(){
    // Read all information from the computers table
    query2.exec("SELECT * FROM Computers");

    while(query2.next()){
        Computer C = getCompValuesFromDB(query2);
        computers.push_back(C);
    }
    return computers;
}

Computer ComputerConnection::getCompValuesFromDB(QSqlQuery query2){

    int id = query2.value("id").toUInt();
    string name = query2.value("computer_name").toString().toStdString();
    int buildYear = query2.value("build_year").toUInt();
    string computerType = query2.value("computer_type").toString().toStdString();
    string wasBuilt = query2.value("was_built").toString().toStdString();
    string description = query2.value("description").toString().toStdString();
    Computer tempo(id, name, buildYear, computerType, wasBuilt, description);
    return tempo;
}

void ComputerConnection::addToCompTable(vector<Computer>& list){

    for (unsigned int i = 0; i < list.size(); i++){
        compTemp = list[i];
        string name = compTemp.getComputerName();
        int buildYear = compTemp.getBuildYear();
        string computerType = compTemp.getComputerType();
        string wasBuilt = compTemp.getWasItBuilt();
        string desc = compTemp.getComputerDescription();

        string buildYearString;
        ostringstream convert;
        convert << buildYear;
        buildYearString = convert.str();

        string id;

        query2.prepare("INSERT INTO computers VALUES(NULL, :tempName, :tempYear, :tempType, :tempWasBuilt, :tempDesc)");
        query2.bindValue("NULL", QString::fromStdString(id));
        query2.bindValue(":tempName", QString::fromStdString(name));
        query2.bindValue(":tempYear", QString::fromStdString(buildYearString));
        query2.bindValue(":tempType", QString::fromStdString(computerType));
        query2.bindValue(":tempWasBuilt", QString::fromStdString(wasBuilt));
        query2.bindValue(":tempDesc", QString::fromStdString(desc));
        query2.exec();

    }
}

vector<Computer> ComputerConnection::getComputerListAsc(){

    // Read all information from the computers table and adds them to vector in ascending order
    query2.exec("SELECT * FROM Computers ORDER by computer_name ASC");

    while(query2.next()){
        Computer C = getCompValuesFromDB(query2);
        computers.push_back(C);
    }
    return computers;
}

vector<Computer> ComputerConnection::getComputerListDesc(){

    // Read all information from the computers table and adds them to vector in descending order
    query2.exec("SELECT * FROM Computers ORDER by computer_name DESC");

    while(query2.next()){
        Computer C = getCompValuesFromDB(query2);
        computers.push_back(C);
    }
    return computers;
}

vector<Computer> ComputerConnection::printQuery(string built, string type, string orderCol, string order){

    // built can be: "true" or "false"
    // type can be: "mechanical" or "electronic" or "transistor"
    // orderCol can be: "computer_name" or "build_year" or "computer_type";

    vector<Computer> list;

    if(built == "" && type == ""){			// If user doesn't choose any filters / wants entire list
        query2.prepare(QString("SELECT * FROM Computers ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(built != "" && type == ""){		// If user chooses to filter only by if the computer was built or not
        query2.prepare(QString("SELECT * FROM Computers WHERE was_built = :built ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if(built == "" && type != ""){		// If user chooses to filter only by computer type
        query2.prepare(QString("SELECT * FROM Computers WHERE computer_type = :type ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    else if (built != "" && type != ""){	// If user chooses to filter by both if computer was built and computer type
        query2.prepare(QString("SELECT * FROM Computers WHERE was_built = :built AND computer_type = :type ORDER BY %1 " + QString::fromStdString(order)).arg(QString::fromStdString(orderCol)));
    }
    query2.bindValue(":built",QString::fromStdString(built));
    query2.bindValue(":type",QString::fromStdString(type));

    query2.exec();

    while(query2.next()){
        int id = query2.value("id").toUInt();
        string name = query2.value("computer_name").toString().toStdString();
        int buildYear = query2.value("build_year").toUInt();
        string computerType = query2.value("computer_type").toString().toStdString();
        string wasBuilt = query2.value("was_built").toString().toStdString();
        string description = query2.value("description").toString().toStdString();

        list.push_back(Computer(id, name, buildYear, computerType, wasBuilt, description));
    }

    return list;
}

vector<Computer> ComputerConnection::searchComp(string searchWord, string searchBy, string built, string type, string orderBy, string direction){
    vector<Computer> searchTempComp;

    if(built == "" && type == ""){                              // If user doesn't choose any filters / wants entire list
            query2.prepare(QString("SELECT * FROM Computers WHERE " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(built != "" && type == ""){                         // If user chooses to filter only by if the computer was built or not
        query2.prepare(QString("SELECT * FROM Computers WHERE was_built = :built AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(built == "" && type != "" && type != "other"){		// If user chooses to filter only by computer type
        query2.prepare(QString("SELECT * FROM Computers WHERE computer_type = :type AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if (built != "" && type != "" && type != "other"){     // If user chooses to filter by both if computer was built and computer type
        query2.prepare(QString("SELECT * FROM Computers WHERE was_built = :built AND computer_type = :type AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(built == "" && type == "other"){
        query2.prepare(QString("SELECT * FROM Computers WHERE computer_type not in (" + QString::fromStdString("'mechanical', ") + QString::fromStdString("'electronic', ") + QString::fromStdString("'transistor'") + ") AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    else if(built != "" && type == "other"){
        query2.prepare(QString("SELECT * FROM Computers WHERE computer_type not in (" + QString::fromStdString("mechanical, ") + QString::fromStdString("electronic") + ") AND was_built = :built AND " + QString::fromStdString(searchBy) + " LIKE '%'||:word||'%' ORDER BY " + QString::fromStdString(orderBy) + " " + QString::fromStdString(direction) + ";"));
    }
    query2.bindValue(":word", QString::fromStdString(searchWord));
    query2.bindValue(":built",QString::fromStdString(built));
    query2.bindValue(":type",QString::fromStdString(type));
    query2.exec();

    while(query2.next()){
        int id = query2.value("id").toUInt();
        string name = query2.value("computer_name").toString().toStdString();
        int buildYear = query2.value("build_year").toUInt();
        string computerType = query2.value("computer_type").toString().toStdString();
        string wasBuilt = query2.value("was_built").toString().toStdString();
        string description = query2.value("description").toString().toStdString();

        searchTempComp.push_back(Computer(id, name, buildYear, computerType, wasBuilt, description));
    }
    return searchTempComp;
}
// ---------------------------------------------------------------------
//                           DELETE FUNCTIONS
// ---------------------------------------------------------------------
void ComputerConnection::deleteSingleComp(string name){
    query2.prepare(QString("DELETE FROM computers WHERE computer_name LIKE '%'||:word||'%';"));
    query2.bindValue(":word", QString::fromStdString(name));
    query2.exec();
}

void ComputerConnection::deleteAllComputers(){
    query2.exec("DELETE FROM computers");
}

