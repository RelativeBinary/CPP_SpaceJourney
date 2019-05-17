#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Officer.h"
#include "SpaceSector.h"
#include "functions.h"

Officer::Officer(){
    this->name = "defaultConstructor";
    this->rank = "Lieutenant";
    this->job = "Captain";
    this->age = 19;
    this->health = 84;
    this->skillLevel = 55; //skillLevel is capped at 99
    this->isDead = false;
}

Officer::Officer(std::string j, int sLevel){
    this->name = getRandName();
    this->job = j;
    this->age = randNumGen(1,100);
    this->health = randNumGen(50, 100);
    this->skillLevel = sLevel;
    this->isDead = false;
    levelUpSkill(0); //checks if the skillLevel given warrents a rank up.
}

void Officer::displayOfficer(){
    std::cout << std::left << std::setw(8) << "Name: " << std::left << std::setw(19) << this->name;
    std::cout << std::left << std::setw(8) << "Rank: " << std::left << std::setw(19) << this->rank << '\n';
    std::cout << std::left << std::setw(8) << "Job: " << std::left << std::setw(19) << this->job;
    std::cout << std::left << std::setw(8) << "Age: " << std::left << std::setw(19) << this->age << '\n';
    std::cout << std::left << std::setw(8) << "Health: " << std::left << std::setw(19) << this->health;
    std::cout << std::left << std::setw(12) << "Skill Profficiency: " << this->skillLevel << '\n';
    std::cout << "Status: " << ((this->isDead) ? "Dead" : "Alive") << '\n';
    if (this->isDead){
        std::cout << "Died on sector: " << this->sectorOfDeath << '\n';
        std::cout << "Cause of death: " << this->causeOfDeath << '\n';
    }
    std::cout <<'\n';
}
#pragma region //getters
bool Officer::getIsDead() {
    return this->isDead;
}

int Officer::getAge(){
    return this->age;
}

int Officer::getHealth(){
    return this->health;
}

int Officer::getSkillLevel(){
    return this->skillLevel;
}

std::string Officer::getName(){
    return this->name;
}

std::string Officer::getRank(){
    return this->rank;
}

std::string Officer::getJob(){
    return this->job;
}
#pragma endregion

void Officer::takeDamage(int damage, std::string dmgSource){
    if(this->job != "none"){//checks for null type officer
        this->health -= damage;
        std::cout << "Officer: " << damage << " damage dealt, " << this->job << " " << this->name << "'s hp is now: " << this->health << "hp\n";
    }

    if (this->health <= 0){//sets hp to 0 and sets how and when an officer died
        this->isDead = true;
        this->sectorOfDeath = SpaceSector::getSectorCount();
        this->causeOfDeath = dmgSource;
        this->health = 0;
        std::cout << this->name << " has been marked as dead.\n";
    }
}

void Officer::restoreHealth(int points){//restores health to living officers
    if (this->health >= 1){
        if (this->job !="none"){
            std::cout << "Officer: " << points << " health restored on " << this->name << ' ';
            this->health += points;
            //magical bonus hp restored
            healthFortuna();
            std::cout << this->name << "'s hp is now: " << this->health << "hp\n";
        }
    } else {
        std::cout << this->name << " is dead. ";
        this->health = 0;
        std::cout << "Officer has been marked as dead\n";
    }
}
    
void Officer::levelUpSkill(int exp) {//raises the officers skill level
    if (this->skillLevel + exp >= 100) {//caps the officers level if maxed out
        this->skillLevel = 99;
        std::cout << this->job << " " << this->name << " has maxed out their skill! Skill level is now: " << this->skillLevel << " ";
    } else {//raises the officers skill level
        this->skillLevel += exp;
        //magical bonus exp
        skillFortuna();
        std::cout << this->job << " " << this->name << " gained " << exp << "exp, is now level: " << this->skillLevel << " ";
    }
    
    //check if the officer can rank up
    if (this->skillLevel >= 90 && this->rank != "Major"){
        std::cout << "Officer: " << this->name << " was promoted to Major! ";
        this->rank = "Major";
    } else if (this->skillLevel >= 75 && this->skillLevel < 90 && this->rank != "Lieutenant Commander"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant Commander ";
        this->rank = "Lieutenant Commander";
    }
    else if (this->skillLevel >= 50 && this->skillLevel < 75 && this->rank != "Lieutenant")
    {
        std::cout << this->job << " " << this->name << " was promoted to Lieutenant ";
        this->rank = "Lieutenant";
    }
    std::cout  << '\n';
    //magical extra level up
    rankFortuna();
}

void Officer::healthFortuna(){//used in restoreHealth
    int chance = randNumGen(0,100);
    if (chance <= 5){
        std::cout << "Health Fortuna! " << this->name << "'s hp is increased by 10\n";
        this->health += 10;
    }

}

void Officer::skillFortuna(){//used in levelUpSkill
    int chance = randNumGen(0,100);
    if (chance <= 5){
        std::cout << "Skill Fortuna! " << this->name << "'s gained bonus 10 exp\n";
        if (this->skillLevel + 10 >= 100)
        {
            this->skillLevel = 99;
            std::cout << this->job << " " << this->name << " has maxed out their skill! Skill level is now: " << this->skillLevel << " ";
        }
        else
        {
            this->skillLevel += 10;
            skillFortuna();
            std::cout << this->job << " " << this->name << " gained 10 exp, is now level: " << this->skillLevel << " ";
        }
    }

}

void Officer::rankFortuna(){ //used in levelUpSkill
    int chance = randNumGen(0,100);
    if (chance == 0){
        std::cout << "Rank Fortuna! " << this->name << "'s";
        if (this->skillLevel >= 90){
            std::cout << " rank is capped out, skill level increased by 10\n";
            this->skillLevel += 10;
        } else {
            std::cout << " rank is raised to major, skill level raised to 90\n";
            this->skillLevel = 90;
            this->rank = "Major";
        }
    }
}

