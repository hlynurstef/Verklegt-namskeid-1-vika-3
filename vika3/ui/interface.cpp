#include "ui/interface.h"
#include "utilities/constants.h"

const int MINYEAR = 0;
const int MAXYEAR = 2015;

Interface::Interface(){

}

void Interface::userInput(){
    int input;
    //menu.asciiArt();

    do{
        menu.startingMessage();

        input = menuErrorCheck(0, 5);

        switch(input){
            case 1:
                // Print MENU:
                print();
                break;
            case 2:
                // Add MENU:
                menu.addByMessage();
                // Choose if you're going to add
                // pioneer or computer.
                addCompOrPio();
                break;
            case 3:
                // Search MENU:
                menu.searchMenu();
                search();
                break;
            case 4:
                //Link computer to pioneer
                linkCtoP();
                break;
            case 5:
                //Deletes either rows or tables
                deleteThings();
                break;
            case 0:
                // Quit
                break;
        }
    }while(input != 0);
     menu.goodBye();
}

void Interface::printList(){
    int input;
    cin >> input;
    if(input == 1){
        vector<Pioneer> list;
        list = pioService.getList();
        for(unsigned int i = 0; i < list.size(); i++){
            pioTemp = list[i];
            cout << pioTemp;
            cout << endl;
        }
    }
}

/* See interface.h file for comments on changes to be made on
 * these print functions
 */
