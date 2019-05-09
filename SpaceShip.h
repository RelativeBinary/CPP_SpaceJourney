#ifndef spaceship_h
#define spaceship_h
//#include "functions.h"
//#include "Officer.h"
#include "SpaceSector.h"
#include <iostream>
#include <string>
#include <vector>
class Spaceship
{
    /* Core Stats: based on shiptype OR rng based on race. (strength, health, shield, armour, fuel, food, agility, speed, resources, money)
       Ability Stats: based on officer skill and rank OR rng based on race for non-player ships.
    */
    int strength, health, shield, armour, fuel, food, agility, speed, resources, money;

    public:
        /* raising any stats should only occur through the abilities that 
           are availble to use on the ship e.g. attempSystemRecovery is the only way
           to raise health, shields and armour.  
        */
        #pragma region //getters
        int getStrenght();
        int getHealth();
        int getShield();
        int getArmour();
        int getFuel();
        int getFood();
        int getAgility();
        int getSpeed();
        int getResources();
        int getMoney();
        int getDefenseLevel();
        #pragma endregion 
        void takeDamageFrom(Spaceship enemy);
        void Attack(Spaceship enemy);

    private:
};

class Playership : public Spaceship
{
    /* Core Stats: based on rng and shipType(strength, health, shield, armour, fuel, food, agility, speed, resources, money, crew, cargoCapacity, miningPower, fuelEfficiency)
       Ability Stats: based on officier skill level and rank
    */
    int crew, cargoCapacity, miningPower, fuelEfficiency;
    std::string shipType;
    std::vector<Officer> officers;

    public:
        //TODO: Added getters for data values

        //TODO: Make sure all abilities are being defined here
        void useDiplomacy(Spaceship &aggressor);                            //use captain, targets diplomacy stat, check skillevel, rng chance of success
        void useTrade();                                                    //use captain, rng chance of success
        void useTravel();                                                   //use pilot, engineer, attempSystemsRecovery(),
        void useCombatMauver(Spaceship &target);                            //use pilot, engineer, takes attackers combat manuver and offensive performance stat
        void useEscape(Spaceship &target);                                  //use engineer, pilot, speed, agility, takes attacker's speed
        void useSystemsRecovery();                                          //use engineer, activates on travel
        void useMine(PlanetEncounter &target);                              //use miner stats.
        void useAttack(Spaceship &target);                                  //uses weaponsSmith and pilot, takes targets defensive stats.
        void useDefenseLevel();                                             //use weaponsSmith and engineer, occurs on initialisation and if the either the weaponsSmith dies or an Engineer dies.
    private:
        void lowerResourceStats(int foodUsed, int fuelUsed, int moneyUsed); //only attempTravel, Trade, Escape, SystemsRecovery and Mining use resources like money, preciousMetals and/or fuel
};  

class NPCship : public Spaceship
{
};
#endif

//TODO:
/*
- Nothing to see here
*/