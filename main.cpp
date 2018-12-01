// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         main.cpp
// Description:

#include <string>
#include <iostream>
#include <cstdlib>
#include "burgermeister.h"
#include "customer.h"
using namespace std;

int main()
{
  // Seed Random Number Generator
  srand(time(0));

  // Round #
  int round = 1;

  // Array of Contestants
  // (CONTESTANTS defined in customer.h)
  Customer contestants[CONTESTANTS];

  // Contest Burgermeister
  //BurgerMeister Krusty;

  // Force prices tp be listed in 2 decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  // Announce
  cout << "Let the Burger Eating Contest Commence!" << endl;

  // Print Contestants
  cout << "The Contestants Are:" << endl;
  for(int i = 0; i < CONTESTANTS; i++)
    cout << i+1 << ":\t"
    << contestants[i] << endl;

  // Play rounds
  cout << "------------------------ "
  << "ROUND #" << round
  << " -------------------" << endl;

  feedCustomers(contestants);
  return 0;
}