void Interface::printListOfPioneers(vector<Pioneer>& list){
    system("CLS");
    cout << string(3, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       *~ LIST OF PIONEERS ~*        " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl << endl;

    for (unsigned int i = 0; i < list.size(); i++){
        pioTemp = list[i];
        cout << pioTemp;
        cout << endl;
    }
    cout << string(LEFT_MARGIN, ' ') << "Press enter key to continue . . . ";
    cin.sync();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::printListOfComputers(vector<Computer>& list){
    system("CLS");
    cout << string(3, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       *~ LIST OF COMPUTERS ~*       " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl << endl;

    for (unsigned int i = 0; i < list.size(); i++){
        compTemp = list[i];
        cout << compTemp;
        cout << endl;
    }
    cout << string(LEFT_MARGIN, ' ') << "Press enter key to continue . . . ";
    cin.sync();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::printListOfRelations(vector<Relation>& list){
    system("CLS");
    cout << string(3, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       *~ LIST OF RELATIONS ~*       " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl << endl;
    Relation instance;
    for(unsigned int i = 0; i < list.size(); i++){
        instance = list[i];
        cout << instance;
        cout << endl;
    }
    cout << string(LEFT_MARGIN, ' ') << "Press enter key to continue . . . ";
    cin.sync();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//--------------------------------------------------------------------
//                          ADD TO LIST
//--------------------------------------------------------------------

void Interface::addCompOrPio(){
    int input;
    cin >> input;

    if (input == 1){
        addPioneer();
    }
    else if (input == 2){
        addComputer();
    }
    else if (input == 0){
        return;
    }
    else {
        errorMessage();
        addCompOrPio();
    }
}

void Interface::addPioneer(){

    vector<Pioneer> list;
    string name, description, sex, relation;
    int bYear, dYear, count = 0;

    cout << endl;
    do{
        system("CLS");
        cout << string(3, '\n');
        // If count = 1, the information already inside vector is cleared
        count++;

        // Get name
        cout << string(LEFT_MARGIN, ' ') << "Enter name: ";
        cin.ignore();
        getline(cin, name);


        // Get sex
        sex = getSex(sex);

        // Get birth year
        cout << string(LEFT_MARGIN, ' ') << "Enter birth year: ";
        bYear = getYear();

        // Get death year
        cout << string(LEFT_MARGIN, ' ') << "Enter year of death (0 if not applicable): ";
        dYear = getYear();

        // Get description
        description = getDescription(description);


        cout << endl;

        cout << string(LEFT_MARGIN, ' ') << "Are you sure you want to add" << endl;
        cout << string(LEFT_MARGIN, ' ') << name << " to the list? (y/n): ";

        if(continueMessage()){
            Pioneer tempAddPio(name, sex, bYear, dYear, description);
            pioService.addPioneers(tempAddPio, count);
            cout << string(LEFT_MARGIN, ' ') << name << " has been added to the list!" << endl;
        }

        cout << endl;
        cout << string(LEFT_MARGIN, ' ') << "Do you want to add another Pioneer? (y/n): ";

        // function call to service with a single pioneer


    }while(continueMessage());

    cout << endl;
}


void Interface::addComputer(){

    vector<Computer> list;
    string name, type, description,was_built;
    int buildYear;
    int count = 0;

        cout << endl;
        do{
            system("CLS");
            cout << string(3, '\n');
            count++;
            cout << string(LEFT_MARGIN, ' ') << "Enter computer name: ";
            cin.ignore();
            getline(cin, name);

            //Get type
            cout << string(LEFT_MARGIN, ' ') << "Enter computer type: ";
            getline(cin, type);

            //Get build year
            cout << string(LEFT_MARGIN, ' ') << "Enter a build year (0 if not built): ";
            buildYear = getYear();

            //Was it built or not
            was_built = wasBuilt(buildYear);

            //Get description
            description = getDescription(description);


            cout << endl;

            cout << string(LEFT_MARGIN, ' ') << "Are you sure you want to add" << endl;
            cout << string(LEFT_MARGIN, ' ') << name << " to the list? (y/n): ";

            if(continueMessage()){
                Computer tempAddComp(name, buildYear, type, was_built, description);
                // function call to service with a single pioneer
                compService.addComputers(tempAddComp, count);
                cout << string(LEFT_MARGIN, ' ') << name << " has been added to the list!" << endl;
            }
            cout << endl;
            cout << string(LEFT_MARGIN, ' ') << "Do you want to add another computer? (y/n): ";
        }while(continueMessage());

    cout << endl;
}


//-------------------------------------------------------------------
//                    The following functions are a
//             part of the addPioneer()/computer() functions.
//-------------------------------------------------------------------

string Interface::getSex(string sex){
    cout << string(LEFT_MARGIN, ' ') << "Enter sex: ";
    cin >> sex;
    while(sex != "male" && sex != "Male" && sex != "female" && sex != "Female"){
        cout << string(LEFT_MARGIN, ' ') << "Wrong input! Try again: ";
        cin >> sex;
    }

    return sex;
}

int Interface::getYear(){
    int year;
    cin >> year;
    while(year < MINYEAR || year > MAXYEAR || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << string(LEFT_MARGIN, ' ') << "Wrong input! Try again: ";
        cin >> year;
    }

    return year;
}

string Interface::getDescription(string desc){
    cout << string(LEFT_MARGIN, ' ') << "Enter a short description: ";
    cin.ignore();
    getline(cin, desc, '\n');
    return desc;
}

string Interface::wasBuilt(int buildYear){
    string wasbuilt = constants::TRUE;

    if(buildYear == 0){
        wasbuilt = constants::FALSE;
    }
    return wasbuilt;
}

//---------------------------------------------------------------------
//           End of addPioneer() and addComputer assisting functions
//---------------------------------------------------------------------

void Interface::search(){
    int input = menuErrorCheck(0, 3);
    char answer;
    bool goToMainMenu = false;
    do{
        if(input == 1){
            // Search pioneer
            searchPioneer(goToMainMenu);
        }
        else if(input == 2){
            // Search computer
            searchComputer(goToMainMenu);
        }
        else if(input == 3){
            // Search relations
            searchRelation(goToMainMenu);
        }
        else if(input == 0){
            // back to main menu
            break;
        }
        if(goToMainMenu){
            return;
        }
        cout << endl;
        cout << string(LEFT_MARGIN, ' ') << "Do you want to search again? (y/n) ";
        cin >> answer;
        while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << string(LEFT_MARGIN, ' ') << "Wrong input! Try again: ";
            cin.get(answer);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(answer == 'y' || answer == 'Y');
}

void Interface::searchComputer(bool& goToMainMenu){
    menu.searchComputerMenu();
    int input = menuErrorCheck(0, 4);

    vector<Computer> results2;
    Computer tempComp;
    string word;

    system("CLS");
    cout << string(3, '\n');

    if(input == 1){
        cout << string(LEFT_MARGIN, ' ') << "Enter a name to search for: ";
    }
    else if(input == 2){
        cout << string(LEFT_MARGIN, ' ') << "Enter a year of build to search for: ";
    }
    else if(input == 3){
        cout << string(LEFT_MARGIN, ' ') << "Enter a part of a description to search for:" << endl;
        cout << string(LEFT_MARGIN, ' ');
    }
    else if(input == 0){
        goToMainMenu = true;
        return;
    }

    cin.ignore();
    getline(cin, word);

    results2 = compService.search(word, input);

    if(results2.size() == 0){
        notFound();
        return;
    }

    searchResults(word);

    for(unsigned int i = 0; i < results2.size(); i++){
        tempComp = results2[i];
        cout << tempComp;
        cout << endl;
    }
}

void Interface::searchPioneer(bool& goToMainMenu){
    menu.searchPioneerMenu();
    int input = menuErrorCheck(0, 5);

    vector<Pioneer> results;
    Pioneer tempPio;
    string word;

    system("CLS");
    cout << string(3, '\n');

    if(input == 1){
        cout << string(LEFT_MARGIN, ' ') << "Enter a name to search for: ";
    }
    else if(input == 2){
        cout << string(LEFT_MARGIN, ' ') << "Enter a birth year to search for: ";
    }
    else if(input == 3){
        cout << string(LEFT_MARGIN, ' ') << "Enter a death year to search for: ";
    }
    else if(input == 4){
        cout << string(LEFT_MARGIN, ' ') << "Enter a part of a description to search for:" << endl;
        cout << string(LEFT_MARGIN, ' ');
    }
    else if(input == 0){
        goToMainMenu = true;
        return;
    }

    cin.ignore();
    getline(cin, word);

    results = pioService.search(word, input);

    if(results.size() == 0){
        notFound();
        return;
    }

    searchResults(word);

    for(unsigned int i = 0; i < results.size(); i++){
        tempPio = results[i];
        cout << tempPio;
        cout << endl;
    }
}

void Interface::searchRelation(bool& goToMainMenu){
    menu.searchRelationMenu();
    int input = menuErrorCheck(0, 2);

    vector<Relation> results;
    Relation tempRelation;
    string word, column;

    system("CLS");
    cout << string(3, '\n');

    if(input == 1){
        cout << string(LEFT_MARGIN, ' ') << "Enter name of Pioneer to search for: ";
        column = constants::REL_PIO_NAME;
    }
    else if(input == 2){
        cout << string(LEFT_MARGIN, ' ') << "Enter name of Computer to search for: ";
        column = constants::REL_COMP_NAME;
    }
    else if(input == 0){
        goToMainMenu = true;
        return;
    }

    cin.ignore();
    getline(cin, word);

    results = relService.relationSearch(word, column);

    if(results.size() == 0){
        notFound();
        return;
    }
    searchResults(word);

    for(unsigned int i = 0; i < results.size(); i++){
        tempRelation = results[i];
        cout << tempRelation;
        cout << endl;
    }
}
// -----------------------------------------------------------
//                  END OF SEARCH FUNCTIONS
// -----------------------------------------------------------

void Interface::linkCtoP(){
    string searchPio, searchComp;
    vector<Pioneer> resultPio;
    Pioneer tempPio, relationPio;
    vector<Computer> resultComp;
    Computer tempComp, relationComp;

    system("CLS");
    cout << string(3, '\n');
    cout << string(LEFT_MARGIN, ' ') << "Enter a Pioneer and a Computer you" << endl;
    cout << string(LEFT_MARGIN, ' ') << "would like to link together. . ." << endl;
    cout << string(LEFT_MARGIN, ' ') << "Pioneer: ";
    cin.ignore();
    getline(cin, searchPio);
    cout << string(LEFT_MARGIN, ' ') << "Computer: ";
    getline(cin, searchComp);

    resultPio = pioService.search(searchPio, 1);
    resultComp = compService.search(searchComp, 1);
    // 1 because we would like to search only by name

    if(resultPio.size() != 0  && resultComp.size() != 0){
        linkPioCheck(resultPio, relationPio);           //hvorugur er 0, þarf að velja eða tékka
        linkCompCheck(resultComp, relationComp, relationPio);
        system("CLS");
        cout << string(3, '\n');
        relService.addRelations(relationPio, relationComp);
        cout << string(LEFT_MARGIN, ' ') << relationPio.getName() << " has been linked" << endl;
        cout << string(LEFT_MARGIN, ' ') << "with " << relationComp.getComputerName() << "!" << endl << endl;
        cout << string(LEFT_MARGIN, ' ') << "Press enter key to continue . . . ";
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        cout << string(LEFT_MARGIN, ' ') << "Search yielded no results." << endl;
        cout << string(LEFT_MARGIN, ' ') << "Press enter key to continue . . . ";
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}

void Interface::linkPioCheck(vector<Pioneer>& result, Pioneer& relationPio){
    Pioneer tempPio;
    int counter = 1, number;

    system("CLS");
    cout << string(3, '\n');
    if(result.size() > 1){
        // Printing out the search results for Pioneer if the result was more than one Pioneer
        for(unsigned int i = 0; i < result.size(); i++){
            tempPio = result[i];
            cout << "(" << counter << ")" << endl;
            cout << tempPio;
            cout << endl;
            counter++;
        }
        cout << endl;
        cout << string(LEFT_MARGIN, ' ') << "Please select the number of Pioneer" << endl;
        cout << string(LEFT_MARGIN, ' ') << "you wish to link to the Computer. . ." << endl;
        cout << string(LEFT_MARGIN, ' ');
        number = menuErrorCheck(1, result.size()+1);

        for(unsigned int i = 0; i < result.size(); i++){
            if(i+1 == static_cast<unsigned int>(number)){
                relationPio = result[i];
                break;
            }
        }
    }               // If there was only one search result
    else if(result.size() == 1){
        relationPio = result[0];
    }
}

void Interface::linkCompCheck(vector<Computer>& result, Computer& relationComp, Pioneer relationPio){
    Computer tempComp;
    int counter = 1, number;

    system("CLS");
    cout << string(3, '\n');
    if(result.size() > 1){
        for(unsigned int i = 0; i < result.size(); i++){
            tempComp = result[i];
            cout << "(" << counter << ")" << endl;
            cout << tempComp;
            cout << endl;
            counter++;
        }
        cout << endl;
        cout << string(LEFT_MARGIN, ' ') << "Please select the number of Computer" << endl;
        cout << string(LEFT_MARGIN, ' ') << "you wish to link to " << relationPio.getName() << ": ";
        number = menuErrorCheck(1, result.size()+1);
        cout << endl;

        for(unsigned int i = 0; i < result.size(); i++){
            if(i+1 == static_cast<unsigned int>(number)){
                relationComp = result[i];
                break;
            }
        }
    }
    else if(result.size() == 1){
        relationComp = result[0];
    }
}
// -----------------------------------------------------------
//                  START OF PRINT FUNCTIONS
// -----------------------------------------------------------

void Interface::print(){
    menu.printListMenu();
    int input = menuErrorCheck(0, 3);
    cout << endl;

    switch(input){
    case 1:
        // pioneers
        pioneerPrintChoice();
        break;
    case 2:
        // computers
        computerPrintChoice();
        break;
    case 3:
        // relations
        printRelations();
        break;
    case 0:
        break;
    }
}

void Interface::pioneerPrintChoice(){
    int input;
    char f = ' ', m = ' ', d = ' ', a = ' ';
    string sex, dead, sortBy, direction;

    do{
        // filter by female/male/dead/alive
        menu.filterByPioneerMessage(f, m, d, a);
        input = menuErrorCheck(0, 4);
        cout << endl;
        getPioFilterInput(f, m, d, a, input);

    }while(input != 0);
    getPioFilterSqlCommand(f, m, d, a, sex, dead);

    // sort by name/yob/yod
    menu.sortPioneersMessage();
    input = menuErrorCheck(0, 3);
    getSortSqlCommand(sortBy, input, constants::PIONEER);

    if(input == 0){
        // return to main menu
        return;
    }
    else{
        // sort ascending / descending
        menu.sortDirectionMessage();
        input = menuErrorCheck(0, 2);
        if(input == 0){
            // return to main menu
            return;
        }
    }
    getDirectionSqlCommand(direction, input);

    vector<Pioneer> list = pioService.printQuery(sex, dead, sortBy, direction);
    printListOfPioneers(list);
}

void Interface::computerPrintChoice(){
    int input;
    char b = ' ', n = ' ', m = ' ', e = ' ', t = ' ';
    string built, type, sortBy, direction;

    do{
        // filter by was built/not built/mechanical/electronic/transistor
        menu.filterByComputerMessage(b, n, m, e, t);
        input = menuErrorCheck(0, 5);
        cout << endl;
        getCompFilterInput(b, n, m, e, t, input);

    }while(input != 0);
    //Convert user choice into correct strings to be used in SQL query
    getCompFilterSqlCommand(b, n, m, e , t, built, type);

    // sort by name/yob/yod
    menu.sortComputersMessage();
    input = menuErrorCheck(0, 3);
    getSortSqlCommand(sortBy, input, constants::COMPUTER);

    if(input == 0){
        // return to main menu
        return;
    }
    else{
        // sort ascending / descending
        menu.sortDirectionMessage();
        input = menuErrorCheck(0, 2);
        if(input == 0){
            // return to main menu
            return;
        }
    }
    getDirectionSqlCommand(direction, input);

    vector<Computer> list = compService.printQuery(built, type, sortBy, direction);
    printListOfComputers(list);
}

void Interface::printRelations(){
    vector<Relation> list;
    list = relService.displayRelations();

    printListOfRelations(list);
}

void Interface::getPioFilterInput(char& f, char& m, char& d, char& a, int input){
    switch(input){
    case 1:
        twoFilterCheck(f, m);
        break;
    case 2:
        twoFilterCheck(m, f);
        break;
    case 3:
        twoFilterCheck(d, a);
        break;
    case 4:
        twoFilterCheck(a, d);
        break;
    case 0:
        break;
    }
}

void Interface::twoFilterCheck(char& input, char& other){
    // Only one can be chosen at any given time, either input or other but not both at the same time

    if(input == constants::X){      // If input had already been chosen, remove choice
        input = ' ';
    }
    else if(other == constants::X){ // If other was chosen already, then remove that choice and choose input instead
        other = ' ';
        input = constants::X;
    }
    else{
        input = constants::X;
    }
}

void Interface::threeFilterCheck(char& input, char& filterTwo, char& filterThree){
    // Only one can be chosen at any given time, either input or other but not both at the same time

    if(input == constants::X){      // If input had already been chosen, remove choice
        input = ' ';
    }
    else if(input != constants::X && (filterTwo == constants::X || filterThree == constants::X)){ // If filterTwo or filterThree was chosen already, then remove that choice and choose input instead
        filterTwo = ' ';
        filterThree = ' ';
        input = constants::X;
    }
    else{
        input = constants::X;
    }
}

void Interface::getCompFilterInput(char& b, char& n, char& m, char& e, char& t, int input){
    switch(input){
    case 1:
        twoFilterCheck(b, n);
        break;
    case 2:
        twoFilterCheck(n, b);
        break;
    case 3:
        threeFilterCheck(m, t, e);
        break;
    case 4:
        threeFilterCheck(e, m, t);
        break;
    case 5:
        threeFilterCheck(t, e, m);
        break;
    case 0:
        break;
    }
}

void Interface::getSortSqlCommand(string& orderBy, int input, string type){
    switch(input){
    case 1:
        if(type == constants::PIONEER){
            orderBy = constants::NAME;
        }
        else if(type == constants::COMPUTER){
            orderBy = constants::COMP_NAME;
        }
        break;
    case 2:
        if(type == constants::PIONEER){
            orderBy = constants::BIRTH_YEAR;
        }
        else if(type == constants::COMPUTER){
            orderBy = constants::COMP_TYPE;
        }
        break;
    case 3:
        if(type == constants::PIONEER){
            orderBy = constants::DEATH_YEAR;
        }
        else if(type == constants::COMPUTER){
            orderBy = constants::BUILD_YEAR;
        }
        break;
    case 0:
        // return to main menu
        break;
    }
    return;
}

void Interface::getCompFilterSqlCommand(char& b, char& n, char& m, char& e, char& t, string& built, string& type){
    if(b == constants::X){
        built = constants::TRUE;
    }
    else if(n == constants::X){
        built = constants::FALSE;
    }

    if(m == constants::X){
        type = constants::MECHANICAL;
    }
    else if(e == constants::X){
        type = constants::ELECTRONIC;
    }
    else if(t == constants::X){
        type = constants::TRANSISTOR;
    }
}

void Interface::getPioFilterSqlCommand(char& f, char& m, char& d, char& a, string& sex, string& dead){
    if(f == constants::X){
        sex = constants::FEMALE;
    }
    else if(m == constants::X){
        sex = constants::MALE;
    }

    if(d == constants::X){
        dead = constants::IS_NOT_NULL;
    }
    else if(a == constants::X){
        dead = constants::IS_NULL;
    }
}

void Interface::getDirectionSqlCommand(string& direction, int input){
    switch(input){
    case 1:
        direction = constants::ASC;
        break;
    case 2:
        direction = constants::DESC;
        break;
    case 0:
        break;
    }
    return;
}

// -----------------------------------------------------------
//                  END OF PRINT FUNCTIONS
// -----------------------------------------------------------

// -----------------------------------------------------------
//                    DELETE FUNCTIONS
// -----------------------------------------------------------

void Interface::deleteThings(){
    menu.deleteMessage();
    int input;
    input = menuErrorCheck(0, 2);

    switch(input){
        case 1:
            // Delete from Pioneer table
            deletePio();
            break;
        case 2:
            // Delete from Computer table
            deleteComp();
            break;
        case 0:
            // Quit
            break;
    }
}

void Interface::deletePio(){
    menu.deletePioMessage();
    int input;
    string name;
    char answer;
    input = menuErrorCheck(0, 2);

    switch(input){
        case 1:
            cout << "Please input the full name of the pioneer you want to delete: ";
            cin >> name;
            //pioService.deleteSinglePio(name);
            cout << "Pioneer has been deleted." << endl;
            cout << string(LEFT_MARGIN, ' ') << "Press enter to continue . . . ";
            cin.sync();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            cout << "Are you sure you want to delete all pioneers? " << endl;
            cout << "Once you delete, the data is gone forever. (y/n)" << endl;
            cin >> answer;
            while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << string(LEFT_MARGIN, ' ') << "Wrong input! Try again: ";
                cin.get(answer);
            }
            if(answer == 'y' || answer == 'Y'){
                pioService.deleteAllPioneers();
                cout << "All pioneers have been deleted. " << endl;
            }
            else{
                cout << "No pioneers have been deleted." << endl;
            }
            cout << string(LEFT_MARGIN, ' ') << "Press enter to continue . . . ";
            cin.sync();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 0:
            break;
    }

}

void Interface::deleteComp(){
    menu.deleteCompMessage();
    int input;
    string name;
    char answer;
    input = menuErrorCheck(0, 2);

    switch(input){
        case 1:
            cout << "Please input the name of the computer you want to delete: ";
            cin >> name;
            compService.deleteSingleComp(name);
            cout << "Computer has been deleted." << endl;
            cout << string(LEFT_MARGIN, ' ') << "Press enter to continue . . . ";
            cin.sync();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            cout << "Are you sure you want to delete all computers? " << endl;
            cout << "Once you delete, the data is gone forever. (y/n)" << endl;
            cin >> answer;
            while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << string(LEFT_MARGIN, ' ') << "Wrong input! Try again: ";
                cin.get(answer);
            }
            if(answer == 'y' || answer == 'Y'){
                compService.deleteAllComputers();
                cout << "All computers have been deleted. " << endl;
            }
            else{
                cout << "No computers have been deleted." << endl;
            }
            cout << string(LEFT_MARGIN, ' ') << "Press enter to continue . . . ";
            cin.sync();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 0:
            break;
    }
}

//------------------------------------------------------------
//                      ERROR MESSAGES
//------------------------------------------------------------
void Interface::errorMessage(){
    cout << string(LEFT_MARGIN, ' ') << "Incorrect input, try again: ";
}

bool Interface::continueMessage(){
    char input;

    while(true){
        cin >> input;
        if(input == 'y' || input == 'Y'){
            return true;
        }
        else if(input == 'n' || input == 'N'){
            return false;
        }
        else{
            errorMessage();
        }
    }
}

int Interface::menuErrorCheck(int min, int max){
    int input;
    cin >> input;
    while(input < min || input > max || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << string(LEFT_MARGIN, ' ') << " Wrong input!" << endl;
        cout << string(LEFT_MARGIN, ' ') << " Choose menu item: ";
        cin >> input;
    }
    return input;
}

void Interface::searchResults(string str){
    int num = (32 - str.size());
    system("CLS");
    cout << string(3, '\n');
    cout << string(12, ' ') << TL_CORNER << string(55, H_LINE) << TR_CORNER << endl;
    cout << string(12, ' ') << V_LINE << " Search Results for: \"" << str << "\"" << string(num, ' ') << V_LINE << endl;
    cout << string(12, ' ') << BL_CORNER << string(55, H_LINE) << BR_CORNER << endl << endl;
}

void Interface::notFound(){
    system("CLS");
    cout << string(3, '\n');
    cout << string(LEFT_MARGIN, ' ') << TL_CORNER << string(37, H_LINE) << TR_CORNER << endl;
    cout << string(LEFT_MARGIN, ' ') << V_LINE << "       No search results found!      " << V_LINE << endl;
    cout << string(LEFT_MARGIN, ' ') << BL_CORNER << string(37, H_LINE) << BR_CORNER << endl << endl;
}
