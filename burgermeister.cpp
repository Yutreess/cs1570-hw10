// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.cpp
// Description:

#include "burgermeister.h"
using namespace std;

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
// friend
// BurgerMeister& operator+=(const double& rhs);
BurgerMeister& BurgerMeister::operator += (const double cash)
{
  bmCash = bmCash + cash;
  return *this;
}

BurgerMeister& BurgerMeister::operator -= (const double cash)
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

// Get Functions

string BurgerMeister::getName() const
{
  return bmName;
}

double BurgerMeister::getCash() const
{
  return bmCash;
}

// Non-Member Functions

void feedCustomers(Customer contestants[])
{
  Burger burg;

  for(int i = 0; i < CONTESTANTS; i++)
  {
    // If Customer is Alive
    // AND Customer can afford Burger
    if(contestants[i].getAlive()
       && contestants[i].getCash() > burg.getPrice())
    {
      // Contestant Eats the burger
      contestants[i].eat(burg);

      // Output name of the contestant who ate
      contestants[i].getName();
      cout << " eats "
      << burg.getName() << endl;
    }
    // Output customer stats
    cout << "-----" << contestants[i] << endl;
  }
}
