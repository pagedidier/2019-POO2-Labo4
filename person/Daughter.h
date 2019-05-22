/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Daughter.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration et implémentation de la class Daughter
 -----------------------------------------------------------------------------------
*/


#ifndef INC_2019_POO2_LABO4_DAUGHTER_H
#define INC_2019_POO2_LABO4_DAUGHTER_H


#include "Person.h"
/**
 * Classe modélisant une fille
 */
class Daughter : public Person {

public:
    Daughter(const std::string &name) : Person(name) {
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
