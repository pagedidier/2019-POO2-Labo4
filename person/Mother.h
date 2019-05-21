//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_MOTHER_H
#define INC_2019_POO2_LABO4_MOTHER_H

#include "Person.h"

class Mother : public Person{
public:
    Mother(const std::string &name) : Person(name) {}

    bool canDrive() override {
        return true;
    }
};

#endif //INC_2019_POO2_LABO4_MOTHER_H
