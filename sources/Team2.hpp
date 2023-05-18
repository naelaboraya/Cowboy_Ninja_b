#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include <vector>

using namespace std;

namespace ariel {}

class Team2 : public Team{

public: 
//constructor
Team2(Character* captain);


//destructor
~Team2();

//-----------------------------Rule of five---------------------------------------
// Copy constructor
    Team2(const Team2& other);

    // Copy assignment operator
    Team2& operator=(const Team2& other);

    // Move constructor
    Team2(Team2&& other) noexcept;

    // Move assignment operator
    Team2& operator=(Team2&& other) noexcept;
//--------------------------------------------------------------------------------

//getters and setters : 

Character* getCaptain(){
    return this->_captain;
}

void setCaptain(Character* new_captain){
    this->_captain=new_captain;
}

//functions:

void add(Character* new_soilder);

void attack(Team* enemy_team);

int stillAlive();

std::string print();

Character* chooseEnemy(Team* enemyTeam);//a helping function to choose the enemy to attack him (the choice is base on the distance)

    
};



#endif