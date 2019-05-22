/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Container.h
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier de déclaration de la class Container
 -----------------------------------------------------------------------------------
*/
#ifndef INC_2019_POO2_LABO4_CONTAINER_H
#define INC_2019_POO2_LABO4_CONTAINER_H

#include <string>
#include <list>
#include <algorithm>

#include "../person/Person.h"
#include "../container/Group.h"

/**
 * Class represantant un objet qui contient des personnes
 */
class Container{

    // Operateur de sortie
    friend std::ostream&operator<<(std::ostream& os,const Container& container);

public:
    // Constructeurs
    Container(const std::string &name);

    /**
     * @return retourn le nom par référence
     */
    const std::string& getName() const;
    /**
     * Ajoute une personne
     * @param p pointeur sur une personne
     */
    void addPerson(const Person* p);
    /**
     * Enlève une personne
     * @param p pointeur sur une personne
     */
    void remove(const Person*p);

    /**
     * Ajoute une liste de pointeur sur des personnes
     * @param list La liste a ajouter
     */
    void addPersons(std::list<const Person*> list);
    /**
     * @return la taille du container
     */
    size_t size();
    /*
     * @return true si vide, false sinon
     */
    bool isEmpty();
    /**
     * @return la liste des personne par référence
     */
    const std::list<const Person*>& getPersons() const;
    /**
     * Fonction qui vide la liste
     */
    void empty();
    /**
     * FOnction qui retourne la personne en fonction de son nom
     * @param name nom de la personne
     * @return le pointeur sur la personne ou null_ptr si pas trouvé
     */
    const Person* getPersonyName(const std::string& name) const;
    /**
     * Test si une personne est présente dans le container
     * @param p pointeur sur la personne
     * @return true si la personne est présente
     */
    bool hasMember(const Person *p) const;

    /**
     * Test si une personne membre d'un groupe donnée est présent dans le container
     * @param container le groupe a tester
     * @return true si il fait parti du container
     */
    bool hasMemberOf(const Group* group) const;

private:

    const std::string name;
    std::list<const Person*> persons;
};

#endif //INC_2019_POO2_LABO4_CONTAINER_H
