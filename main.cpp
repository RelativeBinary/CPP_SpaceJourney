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

    SpaceShip f1;
    Officer f2;
    SpaceSector f3;

    return 0;
}