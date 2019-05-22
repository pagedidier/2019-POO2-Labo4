//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_CONTROLLER_H
#define INC_2019_POO2_LABO4_CONTROLLER_H


#include <list>
#include <exception>
#include <iostream>
#include "container/Bank.h"
#include "container/Boat.h"
#include "container/Group.h"
#include "person/Father.h"
#include "person/Mother.h"
#include "person/Son.h"
#include "person/Daughter.h"
#include "person/PoliceMan.h"
#include "person/Robber.h"
#include <cstdlib>
#include <string>
#include <algorithm>

class Controller {

    unsigned turn;
    unsigned nbPersons;
    bool wantToContinue;
    Bank rightBank;
    Bank leftBank;
    Boat boat;

    Group* family;
    Group* robber;
    Group* police;
    Group* sons;
    Group* daughter;
    Group* mother;
    Group* father;

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
        if(p == nullptr)
            throw std::runtime_error("Personne " + personName + " n'est pas sur cette rive !" );

        if(boat.size()>boat.getMaxPassenger())
            throw std::runtime_error("Plus de place dans le bateau" );


        boat.addPerson(p);
        b->remove(p);
        try{
            check(boat);
            check(*b);
        }catch(std::runtime_error& e){
            std::cout << e.what()<< std::endl;
            boat.remove(p);
            b->addPerson(p);
        }

    }

    void land(std::string personName) {

        Bank* b = boat.getBank();
        Person* p = boat.getPersonyName(personName);
        if(p == nullptr)
            throw std::runtime_error("Personne "+ personName + " n'est pas dans le bateau !" );

        boat.remove(p);
        b->addPerson(p);
        try{
            check(boat);
            check(*b);
        }catch(std::runtime_error& e){
            std::cout << e.what()<< std::endl;
            boat.addPerson(p);
            b->remove(p);
        }
    }

    //hack c'est oas bo
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
            try{
                std::cout << turn <<  "> ";
                handleInput(getInput());
                nextTurn();
            }catch (std::exception& e){
                std::cout << e.what()<<std::endl;
                display();
            }
        }

        std::cout << "Game finished !"<<std::endl;
    }
    bool moveBoat(){
        if(!this->boat.hasDriver())
            throw std::runtime_error("Personne ne peut conduire le bateau");
        boat.setBank((boat.getBank() == &rightBank) ? &leftBank : &rightBank);

    }

    virtual ~Controller() {
    }

public:
    void initGame(){
        leftBank.empty();
        rightBank.empty();
        boat.empty();
        boat.setBank(&leftBank);
        this->wantToContinue = true;

        Person* policeMan =new  PoliceMan("policier");
        Person* robberMan =new  Robber("voleur");

        std::list<Person*> familyList;
        police = new Group("Policier",{policeMan});
        robber = new Group("Voleur",{robberMan});
        sons = new Group("sons",{new Son("paul"),new Son("pierre")});
        daughter = new Group("daughter",{new Daughter("julie"),new Daughter("jeanne")});
        father = new Group("father",{ new Father("pere")});
        mother = new Group("mother",{ new Mother("mere")});



        familyList.insert(familyList.begin(),daughter->getPersons().begin(),daughter->getPersons().end());
        familyList.insert(familyList.end(),sons->getPersons().begin(),sons->getPersons().end());
        familyList.insert(familyList.end(),father->getPersons().begin(),father->getPersons().end());
        familyList.insert(familyList.end(),mother->getPersons().begin(),mother->getPersons().end());

        family = new Group("Famille",familyList);

        leftBank.addPersons(familyList);
        leftBank.addPerson(robberMan);
        leftBank.addPerson(policeMan);

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


    void check(const Container& container){

        if(container.hasMemberOf(robber) && container.hasMemberOf(family) && !container.hasMemberOf(police))
            throw std::runtime_error("Le voleur ne peut pas rester en contact avec un membre de la famille si le policier n'est pas présent");
        if(container.hasMemberOf(sons) && container.hasMemberOf(mother) && !container.hasMemberOf(father))
            throw std::runtime_error("Les fils ne peuvent rester seuls avec leur mère si le père n’est pas présent");

        if(container.hasMemberOf(daughter) && container.hasMemberOf(father) && !container.hasMemberOf(mother))
            throw std::runtime_error("Les filles ne peuvent rester seules avec leur père si la mère n’est pas présente");
    }

};


#endif //INC_2019_POO2_LABO4_CONTROLLER_H
