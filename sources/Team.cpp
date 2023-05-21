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

//----------------------------------------------------------------------------
//Copy constructor
Team::Team(const Team& other)
    : _captain(nullptr), _soilders(other._soilders.size()) {
    
    if (other._captain != nullptr) {
        _captain = new Character(*other._captain);
    }

    
    for (size_t i = 0; i < other._soilders.size(); i++) {
        _soilders[i] = new Character(*other._soilders[i]);
    }
}

//Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this != &other) {
        //Delete existing captain and soilders
        delete _captain;
        for (Character* soilder : _soilders) {
            delete soilder;
        }

        //Deep copy the captain
        _captain = nullptr;
        if (other._captain != nullptr) {
            _captain = new Character(*other._captain);
        }

        //Deep copy the soilders
        _soilders.resize(other._soilders.size());
        for (size_t i = 0; i < other._soilders.size(); i++) {
            _soilders[i] = new Character(*other._soilders[i]);
        }
    }
    return *this;
}

//Move constructor
Team::Team(Team&& other) noexcept
    : _captain(std::move(other._captain)), _soilders(std::move(other._soilders)) {
    // Set 'other' to a valid state
    other._captain = nullptr;
    other._soilders.clear();
}

//Move assignment operator
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

  
    if(this->stillAlive()==0){
        throw std::runtime_error("the attacking team is dead!");        
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
    
    //Iterate through the soldiers vector , first on cowboys and after that on ninjas (ordered by insertion to team)
    
    for (Character* soldier : this->_soilders) {
        if (chosenEnemy == nullptr) {
            break;
        }
        
        if (soldier->isAlive() && dynamic_cast<Cowboy*>(soldier)) {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(soldier);
            if (cowboy->hasboolets()) {
                cowboy->shoot(chosenEnemy);
            } else {
                cowboy->reload();
            }
            
            if (!chosenEnemy->isAlive()) {
                chosenEnemy = chooseEnemy(enemy_team);
            }
            
            remainingSoldiers--;
            
            if (remainingSoldiers == 0) {
                break;
            }
        }
    }
    
    for (Character* soldier : this->_soilders) {
        if (chosenEnemy == nullptr) {
            break;
        }
        
        if (soldier->isAlive() && dynamic_cast<YoungNinja*>(soldier)) {
            YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(soldier);
            if (youngNinja->distance(chosenEnemy) < 1) {
                youngNinja->slash(chosenEnemy);
            } else {
                youngNinja->move(chosenEnemy);
            }
            
            if (!chosenEnemy->isAlive()) {
                chosenEnemy = chooseEnemy(enemy_team);
            }
            
            remainingSoldiers--;
            
            if (remainingSoldiers == 0) {
                break;
            }
        }
    }

    //old Ninjas 
    for (Character* soldier : this->_soilders) {
        if (chosenEnemy == nullptr) {
            break;
        }
        
        if (soldier->isAlive() && dynamic_cast<OldNinja*>(soldier)) {
            OldNinja* oldNinja = dynamic_cast<OldNinja*>(soldier);
            if (oldNinja->distance(chosenEnemy) < 1) {
                oldNinja->slash(chosenEnemy);
            } else {
                oldNinja->move(chosenEnemy);
            }
            
            if (!chosenEnemy->isAlive()) {
                chosenEnemy = chooseEnemy(enemy_team);
            }
            
            remainingSoldiers--;
            
            if (remainingSoldiers == 0) {
                break;
            }
        }
    }

    //Trained ninjas
    for (Character* soldier : this->_soilders) {
        if (chosenEnemy == nullptr) {
            break;
        }
        
        if (soldier->isAlive() && dynamic_cast<TrainedNinja*>(soldier)) {
            TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(soldier);
            if (trainedNinja->distance(chosenEnemy) < 1) {
                trainedNinja->slash(chosenEnemy);
            } else {
                trainedNinja->move(chosenEnemy);
            }
            
            if (!chosenEnemy->isAlive()) {
                chosenEnemy = chooseEnemy(enemy_team);
            }
            
            remainingSoldiers--;
            
            if (remainingSoldiers == 0) {
                break;
            }
        }
    }
	

   /*End of function*/
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

