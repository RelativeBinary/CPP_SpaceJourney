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
    std::string shipType = "defaultConstrutor";
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

