#ifndef functions_h
#define functions_h
#include <iostream>
#include <string>
#include <vector>
                            /************************************************************************************************************************
                             *                                                      TODO
                             * - Complete Class Forward Definition (getters and setters, functions and implementation, constructors and deconstructors)
                             * - Space Sector Interface Methods 
                             * - Everything else.
                             * 
                             * 
                             * 
                             * **********************************************************************************************************************//
class Officer
{
    std::string name, rank, job;
    int age, health, skillLevel;
    bool isDead;
    public:
      void displayOfficer();                    //used durring simluation
      bool isDead();                            //used for documenting purposes and in checking officiers
      int getAge();                             //used for documenting purposes
      int getHealth();                          //used for documenting purposes
      int getSkillLevel();                      //used for documenting purposes
      std::string getName();                    //used for documenting purposes
      std::string getRank();                    //used to determine what ability stats are affected
      std::string getJob();                     //used to determine what ability stats are affected
      void recieveDamage(int damage);           //checks if damage is > 0 and if officer will take extra damage, if health is <= 0 after taking damage then use hasDied().
      void restoreHealth();                     //when systems recovery is used
      void levelUpSkill();                      //when enemies are defeated
    private:
        void hasDied();                         //set isDead to true, ship will check for dead after takeDamageFrom func, if there is dead it will promote a crew member and give appropriate stats and rank.
        void rankUp();                          //if skill level >50, >75 >99 rank up change rank
        void healthFortuna();                   //based on skillLevel and rank, higher = higher chance of bonus health resorted from systemRecovery and from visiting trading stations
        bool skillFortuna();                    //10% chance of getting skill level boost, after surviving combat (when using escape or after enemey is destroyed)
        bool rankFortuna();                     //3% chance of ranking up, after surviving combat (when using escape or after enemey is destroyed)
};

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

class Race
{
  private:
    int diplomacyLevel, tradabilityLevel, travelEfficiencyLevel, combatManuverabilityLevel, evasionAbilityLevel, defesiveAbilityLevel, systemsRecoveryLevel, miningAbilityLevel, offensiveAbilityLevel;
    std::string race, type;
};

class SpaceSector
{
    Race race;
    std::string type;
    int sectorCount; //constant
};

class SpaceshipEncounter : public SpaceSector
{
};

class PlanetEncounter : public SpaceSector
{
};

class TradingStation : public SpaceSector
{
};

class AsteriodBelt : public SpaceSector
{
};

class EmptySector : public SpaceSector
{
};

#endif