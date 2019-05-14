#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "SpaceShip.h"
#include "functions.h"

SpaceShip::SpaceShip(){
    std::cout << "SpaceShip constructor\n";
    fuel = 50;
    food = 50;
    resources = 50;
    money = 50;
}
#pragma region //getters
int SpaceShip::getStrength(){
    return this->strength;
}
int SpaceShip::getHealth() {
    return this->health;
}
int SpaceShip::getShield() {
    return this->shield;
}
int SpaceShip::getArmour() {
    return this->armour;
}
int SpaceShip::getFuel() {
    return this->fuel;
}
int SpaceShip::getFood() {
    return this->food;
}
int SpaceShip::getAgility() {
    return this->agility;
}
int SpaceShip::getSpeed() {
    return this->speed;
}
int SpaceShip::getResources() {
    return this->resources;
}
int SpaceShip::getMoney() {
    return this->money;
}
#pragma endregion

void SpaceShip::displaySpaceShip(){
    std::cout << std::left << std::setw(12) << "Strength: " << std::left << std::setw(12) << this->strength;
    std::cout << std::left << std::setw(12) << "Health: " << std::left << std::setw(12) << this->health << '\n';
    std::cout << std::left << std::setw(12) << "Shield: " << std::left << std::setw(12) << this->shield;
    std::cout << std::left << std::setw(12) << "Armour: " << std::left << std::setw(12) << this->armour << '\n'; //"bonus" health protects officers
    std::cout << std::left << std::setw(12) << "Fuel: " << std::left << std::setw(12) << this->fuel;
    std::cout << std::left << std::setw(12) << "Food: " << std::left << std::setw(12) << this->food << '\n';
    std::cout << std::left << std::setw(12) << "Agility: " << std::left << std::setw(12) << this->agility;
    std::cout << std::left << std::setw(12) << "Speed: " << std::left << std::setw(12) << this->speed << '\n';
    std::cout << std::left << std::setw(12) << "Resources: " << std::left << std::setw(12) << this->resources;
    std::cout << std::left << std::setw(12) << "Money: " << std::left << std::setw(12) << this->money << "\n\n";
}

SpaceShipEncounter::SpaceShipEncounter(){
    std::cout << "SpaceShipEncounter constructor\n";
    this->type = "SpaceShipEncounter";
    if (this->getRace().getType() == "Solaris")
    {
        solarisShipSetup();
    }
    else if (this->getRace().getType() == "Scar")
    {
        scarShipSetup();
    }
    else if (this->getRace().getType() == "Celestial")
    {
        celestialShipSetup();
    }
    else if (this->getRace().getType() == "Galvamek")
    {
        galvamekShipSetup();
    }
    else if (this->getRace().getType() == "Human")
    {
        humanShipSetup();
    } else {
        std::cerr << "ERROR: no race type found\n";
    }
}

#pragma region//TODO: Setup raceshiptypes
void SpaceShipEncounter::celestialShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(lowmin, lowmax);
}
void SpaceShipEncounter::galvamekShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(lowmin, lowmax);
}
void SpaceShipEncounter::solarisShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(lowmin, lowmax);
}
void SpaceShipEncounter::humanShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(lowmin, lowmax);
}
void SpaceShipEncounter::scarShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(lowmin, lowmax);
}
#pragma endregion

Playership::Playership() {
    std::cout << "Playership constructor\n";
    int crew = 0;
    int cargoCapacity = 0; //out of 100
    int mainingPower = 0;  // out of 100
    int fuelEfficiency = 0; //out of 10
    std::string shipType = "Jack";

}

Playership::Playership(std::vector<Officer> officers){
    std::cout << "Playership constructor\n";
    //sets up ship internally
    this->shipType = determineShipType();
    this->officers = officers; //TODO: Global function that sets all the officers
    setupShip();
}

Playership::Playership(std::string type, std::vector<Officer> officers){//if you would like to run a specific ship rather than a random one.
    std::cout << "Playership constructor\n";
    //sets up ship based from external influence
    this->shipType = type;
    this->officers = officers;
    setupShip();
}

