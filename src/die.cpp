//
#include "die.h"
#include <random>
#include <iostream>

int Die::roll(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, sides);
    return dist(rd);
}