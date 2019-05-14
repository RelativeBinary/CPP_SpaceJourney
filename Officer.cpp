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
    this->skillLevel = 55;
    this->isDead = false;
}

Officer::Officer(std::string job, int skillLevel){
    std::cout << "\nstart of constructor ";
    this->name = getRandName();
    this->job = job;
    this->age = randNumGen(1,100);
    this->health = randNumGen(50, 100);
    this->skillLevel = skillLevel;
    this->isDead = false;
    levelUpSkill(0); //checks if the skillLevel given warrents a rank up.
    std::cout << "end of constructor\n\n";
}

void Officer::displayOfficer(){
    std::cout << std::left << std::setw(8) << "Name: " << std::left << std::setw(12) << this->name;
    std::cout << std::left << std::setw(8) << "Rank: " << std::left << std::setw(12) << this->rank << '\n';
    std::cout << std::left << std::setw(8) << "Job: " << std::left << std::setw(12) << this->job;
    std::cout << std::left << std::setw(8) << "Age: " << std::left << std::setw(12) << this->age << '\n';
    std::cout << std::left << std::setw(8) << "Health: " << std::left << std::setw(12) << this->health;
    std::cout << std::left << std::setw(12) << "Skill Proficiency: " << this->skillLevel << '\n';
    std::cout << "Status: " << ((this->isDead) ? "Dead" : "Alive") << '\n';
    if (this->isDead){
        std::cout << "Status: Died on sector " << this->sectorOfDeath << '\n';
    }
    std::cout <<'\n';
}

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

void Officer::takeDamage(int damage){
    std::cout << damage << " damage dealt on " << this->name << '\n';
    this->health -= damage;
    std::cout << this->name << "'s hp is now: " << this->health << "hp\n";

    if (this->health <= 0){
        std::cout << this->name << " was fatally wounded.\n";
        this->isDead = true;
        this->sectorOfDeath = SpaceSector::getSectorCount();
        this->health = 0;
        std::cout << "Officer has been marked as dead\n ";
    }
}

void Officer::restoreHealth(int points){
    if (this->health >= 1){
        std::cout << points << " health resorted on " << this->name << '\n';
        this->health += points;
        healthFortuna();
        std::cout << this->name << "'s hp is now: " << this->health << "hp\n\n";
    } else {
        std::cout << this->name << " is dead.\n";
        this->health = 0;
        std::cout << "Officer has been marked as dead\n\n";
    }
}
    
void Officer::levelUpSkill(int exp) {
    std::cout << this->name << " gained " << exp << "exp\n";
    this->skillLevel += exp;
    skillFortuna();
    int lvl = this->skillLevel;

    std::cout << "checking officer stats" << '\n';
    std::string rank = this->rank;
    if (lvl >= 90 && rank != "Major"){
        std::cout << "Officer: " << this->name << " was promoted to Major!\n\n";
        this->rank = "Major";
    } else if (lvl >= 75 && rank != "Lieutenant Commander"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant Commander\n\n";
        this->rank = "Lieutenant Commander";
    } else if (lvl >= 50 && rank != "Lieutenant"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant\n\n";
        this->rank = "Lieutenant";
    }

    rankFortuna();
}

void Officer::healthFortuna(){
    int chance = randNumGen(0,100);
    if (chance <= 5){
        std::cout << "Health Fortuna! " << this->name << "'s hp is increased by 10\n";
        this->health += 10;
    }

}

void Officer::skillFortuna(){
    int chance = randNumGen(0,100);
    if (chance <= 5){
        std::cout << "Skill Fortuna! " << this->name << "'s gained bonus 10 exp\n";
        this->skillLevel += 10;
    }

}

void Officer::rankFortuna(){
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
