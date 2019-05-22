/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Boat.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration de la class Boat
 -----------------------------------------------------------------------------------
*/

#ifndef INC_2019_POO2_LABO4_BOAT_H
#define INC_2019_POO2_LABO4_BOAT_H


#include <ostream>
#include "Bank.h"

/**
 * Classe modélisant un bateau
 */
class Boat : public Container {

    friend std::ostream&operator<<(std::ostream& os,const Boat& boat){
        os << ((Container) boat).getName() << ": ";
        os << "< " << ((Container) boat) << ">";
        return os;
    }

public:
    Boat(const int MAXPASSENGER, Bank* current): MAXPASSENGER(MAXPASSENGER),current(current),Container("Boat"){

    }

    /**
     * Fonction qui set la berge au bateau pour le faire "bouger"
     * @param newBank vers que'elle berge aller
     */
    void setBank(Bank* newBank){
        current = newBank;
    }

    /**
     * @return un pointeur sur la berge
     */
    Bank* getBank(){
        return current;
    }

    /**
     * Test si le bateau peut être déplacer
     * Il peut être déplacé si au moin un passager peut conduire
     * @return true si il peut être déplacé
     */
    bool hasDriver() {
        for(const Person* p : getPersons()){
            if(p->canDrive())
                return true;
        }
        return false;
    }

    /**
     * @return le nombre de place maximum
     */
    size_t getMaxPassenger() {
        return MAXPASSENGER;
    }

private:

    const int MAXPASSENGER;
    Bank* current;
};


#endif //INC_2019_POO2_LABO4_BOAT_H
