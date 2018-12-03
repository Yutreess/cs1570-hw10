// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.h
// Description:

#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "burger.h"
#include "customer.h"

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
    void disqualifyContestant(Customer& c);
    // Get Functions
    string getName() const { return bmName; }
    float getCash() const { return bmCash; }
  private:
    string bmName;
    float bmCash;
};

// Non-Member Functions
ostream& operator << (ostream& os, BurgerMeister& bm);

void feedCustomers(Contestants&);
