//
// Created by dpage on 16.05.19.
//

#ifndef INC_2019_POO2_LABO4_PARENT_H
#define INC_2019_POO2_LABO4_PARENT_H

#include "Person.h"

class Parent : public Person{

public:
    Parent(const std::string &name);

    virtual bool canDrive(){
        return true;
    }


};


#endif //INC_2019_POO2_LABO4_PARENT_H
