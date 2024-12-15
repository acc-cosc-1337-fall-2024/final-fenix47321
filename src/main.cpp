#include <iostream>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std::cout;

int main() 
{
	Die die1;
	Die die2;

	Shooter shooter;
	Roll* roll = shooter.throw_dice(die1, die2);

	ComeOutPhase come_out_phase;

	int rolled_value;

	while (true) {
        rolled_value = roll->roll_value();
        std::cout << "Rolled " << rolled_value << "\n";
        
        RollOutcome outcome = come_out_phase.get_outcome(roll);
        
        if (outcome == RollOutcome::natural) {
            std::cout << "Shooter wins with natural " << rolled_value << "\n";
            break;  
        } else if (outcome == RollOutcome::craps) {
            std::cout << "Shooter loses with craps " << rolled_value << "\n";
            break; 
        } else if (outcome == RollOutcome::point) {
            std::cout << "Rolled " << rolled_value << " - Start of point phase\n";
            std::cout << "Roll until " << rolled_value << " or a 7 is rolled\n";
            int point = rolled_value;  
            PointPhase point_phase(point);

            // Loop for point phase
            while (true) {
				roll = shooter.throw_dice(die1, die2);
                rolled_value = roll->roll_value();
                std::cout << "Rolled " << rolled_value << " - Roll again\n";
                
                
                // Check outcome of the point phase
                if (rolled_value == point) {
                    std::cout << "Shooter wins with point " << point << "\n";
                    break;
                } else if (rolled_value == 7) {
                    std::cout << "Shooter loses with seven out\n";
                    break;
                }
            }
            break;
        }

    }

	return 0;
}