#include "TrainedNinja.hpp"
#include "Character.hpp"
#include <iostream>


//constructor
TrainedNinja::TrainedNinja(std::string name , Point loc) : Character(name,loc){
    this->speed = 12;
    this->hit_points = 120;
}


//functions


void TrainedNinja::move(Character* enemy){
    Point new_location =Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed);
    this->_location = new_location;//update the location
}

void TrainedNinja::slash(Character* enemy){
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

std::string TrainedNinja::print(){
    std::string info = "";
    info += this->_name;
    info += " , ";
    info += this->_location.print();
    info += " , ";
    info += std::to_string(this->hit_points);

    return info;
}

