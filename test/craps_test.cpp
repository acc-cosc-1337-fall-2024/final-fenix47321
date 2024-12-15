#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}



// Die tests (Q1)
#include "die.h"

TEST_CASE("Does roll return between 1 and 6?"){
	Die die;
	int rollResult = die.roll();
	REQUIRE((rollResult >= 1 && rollResult <= 6));
	
	// Yes
}

TEST_CASE("Display the numbers 10 times in the correct range"){
	Die die;
	std:: cout << "Manual lookup (Die (Q1)): " << "\n";
	// Loop for 10 case's.
	for (int i = 0; i < 9; i ++){
		
		int rollResult = die.roll();
		REQUIRE(rollResult >= 1);
		REQUIRE(rollResult <= 6);
		std::cout << rollResult << "\n";
	}
}



// Roll's tests (Q2)
#include "roll.h"
TEST_CASE("Ensuring that results are in the correct range"){
	Die die1;
	Die die2;

	Roll roll(die1, die2);
	
	roll.roll_dice();
	int Ddices = roll.roll_value();

	REQUIRE((Ddices >= 2 && Ddices <= 12));
}

TEST_CASE("10 times two dices"){
	std:: cout << "Manual lookup (Roll (Q2)): " << "\n";
	for (int i = 0; i < 10; i++){
		Die die1;
		Die die2;

		Roll roll(die1, die2);
		
		roll.roll_dice();
		int Ddices = roll.roll_value();

		REQUIRE((Ddices >= 2 && Ddices <= 12));

		std::cout << Ddices << "\n";
	}
}



// Shooters test (Q3)
#include "shooter.h"


TEST_CASE("Question 3, shooter checker"){
	std:: cout << "Manual lookup (Roll (Q3)): " << "\n";

	Die die1;
	Die die2;

	Shooter shooter;	
	for (int i = 0; i < 10; i++){
		

		Roll* roll = shooter.throw_dice(die1, die2);
		int roll_value = roll->roll_value();

		REQUIRE((roll_value >= 2 && roll_value <= 12));

		std::cout << roll_value << "\n";
	}
}



// Come out and Points tests (Q4)


// Come out
#include "come_out_phase.h"

TEST_CASE("ComeOutPhase get_outcome tests (Q4, a)"){
	Die die1;
	Die die2;
	ComeOutPhase comeOutPhase;
	std::cout << "\nCome out phase test\n";
	Roll roll(die1,die2);

	for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int rolled_value = roll.roll_value();

        RollOutcome outcome = comeOutPhase.get_outcome(&roll);

        std::cout << "Rolled value: " << rolled_value << ", Outcome: ";

        if (outcome == RollOutcome::natural) {
            std::cout << "natural\n";
            REQUIRE((rolled_value == 7 || rolled_value == 11));
        } else if (outcome == RollOutcome::craps) {
            std::cout << "craps\n";
            REQUIRE((rolled_value == 2 || rolled_value == 3 || rolled_value == 12));
        } else if (outcome == RollOutcome::point) {
            std::cout << "point\n";
            REQUIRE((rolled_value == 4 || rolled_value == 5 || rolled_value == 6 || 
                     rolled_value == 8 || rolled_value == 9 || rolled_value == 10));
        }
    }
}

// PointPhase

#include "point_phase.h"

TEST_CASE("Point phase check (Q4, b)"){
	Die die1;
	Die die2;

	int point_value = 0;
	std::cout << "\nPoint phase test\n";
	PointPhase pointPhase(point_value);

	for (int i = 0; i < 10; i++){
		Roll roll(die1,die2);
		roll.roll_dice();
		int rolled_value = roll.roll_value();

		RollOutcome outcome = pointPhase.get_outcome(&roll);

		std::cout << "Rolled value: " << rolled_value << ", Outcome: ";

		if (outcome == RollOutcome::point) {
			std::cout << "Point\n";
			REQUIRE(rolled_value == point_value);
		}
		else if (outcome == RollOutcome::seven_out){
			std::cout << "seven_out\n";
			REQUIRE(rolled_value == 7);
		}
		else if (outcome == RollOutcome::nopoint){
			std::cout << "nopoint\n";
			REQUIRE((rolled_value != point_value && rolled_value != 7));
		}
	}
}
