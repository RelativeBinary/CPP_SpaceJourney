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
    public:
        Officer();                                                                                        //isDead is auto false
        Officer(std::string name, std::string rank, std::string job, int age, int health, int skillLevel);//isDead is auto false
        void displayOfficer();                  //used durring simluation
        bool getIsDead();                       //used for documenting purposes and in checking officiers after taking damage, ship will checkForDead after takeDamageFrom func, if there is dead ship will promote a crew member and give appropriate stats and rank based on rng and the dead officer
        int getAge();                           //used for documenting purposes
        int getHealth();                        //used for documenting purposes
        int getSkillLevel();                    //used for documenting purposes
        std::string getName();                  //used for documenting purposes
        std::string getRank();                  //used to determine what ability stats are affected
        std::string getJob();                   //used to determine what ability stats are affected
        void recieveDamage(int damage);         //checks if damage is > 0 and if officer will take extra damage, if health is <= 0 after taking damage then set isDead to true.
        void restoreHealth();                   //when systems recovery is used
        void levelUpSkill();                    //when enemies are defeated
    private:
        void rankUp();                          //if skill level >50, >75 >99 rank up change rank
        void healthFortuna();                   //based on skillLevel and rank, higher = higher chance of bonus health resorted from systemRecovery and from visiting trading stations
        bool skillFortuna();                    //10% chance of getting skill level boost, after surviving combat (when using escape or after enemey is destroyed)
        bool rankFortuna();                     //3% chance of ranking up, after surviving combat (when using escape or after enemey is destroyed)
};

#endif

//TODO:
/*
- Nothing to see here
*/