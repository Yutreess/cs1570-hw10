// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.cpp
// Description:

#include "burgermeister.h"

ostream& operator << (ostream& os, BurgerMeister& bm)
{
  os << bm.getName()
  << " has $" << bm.getCash();
  return os;
}

BurgerMeister::BurgerMeister()
{
  bmName = NAME;
  bmCash = INITIAL_CASH;
}

BurgerMeister& BurgerMeister::operator += (float cash)
{
  bmCash = bmCash + cash;
  return *this;
}

BurgerMeister& BurgerMeister::operator -= (float cash)
{
  bmCash = bmCash - cash;
  return *this;
}

void BurgerMeister::disqualifyContestant(Customer& c)
{
  //*this += c.getCash();
  c.getName();
  cout << " is disqualified!" << endl;
}

// Non-Member Functions

void feedCustomers(Contestants& con)
{
  Burger burg;
  for(Customer& cus : con)
  {
    // Contestant Eats the burger
    cus.eat(burg);

    // Output name of the contestant who ate
    cus.getName();
    cout << " eats "
    << burg.getName() << endl;

    // Output customer stats
    cout << "-----" << cus << endl;
  }
}
