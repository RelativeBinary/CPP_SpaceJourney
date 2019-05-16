#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

int randNumGen(int min, int max){
    int value = 0;
    std::mt19937 static eng(time(0));
    std::uniform_int_distribution<> dist(min, max-1);//min(includsive) max(exclusive)
    for(int i =0; i<20; i++){
        value = dist(eng);
    } 
    //std::cout << "random number is : " << value << '\n';
    return value;

}

std::string getRandName(){
    std::vector<std::string> names = {"Spike S","Faye V","Edward W", "Jet Black" ,"Barb Dwyer", "Chester Minit", "Doris Shutt", "Dick Hertz", "Freda Livery", "Gus Tofwynde", "Gary Oakie", "Ivana Dayov"};
    std::string newName = names[randNumGen(0, names.size())];
    return newName;
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
    //std::cout << "RACE CHOOSEN WAS: " << race << '\n';
    return race;
}

std::string determineSectorType(){
    int value = randNumGen(0, 100);
    std::string sector = "";
    if (value >= 0 && value <= 34)
    {
        sector = "SpaceShipEncounter";
    }
    else if (value >= 35 && value <= 59)
    {
        sector = "PlanetEncounter";
    }
    else if (value >= 60 && value <= 74)
    {
        sector = "TradingStation";
    }
    else if (value >= 75 && value <= 89)
    {
        sector = "Empty";
    }
    else if (value >= 90 && value <= 99)
    {
        sector = "AsteriodBelt";
    } else {
        std::cerr << "there was an error in selecting sector type\n";
        sector = "error";
    }
    return sector;
}