// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.h
// Description:

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

// Constants
const string NAME = "Krusty";
const int INITIAL_CASH = 100;

// Burgermeister Class
class BurgerMeister
{
  public:
      // Constructor
    BurgerMeister();
    // Member operator Overloads
    BurgerMeister& operator += (float cash);
    BurgerMeister& operator -= (float cash);
    // BurgerMeister Actions
    void disqualifyContestant(Customer c);
    // Get Functions
    string getName();
    double getCash();
  private:
    string bmName;
    double bmCash;
};

// Non-Member Functions
ostream& operator << (ostream& os, BurgerMeister& bm);

void feedCustomers(Customer contestants[]);

#endif
