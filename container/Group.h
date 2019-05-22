/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Group.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration de la class Group
 -----------------------------------------------------------------------------------
*/

#ifndef INC_2019_POO2_LABO4_GROUP_H
#define INC_2019_POO2_LABO4_GROUP_H

#include "Container.h"

/**
 * Classe modélisant un groupe de personne
 */
class Group {

public:
    Group(const std::string &name, const std::list<const Person *> &persons): persons(persons){

    }

    const std::list<const Person *> &getPersons() const {
        return persons;
    }

    virtual ~Group() {
        while(!persons.empty()){
            delete persons.front();
            persons.pop_front();
        }

    }

private:
    std::list<const Person*> persons;
};


#endif //INC_2019_POO2_LABO4_GROUP_H
