#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP


#include "Character.hpp"


class YoungNinja : public Character {

    public:

    int speed;

   
    //constructor
    YoungNinja(std::string name , Point loc);
    
    
    //functions
    //functions:
    void move(Character* enemy);//was pure virtual (interface)
    void slash(Character* enemy);//was pure virtual (interface)
    std::string print() override;
};




#endif