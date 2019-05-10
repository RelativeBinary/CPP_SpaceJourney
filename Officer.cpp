#include <iostream>
#include <string>
#include <vector>
#include "Officer.h"

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
    std::cout << damage << " dealt on " << this->name << '\n';
    this->health -= damage;
    std::cout << this->name << "'s hp is now: " << this->health << "hp" << '\n';
}

void Officer::restoreHealth(int points){
    std::cout << points << " health resorted on " << this->name << '\n';
    this->health += points;
    std::cout << this->name << "'s hp is now: " << this->health << "hp" << '\n';
}
    
void Officer::levelUpSkill(int exp) {
    std::cout << "checking officer stats" << '\n';
    this->skillLevel += exp;
    int lvl = this->skillLevel;
    std::string rank = this->rank;
    if (lvl >= 90 && rank != "Major"){
        std::cout << "Officer: " << this->name << " was promoted to Major!" << '\n';
        this->rank = "Major";
    } else if (lvl >= 75 && rank != "Lieutenant Commander"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant Commander" << '\n';
        this->rank = "Lieutenant Commander";
    } else if (lvl >= 50 && rank != "Lieutenant"){
        std::cout << "Officer: " << this->name << " was promoted to Lieutenant" << '\n';
        this->rank = "Lieutenant";
    }
}