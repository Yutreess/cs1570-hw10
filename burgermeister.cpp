// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burgermeister.cpp
// Description:

#include "burgermeister.h"
using namespace std;

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
  // If Krusty will go deficit for paying, just don't.
  if(bmCash - cash < 0)
    return *this;
  else
  {
    bmCash = bmCash - cash;
    return *this;
  }
}

void BurgerMeister::disqualifyContestant(Customer& c)
{
  //*this += c.getCash();
  c.getName();
  cout << " is disqualified!" << endl;
}

// Non-Member Functions

ostream& operator << (ostream& os, BurgerMeister& bm)
{
  os << bm.getName()
  << " has $" << bm.getCash();
  return os;
}

void feedCustomers(Customer contestants[])
{
  Burger burg;

  // For all Contestants
  for(int i = 0; i < CONTESTANTS; i++)
  {
    // If This Customer is Alive
    // AND This Customer can afford Burger
    if(contestants[i].getAlive()
       && contestants[i].getCash() > burg.getPrice())
    {
      // Output name of the contestant who ate
      contestants[i].getName();
      cout << " eats " << burg.getName() << endl;

      // Contestant Eats the burger
      contestants[i].eat(burg);
    }
    // If this customer vomitted from eating the burger...
    //int v = i;
    if(contestants[i].getHasVomitted())
    {
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~ "
      << "Someone's Sick!"
      << " ~~~~~~~~~~~~~~~~~~~~~~~~"
      << endl;

      cout << "~~~~~~~~~~~~~~~~~~~~~~~~ "
      << "Going Down!"
      << " ~~~~~~~~~~~~~~~~~~~~~~~~"
      << endl;
      // For all customers BELOW them,
      // Execute the following block until
      // a customer below them doesn't vomit
      for(int v = i; v < CONTESTANTS - 1; v++)
      {
        while(contestants[v].getHasVomitted()
              && contestants[v].getAlive())
        {
          // The customer below
          // has a 50% chance of vommiting
          if(rand() % 2)
            contestants[v+1].vomit();
          else
          {
            cout << "|||||";
            contestants[v+1].getName();
            cout << " doesn't barf" << endl;

            // 70& Chance a Food Fight Begins
            if((rand() % 10) < 7)
            {


              int tossTarget = randInterval(0, CONTESTANTS);
              while
              (
                contestants[tossTarget].getAlive()
                && contestants[v+1].getCash() >= burg.getPrice()
              )
              {
                // Announce food fight
                cout << "######################## "
                << "FOOD FIIIIGHT!"
                << " ########################"
                << endl;

                contestants[v+1].toss(contestants[tossTarget], burg);
                tossTarget = randInterval(0, CONTESTANTS);
              }
            }
          }
          v++;
        }
      }

      cout << "~~~~~~~~~~~~~~~~~~~~~~~~ "
      << "Going Up!"
      << " ~~~~~~~~~~~~~~~~~~~~~~~~"
      << endl;

      // Repeat for contestants ABOVE current customer
      for(int v = i; v >= 0; v--)
      {
        while(contestants[v].getHasVomitted()
              && contestants[v].getAlive())
        {
          // The customer below
          // has a 50% chance of vommiting
          if(rand() % 2)
            contestants[v-1].vomit();
          else
          {
            cout << "|||||";
            contestants[v-1].getName();
            cout << " doesn't barf" << endl;

            // 70& Chance a Food Fight Begins
            if((rand() % 10) < 7)
            {

              int tossTarget = randInterval(0, CONTESTANTS);
              while
              (
                contestants[tossTarget].getAlive()
                && contestants[v-1].getCash() >= burg.getPrice()
              )
              {
                // Announce food fight
                cout << "######################## "
                << "FOOD FIIIIGHT!"
                << " ########################"
                << endl;

                contestants[v-1].toss(contestants[tossTarget], burg);
                tossTarget = randInterval(0, CONTESTANTS);
              }
            }
          }
          v--;
        }
      }

      cout << "~~~~~~~~~~~~~~~~~~~~~~~~ "
      << "Sick days are up, keep eating!"
      << " ~~~~~~~~~~~~~~~~~~~~~~~~"
      << endl;
    }
    /*
    for(int v = i; v < CONTESTANTS; v++)
    {
      // The customer below
      // has a 50% chance of vommiting
        if(rand() % 2)
          contestants[v+1].vomit();
    }
    */
    // Output customer stats
    cout << "-----" << contestants[i] << endl;
  }
  // End round by resetting relevant values
  for(int i = 0; i < CONTESTANTS; i++)
    contestants[i].nullVomitted();
}
