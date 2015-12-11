#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "data_types/computer.h"
#include "data_layer/computerconnection.h"
//#include "ui/interface.h"
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
    void addComputers(Computer comp, int count);
    vector<Computer> search(string str, int input);
    vector<Computer> printQuery(string built, string type, string sortBy, string direction);
        // Gets query results from user and sends to ComputerConnection that returns vector corresponding to query from user
    void deleteSingleComp(string name);
        // Sends a name of the computer to delete into ComputerConnection
    void deleteAllComputers();
        // Sends a message to ComputerConnection to delete all computers
    vector<Computer> getList();
        // Returns entire list of computers
    bool removeComputer(Computer comp);
private:
    Computer temp;                      // Temporary object to be used in various situations
    vector<Computer> tempList2;
    ComputerConnection data;
};

#endif // COMPUTERSERVICE_H
