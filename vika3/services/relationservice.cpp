#include "relationservice.h"

using namespace std;

void RelationService::addRelations(Pioneer pio, Computer comp){
    int pioID, compID;
    pioID = pio.getId();
    compID = comp.getId();

    connection.addToRelTable(compID, pioID);

}

vector<Relation> RelationService::relationSearch(string name, string column){
    vector<Relation> list = connection.relationQuery(name, column);
    return list;
}

vector<Relation> RelationService::displayRelations(){
    vector<Relation> list;
    list = connection.getRelationList();
    return list;
}
