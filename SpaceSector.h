#ifndef spacesector_h
#define spacesector_h
#include <iostream>
#include <string>
#include <vector>

class Race //COMPLETE
{
    int combatManuverabilityLevel;
    int offensiveAbilityLevel;
    int defesiveAbilityLevel;
    int systemsRecoveryLevel;
    int evasionAbilityLevel;
    int tradabilityLevel;
    int diplomacyLevel;
    std::string type;
    int lowmin = 0;
    int lowmax = 40;
    int midmin = 41; 
    int midmax = 70;
    int highmin = 71; 
    int highmax = 100;
    public:
        Race();
        Race(std::string type);
        int getCombatManuverabilityLevel(); 
        int getTravelEfficiencyLevel();
        int getOffensiveAbilityLevel();
        int getDefesiveAbilityLevel();
        int getSystemsRecoveryLevel();
        int getEvasionAbilityLevel();
        int getMiningAbilityLevel();
        int getTradabilityLevel();
        int getDiplomacyLevel();
        std::string getType();
    private:
        void setupStats(std::string type);
        void  hostileSetup();
        void  minerSetup();
        void  passiveSetup();
        void  defensiveSetup();
        void  averageSetup();

};

class SpaceSector //COMPLETE
{
    protected:
        Race race;
        std::string type;
        static int sectorCount; //constant
    public:
        SpaceSector();//sectorCount auto incremented
        SpaceSector(Race race, std::string type);
        Race getRace();
        std::string getType();
        static int getSecotorCount();
};

//INCOMPLETE
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
