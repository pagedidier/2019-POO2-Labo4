//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_FATHER_H
#define INC_2019_POO2_LABO4_FATHER_H

#include "Person.h"

class Father : public Person{
public:
    Father(const std::string &name) : Person(name) {}

    bool canDrive() override {
        return true;
    }
};

#endif //INC_2019_POO2_LABO4_FATHER_H
