#include <iostream>
#include <string>
#include <vector>
#include <random>

int randNumGen(int range){
    static std::random_device randEngine;
    static std::mt19937 gen(randEngine());
    static std::uniform_real_distribution<>dis(0.0,1.0);

    int value = 0;

    for (int i = 0; i < 50; i++){
        value = range * dis(gen);
        //std::cout << value << '\n';
    }

    return value;

}


