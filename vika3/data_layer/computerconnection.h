#ifndef COMPUTERCONNECTION_H
#define COMPUTERCONNECTION_H
#include "data_types/pioneer.h"
#include "data_types/computer.h"
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

class ComputerConnection
{
public:
    ComputerConnection();

    vector<Computer> getComputerList();
        // Returns pioneers vector
    Computer getCompValuesFromDB(QSqlQuery query2);
        // gets the computer values and returns them
    vector<Computer> getComputerTrash();
        // return pioneer vector from trash
    void addToCompTable(Computer computer);
        // Adds list vector to Computers table in SQL database
    vector<Computer> getComputerListDesc();
        // Returns computers vector but with the name in descending order
    vector<Computer> getComputerListAsc();
        // Returns computers vector but with the name in ascending order
    vector<Computer> printQuery(string built, string type, string orderCol, string order);
        // Gets input from Print menu in interface and returns what the user wants to see printed
    vector<Computer> searchComp(string searchWord, string searchBy, string built, string type, string orderBy, string direction);
        // Searches through database for a name of computer that matches a search word
    void deleteSingleComp(string name);
        // Deletes a single computer from table
    void deleteAllComputers();
        // Deletes the entire table
    void removeComputer();
        // removes one computer from database
    void editComputer(Computer comp);
        // edits information about one computer from database
    int getHighestId();
        // Returns highest id in Computers table (most recently added entry)
    void computerToTrash(Computer comp);
        // swithces the deleted value from false to true
private:
    vector<Computer> computers;     // Vector that holds onto all information on runtime
    Computer compTemp;
    QSqlQuery query2;
};

#endif // COMPUTERCONNECTION_H
