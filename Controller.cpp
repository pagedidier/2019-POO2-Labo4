/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Controller.cpp
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier d'implémentation de la class Controller
 -----------------------------------------------------------------------------------
*/
#include "Controller.h"

Controller::Controller(): turn(0),rightBank("Droite"),leftBank("Gauche"),boat(2,&leftBank),wantToContinue(true) {
    initGame();
    showMenu();
}

void Controller::start(){

    while(!gameEnded()){
        try{
            display();
            std::cout << turn <<  "> ";
            handleInput(getInput());
            nextTurn();
        }catch (std::exception& e){
            std::cout << e.what()<<std::endl;
        }
    }
    std::cout << "Game finished !"<<std::endl;
}

bool Controller::gameEnded() {
    return !wantToContinue|| (leftBank.isEmpty() && boat.isEmpty() && rightBank.size() == nbPersons);
}

std::string Controller::getInput() {
    std::string str;
    std::getline (std::cin,str,'\n');
    return str;
}

bool Controller::handleInput(std::string command) {

    char input = command[0];

    if(command.size()>1){
        std::string param;
        param = command.substr(2,command.size());
        return handleParamCommand(input,param);
    }else{
        return handleSimpleCommand(input);
    }

}

bool Controller::handleSimpleCommand(const char command){

    switch (command){
        case CMD_SHOW:
            display();
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

bool Controller::handleParamCommand(const char command,const std::string& param){

    switch (command){
        case CMD_EMBARK:
            embark(param);
            break;
        case CMD_LAND:
            land(param);
            break;
        default:
            return false;
    }
    return true;
}

void Controller::moveBoat(){
    if(!this->boat.hasDriver())
        throw std::runtime_error("Personne ne peut conduire le bateau");
    //Si il est a gauche il va a droite sinon il rest (va) a droite
    boat.setBank((boat.getBank() == &rightBank) ? &leftBank : &rightBank);
}

void Controller::initGame(){
    if(turn != 0){
        deleteGroups();
    }
    // Réinitilise les valeurs
    leftBank.empty();
    rightBank.empty();
    boat.empty();
    this->wantToContinue = true;
    boat.setBank(&leftBank);

    //deleteGroups();
    createGroups();

    leftBank.addPersons(police->getPersons());
    leftBank.addPersons(robber->getPersons());
    leftBank.addPersons(family->getPersons());

    nbPersons = leftBank.size();
}

void Controller::createGroups(){

    // On créer les groupes indépendants
    police = new Group("Policier",{new  PoliceMan("policier")});
    robber = new Group("Voleur",{new  Robber("voleur")});
    son = new Group("son",{new Son("paul"),new Son("pierre")});
    daughter = new Group("daughter",{new Daughter("julie"),new Daughter("jeanne")});
    father = new Group("father",{ new Father("pere")});
    mother = new Group("mother",{ new Mother("mere")});

    // Ensuite on créer le groupe famille a partir des autres groupes
    std::list<const Person*> familyList;
    familyList.insert(familyList.begin(),daughter->getPersons().begin(),daughter->getPersons().end());
    familyList.insert(familyList.end(),son->getPersons().begin(),son->getPersons().end());
    familyList.insert(familyList.end(),father->getPersons().begin(),father->getPersons().end());
    familyList.insert(familyList.end(),mother->getPersons().begin(),mother->getPersons().end());

    family = new Group("Famille",familyList);
}

void Controller::showMenu(){
    std::cout << CMD_SHOW   <<"      : afficher"<< std::endl;
    std::cout << CMD_EMBARK <<" <nom>: embarquer <nom>"<< std::endl;
    std::cout << CMD_LAND   <<" <nom>: debarquer <nom>"<< std::endl;
    std::cout << CMD_MOVE   <<"      : deplacer bateau"<< std::endl;
    std::cout << CMD_RESET  <<"      : reinitialiser"<< std::endl;
    std::cout << CMD_QUIT   <<"      : quitter"<< std::endl;
    std::cout << CMD_MENU   <<"      : menu"<< std::endl;
}
void Controller::display(){
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

void Controller::embark(const std::string& personName) {

    Bank* currentBank = boat.getBank();

    const Person* p = currentBank->getPersonyName(personName);
    if(p == nullptr)
        throw std::runtime_error("Personne " + personName + " n'est pas sur cette rive !" );

    if(boat.size()>boat.getMaxPassenger())
        throw std::runtime_error("Plus de place dans le bateau" );

    //On test de mettre la personne dans le bateau
    boat.addPerson(p);
    currentBank->remove(p);
    try{
        //On verifie les régles
        check(boat);
        check(*currentBank);
    }catch(std::runtime_error& e){
        // On reset l'état préscedent
        boat.remove(p);
        currentBank->addPerson(p);
        throw e;
    }

}

void Controller::land(std::string personName) {

    Bank* b = boat.getBank();
    const Person* p = boat.getPersonyName(personName);

    if(p == nullptr)
        throw std::runtime_error("Personne "+ personName + " n'est pas dans le bateau !" );

    boat.remove(p);
    b->addPerson(p);

    try{
        //On verifie les régles
        check(boat);
        check(*b);
    }catch(std::runtime_error& e){
        // On reset l'état préscedent
        boat.addPerson(p);
        b->remove(p);
        throw e;

    }
}

void Controller::check(const Container& container){

    if(container.hasMemberOf(robber) && container.hasMemberOf(family) && !container.hasMemberOf(police))
        throw std::runtime_error("Le voleur ne peut pas rester en contact avec un membre de la famille si le policier n'est pas présent");
    if(container.hasMemberOf(son) && container.hasMemberOf(mother) && !container.hasMemberOf(father))
        throw std::runtime_error("Les fils ne peuvent rester seuls avec leur mère si le père n’est pas présent");
    if(container.hasMemberOf(daughter) && container.hasMemberOf(father) && !container.hasMemberOf(mother))
        throw std::runtime_error("Les filles ne peuvent rester seules avec leur père si la mère n’est pas présente");
}

void Controller::deleteGroups(){
    delete family;
    delete robber;
    delete police;
    delete son;
    delete daughter;
    delete mother;
    delete father;
}
Controller::~Controller() {
    deleteGroups();
}
