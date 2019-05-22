//
// Created by dpage on 22.05.19.
//

#ifndef INC_2019_POO2_LABO4_GROUP_H
#define INC_2019_POO2_LABO4_GROUP_H

#include "Container.h"

class Group : public Container {

public:
    Group(const std::string &name, const std::list<Person *> &persons) : Container(name, persons) {

    }

};


#endif //INC_2019_POO2_LABO4_GROUP_H
