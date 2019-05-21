//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_SON_H
#define INC_2019_POO2_LABO4_SON_H


#include "Person.h"

class Son : public Person {

public:
    Son(const std::string &name) : Person(name) {
    }

    bool canDrive() override {
        return false;
    }
};


#endif //INC_2019_POO2_LABO4_SON_H
