#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "SpaceSector.h"
#include "functions.h"

Race::Race(){
    std::cout << "Race constructor internal type\n";
    this->type = determineRaceType();
    setupStats(type);
}

Race::Race(std::string type){
    std::cout << "Race constructor external type\n";
    setupStats(type);
}

void Race::setupStats(std::string type){
    std::cout << "setting up race stats\n";
    if (type == "Solaris"){
        hostileSetup();
    }else if (type == "Scar"){
        minerSetup();
    }else if (type == "Celestial"){
        passiveSetup();
    }else if (type == "Galvamek"){
        defensiveSetup();
    }else if (type == "Human"){
        averageSetup();
    }
}

void Race::displayRace(){
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
    std::cout << "setting up hostile race stats\n";
    this->combatManuverabilityLevel = randNumGen(highmin, highmax);
    this->offensiveAbilityLevel = randNumGen(highmin, highmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(midmin, midmax);
    this->evasionAbilityLevel = randNumGen(lowmin, lowmax);
    this->tradabilityLevel = randNumGen(lowmin, lowmax);
    this->diplomacyLevel = randNumGen(lowmin, lowmax);
}
void Race::minerSetup(){
    std::cout << "setting up miner race stats\n";
    this->combatManuverabilityLevel = randNumGen(lowmin, lowmax);
    this->offensiveAbilityLevel = randNumGen(lowmin, lowmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(highmin, highmax);
    this->evasionAbilityLevel = randNumGen(lowmin, lowmax);
    this->tradabilityLevel = randNumGen(highmin, highmax);
    this->diplomacyLevel = randNumGen(midmin, midmax);
}
void Race::passiveSetup(){
    std::cout << "setting up passive race stats\n";
    this->combatManuverabilityLevel = randNumGen(midmin, midmax);
    this->offensiveAbilityLevel = randNumGen(lowmin, lowmax);
    this->defesiveAbilityLevel = randNumGen(midmin,midmax);
    this->systemsRecoveryLevel = randNumGen(highmin, highmax);
    this->evasionAbilityLevel = randNumGen(highmin,highmax);
    this->tradabilityLevel = randNumGen(highmin,highmax);
    this->diplomacyLevel = randNumGen(highmin,highmax);
}
void Race::defensiveSetup(){
    std::cout << "setting up defensive race stats\n";
    this->combatManuverabilityLevel = randNumGen(midmin,midmax);
    this->offensiveAbilityLevel = randNumGen(midmin,midmax);
    this->defesiveAbilityLevel = randNumGen(highmin,highmax);
    this->systemsRecoveryLevel = randNumGen(highmin,highmax);
    this->evasionAbilityLevel = randNumGen(midmin,midmax);
    this->tradabilityLevel = randNumGen(lowmin,lowmax);
    this->diplomacyLevel = randNumGen(midmin,midmax);
}
void Race::averageSetup(){
    std::cout << "setting up average race stats\n";
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
#pragma endregion

SpaceSector::SpaceSector(){
    std::cout << "SpaceSector constructor\n";
    SpaceSector::sectorCount++;
}

void SpaceSector::displaySpaceSector(){
    std::cout << "Race: " << this->race.getType() << '\n';
    this->race.displayRace();
    std::cout << "Sector Type: " << this->type << '\n';
}

Race SpaceSector::getRace(){
    return this->race;
}

std::string SpaceSector::getType(){
    return this->type;
}

PlanetEncounter::PlanetEncounter() : SpaceSector(){
    this->type = "PlanetEncounter";
}

