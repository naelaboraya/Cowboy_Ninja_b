#include "Team.hpp"
#include <algorithm>
#include <limits>

//constructor
Team::Team(Character* captain){
     this->setCaptain(captain);
     this->_soilders.reserve(10);
     this->_soilders.push_back(captain);
}

//destructor
Team::~Team(){
    for(Character* soilder : this->_soilders){
        delete soilder;
    }
}

//-----------------------------------------Rule of five-----------------------------------
// Copy constructor
Team::Team(const Team& other)
    : _captain(nullptr), _soilders(other._soilders.size()) {
    // Deep copy the captain
    if (other._captain != nullptr) {
        _captain = new Character(*other._captain);
    }

    // Deep copy the soilders
    for (size_t i = 0; i < other._soilders.size(); i++) {
        _soilders[i] = new Character(*other._soilders[i]);
    }
}

// Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this != &other) {
        // Delete existing captain and soilders
        delete _captain;
        for (Character* soilder : _soilders) {
            delete soilder;
        }

        // Deep copy the captain
        _captain = nullptr;
        if (other._captain != nullptr) {
            _captain = new Character(*other._captain);
        }

        // Deep copy the soilders
        _soilders.resize(other._soilders.size());
        for (size_t i = 0; i < other._soilders.size(); i++) {
            _soilders[i] = new Character(*other._soilders[i]);
        }
    }
    return *this;
}

// Move constructor
Team::Team(Team&& other) noexcept
    : _captain(std::move(other._captain)), _soilders(std::move(other._soilders)) {
    // Set 'other' to a valid state
    other._captain = nullptr;
    other._soilders.clear();
}

// Move assignment operator
Team& Team::operator=(Team&& other) noexcept {
    if (this != &other) {
        // Delete existing captain and soilders
        delete _captain;
        for (Character* soilder : _soilders) {
            delete soilder;
        }

        // Move the captain and soilders from 'other'
        _captain = std::move(other._captain);
        _soilders = std::move(other._soilders);

        // Set 'other' to a valid state
        other._captain = nullptr;
        other._soilders.clear();
    }
    return *this;
}
//----------------------------------------------------------------------------------------



//functions:

void Team::add(Character* new_soilder){
    if(new_soilder->is_in_a_team){
        throw std::runtime_error("already in a team!");
    }
    if(this->_soilders.size() == 10){
        throw std::runtime_error("the team is full!");
    }
    
    for (Character* soldier : this->_soilders) {
        if (soldier == new_soilder) {
            throw std::runtime_error("The soldier already exists in the team!");
        }
    }

    this->_soilders.push_back(new_soilder);
    new_soilder->is_in_a_team=true;
}

int Team::stillAlive(){
    int counter = 0;
	for(Character* soilder : this->_soilders){
        if(soilder->isAlive()){
            counter++;
        }
    }
    return counter;
}

