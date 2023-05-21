#include "Team2.hpp"
#include <algorithm>
#include <limits>

//constructor
Team2::Team2(Character* captain): Team(captain){

}


void Team2::attack(Team* enemy_team){
    
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
    
    //Iterate through all the soldiers (by insertion to team order) , and ignore the type of the soldier (cowboy/ninja)
    
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

}

