#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>
#include <string>

using namespace std;



class Character{


public:


Point _location;
int hit_points;
std::string _name;
bool isCaptain = false;
bool is_in_a_team = false;


//constructor:
Character(std::string name , Point loc);
Character(Point loc , std::string name);

//destructor:
virtual ~Character()=default;//////////////////////////// 

//-------------------------------------------Rule of five--------------------------------------------

 // Copy constructor
Character(const Character& other);

    // Copy assignment operator
Character& operator=(const Character& other);

    // Move constructor
Character(Character&& other) noexcept;

    // Move assignment operator
Character& operator=(Character&& other) noexcept;

//-----------------------------------------------------------------------------------------------------


//getters:
std::string getName() const{
    return this->_name;
}
Point getLocation() const{
    return this->_location;
}
int getHitpoints() const{
    return this->hit_points;
}



//methods : make them virtual!
bool isAlive();//returns true iff this-> hit_points > 0
double distance(Character* other);//returns the distance between this character and other
void hit(int num);
virtual std::string print();




};




#endif
