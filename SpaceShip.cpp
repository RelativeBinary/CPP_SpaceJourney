#include <iostream>
#include <string>
#include <vector>
#include "SpaceShip.h"
#include "Officer.h"

SpaceShip::SpaceShip(){
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

/*Playership::Playership()
{
    int crew = 10;
    int cargoCapacity = 50; //out of 100
    int mainingPower = 40;  // out of 100
    int fuelEfficiency = 5; //out of 10
    std::string shipType = "defaultConstrutor";
}*/
