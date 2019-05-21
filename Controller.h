//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_CONTROLLER_H
#define INC_2019_POO2_LABO4_CONTROLLER_H


#include <list>
#include <iostream>
#include "container/Bank.h"
#include "container/Boat.h"
#include "person/Father.h"
#include "person/Mother.h"
#include "person/Son.h"
#include "person/Daughter.h"
#include "person/PoliceMan.h"
#include "person/Robber.h"
#include <cstdlib>
#include <string>


class Controller {

    unsigned turn;
    unsigned nbPersons;
    bool wantToContinue;
    Bank rightBank;
    Bank leftBank;
    Boat boat;

    static const char CMD_SHOW = 'p';
    static const char CMD_EMBARK = 'e';
    static const char CMD_LAND = 'd';
    static  const char CMD_MOVE = 'm';
    static  const char CMD_RESET = 'r';
    static  const char CMD_QUIT = 'q';
    static const char CMD_MENU = 'h';

public:
    Controller(): turn(0),rightBank("Droite"),leftBank("Gauche"),boat(2,&leftBank) {
        initGame();
        showMenu();
        display();
    }

    bool gameEnded() {
        return !wantToContinue|| (leftBank.isEmpty() && boat.isEmpty() && rightBank.size() == nbPersons);
    }

    std::string getInput() {
        std::string str;
        std::getline (std::cin,str,'\n');
        return str;
    }

    void embark(std::string personName) {
        Bank* b = boat.getBank();
        Person* p = b->getPersonyName(personName);
        if(p == nullptr){
            std::cout << "Personne "<< personName << " n'est pas sur cette rive !" <<std::endl<<std::endl;
            return;
        }
        if(boat.size()<boat.getMaxPassenger()){
            boat.addPerson(p);
            b->remove(p);
        }else{
            std::cout << "Plus de place dans le bateau"<<std::endl;
        }

    }

    void land(std::string personName) {

        Bank* b = boat.getBank();
        Person* p = boat.getPersonyName(personName);
        if(p == nullptr){
            std::cout << "Personne "<< personName << " n'est pas dans le bateau !" <<std::endl<<std::endl;
            return;
        }
        boat.remove(p);
        b->addPerson(p);

    }

    bool handleInput(std::string command) {
        char input = command[0];
        std::string param;

        if(command.size()>1)
            param = command.substr(2,command.size());
        switch (input){
            case CMD_SHOW:
                display();
                break;
            case CMD_EMBARK:
                embark(param);
                break;
            case CMD_LAND:
                land(param);
                break;
            case CMD_MOVE:
                moveBoat();
                break;
            case CMD_RESET:
                initGame();
                break;
            case CMD_QUIT:
                wantToContinue = false;
                break;
            case CMD_MENU:
                showMenu();
                break;
            default:
                return false;
        }
        return true;
    }

    void start(){
        while(!gameEnded()){
            std::string input;
            if(!handleInput(getInput())){
                std::cout << "Error"<<std::endl;
            };
            nextTurn();
        }
        std::cout << "Game finished !"<<std::endl;
    }
    bool moveBoat(){
        if(this->boat.hasDriver()){
            boat.setBank((boat.getBank() == &rightBank) ? &leftBank : &rightBank);
        }else{
            std::cout << "Personne ne peut conduire le bateau"<< std::endl;
        }
    }

public:
    void initGame(){
        leftBank.empty();
        rightBank.empty();
        boat.empty();
        boat.setBank(&leftBank);
        this->wantToContinue = true;

        leftBank.addPersons({
                                    new Father("pere"),
                                    new Mother("mere"),
                                    new Son("paul"),
                                    new Son("pierre"),
                                    new Daughter("julie"),
                                    new Daughter("jeanne"),
                                    new PoliceMan("policier"),
                                    new Robber("voleur")
                            });

        nbPersons = leftBank.size();
    }
    void showMenu(){
        std::cout << "p      : afficher"<< std::endl;
        std::cout << "e <nom>: embarquer <nom>"<< std::endl;
        std::cout << "d <nom>: debarquer <nom>"<< std::endl;
        std::cout << "m      : deplacer bateau"<< std::endl;
        std::cout << "r      : reinitialiser"<< std::endl;
        std::cout << "q      : quitter"<< std::endl;
        std::cout << "h      : menu"<< std::endl;
    }
    void display(){
        std::cout << leftBank<<std::endl;
        if(boat.getBank() == &rightBank){
            std::cout << "==========================================================" <<std::endl;
        }
        std::cout << boat << std::endl;
        if(boat.getBank() == &leftBank){
            std::cout << "==========================================================" <<std::endl;
        }
        std::cout << rightBank <<std::endl;
    }
    void nextTurn(){
        display();
        turn++;
    }
};


#endif //INC_2019_POO2_LABO4_CONTROLLER_H
