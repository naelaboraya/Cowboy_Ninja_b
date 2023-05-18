#include "YoungNinja.hpp"
#include "Character.hpp"
#include <iostream>


//constructor 
YoungNinja::YoungNinja(std::string name , Point loc) : Character(name,loc){
    this->speed = 14;
    this->hit_points = 100;
}

//destructor
YoungNinja::~YoungNinja(){}

//-----------------------------------------Rule of five----------------------------------------------

// Copy constructor
YoungNinja::YoungNinja(const YoungNinja& other)
    : Character(other) {
    // Perform any additional deep copying or resource allocation specific to YoungNinja
}

// Copy assignment operator
YoungNinja& YoungNinja::operator=(const YoungNinja& other) {
    if (this != &other) {
        Character::operator=(other);
        // Perform any additional deep copying or resource allocation specific to YoungNinja
    }
    return *this;
}

// Move constructor
YoungNinja::YoungNinja(YoungNinja&& other) noexcept
    : Character(std::move(other)) {
    // Transfer ownership of any resources from 'other' to 'this'
}

// Move assignment operator
YoungNinja& YoungNinja::operator=(YoungNinja&& other) noexcept {
    if (this != &other) {
        Character::operator=(std::move(other));
        // Transfer ownership of any resources from 'other' to 'this'
    }
    return *this;
}
//----------------------------------------------------------------------------------------------------------------------




//functions

void YoungNinja::move(Character* enemy){
    Point new_location =Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed);
    this->_location = new_location;//update the location
}

void YoungNinja::slash(Character* enemy){
    if(this == enemy){
        throw std::runtime_error("no self harm!!");
    }
    if (!this->isAlive()){
          throw std::runtime_error("this Ninja is dead!");

    }
     if(!enemy->isAlive()){
         throw std::runtime_error("this enemy is dead!");
    }
    if(this->_location.distance(enemy->getLocation()) < 1){
        enemy->hit(40);
    }
}

std::string YoungNinja::print(){
    std::string info = "";
    info += this->_name;
    info += " , ";
    info += this->_location.print();
    info += " , ";
    info += std::to_string(this->hit_points);

    return info;
}

