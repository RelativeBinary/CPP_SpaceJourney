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
    //std::cout << "random number is : " << value << '\n';
    return value;

}

std::string determineShipType(){
    int value = randNumGen(0, 5);
    std::cout << "determining ship type\n";
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

std::string getRandName(){
    std::vector<std::string> names = {"Barb Dwyer", "Chester Minit", "Doris Shutt", "Dick Hertz", "Freda Livery", "Gus Tofwynde", "Gary Oakie", "Ivana Dayov"};
    std::string newName = names[randNumGen(0, names.size())];
    std::cout << "the new name chosen was: " << newName << '\n';
    return newName;
}

std::string determineRaceType(){
    int value = randNumGen(0, 5);
    std::string race = "";
    if (value == 0){
        race = "Solaris";
    }
    else if (value == 1){
        race = "Scar";
    }
    else if (value == 2){
        race = "Celestial";
    }
    else if (value == 3){
        race = "Galvamek";
    }
    else if (value == 4){
        race = "Human";
    }
    std::cout << "RACE CHOOSEN WAS: " << race << '\n';
    return race;
}
