//
#include"die.h"
#include"roll.h"
#include <vector>
#ifndef Shooter_H
#define Shooter_H

class Shooter
{
public:
    Shooter();
    Roll* throw_dice(Die& die1, Die& die2);
    void display_rolled_values() const;
    ~Shooter();

private:
    std::vector<Roll*> rolls;
};

#endif Shooter_H