#include "relation.h"

Relation::Relation(){

}

Relation::Relation(string comp, string pio){
    cName = comp;
    pName = pio;
}

string Relation::getCompName(){

    return cName;
}

string Relation::getPioName(){

    return pName;
}
