/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Controller.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration de la class Controller
 -----------------------------------------------------------------------------------
*/

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

/**
 * Classe qui va géréer tout la logique du jeux
 */
class Controller {

    // Constantes static des commande entrée par l'utilisateur
    static const char CMD_SHOW = 'p';
    static const char CMD_EMBARK = 'e';
    static const char CMD_LAND = 'd';
    static const char CMD_MOVE = 'm';
    static const char CMD_RESET = 'r';
    static const char CMD_QUIT = 'q';
    static const char CMD_MENU = 'h';

public:
    // Constructeur
    Controller();

    /**
    * Fonction qui lance/gère le jeux
    */
    void start();

    /**
     * Test si la partie est fini ou si le joueur veux continuer (Par defaut oui)
     * @return true si la partie est finie
     */
    bool gameEnded();

    /**
     * Récupère l'entrée utilisateur
     * @return l'entrée complète
     */
    std::string getInput();
    /**
     * Gère l'entrle utilisateur
     * @param command La command entrée par l'utilisateur
     * @return false si l'entrée n'est pas correct
     */
    bool handleInput(std::string command);

    /**
    * Gère des commandes sans paramètre
    * @param command La command (un char) entrée par l'utilisateur
    * @return false si l'entrée n'est pas correct
    */
    bool handleSimpleCommand(const char command);

    /**
    * Gère des commandes avace paramètre
    * @param command La command (un char) entrée par l'utilisateur
     * @param param paramètre de la commande
    * @return false si l'entrée n'est pas correct
    */
    bool handleParamCommand(const char command,const std::string& param);


    /**
     * Fonction qui déplace le bateau (change le bateau de rive)
     * @throw runtime_error si le bateau n'as pas de chaffeur
     */
    void moveBoat();

    /**
     * Fonction qui initialise le jeux, elle créer les personnes et les groupes
     */
    void initGame();
    /**
     * Créer les groupes
     */
    void createGroups();
    /**
     * Fonction qui affiche le menu
     */
    void showMenu();
    /**
     * Fonction qui affiche les berges et le bateau
     */
    void display();

    /**
     * Fonction qui passe au prochain tour
     */
    void nextTurn(){
        turn++;
    }

    /**
     * Embarque une personne en fonction de son nom dans le bateau
     * @param personName nom de la personne a embarquer
     * @throws runtime_error si la personne n'exsiste pas, ou si le bateau et plein ou si un règle du jeu n'est pas
     * respectée
     */
    void embark(const std::string& personName);
    /**
     * Débarque une personne en fonction de son nom dans le bateau
     * @param personName nom de la personne a débarquer
     * @throws runtime_error si la personne n'exsiste pas ou si un règle du jeu n'est pas
     * respectée
    */
    void land(std::string personName);

    /**
     * Vérifies les régles du jeu sur un container
     * @param container le container a tester
     * @throws runtime_error si une des régles n'est pas respéctée
     */
    void check(const Container& container);

    /**
     * Désalloue les groupes
     */
    void deleteGroups();

    /**
     * Destructeur
     */
    virtual ~Controller();

private:

    unsigned turn;
    unsigned nbPersons;     // Attribut utile pour tester si tout les personnes ont traversés
    bool wantToContinue;

    Bank rightBank;
    Bank leftBank;
    Boat boat;

    Group* family;
    Group* robber;
    Group* police;
    Group* son;
    Group* daughter;
    Group* mother;
    Group* father;

};


#endif //INC_2019_POO2_LABO4_CONTROLLER_H
