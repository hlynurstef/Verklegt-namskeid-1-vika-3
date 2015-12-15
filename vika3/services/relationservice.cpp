#include "relationservice.h"

using namespace std;

void RelationService::addRelations(int pioneerId, int computerId){
    connection.addToRelTable(pioneerId, computerId);
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

void RelationService::removePioneerRelation(int pioID){
    connection.removeRelationPioneer(pioID);
}

void RelationService::removeRelation(int pioID, int compID){
    connection.removeRelation(pioID, compID);
}
