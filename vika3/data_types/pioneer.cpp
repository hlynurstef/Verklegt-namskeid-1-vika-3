#include "data_types/pioneer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

Pioneer::Pioneer(){

}

Pioneer::Pioneer(string pName, string s, int birthY, int deathY, string desc, QByteArray image){
    id = 0;
    name = pName;
    sex = s;
    bYear = birthY;
    dYear = deathY;
    description = desc;
    imageByteArray = image;
}

Pioneer::Pioneer(int index, string pName, string s, int birthY, int deathY, string desc, QByteArray image){
    id = index;
    name = pName;
    sex = s;
    bYear = birthY;
    dYear = deathY;
    description = desc;
    imageByteArray = image;
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

QByteArray Pioneer::getImageByteArray(){

    return imageByteArray;
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



