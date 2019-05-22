//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_PERSON_H
#define INC_2019_POO2_LABO4_PERSON_H

#include <string>
#include <iostream>

class Person{

    friend std::ostream&operator<<(std::ostream& os,const Person& person){
        os << person.name;
        return os;
    }

public:
    Person(const std::string &name) : name(name) {}
    virtual bool canDrive() =0;

    const std::string& getName() const {
        return name;
    }

public:

private:
    std::string name;

};

#endif //INC_2019_POO2_LABO4_PERSON_H
