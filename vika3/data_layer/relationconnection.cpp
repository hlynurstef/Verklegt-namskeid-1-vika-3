#include "relationconnection.h"
#include "utilities/constants.h"

using namespace std;

const QString connectionName = "name3";

RelationConnection::RelationConnection(){

    QSqlDatabase db3;
    QString dbN = "computer_science_db.sqlite";

    if(QSqlDatabase::contains(connectionName))
        {
            db3 = QSqlDatabase::database(connectionName);
        }
        else
        {
            db3 = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db3.setDatabaseName(dbN);

            db3.open();
        }

    query3 = QSqlQuery(db3);
}

void RelationConnection::addToRelTable(int pioID, int compID){
    string IDCompString;
    ostringstream convert;
    convert << compID;
    IDCompString = convert.str();

    string IDPioString;
    ostringstream convert2;
    convert2 << pioID;
    IDPioString = convert2.str();

    query3.prepare("INSERT INTO Relations VALUES(NULL, :tempCompID, :tempPioID)");
    query3.bindValue(":tempCompID", QString::fromStdString(IDCompString));
    query3.bindValue(":tempPioID", QString::fromStdString(IDPioString));
    query3.exec();
}

vector<Relation> RelationConnection::getRelationList(){
    // Read all information from Relations table
    query3.exec("SELECT c.computer_name, p.name FROM relations r join pioneers p on p.id = r.pioneer_id join computers c on c.id = r.computer_id WHERE p.deleted = 'false' AND c.deleted = 'false' ");

    while(query3.next()){
        Relation R = getRelValuesFromDB(query3);
        relation.push_back(R);
    }
    return relation;
}

Relation RelationConnection::getRelValuesFromDB(QSqlQuery query3){

        //gets the Relation values from database
    string pioName = query3.value("name").toString().toStdString();
    string compName = query3.value("computer_name").toString().toStdString();
    Relation tempo(compName, pioName);
    return tempo;
}

vector<Relation> RelationConnection::relationQuery(string name, string column){
    vector<Relation> list;
    if(column == constants::REL_COMP_NAME){
        query3.prepare("SELECT c.computer_name, p.name FROM relations r join pioneers p on p.id = r.pioneer_id join computers c on c.id = r.computer_id WHERE p.deleted = 'false' AND c.deleted = 'false' AND c.computer_name LIKE '%'||:word||'%';");
    }
    else if(column == constants::REL_PIO_NAME){
        query3.prepare("SELECT c.computer_name, p.name FROM relations r join pioneers p on p.id = r.pioneer_id join computers c on c.id = r.computer_id WHERE p.deleted = 'false' AND c.deleted = 'false' AND p.name LIKE '%'||:word||'%';");
    }
    query3.bindValue(":word",QString::fromStdString(name));

    query3.exec();
    while(query3.next()){

        string compName = query3.value("computer_name").toString().toStdString();
        string pioName = query3.value("name").toString().toStdString();

        list.push_back(Relation(compName, pioName));
    }
    return list;
}


void RelationConnection::removeRelationPioneer(int pioID){

    query3.prepare("DELETE FROM relations WHERE pioneer_id = " + pioID );
    query3.exec();

    relation.clear();
}
