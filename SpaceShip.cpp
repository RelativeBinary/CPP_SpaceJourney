#include <iostream>
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

SpaceShipEncounter::SpaceShipEncounter(){
    if (this->getRace().getType() == "Solaris") {
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
    }
}
//TODO: Setup raceshiptypes
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

Playership::Playership() 
{
    int crew = 0;
    int cargoCapacity = 0; //out of 100
    int mainingPower = 0;  // out of 100
    int fuelEfficiency = 0; //out of 10
    std::string shipType = "Jack";

}

Playership::Playership(std::vector<Officer> officers){
    //sets up ship internally
    this->shipType = determineShipType();
    this->officers = officers; //TODO: Global function that sets all the officers
    setupShip();
}

Playership::Playership(std::string type, std::vector<Officer> officers){
    //sets up ship based from external influence
    this->shipType = type;
    this->officers = officers;
    setupShip();
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

void Playership::useDiplomacy(SpaceSector &aggressor){ //INCOMPLETE
    Officer captain = findOfficer("captain");
    int capLvl = captain.getSkillLevel();
    int chance = (capLvl + aggressor.getRace().getDiplomacyLevel())/2;
    if (chance >= randNumGen(0,100)){
        std::cout << "negotiations successful!! pay resources and other things happen\n"; 
    }
}
void Playership::useTrade(SpaceSector &trader){
    Officer captain = findOfficer("captain");
    int capLvl = captain.getSkillLevel();
    int chance = (capLvl + trader.getRace().getTradabilityLevel())/2;
    if (chance >= randNumGen(0,100)){
        std::cout << "trade successful!! pay resources and other things\n";
    }
}
bool Playership::hasFuel(){
    if (this->fuel > 0){
        return true;
    }
    return false;
}

bool Playership::useTravel() //USED IN FUNCTIONS.CPP/H
{
    //get appropriate stats
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    //determine fuel and food costs(if there is no food left then all officers take famine damage)
    int chance = (pilotLvl + engiLvl + this->fuelEfficiency)/3;
    if (chance >= randNumGen(0,100)){
        fuel -= 1;
        food -= 1;
        std::cout << "Travel used. Fuel and Food lowered by 1 to: " << this->fuel << " and " << this->food << ".\n";
        return hasFuel();
    } else {
        fuel -= 5;
        food -= 5;
        std::cout << "Travel used. Fuel and Food lowered by 5 to: " << this->fuel << " and " << this->food << ".\n";
        return hasFuel();
    }
}
bool Playership::useEscape(SpaceShipEncounter &attacker) //TBU IN FUNCTIONS if HP is low then attemp escape, if that fails then takeDamage();
{
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
bool Playership::useCombatMauver(SpaceShipEncounter &attacker)
{
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
bool Playership::takeDamageFrom(SpaceShipEncounter &attacker) //TBU IN FUNCTIONS
{
    //determine damage taken
    int damage = (attacker.getRace().getOffensiveAbilityLevel() + attacker.getStrength() - this->defesiveAbilityLevel) / 2;
    //attempt to avoid / take damage
    if (useCombatMauver(attacker))
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

void Playership::useSystemsRecovery()
{
    int engiLvl = findOfficer("engineer").getSkillLevel();
    if (engiLvl >= randNumGen(0,100)){
        this->health += engiLvl;
        this->shield += engiLvl;
        this->armour += engiLvl/4;
        std::cout << "successful repairs\n";
    }
}
void Playership::useMine(PlanetEncounter &planet)
{
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
bool Playership::useAttack(SpaceShipEncounter &target)
{
    int weaponLvl = findOfficer("weapons").getSkillLevel() + this->strength;
    int chance = (weaponLvl - target.getRace().getCombatManuverabilityLevel())/1.5;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful attack\n";
        return true;
    }
    std::cout << "attack failed\n";
    return false;
}
void Playership::reallocateDefense(){ //INCOMPLETE
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int weaponsLvl = findOfficer("weapons").getSkillLevel();
    int chance = (engiLvl + weaponsLvl)/2;
    if (chance >= randNumGen(0,100)){
        this->defesiveAbilityLevel = chance;
        std::cout << "new defesive ability level hsa been set to: " << chance << '\n';
    }
    
}

void Playership::addToCrew()
{ 
    if (50 >= randNumGen(0,100)){
        std::cout << "your ship has picked up a new crew member\n";
        this->crew++;
    }
}

void Playership::damageCrew(){
    if (50 >= randNumGen(0,100)){
        std::cout << "a crew member has died\n";
        this->crew--;
    }
}

void Playership::checkForDead() //INCOMPLETE
{ 
    for(Officer currOfficer : officers){
        if (currOfficer.getIsDead()){
            //replace with a new one, on death the Officers information will contain the last sector he/she died on.
            std::cout << "Officer " << currOfficer.getRank() << " " << currOfficer.getName() << " has died\n";
            if (this->crew >0){
                //create new Officer
                //SOME GLOBAL FUNCTION
                //addOfficer(newOfficer);
                this->crew--;
            }
        }
    }
}

int Playership::addOfficer(Officer newOfficer)
{
    for (Officer currOfficer : this->officers){
        if (newOfficer.getJob() == currOfficer.getJob() && !currOfficer.getIsDead()){
            std::cerr << "Error: there is already an officer in this position\n";
            return 0;
        }
    }
    officers.push_back(newOfficer);
    std::cout << "new officer added\n";
    return 0;
}

Officer Playership::findOfficer(std::string job)
{
    Officer temp("noOfficer", "none", "none", 20, 50, 0);

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


