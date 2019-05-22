//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_DAUGHTER_H
#define INC_2019_POO2_LABO4_DAUGHTER_H


#include "Person.h"
#include "../container/Group.h"

class Daughter : public Person {

public:
    Daughter(const std::string &name) : Person(name) {
    }

    bool canDrive() override {
        return false;
    }
};


#endif //INC_2019_POO2_LABO4_SON_H
