//

#include "die.h"

#ifndef Roll_H
#define Roll_H

class Roll
{
public:
    Roll(Die& die1, Die& die2);

    void roll_dice();

    const int roll_value();

private:
    Die& die1;
    Die& die2;

    int rolled_value;
};

#endif Roll_H