#include "services/computerservice.h"

ComputerService::ComputerService()
{

}


void ComputerService::addComputers(Computer comp, int count){
    if(count == 1){
        tempList2.clear();
    }

    tempList2.push_back(comp);

    data.addToCompTable(tempList2);       // call to database to add list to database
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

void ComputerService::deleteAllComputers(){
    data.deleteAllComputers();
}

vector<Computer> ComputerService::getList()
{
    vector<Computer> list = data.getComputerList();
    return list;
}
