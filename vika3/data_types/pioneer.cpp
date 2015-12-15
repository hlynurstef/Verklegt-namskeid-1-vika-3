#include "data_types/pioneer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

Pioneer::Pioneer(){

}

Pioneer::Pioneer(string pName, string s, int birthY, int deathY, string desc/*, QByteArray image*/){
    id = NULL;
    name = pName;
    sex = s;
    bYear = birthY;
    dYear = deathY;
    description = desc;
    //imageByteArray = image;
}

Pioneer::Pioneer(int index, string pName, string s, int birthY, int deathY, string desc/*, QByteArray image*/){
    id = index;
    name = pName;
    sex = s;
    bYear = birthY;
    dYear = deathY;
    description = desc;
    //imageByteArray = image;
}

int Pioneer::getId(){
    return id;
}

string Pioneer::getName(){
    return name;
}

string Pioneer::getSex(){
    return sex;
}

int Pioneer::getByear(){
    return bYear;
}

int Pioneer::getDyear(){
    return dYear;
}

string Pioneer::getDescription(){
    return description;
}


ostream& operator <<(ostream& out, Pioneer temp){
    out << "Name: " << temp.getName() << endl;
    out << "Sex: " << temp.getSex() << endl;
    out << "Year of birth: " << temp.getByear() << endl;
    if(temp.getDyear() == 0){
        out << "Year of death: N/A" << endl;
    }
    else{
        out << "Year of death: " << temp.getDyear() << endl;
    }
    out << "Description: " << temp.getDescription() << endl;
    return out;
}

int Pioneer::getYear(int number){

    if (number == 3){
        return getByear();
    }
    else if(number == 4){
        return getDyear();
    }
    return -1;
}

