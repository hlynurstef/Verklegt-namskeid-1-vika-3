#ifndef PIONEERCONNECTION_H
#define PIONEERCONNECTION_H
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

class PioneerConnection
{
public:
    PioneerConnection();
        // Default constructor, creates connection with SQLite database
    vector<Pioneer> getPioneerList();
        // Returns pioneers vector
    vector<Pioneer> getPioneerTrash();
        // Returns pioneer vector from trash
    Pioneer getPioValuesFromDB(QSqlQuery query);
        //gets the pioneer values and returns them
    void addToPioTable(Pioneer pioneer);
        // Adds list vector to Pioneers table in SQL database
    vector<Pioneer> getPioneerListAsc();
        // Returns pioneers vector but with the name in ascending order
    vector<Pioneer> getPioneerListDesc();
        // Returns pioneers vector but with the name in descending order
    string convertToString(int year);
        // Converts integers to strings
    void removePioneer();
        // Deletes a single pioneer from table
    void deleteAllPioneers();
        // Deletes the entire table
    void editPioneer(Pioneer pio);
        // Edits information already in table
    int getHighestId();
        // Returns highest id in Pioneers table (most recently added entry)

    // ---------------------------------------------------------------------
    //                        PRINT QUERY FUNCTIONS:
    // ---------------------------------------------------------------------

    vector<Pioneer> printQueryPioneers(string sex, string dYear, string orderCol, string order);
        // Gets input from Print menu in interface and returns what the user wants to see printed
    vector<Pioneer> searchPio(string searchWord, string searchBy, string sex, string vitalStatus, string orderBy, string direction);
        // Searches through database for a name of pioneer that matches a search word


    void pioneerToTrash(Pioneer pio);

    void removeSinglePioneer(Pioneer pio);
private:
    vector<Pioneer> pioneers;       // Vector that holds onto all information on runtime
    Pioneer temp;
    QSqlQuery query;                // Object used to send query to SQLite database
};


#endif // PIONEERCONNECTION_H
