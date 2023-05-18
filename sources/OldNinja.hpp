#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"


class OldNinja : public Character {

    public:

    int speed;

    
    //constructor
    OldNinja(std::string name , Point loc);
    
    //destructor
    ~OldNinja() override;

    //------------------------Rule of five--------------------------------------------

    // Copy constructor
    OldNinja(const OldNinja& other);

    // Copy assignment operator
    OldNinja& operator=(const OldNinja& other);

    // Move constructor
    OldNinja(OldNinja&& other) noexcept;

    // Move assignment operator
    OldNinja& operator=(OldNinja&& other) noexcept;
    //--------------------------------------------------------------------------------

    //functions:
    void move(Character* enemy);//was pure virtual (interface)
    void slash(Character* enemy);//was pure virtual (interface)
    std::string print() override;
    
};



#endif