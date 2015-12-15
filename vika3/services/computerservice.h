#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "data_layer/computerconnection.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <ctype.h>
#include <algorithm>

class ComputerService
{
public:
    ComputerService();
    void addComputer(Computer computer);
    vector<Computer> search(string searchWord, string searchBy, string built, string type, string orderBy, string direction);
    vector<Computer> printQuery(string built, string type, string sortBy, string direction);
        // Gets query results from user and sends to ComputerConnection that returns vector corresponding to query from user
    void deleteSingleComp(string name);
        // Sends a name of the computer to delete into ComputerConnection
    void deleteAllComputers();
        // Sends a message to ComputerConnection to delete all computers
    vector<Computer> getList();
        // Returns entire list of computers
    vector<Computer> getTrash();
        // Return list of computers in the trash
    bool removeComputer(Computer comp);
    void editComputer(Computer pio);
        // Sends information about a pioneer that needs to be edited
    int getHighestId();
        // Returns highest id in Pioneers table (most recently added entry)

    void computerToTrash(Computer comp);
private:
    Computer temp;                      // Temporary object to be used in various situations
    vector<Computer> tempList2;
    ComputerConnection data;
};

#endif // COMPUTERSERVICE_H
