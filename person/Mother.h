/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Mother.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration et implémentation de la class Mother
 -----------------------------------------------------------------------------------
*/

#ifndef INC_2019_POO2_LABO4_MOTHER_H
#define INC_2019_POO2_LABO4_MOTHER_H

#include "Person.h"

/**
 * Classe modélisant une mère
 */
class Mother : public Person{
public:
    Mother(const std::string &name) : Person(name) {}

    /**
    * Surcharge de la fonction can drive
    * @return true si il peut conduire le bateau
    */
    bool canDrive() const override {
        return true;
    }
};

#endif //INC_2019_POO2_LABO4_MOTHER_H
