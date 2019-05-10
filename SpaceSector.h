#ifndef spacesector_h
#define spacesector_h
#include <iostream>
#include <string>
#include <vector>
class Race
{
    int diplomacyLevel, tradabilityLevel, travelEfficiencyLevel, combatManuverabilityLevel, evasionAbilityLevel, defesiveAbilityLevel, systemsRecoveryLevel, miningAbilityLevel, offensiveAbilityLevel;
    std::string race, type;
    public:
        Race();
        Race(int diploLvl, int tradeLvl, int  travelEffLvl, int  combatManuLvl, int  evasionLvl, int  defLvl, int sysRecoverLvl, int  mineLvl, int offLvl);
};

class SpaceSector
{
    Race race;
    std::string type;
    int sectorCount; //constant
    public:
        SpaceSector();//sectorCount auto incremented
        SpaceSector(Race reace, std::string type);
};

class SpaceshipEncounter : public SpaceSector
{
};

class PlanetEncounter : public SpaceSector
{

    public:
        PlanetEncounter();
};

class TradingStation : public SpaceSector
{

    public:
        TradingStation();
};

class AsteriodBelt : public SpaceSector
{
    int resources, damage;
    public: 
        AsteriodBelt();        //should easily be created without need for parameters
    private:
        void calculateStats(); //based on the current sectorcount, higher sectors mean higher damamge but more resources
};

class EmptySector : public SpaceSector
{
    public:
        EmptySector();      //do nothing
};
#endif

//TODO:
/*
- Interface Behaviours for trading
- POSSIBLE behaviours for combat
*/