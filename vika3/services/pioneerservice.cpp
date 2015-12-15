#include "services/pioneerservice.h"

const int ZERO_BIAS = 2016;

PioneerService::PioneerService(){

}

void PioneerService::addPioneer(Pioneer pioneer){

    data.addToPioTable(pioneer);       // call to database to add pioneer to database
}

string PioneerService::toLower(string name){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    return name;
}

vector<Pioneer> PioneerService::getList(){
    vector<Pioneer> list;
    list = data.getPioneerList();
    return list;
}

vector<Pioneer> PioneerService::getTrash()
{
    vector<Pioneer> trash = data.getPioneerTrash();
    return trash;
}

vector<Pioneer> PioneerService::search(string searchWord, string searchBy, string sex, string vitalStatus, string orderBy, string direction){
    vector<Pioneer> searchResults;
    searchResults = data.searchPio(searchWord, searchBy, sex, vitalStatus, orderBy, direction);
    return searchResults;
}

vector<Pioneer> PioneerService::printQuery(string sex, string dYear, string sortBy, string direction){
    tempList = data.printQueryPioneers(sex, dYear, sortBy, direction);
    return tempList;
}

bool PioneerService::removePioneer(Pioneer pio){
    return data.removePioneer(pio);
}

void PioneerService::deleteAllPioneers(){
    data.deleteAllPioneers();
}

void PioneerService::editPioneer(Pioneer pio){
    data.editPioneer(pio);
}

int PioneerService::getHighestId(){
    int highestId = data.getHighestId();

    return highestId;
}
