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


//functions
void shoot(Character* enemy);
bool hasboolets();
void reload();
std::string print() override;


};




#endif