void Playership::displayPlayership(){//INCOMPLETE
    displaySpaceShip();
    std::cout << std::left << std::setw(12) << "cargoCap:" << std::left << std::setw(12) << this->cargoCapacity;
    std::cout << std::left << std::setw(12) << "miningPow:" << std::left << std::setw(12) << this->miningPower << '\n';
    std::cout << std::left << std::setw(12) << "fuelEff:" << std::left << std::setw(12) << this->fuelEfficiency;
    std::cout << std::left << std::setw(12) << "diplomacyLvl:" << std::left << std::setw(12) << this->diplomacyLevel << '\n';
    std::cout << std::left << std::setw(12) << "tradeLvl:" << std::left << std::setw(12) << this->tradabilityLevel;
    std::cout << std::left << std::setw(12) << "travelEffLvl:" << std::left << std::setw(12) << this->travelEfficiencyLevel << '\n';
    std::cout << std::left << std::setw(12) << "combatManuverLvl:" << std::left << std::setw(12) << this->combatManuverabilityLevel;
    std::cout << std::left << std::setw(12) << "evasionLvl:" << std::left << std::setw(12) << this->evasionAbilityLevel << '\n';
    std::cout << std::left << std::setw(12) << "defesiveLvl:" << std::left << std::setw(12) << this->defesiveAbilityLevel;
    std::cout << std::left << std::setw(12) << "sysRecoveryLvl:" << std::left << std::setw(12) << this->systemsRecoveryLevel << '\n';
    std::cout << std::left << std::setw(12) << "miningLvl:" << std::left << std::setw(12) << this->miningAbilityLevel;
    std::cout << std::left << std::setw(12) << "offensiveLvl:" << std::left << std::setw(12) << this->offensiveAbilityLevel << '\n';
    std::cout << std::left << std::setw(12) << "crew:"<< std::left << std::setw(12)  << this->crew;
    std::cout << std::left << std::setw(12) << "shipType: " << std::left << std::setw(12) << this->shipType << '\n';
    std::cout << "displaying officers:\n";
    //dont use for each loop
}

void Playership::setupShip(){
    if (this->shipType == "Dawn Sailor"){
        OffensiveSetup();
    }else if (this->shipType == "Scavenger"){
        MinerSetup();
    }else if (this->shipType == "Nebula"){
        DefensiveSetup();
    }else if (this->shipType == "ONE-HIT-WONDER"){
        OneHitSetup();
    }else if (this->shipType == "Jack"){
        AverageSetup();
    }
}

bool Playership::useDiplomacy(SpaceSector &aggressor){
    Officer captain = findOfficer("captain");
    int capLvl = captain.getSkillLevel();
    int chance = (capLvl + aggressor.getRace().getDiplomacyLevel())/2;
    if (chance >= randNumGen(0,100)){
        std::cout << "negotiations are being attempted\n"; 
        if (this->money > 10 && this->resources > 10){
            money -= 10;
            resources -= 10;
            std::cout << "negotiations successful!\n";
            return true;
        } else {
            std::cout << "negotiations failed, you didnt have enough resources!\n";
            return false;
        }
    }
    std::cout << "negotiations failed!!\n";
    return false;
}

void Playership::useTrade(SpaceSector &trader){ //only works with planets and trading stations
    Officer captain = findOfficer("captain");
    int capLvl = captain.getSkillLevel();
    int chance = (capLvl + trader.getRace().getTradabilityLevel())/2;
    if (chance >= randNumGen(0,100)){
        std::cout << "attempting to trade\n";
        if (this->food <= 10 && this->money >= 10){
            std::cout << "buying food\n";
            this->money -= 10;
            this->food += 10;
        } else if (this->money < 10){
            std::cout << "no money to buy food\n";
        } else if (this->food >= 10){
            std::cout << "no need to buy food\n";
        }
        std::cout << "topping fuel up\n";
        this->fuel += 20;
    }
    std::cout << "failed to trade\n";
}
bool Playership::hasFuel(){
    if (this->fuel > 0){
        return true;
    }
    return false;
}

