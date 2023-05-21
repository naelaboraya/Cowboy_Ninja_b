#include "Cowboy.hpp"

//constructor
Cowboy::Cowboy(std::string name , Point loc):Character(name,loc){
    this->num_of_bullets = 6;
    this->hit_points = 110;
}


//functions:

void Cowboy::shoot(Character* enemy){
    if(this == enemy){
        throw std::runtime_error("no self harm!!");
    }
    if(!this->isAlive()){
        throw std::runtime_error("this Cowboy is dead!");
    }
     if(!enemy->isAlive()){
         throw std::runtime_error("this enemy is dead!");
    }
    if(this->hasboolets()){
    this->num_of_bullets--;
    enemy->hit(10);
    }
}

bool Cowboy::hasboolets(){
    return this->num_of_bullets > 0 ;
}


void Cowboy::reload(){
    if(!this->isAlive()){
        throw std::runtime_error("dead Cowboy cannot reaload!");
    }
    this->num_of_bullets = 6;
}

std::string Cowboy::print(){
    std::string info = "";
    info += this->_name;
    info += " , ";
    info += this->_location.print();
    info += " , ";
    info += std::to_string(this->hit_points);

    return info;
}