#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "SpaceShip.h"
#include "functions.h"

SpaceShip::SpaceShip(){
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
    std::cout << std::left << std::setw(12) << "Money: " << std::left << std::setw(12) << this->money << "\n";
}

SpaceShipEncounter::SpaceShipEncounter(){
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

void SpaceShipEncounter::takeDamage(int damage){
    if (this->shield > 0){
        this->shield -= damage;
    } else if (this->shield <= 0 && this->armour > 0){
        this->armour -= damage;
    } else {
        this->health -= damage;
    }

}

#pragma region//TODO: Setup raceshiptypes
void SpaceShipEncounter::celestialShipSetup(){
    this->speed = randNumGen(highmin, highmax);
    this->health = randNumGen(highmin, highmax);
    this->shield = randNumGen(highmin, highmax);
    this->armour = randNumGen(highmin, highmax);
    this->agility = randNumGen(highmin, highmax);
    this->strength = randNumGen(lowmin, lowmax);
}
void SpaceShipEncounter::galvamekShipSetup(){
    this->speed = randNumGen(lowmin, lowmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(highmin, highmax);
    this->armour = randNumGen(highmin, highmax);
    this->agility = randNumGen(lowmin, lowmax);
    this->strength = randNumGen(highmin, highmax);
}
void SpaceShipEncounter::solarisShipSetup(){
    this->speed = randNumGen(midmin, midmax);
    this->health = randNumGen(midmin, midmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(highmin, highmax);
    this->agility = randNumGen(midmin, midmax);
    this->strength = randNumGen(highmin, highmax);
}
void SpaceShipEncounter::humanShipSetup(){
    this->speed = randNumGen(midmin, midmax);
    this->health = randNumGen(midmin, midmax);
    this->shield = randNumGen(midmin, midmax);
    this->armour = randNumGen(midmin, midmax);
    this->agility = randNumGen(midmin, midmax);
    this->strength = randNumGen(midmin, midmax);
}
void SpaceShipEncounter::scarShipSetup(){
    this->speed = randNumGen(highmin, highmax);
    this->health = randNumGen(lowmin, lowmax);
    this->shield = randNumGen(lowmin, lowmax);
    this->armour = randNumGen(lowmin, lowmax);
    this->agility = randNumGen(highmin, highmax);
    this->strength = randNumGen(midmin, midmax);
}
#pragma endregion

Playership::Playership() {
    std::cout << "Playership constructor\n";
    this->crew = 0;
    this->cargoCapacity = 0; //out of 100
    this->miningPower = 0;  // out of 100
    this->fuelEfficiency = 0; //out of 10
    this->shipType = "Jack";

}

Playership::Playership(std::vector<Officer>& officers){
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
    std::cout << std::left << std::setw(12) << "crew:"<< std::left << std::setw(12)  << this->crew;
    std::cout << std::left << std::setw(12) << "shipType: " << std::left << std::setw(12) << this->shipType << '\n';
    std::cout << "\n";
    for (int i = 0; i < officers.size(); i++){
        if (officers[i].getJob() != "none"){
            officers[i].displayOfficer();
        }
    }
    for (int i = 0; i < deadofficers.size(); i++){
        if (deadofficers[i].getJob() != "none"){
            deadofficers[i].displayOfficer();
        }
    }
}

void Playership::setupShip(){
    this->crew = randNumGen(0,20);
    recalculateDefense();
    if (this->shipType == "Dawn Sailor")
    {
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
    int chance = (capLvl + aggressor.getRace().getDiplomacyLevel())%100;
    if (chance >= randNumGen(0,100)){
        return true;
    }
    std::cout << "Negotiations failed";
    return false;
}
//INCOMPLETE: you also need to sell resources for money.
bool Playership::useTrade(SpaceSector &trader){ //only works with planets and trading stations
    Officer captain = findOfficer("captain");
    int capLvl = captain.getSkillLevel();
    int chance = (capLvl + trader.getRace().getTradabilityLevel())/2;
    if (!(trader.getType() == "SpaceShipEncounter" || trader.getType() == "AsteroidBelt")){
        if (chance >= randNumGen(0, 100)){
            std::cout << "Attempting to trade, ";
            if (this->food <= 10 && this->money >= 10){
                std::cout << " buying food, ";
                this->money -= 10;
                this->food += 10;
            }else if (this->money < 10){
                std::cout << "no money to buy food, ";
            }else if (this->food >= 10){
                std::cout << "no need to buy food, ";
            }
            //chance for bonus trade
            if (chance >= randNumGen(0, 100)){
                if (this->resources > 0){
                    std::cout << " the trading station took resources and gave you food and fuel in return, ";
                    this->fuel += 20;
                    this->food += 40;
                    this->resources -= 20;
                }
            }
            std::cout << "topping fuel up. trade complete.\n";
            this->fuel += 20;
            findOfficer("captain").levelUpSkill(10);
            return true;
        }
        std::cout << "Failed to make negotiations to trade\n";
        return false;
    }
    //when trade is not enabled for the sector type
    return false;
}
bool Playership::hasFuel(){
    if (this->fuel > 0){
        return true;
    }
    return false;
}

bool Playership::useTravel() {
    //get appropriate stats
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    //determine fuel and food costs(if there is no food left then all officers take famine damage)
    int chance = (pilotLvl + engiLvl + this->fuelEfficiency)/3;
    if (chance >= randNumGen(0,100)){
        fuel -= 5;
        food -= 5;
        std::cout << "Travel used. Fuel and Food lowered by 5 to: " << this->fuel << " and " << this->food << '\n';
        addToCrew();
        useSystemsRecovery();
        return hasFuel();
    } else {
        fuel -= 10;
        food -= 10;
        std::cout << "Travel used. Fuel and Food lowered by 10 to: " << this->fuel << " and " << this->food << '\n';
        addToCrew();
        useSystemsRecovery();
        return hasFuel();
    }
}

bool Playership::useEscape(SpaceShipEncounter &attacker) {//TBU IN FUNCTIONS if HP is low then attemp escape, if that fails then takeDamageFrom();
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int chance = (engiLvl + pilotLvl + this->speed + this->agility - (attacker.getRace().getOffensiveAbilityLevel())) / 3;
    if (chance >= randNumGen(0, 100))
    {
        if(hasFuel()){
            return true;
        } else {
            std::cout << "CRITCAL FAILURE: ship is out of fuel and cannot escape!\n";
            return false;
        }
    }
    return false;
}

bool Playership::useCombatManuver(int offensiveAbilityLevel){ //used in takeDamageFrom()
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int chance = (engiLvl + pilotLvl + this->agility + this->speed - offensiveAbilityLevel) / 4;
    if (chance >= randNumGen(0,100)){
        std::cout << "Attack was successfully evaded.\n";
        return true;
    }
    std::cout << "Unable to evade attack. \n";
    return false;
}

bool Playership::takeDamageFrom(int offensiveAbilityLevel, int strength){
    //determine damage taken
    int damage = 0;
    if (strength > this->defesiveAbilityLevel){ //enemy has more strength than our defense can hold up against
        damage = (strength - this->defesiveAbilityLevel);
    } else { 
        damage = strength / 2;
    }
    //attempt to avoid / take damage
    if (useCombatManuver(offensiveAbilityLevel)){
        //successful evasion
        return true;
    }
    if (shield <= 0 && armour <= 0){
        //deal damage to ship
        this->health -= damage;
        std::cout << "Ship's health has taken "<< damage <<" damage. ";
        std::cout << "\nShip Health: " << this->health << "\n\n";
        //deal damage to officers
        for (int i = 0; i < officers.size(); i++)
        {
            officers[i].takeDamage(damage);
        }
        //rng kill off crew :(
        damageCrew();
        //check for dead (if dead replace)
        checkForDead();
        return true;
    } else if (shield > 0 ) { //deal damage only to ship
        this->shield -= damage;
        std::cout << "Ship's shield has taken " << damage << " damage. ";
        std::cout << "\nShip Shield: " << this->shield << '\n';
        return true;
    } else if (armour > 0 && shield <= 0){
        this->armour -= damage;
        std::cout << "Ship's shield is down, armour has taken " << damage << " damage. ";
        std::cout << "\nShip Armour: " << this->armour << '\n';
    }
}

void Playership::checkForDead(){ //used in takeDamage();
    for (int i = 0; i < officers.size(); i++){
        Officer temp = officers[i];
        if (temp.getIsDead() && temp.getJob() != "none"){//none officer is used as a 'null' value for findOfficer
            if (crew > 0){
                //create new officer of lesser skill
                Officer newOfficer(temp.getJob(), randNumGen(0, temp.getSkillLevel()));
                std::cout << "\nNew " << newOfficer.getJob() << " joins the ranks.\n";
                //move dead officer into deadOfficers list
                this->deadofficers.push_back(temp);
                this->officers.erase(officers.begin() + i);
                addOfficer(newOfficer);
                if (newOfficer.getJob()== "engineer" || newOfficer.getJob() == "weapons"){
                    recalculateDefense();
                }
                newOfficer.displayOfficer();
                std::cout << "\n";
                this->crew--;
            }
        }
    }
}

int Playership::addOfficer(Officer newOfficer){// used in checkForDead()
    for (int i =0; i < this->officers.size(); i++)
    {
        if (newOfficer.getJob() == officers[i].getJob() && !officers[i].getIsDead())
        {
            std::cerr << "Error: there is already an officer in this position\n";
            return 0;
        }
    }
    officers.push_back(newOfficer);
    return 0;
}

void Playership::useSystemsRecovery(){ // will not occur if useEscape is used.
    int engiLvl = findOfficer("engineer").getSkillLevel();
    if (engiLvl >= randNumGen(0,100)){
        this->health += engiLvl;
        this->shield += engiLvl*2;
        this->armour += engiLvl/4;
        std::cout << "Successful repairs, hp is now: " << this->health << ", shield is now: " << this->shield << " and armour is now: " << this->armour;
    } else {
        std::cout << "The engineer failed to improve the ships systems\n";
    }
    //restore health on officers and give exp
    for (int i = 0; i < officers.size(); i++) {
        officers[i].restoreHealth(10);
    }
}

void Playership::useMine(PlanetEncounter &planet){
    int minerLvl = findOfficer("miner").getSkillLevel();
    int chance = (minerLvl + this->miningPower)/1.5;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful mine! you've gained 10 resources.\n";
        addResources(10);
        findOfficer("miner").levelUpSkill(10);
    } else {
        std::cout << "mine failed...\n";
    }
    
}

bool Playership::useAttack(SpaceShipEncounter &target){
    int weaponLvl = findOfficer("weapons").getSkillLevel() + this->strength;
    int chance = (weaponLvl - (target.getRace().getCombatManuverabilityLevel()/2));
    if (chance >= randNumGen(0,100)){
        std::cout << "You land a direct hit on your target.\n";
        target.takeDamage(chance);
        return true;
    }
    std::cout << "Your target manages to out manuver your attack.\n";
    return false;
}

void Playership::recalculateDefense(){ //used after addOfficer and officer is of job "engi" or "weapons" 
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int weaponsLvl = findOfficer("weapons").getSkillLevel();
    int chance = (engiLvl + weaponsLvl)/2;
    if (chance >= randNumGen(0,100)){
        this->defesiveAbilityLevel = chance;
        std::cout << "Defesive ability level has been set to: " << chance << '\n';
    }
    
}

bool Playership::flyThroughAsteriodBelt(){
    int chance = (this->agility + this->speed + findOfficer("pilot").getSkillLevel())/3;
    if (chance >= randNumGen(0,80)){
        this->fuel += 10;
        std::cout << "Successful flythrough an asteriodbelt, fuel and resources raised by 10\n\n";
        addResources(10);
        findOfficer("pilot").levelUpSkill(10);
        return true;
    }
    return false;
}

void Playership::addResources(int amount){
    if ((amount + this->resources) > this->cargoCapacity){
        std::cout << "Cannot hold anymore resources, cargo capacity reached.\n";
    } else {
        this->resources += amount;
        std::cout << "Reources has been raised by " << amount << " to " << this->resources << "/" << this->cargoCapacity <<'\n';
    }
}

void Playership::addToCrew(){ 
    if (25 >= randNumGen(0,100)){
        std::cout << "Your ship has picked up a new crew member\n";
        this->crew++;
    }
}

void Playership::damageCrew(){// used in takeDamage
    if (50 >= randNumGen(0,100)){
        std::cout << "A crew member has died\n";
        this->crew--;
    }
}

void Playership::getLoot(){
    std::cout << "Looting the enemey ship. ";
    int gatheredFuel = randNumGen(10,50);
    int gatheredFood = randNumGen(10,50);
    int gatheredResources = randNumGen(10,50);
    std::cout << "Your crew loots the wreckage gathering, " << gatheredFood << " food, " << gatheredFuel << " fuel and " << gatheredResources << " resources.\n";
    this->food += gatheredFood;
    this->fuel += gatheredFuel;
    addResources(gatheredResources);
}

Officer& Playership::findOfficer(std::string job){//used most abilities
    for (int i = 0; i < this->officers.size(); i++){
        if (officers[i].getJob() == job && !officers[i].getIsDead())
        {
            return officers[i];
        }
    }

    //std::cout << "There is currently no " << job << " on the ship! \n";
    for (int i = 0; i < this->officers.size(); i++)
    {
        if (officers[i].getJob() == "none")
        {
            return officers[i];
        }
    }
}

void Playership::OffensiveSetup(){
    this->speed = randNumGen(midmin, midmax);
    this->shield = randNumGen(midmin, midmax);
    this->agility = randNumGen(midmin, midmax);
    this->health = randNumGen(highmin, highmax);
    this->armour = randNumGen(highmin, highmax);
    this->strength = randNumGen(highmin, highmax);
    this->miningPower = randNumGen(0, 40);
    this->cargoCapacity = randNumGen(0, 40);
    this->fuelEfficiency = randNumGen(midmin, midmax);
}

void Playership::MinerSetup(){
    this->speed = randNumGen(midmin, midmax);
    this->shield = randNumGen(0, 40);
    this->agility = randNumGen(midmin, midmax);
    this->health = randNumGen(midmin, midmax);
    this->armour = randNumGen(0, 40);
    this->strength = randNumGen(midmin, midmax);
    this->miningPower = randNumGen(highmin, highmax);
    this->cargoCapacity = randNumGen(highmin, highmax);
    this->fuelEfficiency = randNumGen(highmin, highmax);
}

void Playership::DefensiveSetup(){
    this->speed = randNumGen(highmin, highmax);
    this->shield = randNumGen(highmin, highmax);
    this->agility = randNumGen(highmin, highmax);
    this->health = randNumGen(highmin, highmax);
    this->armour = randNumGen(highmin, highmax);
    this->strength = randNumGen(0, 20);
    this->miningPower = randNumGen(midmin, midmax);
    this->cargoCapacity = randNumGen(midmin, midmax);
    this->fuelEfficiency = randNumGen(midmin, midmax);
}

void Playership::OneHitSetup(){
    this->speed = randNumGen(highmin, highmax);
    this->shield = randNumGen(highmin, highmax);
    this->agility = randNumGen(highmin, highmax);
    this->health = 1;
    this->armour = randNumGen(midmin, midmax);
    this->strength = randNumGen(90, 100);
    this->miningPower = randNumGen(midmin, midmax);
    this->cargoCapacity = randNumGen(midmin, midmax);
    this->fuelEfficiency = randNumGen(midmin, midmax);
}
    
void Playership::AverageSetup(){
    this->speed = randNumGen(midmin, midmax);
    this->shield = randNumGen(midmin, midmax);
    this->agility = randNumGen(midmin, midmax);
    this->health = randNumGen(midmin, midmax);
    this->armour = randNumGen(midmin, midmax);
    this->strength = randNumGen(midmin, midmax);
    this->miningPower = randNumGen(midmin, midmax);
    this->cargoCapacity = randNumGen(midmin, midmax);
    this->fuelEfficiency = randNumGen(midmin, midmax);
}


