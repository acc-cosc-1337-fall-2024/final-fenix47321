//
#include "die.h"
#include <random>
#include <iostream>

int Die::roll(){
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(1, sides);
    return dist(rng);
}

// PLAN B :)
// int Die::roll(){
//     return rand() % sides + 1;
// }