#ifndef RELATION_H
#define RELATION_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Relation
{
public:
    Relation();
        // Default constructor
    Relation(string comp, string pio);
        // Constructor that sets values of private members
    string getCompName();
        // Returns the name of the computer
    string getPioName();
        // Returns the name of the pioneer

private:
    string cName;
    string pName;
};

#endif // RELATION_H
