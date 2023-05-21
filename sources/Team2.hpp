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


void attack(Team* enemy_team);
  
};



#endif