#ifndef PIONEER_H
#define PIONEER_H

#include <iostream>
#include <string>
#include <vector>

#include <QtSql>
#include <QtWidgets>

using namespace std;

class Pioneer
{
public:

    Pioneer();                                                                       //Default constructor
    Pioneer(string pName, string s, int birthY, int deathY, string desc, QByteArray image);              // Constructor without id
    Pioneer(int index, string pName, string s, int bYear, int dYear, string desc, QByteArray image);   // Constructor

    int getId();                           //Returns ID of pioneer
    string getName ();                     // Returns name of pioneer
    string getSex ();                      // Returns sex of pioneer
    int getByear ();                       // Returns birth year of pioneer
    int getDyear ();                       // Returns year of death of pioneer
    string getDescription ();              // Returns description of pioneer
    int getYear(int number);               // Returns year of birth if number == 1 / Returns year of death if number == 2
    QByteArray getImageByteArray();        // Returns binary array of pioneer's image

    friend ostream& operator <<(ostream& out, Pioneer temp);

    /*void printPioneers();                // Prints information about pioneer
    */

private:
    int id;                    // Primary Key of pioneer
    string name;               // Last Name of pioneer
    string sex;                // Sex  of poineer
    int bYear;                 // Birthyear of pioneer
    int dYear;                 // Deathyear of pioneer
    string description;        // Description of what the person is famous for
    QByteArray imageByteArray; //Image of pioneer
};

#endif // PIONEER_H
