/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Son.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration et implémentation de la class Son
 -----------------------------------------------------------------------------------
*/

#ifndef INC_2019_POO2_LABO4_SON_H
#define INC_2019_POO2_LABO4_SON_H


#include "Person.h"

/**
 * Classe modélisant un fils
 */
class Son : public Person {

public:
    Son(const std::string &name) : Person(name) {
    }

    /**
     * Surcharge de la fonction can drive
     * @return true si il peut conduire le bateau
     */
    bool canDrive() const override {
        return false;
    }
};


#endif //INC_2019_POO2_LABO4_SON_H
