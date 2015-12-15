#include "data_types/computer.h"
#include "utilities/constants.h"

Computer::Computer(){

}

Computer::Computer(string inputName, int inputYear, string inputType, string inputBuilt, string inputDes){
    id = NULL;
    computerName = inputName;
    computerBuildYear = inputYear;
    computerType = inputType;
    wasItBuilt = inputBuilt;
    computerDescription = inputDes;
}

Computer::Computer(int index, string inputName, int inputYear, string inputType, string inputBuilt, string inputDes){
    id = index;
    computerName = inputName;
    computerBuildYear = inputYear;
    computerType = inputType;
    wasItBuilt = inputBuilt;
    computerDescription = inputDes;
}

int Computer::getId(){
    return id;
}

string Computer::getComputerName(){
    return computerName;
}

int Computer::getBuildYear(){
    return computerBuildYear;
}

string Computer::getComputerType(){
    return computerType;
}

string Computer::getWasItBuilt(){
    return wasItBuilt;
}

string Computer::getComputerDescription(){
    return computerDescription;
}

ostream& operator <<(ostream& out, Computer temp){
    out << "Name: " << temp.getComputerName() << endl;

    string built = temp.getWasItBuilt();
    if(built == constants::DB_TRUE){
        out << "Build year: " << temp.getBuildYear() << endl;
    }
    else{
        out << "This computer was not built." << endl;
    }

    out << "Computer Type: " << temp.getComputerType() << endl;
    out << "Description: " << temp.getComputerDescription() << endl;
    return out;
}


