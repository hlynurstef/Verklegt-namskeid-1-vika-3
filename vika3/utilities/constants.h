#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using namespace std;

/**
 * This file contains constants that this application uses
 */
namespace constants {

    // Following constants are used when asking user how to print the list:

    const std::string MALE = "male";
    const std::string FEMALE = "female";
    const std::string IS_NULL = "IS NULL";
    const std::string IS_NOT_NULL = "IS NOT NULL";
    const std::string DB_TRUE = "true";
    const std::string DB_FALSE = "false";
    const std::string MECHANICAL = "mechanical";
    const std::string ELECTRONIC = "electronic";
    const std::string TRANSISTOR = "transistor";
    const std::string NAME = "name";
    const std::string COMP_NAME = "computer_name";
    const std::string BIRTH_YEAR = "bYear";
    const std::string DEATH_YEAR = "dYear";
    const std::string COMP_TYPE = "computer_type";
    const std::string BUILD_YEAR = "build_year";
    const std::string ASC = "ASC";
    const std::string DESC = "DESC";
    const std::string PIONEER = "pioneer";
    const std::string COMPUTER = "computer";
    const std::string REL_COMP_NAME = "c.computer_name";
    const std::string REL_PIO_NAME = "p.name";
    const char X = 'X';
    const int CURRENT_YEAR = 2015;
}

#endif // CONSTANTS_H