bool Playership::useTravel() {//USED IN FUNCTIONS.CPP/H
    //get appropriate stats
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    //determine fuel and food costs(if there is no food left then all officers take famine damage)
    int chance = (pilotLvl + engiLvl + this->fuelEfficiency)/3;
    if (chance >= randNumGen(0,100)){
        fuel -= 1;
        food -= 1;
        std::cout << "Travel used. Fuel and Food lowered by 1 to: " << this->fuel << " and " << this->food << ".\n";
        addToCrew();
        return hasFuel();
    } else {
        fuel -= 5;
        food -= 5;
        std::cout << "Travel used. Fuel and Food lowered by 5 to: " << this->fuel << " and " << this->food << ".\n";
        addToCrew();
        return hasFuel();
    }
}

bool Playership::useEscape(SpaceShipEncounter &attacker) {//TBU IN FUNCTIONS if HP is low then attemp escape, if that fails then takeDamage();
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int chance = (engiLvl + pilotLvl + this->speed + this->agility - (attacker.getRace().getOffensiveAbilityLevel())) / 3;
    if (chance >= randNumGen(0, 100))
    {
        std::cout << "attemping escape\n";
        return hasFuel();
    }
    std::cout << "escape failed\n";
    return false;
}

bool Playership::useCombatManuver(SpaceShipEncounter &attacker){//used in takeDamage()
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int chance = (engiLvl + pilotLvl + this->agility + this->speed - attacker.getRace().getOffensiveAbilityLevel())/3;
    if (chance >= randNumGen(0,100)){
        std::cout << "Attack was successfully evaded.\n";
        return true;
    }
    std::cout << "Unable to evade attack. \n";
    return false;
}

bool Playership::takeDamageFrom(SpaceShipEncounter &attacker) {//TBU IN FUNCTIONS
    //determine damage taken
    int damage = (attacker.getRace().getOffensiveAbilityLevel() + attacker.getStrength() - this->defesiveAbilityLevel) / 2;
    //attempt to avoid / take damage
    if (useCombatManuver(attacker))
    {
        //successful evasion
        damage = 0;
    }
    if (shield <= 0 && armour <= 0)
    {
        //deal damage to ship
        this->health -= damage;
        //deal damamge to officers
        for (int i = 0; i < officers.size(); i++)
        {
            officers[i].takeDamage(damage);
        }
        //rng kill off crew :(
        damageCrew();
        //check for dead (if dead replace)
        checkForDead();
    } else { //deal damage only to ship
        this->shield -= damage;
        this->armour -= damage;
    }
    std::cout << "ship has taken damage\n";
}

void Playership::checkForDead(){ //used in takeDamage();
    for (int i = 0; i < officers.size(); i++){
        Officer temp = officers[i];
        if (temp.getIsDead()){
            if (crew > 0){
                //create new officer of lesser skill
                Officer newOfficer(temp.getJob(), randNumGen(0, temp.getSkillLevel()));
                //move dead officer into deadOfficers list
                this->deadofficers.push_back(temp);
                this->officers.erase(officers.begin() + i);
                addOfficer(newOfficer);
                if (newOfficer.getJob()== "engineer" || newOfficer.getJob() == "weapons"){
                    recalculateDefense();
                }
            }
        }
    }
}

int Playership::addOfficer(Officer newOfficer){// used in checkForDead()
    for (Officer currOfficer : this->officers)
    {
        if (newOfficer.getJob() == currOfficer.getJob() && !currOfficer.getIsDead())
        {
            std::cerr << "Error: there is already an officer in this position\n";
            return 0;
        }
    }
    officers.push_back(newOfficer);
    std::cout << "new officer added\n";
    return 0;
}

void Playership::useSystemsRecovery(){
    int engiLvl = findOfficer("engineer").getSkillLevel();
    if (engiLvl >= randNumGen(0,100)){
        this->health += engiLvl;
        this->shield += engiLvl;
        this->armour += engiLvl/4;
        std::cout << "successful repairs\n";
    }
}

