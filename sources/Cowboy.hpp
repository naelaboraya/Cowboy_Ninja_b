#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;

class Cowboy : public Character{

private:
int num_of_bullets;

public:
//constructor
Cowboy(std::string name , Point loc);

~Cowboy() override;

//---------------------------------------------Rule of five----------------------------------------
 // Copy constructor
    Cowboy(const Cowboy& other);

    // Copy assignment operator
    Cowboy& operator=(const Cowboy& other);

    // Move constructor
    Cowboy(Cowboy&& other) noexcept;

    // Move assignment operator
    Cowboy& operator=(Cowboy&& other) noexcept;
//-----------------------------------------------------------------------------------------------------

//functions
void shoot(Character* enemy);
bool hasboolets();
void reload();
std::string print() override;


};




#endif
