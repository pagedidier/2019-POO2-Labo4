//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_BANK_H
#define INC_2019_POO2_LABO4_BANK_H


#include "Container.h"

class Bank : public Container {

    friend std::ostream&operator<<(std::ostream& os,const Bank& bank){
        os << "----------------------------------------------------------" <<std::endl;
        os << ((Container) bank).getName() << ": ";
        os << ((Container) bank) <<std::endl;
        os << "----------------------------------------------------------";
        return os;
    }

public:
    Bank(const std::string &name, const std::list<Person*> &persons): Container(name,persons){

    }
    Bank(const std::string &name) : Container(name) {

    }
    virtual ~Bank(){

    }
};


#endif //INC_2019_POO2_LABO4_BANK_H
