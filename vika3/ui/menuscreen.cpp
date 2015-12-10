#include "menuscreen.h"
#include "utilities/constants.h"

using namespace std;

void MenuScreen::asciiArt(){
    // Looks kinda funky because backslashes are escape characters
    // so I had to add another backslash where there already was one

    // CSci = Computer Scientist
    cout << string(LEFT_MARGIN, ' ') << "    _________   _________      .__ " << endl;
    cout << string(LEFT_MARGIN, ' ') << "    \\_   ___ \\ /   _____/ ____ |__|" << endl;
    cout << string(LEFT_MARGIN, ' ') << "    /    \\  \\/ \\_____  \\_/ ___\\|  |" << endl;
    cout << string(LEFT_MARGIN, ' ') << "    \\     \\____/        \\  \\___|  |" << endl;
    cout << string(LEFT_MARGIN, ' ') << "     \\______  /_______  /\\___  >__|" << endl;
    cout << string(LEFT_MARGIN, ' ') << "            \\/        \\/     \\/    " << endl;
    cout << string(LEFT_MARGIN, ' ') << "             WELCOME TO THE" << endl;
    cout << string(LEFT_MARGIN, ' ') << "-~*^ COMPUTER SCIENTIST LIST PROGRAM! ^*~-" << endl << endl;
}
void MenuScreen::goodBye(){

    system("CLS");
    cout << string(9, '\n');
    cout << string(17, ' ') << TL_CORNER << string(44, H_LINE) << TR_CORNER << endl;
    cout << string(17, ' ') << V_LINE << "  ____                 _ _                _ " << V_LINE << endl;
    cout << string(17, ' ') << V_LINE << " / ___| ___   ___   __| | |__  _   _  ___| |" << V_LINE << endl;
    cout << string(17, ' ') << V_LINE << "| |  _ / _ \\ / _ \\ / _` | '_ \\| | | |/ _ \\ |" << V_LINE << endl;
    cout << string(17, ' ') << V_LINE << "| |_| | (_) | (_) | (_| | |_) | |_| |  __/_|" << V_LINE << endl;
    cout << string(17, ' ') << V_LINE << " \\____|\\___/ \\___/ \\__,_|_.__/ \\__, |\\___(_)" << V_LINE << endl;
    cout << string(17, ' ') << V_LINE << "                               |___/        " << V_LINE << endl;
    cout << string(17, ' ') << BL_CORNER << string(44, H_LINE) << BR_CORNER << endl;
    cout << string(9, '\n');
}
void MenuScreen::startingMessage(){
    system("CLS");

    asciiArt();

    // Testing a new look for the menu windows :D
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "          *~ START MENU ~*           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Print list                      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Add to list                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Search/modify list              " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (4) Link computer and pioneer       " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (5) Delete                          " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Quit                            " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::printListMenu(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "          *~ PRINT LIST ~*           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Print Pioneers                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Print Computers                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Print Relations                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::sortPioneersMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "            *~ SORT BY ~*            " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Sort by name                    " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Sort by year of birth           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Sort by year of death           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::filterByPioneerMessage(char& f, char& m, char& d, char& a){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "          *~ FILTER MENU ~*          " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Female [" << f << "]                      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Male   [" << m << "]                      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Dead   [" << d << "]                      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (4) Alive  [" << a << "]                      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    if(f == ' ' && m == ' ' && d == ' ' && a == ' '){
        cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) No filter                       " << V_LINE << endl;
    }
    else{
        cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Finish filtering                " << V_LINE << endl;
    }
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose filter options: ";
}

void MenuScreen::filterByComputerMessage(char& b, char& n, char& m, char& e, char& t){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "          *~ FILTER MENU ~*          " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Was built     [" << b << "]               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Was not built [" << n << "]               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Mechanical    [" << m << "]               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (4) Electronic    [" << e << "]               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (5) Transistor    [" << t << "]               " << V_LINE << endl;
    if(b == ' ' && n == ' ' && m == ' ' && e == ' ' && t == ' '){
        cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) No filter                       " << V_LINE << endl;
    }
    else{
        cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Finish filtering                " << V_LINE << endl;
    }
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose filter options: ";
}

void MenuScreen::sortDirectionMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       *~ SORTING DIRECTION ~*       " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Sort ascending                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Sort descending                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::sortComputersMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "            *~ SORT BY ~*            " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Sort by name                    " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Sort by type                    " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Sort by year of build           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::searchMenu(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "     *~ SEARCH & MODIFY MENU ~*      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Search Pioneer                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Search Computer                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Search Relation                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::searchPioneerMenu(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "    *~ SEARCH/MODIFY PIONEERS ~*     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Search by name                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Search by year of birth         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Search by year of death         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (4) Search by description           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::searchComputerMenu(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "   *~ SEARCH/MODIFY COMPUTERS ~*     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Search by name                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Search by year of build         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (3) Search by description           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::searchRelationMenu(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "   *~ SEARCH/MODIFY RELATIONS ~*     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Find Computer/s related         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "     to a Pioneer                    " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Find Pioneer/s related          " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "     to a Computer                   " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::addByMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "           *~ ADD MENU ~*            " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Pioneer                         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Computer                        " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::deleteMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "         *~ DELETE MENU ~*           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Delete Pioneer                  " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Delete Computer                 " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}
void MenuScreen::deletePioMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       *~ DELETE PIONEERS ~*         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Delete Single Pioneer           " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Delete All Pioneers             " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}

void MenuScreen::deleteCompMessage(){
    system("CLS");
    cout << string(9, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "      *~ DELETE COMPUTERS ~*         " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << L_JOIN << string(37, H_LINE) << R_JOIN << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (1) Delete Single Computer          " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (2) Delete All Computers            " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "                                     " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << " (0) Back to Main Menu               " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
}
