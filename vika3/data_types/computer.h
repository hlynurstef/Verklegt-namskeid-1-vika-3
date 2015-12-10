#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string inputName, int inputYear, string inputType, string inputBuilt, string inputDes);
    Computer(int index, string inputName, int inputYear, string inputType, string inputBuilt, string inputDes);
        // Constructors that set values of different private members

    int getId();                                  // Returns the Id of computer
    string getComputerName();                     // Returns the computers name
    int getBuildYear ();                          // Returns the computers build year
    string getComputerType();                     // Returns the computers type
    string getWasItBuilt();                       // Returns either y or n depending if it was build or not
    string getComputerDescription ();             // Returns a description on the computer
    void printComputers();                        // Prints information about computer

    friend ostream& operator <<(ostream& out, Computer temp);

private:
    int id;
    string computerName;
    int computerBuildYear;
    string computerType;
    string wasItBuilt;
    string computerDescription;
};

#endif // COMPUTER_H
