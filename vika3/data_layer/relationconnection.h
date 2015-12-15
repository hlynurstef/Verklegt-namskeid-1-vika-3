#ifndef RELATIONCONNECTION_H
#define RELATIONCONNECTION_H
#include "data_types/relation.h"
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>


class RelationConnection
{
public:
    RelationConnection();
    void addToRelTable(int pioID, int compID);
        // Links one computer and one pioneer together
    vector<Relation> getRelationList();
        // Returns the whole list from database
    Relation getRelValuesFromDB(QSqlQuery query3);
        // Returns one Relation from database
    vector<Relation> relationQuery(string name, string column);
        // Returns vector of relation where name can be found
private:
    QSqlQuery query3;                // Object used to send query to SQLite database
    vector<Relation> relation;
};

#endif // RELATIONCONNECTION_H
