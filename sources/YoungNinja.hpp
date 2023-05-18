#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP


#include "Character.hpp"


class YoungNinja : public Character {

    public:

    int speed;

   
    //constructor
    YoungNinja(std::string name , Point loc);

    //destructor
    ~YoungNinja() override;

    //----------------------------------------Rule of five-----------------------------------
    // Copy constructor
    YoungNinja(const YoungNinja& other);

    // Copy assignment operator
    YoungNinja& operator=(const YoungNinja& other);

    // Move constructor
    YoungNinja(YoungNinja&& other) noexcept;

    // Move assignment operator
    YoungNinja& operator=(YoungNinja&& other) noexcept;
    //-----------------------------------------------------------------------------------------

    //functions
    //functions:
    void move(Character* enemy);//was pure virtual (interface)
    void slash(Character* enemy);//was pure virtual (interface)
    std::string print() override;
};




#endif