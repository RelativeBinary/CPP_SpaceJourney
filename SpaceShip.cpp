#include <iostream>
#include <string>
#include <vector>
#include "SpaceShip.h"
#include "Officer.h"
#include "functions.h"

SpaceShip::SpaceShip(){
    strength = 50;
    health = 50;
    shield = 50;
    armour = 50;
    fuel = 50;
    food = 50;
    agility = 50;
    speed = 50;
    resources = 50;
    money = 50;
}

SpaceShip::SpaceShip(int strgth, int health, int shield, int armour, int fuel, int food, int agility, int speed, int resources, int money){
    this->strength = strgth;
    this->health = health;
    this->shield = shield;
    this->armour = armour;
    this->fuel = fuel;
    this->food = food;
    this->agility = agility;
    this->speed = speed;
    this->resources = resources;
    this->money = money;
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

void Playership::useDiplomacy(SpaceSector &aggressor){
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
void Playership::useTravel(){
    //get appropriate stats
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    //determine fuel and food costs(if there is no food left then all officers take famine damage)
    int chance = (pilotLvl + engiLvl + this->fuelEfficiency)/3;
    if (chance >= randNumGen(0,100)){
        fuel -= 5;
        food -= 5;
        std::cout << "Travel used. Fuel and Food lowered by 5 to: " << this->fuel << " and " << this->food << ".\n";
    } else {
        fuel -= 10;
        food -= 10;
        std::cout << "Travel used. Fuel and Food lowered by 10 to: " << this->fuel << " and " << this->food << ".\n";
    }
    //SOME GLOBAL FUNCTION TO MOVE TO THE NEXT SPACESECTOR
}
bool Playership::useCombatMauver(SpaceshipEncounter &attacker){
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
void Playership::useEscape(SpaceshipEncounter &attacker){
    int pilotLvl = findOfficer("pilot").getSkillLevel();
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int chance = (engiLvl + pilotLvl + this->speed + this->agility - (attacker.getRace().getOffensiveAbilityLevel() + attacker.getShip().getSpeed()))/3;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful escape\n";
        //determine fuel and food costs
        //SOME GLOBAL FUNCTION INVOLVING ESCAPE
    }
}
void Playership::useSystemsRecovery(){
    int engiLvl = findOfficer("engineer").getSkillLevel();
    if (engiLvl >= randNumGen(0,100)){
        std::cout << "successful repairs\n";
    }
}
void Playership::useMine(PlanetEncounter &planet){
    int minerLvl = findOfficer("miner").getSkillLevel();
    int chance = (minerLvl + this->miningPower)/1.5;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful mine, now determine how much loot u get\n";
    }
}
void Playership::useAttack(SpaceshipEncounter &target){
    int weaponLvl = findOfficer("weapons").getSkillLevel() + this->strength;
    int chance = (weaponLvl - target.getRace().getCombatManuverabilityLevel())/1.5;
    if (chance >= randNumGen(0,100)){
        std::cout << "successful attack, things involving lowering enemy hp, arm, shld\n";
    }
}
void Playership::upgradeDefense(){
    int engiLvl = findOfficer("engineer").getSkillLevel();
    int weaponsLvl = findOfficer("weapons").getSkillLevel();
    int chance = (engiLvl + weaponsLvl)/2;
    if (chance >= randNumGen(0,100)){
        std::cout << "new defesive ability level hsa been set to: " << chance << '\n';
    }
    
}
void Playership::takeDamageFrom(SpaceshipEncounter &attacker){
    //get appropriate stats
    
    //determine damage taken
    int damage = (attacker.getRace().getOffensiveAbilityLevel() + attacker.getShip().getStrength() - this->defesiveAbilityLevel)/2;
    //attempt to avoid / take damage
    if (useCombatMauver(attacker)){
        //successful dogde
        damage = 0;
    } else if (this->health < 20) {//try to escape
        useEscape(attacker);
        //the above calls some global escape function to move to a new sector
    }

    //if ship isnt destroyed apply damage to officers
    if (this->health <= 0){
        //game over
        //SOME GLOBAL FUNCTION TO DISPLAY GAME RESULTS
    } else {
        if(shield <= 0 && armour <= 0){
            //deal damamge to officers
            for (int i = 0; i < officers.size(); i++){
                officers[i].takeDamage(damage);
            }
            //rng kill off crew :(
            damageCrew();
        }
        //check for dead (if dead replace)
        checkForDead();
    }
}

void Playership::addToCrew(){
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
void Playership::checkForDead(){
    for(Officer currOfficer : officers){
        if (currOfficer.getIsDead()){
            //replace with a new one 
            std::cout << "Officer " << currOfficer.getRank() << " " << currOfficer.getName() << " has died\n";
            if (this->crew >0){
                //create new Officer
                //SOME GLOBAL FUNCTION
                //addOfficer(newOfficer);
            }
        }
    }
}

int Playership::addOfficer(Officer newOfficer){
    for (Officer currOfficer : this->officers){
        if (newOfficer.getJob() == currOfficer.getJob() && !currOfficer.getIsDead()){
            std::cerr << "Error: there is already an officer in this position\n";
            return 0;
        }
    }
    officers.push_back(newOfficer);
    return 0;
}

Officer Playership::findOfficer(std::string job){
    Officer temp("noOfficer", "none", "none", 20, 50, 0);

    for (Officer currOfficer: this->officers){
        if(currOfficer.getJob() == job && !currOfficer.getIsDead()){
            return currOfficer;
        }
    }

    std::cout << "There is currently no " << job << " on the ship! \n";
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

