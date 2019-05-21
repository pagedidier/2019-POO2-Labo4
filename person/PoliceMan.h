//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_POLICEMAN_H
#define INC_2019_POO2_LABO4_POLICEMAN_H


#include "Person.h"

class PoliceMan : public Person {

public:
    PoliceMan(const std::string &name) : Person(name) {}

    bool canDrive() override;

};

bool PoliceMan::canDrive() {
    return true;
}


#endif //INC_2019_POO2_LABO4_POLICEMAN_H
