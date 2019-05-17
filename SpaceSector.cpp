#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "SpaceSector.h"
#include "functions.h"

Race::Race(){//default constructor to randomly set race
    this->type = determineRaceType();
    setupStats(type);
}

Race::Race(std::string rType){//the spacesector was given a specific race setting
    setupStats(rType);
}

void Race::setupStats(std::string rType){//sets up the race stats based on type
    if (rType == "Solaris"){
        hostileSetup();
    }else if (rType == "Scar"){
        minerSetup();
    }else if (rType == "Celestial"){
        passiveSetup();
    }else if (rType == "Galvamek"){
        defensiveSetup();
    }else if (rType == "Human"){
        averageSetup();
    }
}

void Race::displayRace(){//displays race stats
    std::cout << std::left << std::setw(12) << "dodgeLvl:" << std::left << std::setw(12) << this->combatManuverabilityLevel << '\n';
    std::cout << std::left << std::setw(12) << "offensiveLvl:" << std::left << std::setw(12) << this->offensiveAbilityLevel;
    std::cout << std::left << std::setw(12) << "defesiveLvl:" << std::left << std::setw(12) << this->defesiveAbilityLevel << '\n';
    std::cout << std::left << std::setw(12) << "sysRecoveryLvl:" << std::left << std::setw(12) << this->systemsRecoveryLevel;
    std::cout << std::left << std::setw(12) << "evasionLvl:" << std::left << std::setw(12) << this->evasionAbilityLevel << '\n';
    std::cout << std::left << std::setw(12) << "tradeLvl:" << std::left << std::setw(12) << this->tradabilityLevel;
    std::cout << std::left << std::setw(12) << "diplomacyLvl:" << std::left << std::setw(12) << this->diplomacyLevel << '\n';
}

#pragma region //race stat setup
void Race::hostileSetup(){
    this->combatManuverabilityLevel = randNumGen(highmin, highmax);
    this->offensiveAbilityLevel = randNumGen(highmin, highmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(midmin, midmax);
    this->evasionAbilityLevel = randNumGen(lowmin, lowmax);
    this->tradabilityLevel = randNumGen(lowmin, lowmax);
    this->diplomacyLevel = randNumGen(0,9);
}
void Race::minerSetup(){
    this->combatManuverabilityLevel = randNumGen(lowmin, lowmax);
    this->offensiveAbilityLevel = randNumGen(lowmin, lowmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(highmin, highmax);
    this->evasionAbilityLevel = randNumGen(lowmin, lowmax);
    this->tradabilityLevel = randNumGen(highmin, highmax);
    this->diplomacyLevel = randNumGen(midmin, midmax);
}
void Race::passiveSetup(){
    this->combatManuverabilityLevel = randNumGen(midmin, midmax);
    this->offensiveAbilityLevel = randNumGen(0, 0);
    this->defesiveAbilityLevel = randNumGen(midmin,midmax);
    this->systemsRecoveryLevel = randNumGen(highmin, highmax);
    this->evasionAbilityLevel = randNumGen(highmin,highmax);
    this->tradabilityLevel = randNumGen(highmin,highmax);
    this->diplomacyLevel = randNumGen(highmin,highmax);
}
void Race::defensiveSetup(){
    this->combatManuverabilityLevel = randNumGen(midmin,midmax);
    this->offensiveAbilityLevel = randNumGen(midmin,midmax);
    this->defesiveAbilityLevel = randNumGen(highmin,highmax);
    this->systemsRecoveryLevel = randNumGen(highmin,highmax);
    this->evasionAbilityLevel = randNumGen(midmin,midmax);
    this->tradabilityLevel = randNumGen(lowmin,lowmax);
    this->diplomacyLevel = randNumGen(midmin,midmax);
}
void Race::averageSetup(){
    this->combatManuverabilityLevel = randNumGen(midmin, midmax);
    this->offensiveAbilityLevel = randNumGen(midmin, midmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(midmin, midmax);
    this->evasionAbilityLevel = randNumGen(midmin, midmax);
    this->tradabilityLevel = randNumGen(midmin, midmax);
    this->diplomacyLevel = randNumGen(midmin, midmax);
}

int Race::getCombatManuverabilityLevel(){
    return this->combatManuverabilityLevel;
}

int Race::getOffensiveAbilityLevel(){
    return this->offensiveAbilityLevel;
}

int Race::getDefesiveAbilityLevel(){
    return this->defesiveAbilityLevel;
}

int Race::getSystemsRecoveryLevel(){
    return this->systemsRecoveryLevel;
}

int Race::getEvasionAbilityLevel(){
    return this->evasionAbilityLevel;
}

int Race::getTradabilityLevel(){
    return this->tradabilityLevel;
}

int Race::getDiplomacyLevel(){
    return this->diplomacyLevel;
}

std::string Race::getType(){
    return this->type;
}

void Race::setOffensiveAbilityLevel(int level){
    this->offensiveAbilityLevel = level;
}
#pragma endregion

SpaceSector::SpaceSector(){//default constructor
    SpaceSector::sectorCount++;
}

void SpaceSector::displaySpaceSector(){//displays basic stats
    std::cout << "Race: " << this->race.getType() << '\n';
    this->race.displayRace();
    std::cout << "Sector Type: " << this->type << '\n';
}

#pragma reigon //getters
Race SpaceSector::getRace(){
    return this->race;
}

std::string SpaceSector::getType(){
    return this->type;
}
#pragma endregion

//PLANET ENCOUNTER CLASS FUNCTIONS
PlanetEncounter::PlanetEncounter() : SpaceSector(){
    this->type = "PlanetEncounter";
}

void PlanetEncounter::displayPlanet(){
    displaySpaceSector();
}

//TRADING STATION CLASS FUNCTIONS
TradingStation::TradingStation() : SpaceSector(){
    this->type = "TradingStation";
}

void TradingStation::displayStation(){
    displaySpaceSector();
}

//ASTERIOD BELT CLASS FUNCTIONS
AsteriodBelt::AsteriodBelt() : SpaceSector(){
    this->type = "AsteriodBelt";
    this->race.setOffensiveAbilityLevel(9999); //cannot out manuver an asteriod belt if the pilot fails to fly through
    this->strength *= (SpaceSector::getSectorCount()/2); //asteriiod belts become stronger in higher sector counts
}

void AsteriodBelt::displayAsteriodBelt(){
    displaySpaceSector();
}

int AsteriodBelt::getStrength(){
    return this->strength;
}




