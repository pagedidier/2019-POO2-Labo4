//
// Created by dpage on 09.05.19.
//

#ifndef INC_2019_POO2_LABO4_CONTAINER_H
#define INC_2019_POO2_LABO4_CONTAINER_H

#include <string>
#include <list>
#include <algorithm>

#include "../person/Person.h"
#include <iostream>
class Container{
    std::string name;
    std::list<Person*> persons;

    friend std::ostream&operator<<(std::ostream& os,const Container& container){
        for(Person* p : container.persons)
            os << *p << " ";
        return os;
    }

public:
    Container(const std::string &name,const std::list<Person*> persons) : name(name),persons(persons) {
    }
    Container(const std::string &name) : name(name) {
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Container::name = name;
    }

    void addPerson(Person* p){
        persons.push_back(p);
    }

    void remove(Person*p){
        persons.remove(p);
    }

    void addPersons(std::list<Person*> list){
        persons = list;
    }
    size_t size(){
        return persons.size();
    }
    bool isEmpty() {
        return size() == 0;
    }
    const std::list<Person*>& getPersons() const{
        return persons;
    }
    bool empty(){
        while (!persons.empty())
            persons.pop_front();
    }
    Person* getPersonyName(std::string name) const {
        for(Person* p : getPersons()){
            if(p->getName() == name)
                return p;
        }
        return nullptr;
    }
    bool hasMember(const Person *p) const{
        return find(persons.begin(),persons.end(),p) != persons.end();
    }
    bool hasMemberOf(const Container* container) const{
        for(const Person* p : container->getPersons()) {
            if (hasMember(p)) {
                return true;
            }
        }
        return false;
    }

};

#endif //INC_2019_POO2_LABO4_CONTAINER_H
