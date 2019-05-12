#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>

int randNumGen(int range){
    int value = 0;
    for(int i =0; i<20; i++){
        value = rand() % 100;
    } 
    std::cout << "random number is : " << value << '\n';
    return value;

}


