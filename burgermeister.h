// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.h
// Description:

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

#include "main.h"
#include <iostream>
#include <string>
#include "burger.h"
#include "customer.h"

using namespace std;

// Burgermeister Class
class BurgerMeister
{
  public:
      // Constructor
    BurgerMeister();
    // Member operator Overloads
    BurgerMeister& operator += (const double cash);
    BurgerMeister& operator -= (const double cash);
    // BurgerMeister Actions
    void disqualifyContestant(Customer& c);
    // Get Functions
    string getName() const {return bmName; };
    double getCash() const {return bmCash; };
  private:
    string bmName;
    double bmCash;
};

// Non-Member Functions
ostream& operator << (ostream& os, BurgerMeister& bm);

void feedCustomers(Customer contestants[]);

#endif
