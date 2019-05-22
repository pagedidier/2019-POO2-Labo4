/*
 -----------------------------------------------------------------------------------
 Laboratoire : 4
 Fichier     : Container.cpp
 Auteur(s)   : Page Didier
 Date        : 22.05.2019

 But         : Fichier d'implémentation de la class Container
 -----------------------------------------------------------------------------------
*/
#include "Container.h"

std::ostream& operator<<(std::ostream& os,const Container& container){
    for(const Person* p : container.persons)
        os << *p << " ";
    return os;
}


Container::Container(const std::string &name) : name(name) {
}

const std::string& Container::getName() const {
    return name;
}

void Container::addPerson(const Person* p){
    persons.push_back(p);
}

void Container::remove(const Person*p){
    persons.remove(p);
}


void Container::addPersons(std::list<const Person*> list){
    persons.insert(persons.begin(),list.begin(),list.end());
}

size_t Container::size(){
    return persons.size();
}

bool Container::isEmpty() {
    return size() == 0;
}

const std::list<const Person*>& Container::getPersons() const{
    return persons;
}

void Container::empty(){
    while (!persons.empty())
        persons.pop_front();
}

const Person* Container::getPersonyName(const std::string& name) const {
    for(const Person* p : getPersons()){
        if(p->getName() == name)
            return p;
    }
    return nullptr;
}

bool Container::hasMember(const Person *p) const{
    return find(persons.begin(),persons.end(),p) != persons.end();
}


bool Container::hasMemberOf(const Group* group) const{
    for(const Person* p : group->getPersons()) {
        if (hasMember(p)) {
            return true;
        }
    }
    return false;
}