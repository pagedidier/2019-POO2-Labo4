/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Person.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration et implémentation de la class Person
 -----------------------------------------------------------------------------------
*/
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
    /**
     * Constructeur
     * @param name nom de la personne
     */
    Person(const std::string &name) : name(name) {

    }
    /**
     * Personne qui doit être surchargé dans les enfant
     * @return
     */
    virtual bool canDrive() const =0;

    /**
     * @return retoune le nom de la personne
     */
    const std::string& getName() const {
        return name;
    }

private:

    std::string name;

};

#endif //INC_2019_POO2_LABO4_PERSON_H
