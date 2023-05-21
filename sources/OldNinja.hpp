#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"


class OldNinja : public Character {

    public:

    int speed;

    
    //constructor
    OldNinja(std::string name , Point loc);
    

    //functions:
    void move(Character* enemy);
    void slash(Character* enemy);
    std::string print() override;
    
};



#endif