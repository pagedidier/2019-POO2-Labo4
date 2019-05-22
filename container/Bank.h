/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Bank.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration de la class Bank
 -----------------------------------------------------------------------------------
*/


#ifndef INC_2019_POO2_LABO4_BANK_H
#define INC_2019_POO2_LABO4_BANK_H


#include "Container.h"

/**
 * Classe modélisant une barge
 */
class Bank : public Container {

    friend std::ostream&operator<<(std::ostream& os,const Bank& bank){
        os << "----------------------------------------------------------" <<std::endl;
        os << ((Container) bank).getName() << ": ";
        os << ((Container) bank) <<std::endl;
        os << "----------------------------------------------------------";
        return os;
    }

public:
    Bank(const std::string &name) : Container(name) {

    }
};


#endif //INC_2019_POO2_LABO4_BANK_H
