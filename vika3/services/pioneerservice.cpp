#include "services/pioneerservice.h"

const int ZERO_BIAS = 2016;

PioneerService::PioneerService(){

}

void PioneerService::addPioneers(Pioneer pio, int count){

    if(count == 1){
        tempList.clear();
    }

    tempList.push_back(pio);

    data.addToPioTable(tempList);       // call to database to add list to database
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

vector<Pioneer> PioneerService::search(string str, int input){
    vector<Pioneer> searchResults;
    searchResults = data.searchPio(str, input);
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
