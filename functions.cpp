#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

int randNumGen(int min, int max){
    int value = 0;
    for(int i =0; i<20; i++){
        value = rand() % max;
        value += min;
    } 
    std::cout << "random number is : " << value << '\n';
    return value;

}

std::string determineShipType(){
    int value = randNumGen(0, 5);

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




