#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"


class TrainedNinja : public Character{

    public :    

    int speed;

   
    //constructor
    TrainedNinja(std::string name , Point loc);

    //destructor
    ~TrainedNinja() override;

    //--------------------------------Rule of five------------------------------------
     // Copy constructor
    TrainedNinja(const TrainedNinja& other);

    // Copy assignment operator
    TrainedNinja& operator=(const TrainedNinja& other);

    // Move constructor
    TrainedNinja(TrainedNinja&& other) noexcept;

    // Move assignment operator
    TrainedNinja& operator=(TrainedNinja&& other) noexcept;
    //-------------------------------------------------------------------------------------

    //functions 
    void move(Character* enemy);//was pure virtual (interface)
    void slash(Character* enemy);//was pure virtual (interface)
    std::string print() override;
};





#endif