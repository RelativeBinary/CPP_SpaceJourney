#include "functions.h"
#include "Officer.h"
#include "SpaceShip.h"
#include "SpaceSector.h"
#include <time.h>

int SpaceSector::sectorCount = 0;

int determineNextAction(SpaceSector curSector){
    //after the sector type is determined and the newSector is created
    //this function will take that sector and determine based on its type what actions the playership will take
    //combat will be a whole nother function
}

int main(int argc, char* argv[]){
    std::srand(time(NULL));
    std::cout << "Charging Partical Accellerators.." << '\n';
    std::cout << '\n';
    std::cout << "Lauching The Space Journey" << '\n';
    //take cli args
    const int limit = std::atoi(argv[1]);
    std::cout << "Targeting " << limit << " sectors from initializtion point" << '\n';

    //initialize spaceship

    //initialize officiers and skill stats


#pragma region //Class Testing
    #pragma region //Officer Test Code
    //Officer function testing
    //Stage one - no rng, testing function effects: testing complete, outputs OK, logic OK, non-rng testing completed
    //Stage two - rng, testing function effects:
    std::vector<Officer> officers;
    Officer f1("captain", randNumGen(50,100));
    Officer f2("pilot", randNumGen(50, 100));
    Officer f3("engineer", randNumGen(50, 100));
    Officer f4("miner", randNumGen(50, 100));
    Officer f5("weapons", randNumGen(50, 100));
    Officer f6("none", 0);
    officers.push_back(f6);
    f1.displayOfficer();
    f1.levelUpSkill(10);
    f1.takeDamage(2000);
    f1.restoreHealth(5);
    f1.displayOfficer();
    officers.push_back(f1);

    f2.displayOfficer();
    officers.push_back(f2);

    f3.displayOfficer();
    officers.push_back(f3);

    f4.displayOfficer();
    officers.push_back(f4);

    f5.displayOfficer();
    officers.push_back(f5);
    std::cout << '\n' << '\n';
    #pragma endregion
    
    #pragma region//SpaceShip Testing
    SpaceShip sh1;
    sh1.displaySpaceShip();
    std::cout << '\n' << '\n';
    #pragma endregion
    
    #pragma region //SpaceShipEncounter Testing
    SpaceShipEncounter she1;
    std::cout << std::endl;
    she1.displaySpaceSector();
    she1.displaySpaceShip();
    std::cout << '\n'<< '\n';
    #pragma endregion

    #pragma region //SpaceSector Testing
    SpaceSector s1;
    s1.displaySpaceSector();
    std::cout << '\n'<< '\n';
    #pragma endregion/**/

    #pragma region //PlanetEncounter Testing
    PlanetEncounter pl1;
    #pragma endregion

    #pragma region //TradingStation Testing
    TradingStation tr1;
    #pragma endregion

    #pragma region //AsteriodBelt Testing
    AsteriodBelt a1;
    #pragma endregion

    #pragma region //Playership Testing
    Playership p1(officers);
    p1.displayPlayership();
    std::cout << "Attempting to fly through asteroidbelt: ";
    std::cout << (p1.flyThroughAsteriodBelt() ? "true" : "false") << '\n';
    //std::cout << "Attempting to travel: " ;
    //std::cout << (p1.useTravel()? "true": "false") << '\n';
    //std::cout << "Using diplomacy: ";
    //std::cout << (p1.useDiplomacy(she1) ? "true" : "false") << '\n';
    //std::cout << "Using trade: ";
    //std::cout << (p1.useTrade(she1)? "true":"false")<<'\n';
    //std::cout << "Taking damage: ";
    //std::cout << (p1.takeDamageFrom(she1)? "true" : "false") << '\n';
    //std::cout << "Attemptng to escape: ";
    //std::cout << (p1.useEscape(she1)?"true":"false") << '\n';
    //std::cout << "Attempting sys recovery: "; 
    //p1.useSystemsRecovery();
    //std::cout << '\n';
    //std::cout << "Attempting mine: ";
    //std::cout << "not set up\n";
    //std::cout << "Attempting to attack: ";
    //std::cout << (p1.useAttack(she1)?"true":"false") << '\n';
    std::cout << '\n'<< '\n';
    #pragma endregion
#pragma endregion
    

    return 0;
}