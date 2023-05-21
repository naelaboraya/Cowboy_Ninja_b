#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"


class TrainedNinja : public Character{

    public :    

    int speed;

   
    //constructor
    TrainedNinja(std::string name , Point loc);


    //functions 
    void move(Character* enemy);//was pure virtual (interface)
    void slash(Character* enemy);//was pure virtual (interface)
    std::string print() override;
};





#endif