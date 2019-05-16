#include "functions.h"
#include "Officer.h"
#include "SpaceShip.h"
#include "SpaceSector.h"
#include <time.h>

int SpaceSector::sectorCount = 0;

void displayScoreBoard(Playership& pShip){
    std::cout << "IT WAS A SPAAACCEE JOUURRNNEEYY AND IT WAS A GREEAATT ONNNEE OHH YEAAH";
}

int main(int argc, char* argv[]){
    std::srand(time(NULL));
    
    //PREGAME LOOP SETUP//
    std::cout << "Settup up officers...\n";
    std::vector<Officer> officers;
    Officer captain("captain", randNumGen(50,80));
    Officer pilot("pilot", randNumGen(50,80));
    Officer engineer("engineer", randNumGen(50,80));
    Officer miner("miner", randNumGen(50,80));
    Officer weapons("weapons", randNumGen(50,80));
    Officer none("none", 0);
    officers.push_back(captain);
    officers.push_back(pilot);
    officers.push_back(engineer);
    officers.push_back(miner);
    officers.push_back(weapons);
    officers.push_back(none);
    std::cout << "Officers have been set.\n\n";
    std::cout << "Setting up your spaceship\n";
    Playership pShip(officers);
    std::cout << "Setup complete.\n\n";
    pShip.displayPlayership();
    std::cout << "\n\n";

    std::cout << "Charging Partical Accellerators.." << '\n';
    std::cout << '\n';
    std::cout << "Lauching The Space Journey" << '\n';
    //take cli args
    const int limit = std::atoi(argv[1]);
    std::cout << "Targeting " << limit << " sectors from initializtion point\n\n";

    //GAME LOOP//
    int travelCount = 0;
    while(travelCount < limit && limit <= 50 && pShip.getHealth() > 0 && pShip.getFood() > 0  && pShip.getFuel() > 0){
        std::string curSecType = determineSectorType();
            bool escapedCombat = false; //escapedCombat is used to override the useTravel at the end.
        //Create the sector and perform interactions
        if (curSecType == "SpaceShipEncounter"){
            SpaceShipEncounter newSSE; //SpaceShipEncounter(SSE)
            std::cout << "An unknown ship of the " << newSSE.getRace().getType() << " race has been encountered.\n";
            //ATTEMPT TO AVOID COMBAT
            if (!pShip.useDiplomacy(newSSE)){
                //BEGIN COMBAT LOOP
                std::cout << "Entering combat mode\n";
                int turn = 0;
                while(pShip.getHealth() > 0 && newSSE.getHealth() > 0 && !escapedCombat){
                    if (turn == 0){//player attacks
                        std::cout << "Player turn ";
                        if(70 >= randNumGen(0,100)){
                            pShip.useAttack(newSSE);
                        } else{
                            if(pShip.useEscape(newSSE)){
                                std::cout << "You have successfully escaped combat\n";
                                pShip.findOfficer("pilot").levelUpSkill(10);
                                escapedCombat = true;
                            }
                        }
                        turn++;
                    } else {//enemey attacks
                        //enemy strength will increase dramatically when traveling through higher number space sectors.
                        if (newSSE.getRace().getType() == "Celestial"){ //this race can't fight
                            std::cout << "The Celestials refuse to engage in combat.\n";
                            turn--;
                        } else {
                            pShip.takeDamageFrom(newSSE.getRace().getOffensiveAbilityLevel(), newSSE.getStrength() * (SpaceSector::getSectorCount() / 2));
                            turn--;
                        }
                    }
                }
                std::cout << "Combat has ended.\n";
                if (newSSE.getHealth() <= 0){
                    std::cout << "The hostile entity has been destroyed.\n";
                    pShip.findOfficer("captain").levelUpSkill(10);
                    pShip.findOfficer("pilot").levelUpSkill(10);
                    pShip.findOfficer("weapons").levelUpSkill(10);
                    pShip.findOfficer("engineer").levelUpSkill(10);
                    pShip.getLoot();
                    pShip.shipsDestroyed++;
                }
            } else {
                escapedCombat = true;
                std::cout << "Neogitations were successful, combat was avoided.\n";
                pShip.findOfficer("captain").levelUpSkill(10);
            }
            pShip.shipsEncountered++;
        }else if (curSecType == "PlanetEncounter"){
            std::cout << "As you appear out of warp speed, you encounter a new planet.\n";
            PlanetEncounter newPE; //PlanetEncounter(PE)
            if (newPE.getRace().getType() != "Solaris"){
                int option = randNumGen(0, 2);
                if (option < 1){
                    pShip.useMine(newPE);
                }else{
                    pShip.useTrade(newPE);
                }
            } else {
                std::cout << "The planet refuses outsiders to land, warning shots are fired toward your ship.\n";
            }
            pShip.planetsVisited++;
        }else if (curSecType == "TradingStation"){
            TradingStation newTS; //TradingStation(TS)
            std::cout << "Your ship eases to a stop as you reach a "<< newTS.getRace().getType() <<" trading station.\n";
            if (newTS.getRace().getType() != "Solaris"){ //solaris race will not trade
                pShip.useTrade(newTS);
            } else {
                std::cout << "The solaris trading stations refuses outsiders to approach, warning shots are fired toward your ship.\n";
            }
            pShip.tradingStationsVisited++;
        }else if (curSecType == "Empty"){
            if (pShip.findOfficer("captain").getJob() != "none"){
                std::cout << "Captain "<< pShip.findOfficer("captain").getName() << " made a stop by an empty sector to gaze into the empty void of space. \n";
            }
            SpaceSector empty;
            pShip.EmptySectorsPassed++;
            //probably add a comment on the scoreboard, saying you spend a lot of time 
            //staring into the void of space if you traveled a lot of empty sectors
        }else if (curSecType == "AsteriodBelt"){
            AsteriodBelt newAB; //AsteriodBelt(AB)
            std::cout << "DANGER incomming asteriods, attempting to fly through.\n";
            if(!pShip.flyThroughAsteriodBelt()){
                std::cout << "AB damage is: " << newAB.getStrength() << '\n';
                //strength will increase dramatically when traveling through higher number space sectors.
                std::cout << "The ship is about to take heavy damage flying through the asteriod belt.\n";
                pShip.takeDamageFrom(newAB.getRace().getOffensiveAbilityLevel(), newAB.getStrength() * (SpaceSector::getSectorCount()/5));
            }
            pShip.AsteriodBeltsPassed++;
        }// end of sector interactions.

        //Check playership status
        if (escapedCombat == false){
            if (pShip.getHealth() <= 0){//Playership was destroyed
                std::cout << "Your ship was destroyed...\n\n";
                std::cout << "GAME OVER\n";
            } else {
                if (!pShip.useTravel()){//Playership has run out of fuel
                    std::cout << "You're out of fuel, and stranded in space...\n\n";
                    std::cout << "GAME OVER\n";
                } else {
                    if (pShip.getFood() <= 0){//Playership has run out of food
                        std::cout << "You're out of food, everyone has starved to death...\n\n";
                        std::cout << "GAME OVER\n";
                    } else {//Playership is OK
                        std::cout << "Boosters roar, as you blast off to the next space sector.\n";
                    }
                }
            }
        }else{ //Playership successfully used escape ability during combat.
            std::cout << "Success, you escaped the conflict.\n";
        }
        std::cout << "====================\n";
        std::cout << "End of sector #" << SpaceSector::getSectorCount() << '\n';
        std::cout << "====================\n\n";
        travelCount++;
    }//END OF GAME LOOP//

    //Check for GAME OVER from dying or invliid input
    if (limit <= 50){//Display Score Board
        displayScoreBoard(pShip);
    } else {//Invalid number of sectors entered
        std::cerr << "ERROR: Max space sectors traveled must be <= 50";
    }

    //Secret ending for those who had luck on their side.
    if (travelCount >= limit && pShip.getHealth() > 0) {
        //maybe print out the space jame lyrics
        std::cout << "And so this space journey comes to an end.\n\n";
        std::cout << "But YOUR space journey has just begun.\nSee you space cowboy.";
    }
    return 0;
}