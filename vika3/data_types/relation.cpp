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

ostream& operator <<(ostream& out, Relation temp){
    out << "Name of pioneer: " << temp.getPioName() << endl;
    out << "Name of computer: " << temp.getCompName() << endl;
    return out;
}
