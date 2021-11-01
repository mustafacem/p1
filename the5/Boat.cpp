#include "Boat.h"


// implementation of dice class
// written Jan 31, 1994, modified 5/10/94 to use RandGen class
// modified 3/31/99 to move RandGen class here from .h file

Boat:: Boat(string isb, string idb, string reb);
// postcondition: all private fields initialized     
{
  
}

int Boat::bir()
// postcondition: number of rolls updated
//                random 'die' roll returned     
{
	string gen;    // random number generator
    
	gen ="";

    return gen.RandInt(1,mySides);        // in range [1..mySides]
}
/*
int Dice::NumSides() const
// postcondition: return # of sides of die     
{
    return mySides;
}

int Dice::NumRolls() const
// postcondition: return # of times die has been rolled     
{
    return myRollCount;
}

int Dice::MultipleRolls(int n) {
    int sum = 0;
    
    for (int i=0; i < n; i++) {
        sum += Roll();
    }
    
    return sum;
	*/
}