void Team::attack(Team* enemy_team){
    
    //check if the enemy team is null
    if(enemy_team==nullptr){
        throw std::invalid_argument("cannot attack null!");
    }
    if(enemy_team->stillAlive()==0){
        throw std::runtime_error("the attacked team is dead!");
    }

    if(this->stillAlive()==0 || enemy_team->stillAlive()==0){
        if(this->stillAlive()==0){
            std::cout<< "all the attacking team soilders are dead! " << endl;
            return;
        }
        else if (enemy_team->stillAlive()==0){
            std::cout<< "all the attacked team soilders are dead!" << endl;
            return;
        }
        //return because either the attacking team or the attacked team soilders are dead
        //return;
    }
       
     if (this->_captain==nullptr){
        throw std::runtime_error("null captain!");
     }
    
    //checking if the current team's captain is alive , if not appoint another captain (the nearest soilder)
     if (!this->_captain->isAlive()) {
        double minimum_distance = std::numeric_limits<double>::max();
        Character* nearestSoldier = nullptr;

        for (Character* soldier : this->_soilders) {
            if (soldier->isAlive()) {
                double distance = soldier->getLocation().distance(this->_captain->getLocation());
                if (distance < minimum_distance) {
                    minimum_distance = distance;
                    nearestSoldier = soldier;
                }
            }
        }
         
        if (nearestSoldier != nullptr) {
            setCaptain(nearestSoldier);
        }
    }

   

    /*Start the attack*/

    //first choose an enemy soilder based on distance
    Character* chosenEnemy = chooseEnemy(enemy_team);//the chosen enemy soilder to attack
    
    //remaining soilders (in the attacked team)//
    int remainingSoldiers = this->_soilders.size();
    
    for (Character* soldier : this->_soilders) {
    if (soldier->isAlive()) {
        // Perform attack logic on chosenEnemy--------------------------------------------------
        
        //checking if the currrent soldier is a cowboy 
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(soldier)) {
            //attacking logic for cowboy
            if(cowboy->hasboolets()){
                cowboy->shoot(chosenEnemy);
            }
            else if(!cowboy->hasboolets()){
                cowboy->reload();
            }
            //remainingSoldiers--;
        }

        //checking if the current sodldier is OldNinja
        if (OldNinja* oldninja = dynamic_cast<OldNinja*>(soldier)) {
            //attacking logic for oldNinja
             
            if(oldninja->distance(chosenEnemy) < 1){
                 
                oldninja->slash(chosenEnemy);   
            }
            else if (oldninja->distance(chosenEnemy) >= 1){
                oldninja->move(chosenEnemy);
            }
            //remainingSoldiers--;
        }

        //checking if the current sodldier is TrainedNinja
        if (TrainedNinja* trainedninja = dynamic_cast<TrainedNinja*>(soldier)) {
            //attacking logic for TrainedNinja
          
            if(trainedninja->distance(chosenEnemy) < 1){
                trainedninja->slash(chosenEnemy);   
            }
            else if (trainedninja->distance(chosenEnemy) >= 1){
                trainedninja->move(chosenEnemy);
            }
            //remainingSoldiers--;
        }

        //checking if the current sodldier is YoungNinja
        if (YoungNinja* youngninja = dynamic_cast<YoungNinja*>(soldier)) {
            //attacking logic for YoungNinja
            if(youngninja->distance(chosenEnemy) < 1){
                youngninja->slash(chosenEnemy);   
            }
            else if (youngninja->distance(chosenEnemy) >= 1){
                youngninja->move(chosenEnemy);
            }
            //remainingSoldiers--;
        }
        

        //End of performing the attack logic ---------------------------------------------------
        
        if (!chosenEnemy->isAlive()) {
           
            chosenEnemy = chooseEnemy(enemy_team);
        }

        //remainingSoldiers--;
        
      
        if(enemy_team->stillAlive()==0){
            
            break;
        }
         
    }
}

//  std :: cout << "aa" << endl;

    // for(Character* enemy : enemy_team->_soilders){
    //     enemy->hit_points=0;
    // }
    // return;
}

std::string Team::print(){
    std::string result = "";

    for (Character* character : this->_soilders) {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character)) {
            result += cowboy->print() + "\n";
        }
    

    
        if (OldNinja* oldNinja = dynamic_cast<OldNinja*>(character)) {
            result += oldNinja->print() + "\n";
        }
    

    
        if (TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(character)) {
            result += trainedNinja->print() + "\n";
        }
    

    
        if (YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(character)) {
            result += youngNinja->print() + "\n";
        }
    
    }
    return result;
}


Character* Team::chooseEnemy(Team* enemyTeam) {
    double nearestEnemyDistance = std::numeric_limits<double>::max();
    Character* nearestEnemy = nullptr;

    for (Character* enemy : enemyTeam->_soilders) {
        if (enemy->isAlive()) {
            double distance = enemy->getLocation().distance(this->_captain->getLocation());
            if (distance < nearestEnemyDistance) {
                nearestEnemyDistance = distance;
                nearestEnemy = enemy;
            }
        }
    }

    return nearestEnemy;
}
