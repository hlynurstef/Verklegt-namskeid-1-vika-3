#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>

class MenuScreen
{
public:
    void asciiArt();
        // Ascii art, displayed at the top of program
    void goodBye();
        // Good bye message if quiting the program
    void startingMessage();
        // Main menu
    void printListMenu();
        // Menu for printing list
    void filterByPioneerMessage(char &f, char &m, char &d, char &a);
        // Menu for pioneer filter options
    void filterByComputerMessage(char &b, char &n, char &m, char &e, char &t);
        // Menu for computer filter options
    void sortDirectionMessage();
        // Menu for sorting descending or ascending
    void sortPioneersMessage();
        // Menu for sorting pioneers option
    void sortComputersMessage();
        // Menu for sorting computers option
    void searchMenu();
        // Menu for search options
    void searchPioneerMenu();
        // Search for a specific pioneer
    void searchComputerMenu();
        // Search for a specific computer
    void searchRelationMenu();
        // Search for relation to/from computers/pioneers
    void addByMessage();
        // Menu for adding new entries into the database
    void deleteMessage();
        // Menu for choosing where to delete from
    void deletePioMessage();
        // Menu for choosing if you want to delete a single pioneer or all pioneers
    void deleteCompMessage();
        // Menu for choosing if you want to delete a single computer or all computers
};

#endif // MENUSCREEN_H
