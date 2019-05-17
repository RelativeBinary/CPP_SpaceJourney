#ifndef spaceship_h
#define spaceship_h
#include <iostream>
#include <string>
#include <vector>
#include "SpaceSector.h"
#include "Officer.h"

class SpaceShip {
    /* 
        Core Stats: based on shiptype OR rng based on race. (strength, health, shield, armour, fuel, food, agility, speed, resources, money)
        Ability Stats: based on officer skill and rank OR rng based on race for non-player ships.
    */
    protected:
        int strength = 0;
        int health = 0;
        int shield = 0;
        int armour = 0;                 // acts like "bonus" health protects officers
        int fuel = 0;
        int food = 0;
        int agility = 0;
        int speed = 0;
        int resources = 0;              //for payership will cap out based on cargoCapacity
        int money = 0;
        int lowmin = 0;
        //used in ship setup
        int lowmax = 40;
        int midmin = 41;
        int midmax = 70;
        int highmin = 71;
        int highmax = 100;
    public:
        /*
            raising any stats should only occur through the abilities that 
            are availble to use on the ship e.g. attempSystemRecovery is the only way
            to raise health, shields and armour.  
        */
        SpaceShip();
        #pragma region //getters and display
        int getStrength();
        int getHealth();
        int getShield();
        int getArmour();
        int getFuel();
        int getFood();
        int getAgility();
        int getSpeed();
        int getResources();
        int getMoney();
        void displaySpaceShip();
        #pragma endregion 
    private:
};

class SpaceShipEncounter : public SpaceShip, public SpaceSector {
    public:
        SpaceShipEncounter();
        void takeDamage(int damage);
    private:
        //setup based on race
        void solarisShipSetup();
        void scarShipSetup();
        void celestialShipSetup();
        void galvamekShipSetup();
        void humanShipSetup();

};

class Playership : public SpaceShip{
    /* 
        Core Stats: based on rng and shipType(strength, health, shield, armour, fuel, food, agility, speed, resources, money, crew, cargoCapacity, miningPower, fuelEfficiency)
        Ability Stats: based on officier skill level and rank
    */
    protected:
        int crew = 0;
        int cargoCapacity = 0;
        int miningPower = 0;
        int fuelEfficiency = 0;
        int defesiveAbilityLevel = 0;
        std::string shipType = "";
        std::vector<Officer> officers;
        std::vector<Officer> deadofficers;
        //Setup variables
        int lowmin = 0;
        int lowmax = 40;
        int midmin = 40;
        int midmax = 70;
        int highmin = 70;
        int highmax = 100;
        //SCOREBOARD STATS
        //most of the ships resource based values, number of sectors travelled
        int asteriodBeltsPassedScore = 0;
        int tradeStationVisitsScore = 0;
        int emptySectorsPassedScore = 0;
        int successfulTradesScore = 0;
        int successfulMinesScore = 0;
        int deadCrewMembersScore = 0;
        int shipEncountersScore = 0;
        int planetsVisitedScore = 0;
        int shipsDestroyedScore = 0;
        int crewPickedUpScore = 0;
        int moneyEarnedScore = 0;
    public:
        Playership();
        Playership(std::vector<Officer>& officers);
        Playership(std::string type, std::vector<Officer> officers);
        void displayPlayership();
        void getLoot();
        std::string getShipType();
        std::vector<Officer> getOfficers();
        void explode(std::string dmgSource);                    
        bool useTrade(SpaceSector &trader);                     //use captain, rng chance of success
        void useSystemsRecovery();                              //use engineer, activates on travel
        bool useDiplomacy(SpaceSector &aggressor);              //use captain, targets diplomacy stat, check skillevel, rng chance of success
        bool useTravel();                                       //use pilot, engineer, attempSystemsRecovery(),
        bool useCombatManuver(int offensiveAbilityLevel);       //use pilot, engineer, takes attackers combat manuver and offensive performance stat
        bool useEscape(SpaceShipEncounter &attack);             //use engineer, pilot, speed, agility, takes attacker's speed
        void useMine(PlanetEncounter &target);                  //use miner stats.
        bool useAttack(SpaceShipEncounter &target);             //uses weaponsSmith and pilot, takes targets defensive stats.
        bool takeDamageFrom(int offensiveAbilityLevel, int strength, std::string dmgSource);
        bool flyThroughAsteriodBelt();                          //uses pilot
        Officer& findOfficer(std::string job);                  //returns an unusable officer of job "none" if it cannot find the officer required
        //SCOREBOARD STATS ships resource based values, number of sectors travelled
        void asteriodBeltsPassed();
        void tradeStationVisits();
        void emptySectorsPassed();
        void successfulTrades();
        void successfulMines();
        void deadCrewMembers();
        void shipEncounters();
        void planetsVisited();
        void shipsDestroyed();
        void crewPickedUp();
        void moneyEarned(int amount);
        void showScores();
    private:
        void recalculateDefense();                              //use weaponsSmith and engineer, occurs on initialisation and if the either the weaponsSmith dies or an Engineer dies.
        void setupShip();
        void OffensiveSetup();
        void MinerSetup();
        void DefensiveSetup();
        void OneHitSetup();
        void AverageSetup();
        void addToCrew();                                       
        void damageCrew();                                      
        void addResources(int amount);
        bool addOfficer(Officer newOfficer, int index);         
        void checkForDead();                    
        void checkFood();
        bool hasFuel();
};

#endif