void Playership::useMine(PlanetEncounter &planet){
    int minerLvl = findOfficer("miner").getSkillLevel();
    int chance = (minerLvl + this->miningPower)/1.5;
    if (chance >= randNumGen(0,100)){
        if (resources + 10 > this->cargoCapacity){
            this->resources = this->cargoCapacity;
            std::cout << "successful mine! you've maxed out cargoCapacity.\n";
        } else {
            this->resources += 10;
            std::cout << "successful mine! you've gained 10 resources.\n";
        }
    } else {
        std::cout << "mine failed...\n";
    }
    
}

bool Playership::useAttack(SpaceShipEncounter &target){
    int weaponLvl = findOfficer("weapons").getSkillLevel() + this->strength;
    int chance = (weaponLvl - target.getRace().getCombatManuverabilityLevel())/1.5;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful attack\n";
        return true;
    }
    std::cout << "attack failed\n";
    return false;
}

void Playership::recalculateDefense(){ //used after addOfficer and officer is of job "engi" or "weapons" 
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int weaponsLvl = findOfficer("weapons").getSkillLevel();
    int chance = (engiLvl + weaponsLvl)/2;
    if (chance >= randNumGen(0,100)){
        this->defesiveAbilityLevel = chance;
        std::cout << "new defesive ability level hsa been set to: " << chance << '\n';
    }
    
}

void Playership::addToCrew(){ 
    std::cout << "testing add to crew \n";
    if (50 >= randNumGen(0,100)){
        std::cout << "your ship has picked up a new crew member\n";
        this->crew++;
    }
}

void Playership::damageCrew(){// used in takeDamage
    if (50 >= randNumGen(0,100)){
        std::cout << "a crew member has died\n";
        this->crew--;
    }
}

Officer Playership::findOfficer(std::string job){//used most abilities
    Officer temp("none", 0);

    for (Officer currOfficer: this->officers){
        if(currOfficer.getJob() == job && !currOfficer.getIsDead()){
            std::cout << "officer found\n";
            return currOfficer;
        }
    }

    std::cerr << "There is currently no " << job << " on the ship! \n";
    return temp;
}

void Playership::OffensiveSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(40, 70);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(70, 100);
    this->armour = randNumGen(70, 100);
    this->strength = randNumGen(70, 100);
    this->miningPower = randNumGen(0, 40);
    this->cargoCapacity = randNumGen(0, 40);
    this->fuelEfficiency = randNumGen(40, 70);
}

void Playership::MinerSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(0, 40);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(40, 70);
    this->armour = randNumGen(0, 40);
    this->strength = randNumGen(40, 70);
    this->miningPower = randNumGen(70, 100);
    this->cargoCapacity = randNumGen(70, 100);
    this->fuelEfficiency = randNumGen(70, 100);
}

void Playership::DefensiveSetup(){
    this->speed = randNumGen(70, 100);
    this->shield = randNumGen(70, 100);
    this->agility = randNumGen(70, 100);
    this->health = randNumGen(70, 100);
    this->armour = randNumGen(70, 100);
    this->strength = randNumGen(0, 40);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}

void Playership::OneHitSetup(){
    this->speed = randNumGen(70, 100);
    this->shield = randNumGen(70, 100);
    this->agility = randNumGen(70, 100);
    this->health = 1;
    this->armour = randNumGen(40, 70);
    this->strength = randNumGen(90, 100);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}
    
void Playership::AverageSetup(){
    this->speed = randNumGen(40, 70);
    this->shield = randNumGen(40, 70);
    this->agility = randNumGen(40, 70);
    this->health = randNumGen(40, 70);
    this->armour = randNumGen(40, 70);
    this->strength = randNumGen(40, 70);
    this->miningPower = randNumGen(40, 70);
    this->cargoCapacity = randNumGen(40, 70);
    this->fuelEfficiency = randNumGen(40, 70);
}


