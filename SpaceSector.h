#ifndef spacesector_h
#define spacesector_h
#include <iostream>
#include <string>
#include <vector>

class Race {
    int combatManuverabilityLevel = 0;
    int offensiveAbilityLevel = 0;
    int defesiveAbilityLevel = 0;
    int systemsRecoveryLevel = 0;
    int evasionAbilityLevel = 0;
    int tradabilityLevel = 0;
    int diplomacyLevel = 0;
    public:
    std::string type = "";
    private:
    //setup stats
    int lowmin = 0;
    int lowmax = 40;
    int midmin = 40; 
    int midmax = 70;
    int highmin = 70; 
    int highmax = 100;
    public:
        Race();
        Race(std::string type);
        void displayRace();
        int getCombatManuverabilityLevel(); 
        int getTravelEfficiencyLevel();
        int getOffensiveAbilityLevel();
        int getDefesiveAbilityLevel();
        int getSystemsRecoveryLevel();
        int getEvasionAbilityLevel();
        int getMiningAbilityLevel();
        int getTradabilityLevel();
        int getDiplomacyLevel();
        void setOffensiveAbilityLevel(int level);
        std::string getType();
    private:
        void setupStats(std::string type);
        void  hostileSetup();
        void  minerSetup();
        void  passiveSetup();
        void  defensiveSetup();
        void  averageSetup();

};

class SpaceSector {
    protected:
        Race race;
        std::string type = "SpaceSector";
    public:
        static int sectorCount;
        SpaceSector();              //sectorCount auto incremented, auto race setup included
        Race getRace();
        std::string getType();
        void displaySpaceSector(); 
        static int getSectorCount(){
            return sectorCount;
        }

};

class PlanetEncounter : public SpaceSector{
    int resources;
    public:
        PlanetEncounter();
        void displayPlanet();
};

class TradingStation : public SpaceSector{
    public:
        TradingStation();
        void displayStation();
};

class AsteriodBelt : public SpaceSector{
    int strength = 10; //will be modified in the constructor to scale with higher space sector counts
    public: 
        AsteriodBelt();       
        void displayAsteriodBelt();
        int getStrength();
};

//empty sector doesnt do anything

#endif

