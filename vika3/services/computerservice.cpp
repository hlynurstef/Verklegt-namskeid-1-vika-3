#include "services/computerservice.h"

ComputerService::ComputerService(){

}

void ComputerService::addComputer(Computer computer){
    data.addToCompTable(computer);       // call to database to add list to database
}

vector<Computer> ComputerService::search(string searchWord, string searchBy, string built, string type, string orderBy, string direction){
    vector<Computer> searchResultsC;
    searchResultsC = data.searchComp(searchWord, searchBy, built, type, orderBy, direction);
    return searchResultsC;
}

vector<Computer> ComputerService::printQuery(string built, string type, string sortBy, string direction){
    tempList2 = data.printQuery(built, type, sortBy, direction);
    return tempList2;
}

bool ComputerService::removeComputer(Computer comp){
    return data.removeComputer(comp);
}

bool ComputerService::computerToTrash(Computer comp){
    return data.computerToTrash(comp);
}

void ComputerService::editComputer(Computer comp){
    data.editComputer(comp);
}

void ComputerService::deleteAllComputers(){
    data.deleteAllComputers();
}

vector<Computer> ComputerService::getList(){
    vector<Computer> list = data.getComputerList();
    return list;
}

vector<Computer> ComputerService::getTrash(){
    vector<Computer> trash = data.getComputerTrash();
    return trash;
}

int ComputerService::getHighestId(){
    int highestId = data.getHighestId();

    return highestId;
}
