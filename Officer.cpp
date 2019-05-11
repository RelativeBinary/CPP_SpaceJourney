#include <iostream>
#include <string>
#include <vector>
#include "Officer.h"
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

Officer::Officer(std::string name, std::string rank, std::string job, int age, int health, int skillLevel){
    this->name = name;
    this->rank = rank;
    this->job = job;
    this->age = age;
    this->health = health;
    this->skillLevel = skillLevel;
    this->isDead = false;
}

void Officer::displayOfficer(){
    std::cout << "Name: " << this->name << '\n';
    std::cout << "Rank: " << this->rank << '\n';
    std::cout << "Job: " << this->job << '\n';
    std::cout << "Age: " << this->age << '\n';
    std::cout << "Health: " << this->health << '\n';
    std::cout << "Skill Proficiency: " << this-> skillLevel << '\n';
    std::cout << "Status: " << ((this->isDead) ? "Dead" : "Alive") << '\n';
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

void Officer::recieveDamage(int damage){
    std::cout << damage << " damage dealt on " << this->name << '\n';
    this->health -= damage;
    std::cout << this->name << "'s hp is now: " << this->health << "hp\n";

    if (this->health <= 0){
        std::cout << this->name << " was fatally wounded.\n";
    }
}

void Officer::restoreHealth(int points){
    std::cout << points << " health resorted on " << this->name << '\n';
    this->health += points;
    healthFortuna();
    std::cout << this->name << "'s hp is now: " << this->health << "hp\n";
}
    
void Officer::levelUpSkill(int exp) {
    std::cout << this->name << " gained " << exp << "exp\n";
    this->skillLevel += exp;
    skillFortuna();
    int lvl = this->skillLevel;

    std::cout << "checking officer stats" << '\n';
    std::string rank = this->rank;
    if (lvl >= 90 && rank != "Major"){
        std::cout << "Officer: " << this->name << " was promoted to Major!\n";
        this->rank = "Major";
    } else if (lvl >= 75 && rank != "Lieutenant Commander"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant Commander\n";
        this->rank = "Lieutenant Commander";
    } else if (lvl >= 50 && rank != "Lieutenant"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant\n";
        this->rank = "Lieutenant";
    }

    rankFortuna();
}

void Officer::healthFortuna(){
    int chance = randNumGen(100);
    if (chance <= 5){
        std::cout << "Health Fortuna! " << this->name << "'s hp is increased by 10\n";
        this->health += 10;
    }

}

void Officer::skillFortuna(){
    int chance = randNumGen(100);
    if (chance <= 5){
        std::cout << "Skill Fortuna! " << this->name << "'s gained bonus 10 exp\n";
        this->skillLevel += 10;
    }

}

void Officer::rankFortuna(){
    int chance = randNumGen(100);
    if (chance == 0){
        std::cout << "Rank Fortuna! " << this->name << "'s";
        if (this->skillLevel >= 90){
            std::cout << " rank is capped out, skill level increased by 10\n";
            this->skillLevel += 10;
        } else {
            std::cout << " rank is raised to major, skill level raised to 90\n";
            this->skillLevel = 99;
            this->rank = "Major";
        }
    }
}
