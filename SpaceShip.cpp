#include <iostream>
#include <string>
#include <vector>
#include "SpaceShip.h"
#include "Officer.h"
#include "functions.h"

SpaceShip::SpaceShip(){
    strength = 50;
    health = 50;
    shield = 50;
    armour = 50;
    fuel = 50;
    food = 50;
    agility = 50;
    speed = 50;
    resources = 50;
    money = 50;
}

SpaceShip::SpaceShip(int strgth, int health, int shield, int armour, int fuel, int food, int agility, int speed, int resources, int money){
    this->strength = strgth;
    this->health = health;
    this->shield = shield;
    this->armour = armour;
    this->fuel = fuel;
    this->food = food;
    this->agility = agility;
    this->speed = speed;
    this->resources = resources;
    this->money = money;
}


int SpaceShip::getStrength(){
    return this->strength;
}
int SpaceShip::getHealth() {
    return this->health;
}
int SpaceShip::getShield() {
    return this->shield;
}
int SpaceShip::getArmour() {
    return this->armour;
}
int SpaceShip::getFuel() {
    return this->fuel;
}
int SpaceShip::getFood() {
    return this->food;
}
int SpaceShip::getAgility() {
    return this->agility;
}
int SpaceShip::getSpeed() {
    return this->speed;
}
int SpaceShip::getResources() {
    return this->resources;
}
int SpaceShip::getMoney() {
    return this->money;
}

Playership::Playership() 
{
    int crew = 0;
    int cargoCapacity = 0; //out of 100
    int mainingPower = 0;  // out of 100
    int fuelEfficiency = 0; //out of 10
    std::string shipType = "Jack";

}

Playership::Playership(std::vector<Officer> officers){
    //setup ship internally
    this->shipType = determineShipType();
    this->officers = officers; //POSSIBLE: Internal officers setup function, very cool
    setupShip();
}

Playership::Playership(std::string type, std::vector<Officer> officers){
    //setup ship externally
    this->shipType = type;
    this->officers = officers;
    setupShip();
}

void Playership::setupShip(){
    if (this->shipType == "Dawn Sailor"){
        OffensiveSetup();
    }else if (this->shipType == "Scavenger"){
        MinerSetup();
    }else if (this->shipType == "Nebula"){
        DefensiveSetup();
    }else if (this->shipType == "ONE-HIT-WONDER"){
        OneHitSetup();
    }else if (this->shipType == "Jack"){
        AverageSetup();
    }
}

void Playership::addOfficer(Officer newOfficer){

}

void Playership::useDiplomacy(SpaceShip &aggressor){

}
void Playership::useTrade(SpaceShip &tradeShip){

}
void Playership::useTravel(){
    //check for dead officers, replace dead officers etc
    //perform systems recovery
    //

}
void Playership::useCombatMauver(SpaceShip &target){

}
void Playership::useEscape(SpaceShip &enemy){

}
void Playership::useSystemsRecovery(){

}
void Playership::useMine(PlanetEncounter &planet){

}
void Playership::useAttack(SpaceShip &target){

}
void Playership::upgradeDefense(){

}
void Playership::takeDamageFrom(SpaceShip enemy){

}

Officer Playership::findOfficer(std::string job){
    Officer temp("noOfficer", "none", "none", 20, 50, 0);

    for (Officer currOfficer: this->officers){
        if(currOfficer.getJob() == job && !currOfficer.getIsDead()){
            return currOfficer;
        }
    }

    std::cout << "There is currently no " << job << " on the ship! \n";
    return temp;
}

void Playership::OffensiveSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(40, 70);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(70, 100);
    this->armour = randNumGen(70, 100);
    this->strength = randNumGen(70, 100);
    this->miningPower = randNumGen(0, 40);
    this->cargoCapacity = randNumGen(0, 40);
    this->fuelEfficiency = randNumGen(40, 70);
}

void Playership::MinerSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(0, 40);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(40, 70);
    this->armour = randNumGen(0, 40);
    this->strength = randNumGen(40, 70);
    this->miningPower = randNumGen(70, 100);
    this->cargoCapacity = randNumGen(70, 100);
    this->fuelEfficiency = randNumGen(70, 100);
}

void Playership::DefensiveSetup(){
    this->speed = randNumGen(70, 100);
    this->shield = randNumGen(70, 100);
    this->agility = randNumGen(70, 100);
    this->health = randNumGen(70, 100);
    this->armour = randNumGen(70, 100);
    this->strength = randNumGen(0, 40);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}

void Playership::OneHitSetup(){
    this->speed = randNumGen(70, 100);
    this->shield = randNumGen(70, 100);
    this->agility = randNumGen(70, 100);
    this->health = 1;
    this->armour = randNumGen(40, 70);
    this->strength = randNumGen(90, 100);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}
    
void Playership::AverageSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(40, 70);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(40, 70);
    this->armour = randNumGen(40, 70);
    this->strength = randNumGen(40, 70);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}

