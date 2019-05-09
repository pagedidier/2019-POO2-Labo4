//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_PERSON_H
#define INC_2019_POO2_LABO4_PERSON_H

#include <string>

class Person{
    std::string name;

public:
    virtual bool canDrive() =0;
};

#endif //INC_2019_POO2_LABO4_PERSON_H
