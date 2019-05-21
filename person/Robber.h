//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_ROBBER_H
#define INC_2019_POO2_LABO4_ROBBER_H


#include "Person.h"

class Robber : public Person {
public:
    Robber(const std::string &name) : Person(name) {}

    bool canDrive() override {
        return false;
    }
};


#endif //INC_2019_POO2_LABO4_ROBBER_H
