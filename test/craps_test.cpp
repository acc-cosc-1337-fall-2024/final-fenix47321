#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

// Die tests
#include "die.h"

TEST_CASE("Does roll return between 1 and 6?"){
	Die die;
	int rollResult = die.roll();
	REQUIRE((rollResult >= 1 && rollResult <= 6));
	// Yes
}

TEST_CASE("Display the numbers 10 times in the correct range"){
	Die die;
	// Loop for 10 case's.
	for (int i = 0; i < 9; i ++){
		
		int rollResult = die.roll();
		REQUIRE(rollResult >= 1);
		REQUIRE(rollResult <= 6);
		std::cout << rollResult << "\n";
	}
}