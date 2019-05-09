#ifndef spacesector_h
#define spacesector_h
//#include "functions.h"
//#include "Officer.h"
//#include "SpaceShip.h"
#include <iostream>
#include <string>
#include <vector>
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

//TODO:
/*
- Nothing to see here
*/