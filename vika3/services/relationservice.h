#ifndef RELATIONSERVICE_H
#define RELATIONSERVICE_H
#include "data_layer/relationconnection.h"
#include "data_types/computer.h"
#include "data_types/pioneer.h"
#include "data_types/relation.h"


class RelationService
{
public:
    void addRelations(int pioneerId, int computerId);
        // Sends one pioneer and one computer that should link together to RelationConnection
    vector<Relation> displayRelations();
        // Sends relations from database to interface. Interface then prints out relations
    vector<Relation> relationSearch(string name, string column);
        // Returns vector containing relations to name
    void removePioneerRelation(int pioID);
        // Sends pioneer information to RelationConnection, to remove all relations to that person
private:
    RelationConnection connection;
    Pioneer pio;
    Computer comp;
};

#endif // RELATIONSERVICE_H
