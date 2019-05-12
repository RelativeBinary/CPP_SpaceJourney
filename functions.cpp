#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

int randNumGen(int range){//a need to take upper and lower limits for ship types and race types.
    int value = 0;
    for(int i =0; i<20; i++){
        value = rand() % 100;
    } 
    std::cout << "random number is : " << value << '\n';
    return value;

}

std::string determineShipType(){
    int value = 0;
    for (int i = 0; i < 20; i++){
        value = rand() % 5;
    }
    std::cout << "random number is : " << value << '\n';

    if (value == 0){
        return "Dawn Sailor";
    }else if ( value == 1){
        return "Scavenger";
    }else if ( value == 2){
        return "Nebula";
    }else if ( value == 3){
        return "ONE-HIT-WONDER";
    }else if ( value == 4){
        return "Jack";
    }
    return "error";
}




