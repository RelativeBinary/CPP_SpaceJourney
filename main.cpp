#include "functions.h"
#include "Officer.h"
#include "SpaceShip.h"
#include "SpaceSector.h"
int main(int argc, char* argv[]){
    std::cout << "Charging Partical Accellerators.." << '\n';
    std::cout << '\n';
    std::cout << "Lauching The Space Journey" << '\n';
    //take cli args
    const int limit = std::atoi(argv[1]);
    std::cout << "Targeting " << limit << " sectors from initializtion point" << '\n';

    //initialize spaceship

    //initialize officiers and skill stats

    #pragma region
    //Officer function testing
    //Stage one - no rng, testing function effects
    Officer f2;
    f2.displayOfficer();
    f2.levelUpSkill(10);
    f2.recieveDamage(20);
    f2.restoreHealth(5);
    f2.displayOfficer();



    #pragma endregion

    SpaceShip f1;
    SpaceSector f3;

    return 0;
}