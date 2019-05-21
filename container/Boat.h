//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_BOAT_H
#define INC_2019_POO2_LABO4_BOAT_H


#include <ostream>
#include "Bank.h"

class Boat : public Container {

    friend std::ostream&operator<<(std::ostream& os,const Boat& boat){
        os << ((Container) boat).getName() << ": ";
        os << "< " << ((Container) boat) << ">";
        return os;
    }

public:
    Boat(const int MAXPASSENGER, Bank* current): MAXPASSENGER(MAXPASSENGER),current(current),Container("Boat"){

    }
    void setBank(Bank* newBank){
        current = newBank;
    }
    Bank* getBank(){
        return current;
    }


    bool hasDriver() {
        for(Person* p : getPersons()){
            if(p->canDrive())
                return true;
        }
        return false;
    }

    size_t getMaxPassenger() {
        return MAXPASSENGER;
    }

private:
    const int MAXPASSENGER;
    Bank* current;
};


#endif //INC_2019_POO2_LABO4_BOAT_H
