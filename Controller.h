//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_CONTROLLER_H
#define INC_2019_POO2_LABO4_CONTROLLER_H


#include <list>

#include "Bank.h"
#include "Boat.h"

class Controller {

    int turn;

    std::list<Bank> banks;
    Boat boat;


public:
    void showMenu();
    void display();
    void nextTurn();
};


#endif //INC_2019_POO2_LABO4_CONTROLLER_H
