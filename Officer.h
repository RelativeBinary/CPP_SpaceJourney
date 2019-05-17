#ifndef officer_h
#define officer_h
#include <iostream>
#include <string>
#include <vector>
class Officer
{
    std::string name, rank, job;
    int age, health, skillLevel;
    bool isDead;
    int sectorOfDeath;
    std::string causeOfDeath;
    public:
        Officer();                               //isDead is auto false
        Officer(std::string job, int skillLevel);//isDead is auto false
        void displayOfficer();                  
        bool getIsDead();                        //used in checking officiers after taking damage
        int getAge();                           
        int getHealth();                        
        int getSkillLevel();                    
        std::string getName();                  
        std::string getRank();                   //used to determine what ability stats are affected
        std::string getJob();                    //used to determine what ability stats are affected
        void takeDamage(int damage, std::string dmgSource);        //will be used in playerShip takeDamageFrom
        void restoreHealth(int damage);                            //used when systems recovery is used
        void levelUpSkill(int exp);                    
    private:
        void healthFortuna();                   //5% chance of getting bonus health
        void skillFortuna();                    //10% chance of getting skill level boost, after surviving combat (when using escape or after enemey is destroyed)
        void rankFortuna();                     //3% chance of ranking up, after surviving combat (when using escape or after enemey is destroyed)
};

#endif


