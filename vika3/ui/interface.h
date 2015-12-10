#ifndef INTERFACE_H
#define INTERFACE_H
#include "data_types/pioneer.h"
#include "data_types/computer.h"
#include "services/pioneerservice.h"
#include "services/computerservice.h"
#include "services/relationservice.h"
#include "services/relationservice.h"
#include "ui/menuscreen.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Interface{
public:
    Interface();
        // Default Constructor
    void userInput();
        // Decides what the program should do, based on the input from user

    // -----------------------------------------------------------
    //                 MENU SCREENS & MESSAGES
    // -----------------------------------------------------------

    void searchPioneer(bool &goToMainMenu);
        // Function that allows user to search for pioneer
    void searchComputer(bool &goToMainMenu);
        // Function that allows user to search for computer
    void searchRelation(bool& goToMainMenu);
        // Function that allows user to search for relations
    void errorMessage();
        // General error message
    bool continueMessage();
        // Asks if user wants to continue
    int menuErrorCheck(int min, int max);
        // Checks if input is correct. If not, displays an error message
    void searchResults(string str);
        // Display of search result
    void notFound();
        // Prints out a message that says "No search results were found"

    // -----------------------------------------------------------
    //                    PRINT FUNCTIONS
    // -----------------------------------------------------------

    void printListOfPioneers(vector<Pioneer>& list);
        // Prints list of pioneers
    void printListOfComputers(vector<Computer>& list);
        // Prints list of computers
    void printListOfRelations(vector<Relation>& list);
        // Prints list of relations
    void print();
        // Sends user to correct print function
    void pioneerPrintChoice();
        // Gets input from user how to print list of pioneers and prints it out
    void computerPrintChoice();
        // Gets input from user how to print list of computers and prints it out
    void printRelations();
        // Prints relations between pioneer and computer
    void getPioFilterInput(char& f, char& m, char& d, char& a, int input);
        // Gets input from user from filter menu and sets parameters as 'X' or ' ' depending on what was chosen
    void getCompFilterInput(char& b, char& n, char& m, char& e, char& t, int input);
        // Gets input from user from filter menu and sets parameters as 'X' or ' ' depending on what was chosen
    void twoFilterCheck(char& input, char& other);
        // Checks and makes sure that input and other are never chosen at same time and toggles values if already chosen
    void threeFilterCheck(char& input, char& filterTwo, char& filterThree);
        // Checks and makes sure that input, filterTwo and filterThree are never chosen at same time and toggles values if already chosen
    void getSortSqlCommand(string &orderBy, int input, string type);
        // Returns correct string to be used in SQL command in Connection class based on user input
    void getPioFilterSqlCommand(char& f, char& m, char& d, char& a, string& sex, string& dead);
        // Returns correct string to be used in SQL command in Connection class based on user input
    void getCompFilterSqlCommand(char& b, char& n, char& m, char& e, char& t, string& built, string& type);
        // Returns correct string to be used in SQL command in Connection class based on user input
    void getDirectionSqlCommand(string& direction, int input);
        // Returns correct string to be used in SQL command in Connection class based on user input

    // -----------------------------------------------------------
    //                    SEARCH FUNCTIONS
    // -----------------------------------------------------------

    void search();
        // Function that starts search

    // -----------------------------------------------------------
    //                    ADD FUNCTIONS
    // -----------------------------------------------------------

    void addCompOrPio();
        // Add a pioneer or a computer to the list ?
    void addPioneer();
        // Gets input from user about a new pioneer to add to database
    void addComputer();
        // Gets input from user about a new computer to add to database

    // -----------------------------------------------------------
    //                    DELETE FUNCTIONS
    // -----------------------------------------------------------

    void deleteThings();
        // Delete menu, chooses where to delete from
    void deletePio();
        // Deletes either a single pioneer or all pioneers
    void deleteComp();
        // Deletes either a single computer or all computers

    // -----------------------------------------------------------
    //                      GET FUNCTIONS
    // -----------------------------------------------------------

    string getSex(string sex);
        // Gets input from user with error check and returns result
    int getYear();
        // Gets input from user with error check and returns result
    void getRelation(char numb);
        // ...
    string getDescription(string desc);
        // Gets description from user and returns the result
    string wasBuilt(int buildYear);
        // Gets if the computer was built or not
    void printList();
        // Prints list from SQL database

    void linkCtoP();
        // Links computer to pioneer
    void linkPioCheck(vector<Pioneer>& result, Pioneer& relationPio);
        // Checks size of vector and lets user pick Pioneer if vector is > 1
    void linkCompCheck(vector<Computer>& result, Computer& relationComp, Pioneer relationPio);
        // Checks size of vector and lets user pick Computer if vector is > 1
private:
    PioneerService pioService;
    ComputerService compService;
    RelationService relService;
    Pioneer pioTemp;
    Computer compTemp;
    MenuScreen menu;
};

#endif // INTERFACE_H
