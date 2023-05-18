#include "Character.hpp"
#include <iostream>
using namespace std;


//constructors
Character::Character(std::string name , Point loc):_name(name),_location(loc){}

Character::Character(Point loc , std::string name):_name(name),_location(loc){}


//destructor
//Character::~Character(){}

//-------------------------------------------------"Rule of five"----------------------------------//
// Copy constructor
Character::Character(const Character& other)
    : _name(other._name), _location(other._location) {
    // Perform any necessary deep copying or resource allocation
}

// Copy assignment operator
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        _location = other._location;
        // Perform any necessary deep copying or resource allocation
    }
    return *this;
}

// Move constructor
Character::Character(Character&& other) noexcept
    : _name(std::move(other._name)), _location(std::move(other._location)) {
    // Transfer ownership of any resources from 'other' to 'this'
}

// Move assignment operator
Character& Character::operator=(Character&& other) noexcept {
    if (this != &other) {
        _name = std::move(other._name);
        _location = std::move(other._location);
        // Transfer ownership of any resources from 'other' to 'this'
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------//

//functions: 

bool Character::isAlive(){
    return this->hit_points > 0;
}

double Character::distance(Character* other){//returns the distance between this character and other
    return this->_location.distance(other->getLocation());
}


void Character::hit(int num){
    if(num<0){
        throw std::invalid_argument("cannot hit with negative value!");
    }
    hit_points-=num;
}

std::string Character::print(){
    std::string info ="this is a character";
    return info;
}