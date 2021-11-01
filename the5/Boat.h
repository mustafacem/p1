#ifndef  _BOAT_H
#define  _BOAT_H

/******************************************************************** 
This code is freely distributable and modifiable providing you
leave this notice in it.
Copyright @ Owen Astrachan
********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Boat
{
  public:
	  Boat(string isb, string idb, string reb);           // constructor
    int bir();                // return the random roll
    /*int NumSides() const;      // how many sides this die has
    int NumRolls() const;      // # times this die rolled
    
    int MultipleRolls(int);
    
  private:
    int myRollCount;           // # times die rolled
    int mySides;               // # sides on die
	*/
};

#endif    /* _DICE_H not defined */