//
// //
// class Roll
// {
// public:
//     Roll(Die& die1, Die& die2);

//     void roll_dice();

//     const int roll_value();

// private:
//     Die& die1;
//     Die& die2;

//     int rolled_value;
// };

// #endif Roll_H
// //

#include "roll.h"
#include "die.h"
#include <iostream>
Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2) {}

void Roll::roll_dice(){
    rolled_value = die1.roll() + die2.roll();
}

const int Roll::roll_value() {
    return rolled_value;
}