#include <iostream>
#include <string>
#include <vector>
#include "SpaceSector.h"
#include "SpaceShip.h"
#include "functions.h"

Race::Race(){
    this->combatManuverabilityLevel = 50; 
    this->offensiveAbilityLevel = 50;
    this->defesiveAbilityLevel = 50;
    this->systemsRecoveryLevel = 50;
    this->evasionAbilityLevel = 50;
    this->tradabilityLevel = 50;
    this->diplomacyLevel = 50;
    this->type = "constructor";
}

Race::Race(std::string type){
    setupStats(type);
}

void Race::setupStats(std::string type){
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

void Race::hostileSetup(){
    this->combatManuverabilityLevel = randNumGen(highmin, highmax);
    this->offensiveAbilityLevel = randNumGen(highmin, highmax);
    this->defesiveAbilityLevel = randNumGen(midmin, midmax);
    this->systemsRecoveryLevel = randNumGen(midmin, midmax);
    this->evasionAbilityLevel = randNumGen(lowmin, lowmax);
    this->tradabilityLevel = randNumGen(lowmin, lowmax);
    this->diplomacyLevel = randNumGen(lowmin, lowmax);
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
    this->offensiveAbilityLevel = randNumGen(lowmin, lowmax);
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
    this->combatManuverabilityLevel;
}

int Race::getOffensiveAbilityLevel(){
    this->offensiveAbilityLevel;
}

int Race::getDefesiveAbilityLevel(){
    this->defesiveAbilityLevel;
}

int Race::getSystemsRecoveryLevel(){
    this->systemsRecoveryLevel;
}

int Race::getEvasionAbilityLevel(){
    this->evasionAbilityLevel;
}

int Race::getTradabilityLevel(){
    this->tradabilityLevel;
}

int Race::getDiplomacyLevel(){
    this->diplomacyLevel;
}

std::string Race::getType(){
    this->type;
}


SpaceSector::SpaceSector(){

}

PlanetEncounter::PlanetEncounter() : SpaceSector(){

}