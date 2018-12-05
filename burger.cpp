// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burger.cpp
// Description:

#include "burger.h"
using namespace std;


ostream& operator <<(ostream& os, Burger& b)
{
  os << "Name:    " << b.getName() << endl;
  os << "Price:  $" << b.getPrice() << endl;
  os << "Patties: " << b.getNumPatties() << endl;
  os << "Bacon:   " << b.getNumBacon() << endl;
  os << "Pickles: " << b.getNumPickles() << endl;
  os << "Cheese:  ";
  os << (b.getCheese() ? "Yes" : "No") << endl;
  os << "Special Sauce:  ";
  os << (b.getSpecialSauce() ? "Yes" : "No") << endl;
  os << "Pathogen:  ";
  os << (b.getPathogen() ? "Yes" : "No") << endl;
  return os;
}

short randInterval(const short lower, const short upper)
{
  return (rand() % upper) + lower;
}

// Constructors

  // Burger <varName>(values)
Burger::Burger(const int patties, const int bacon, const int pickles,
       const bool cheese, const bool sauce, const bool pathogen)
{
  // Assign Member Variables
  bNumPatties = patties;
  bNumBacon = bacon;
  bNumPickles = pickles;
  bHasCheese = cheese;
  bHasSpecialSauce = sauce;
  bHasPathogen = pathogen;
  setName();
  setPrice();
}

  // Burger <varName>
Burger::Burger()
{
  bNumPatties = randInterval(MIN_PATTIES, MAX_PATTIES);
  bNumBacon = randInterval(MIN_BACON, MAX_BACON);
  bNumPickles = randInterval(MIN_PICKLES, MAX_PICKLES);
  bHasCheese = randInterval(0, 1);
  bHasSpecialSauce = randInterval(0, 1);
  bHasPathogen = !(static_cast<bool>(rand() % 10));
  /*
  if(randInterval(1, 10) == 5)
    bHasPathogen = true;
  else
    bHasPathogen = false;
  */
  setName();
  setPrice();
}

// Set Functions

void Burger::setNumPatties(const int patties)
{
  bNumPatties = patties;
}

void Burger::setNumBacon(const int bacon)
{
  bNumBacon = bacon;
}

void Burger::setNumPickles(const int pickles)
{
  bNumPickles = pickles;
}

void Burger::setCheese(const bool cheese)
{
  bHasCheese = cheese;
}

void Burger::setSpecialSauce(const bool sauce)
{
  bHasSpecialSauce = sauce;
}

void Burger::setPathogen(const bool pathogen)
{
  bHasPathogen = pathogen;
}

void Burger::setName()
{
  // Decide Burger Name based on ingredients
  bName = DEFAULT;
  // "Veggie" Burger
  if (bNumPickles >= (bNumBacon
                      +bNumPatties))
  {
    bName += SP
          + MORE_PICKLE_LESS_MEAT;
  }
  // "Koronary" Burger
  else if ((bNumBacon
            + bNumPatties) == 6
            && bNumPickles < 2)
  {
    bName += SP
          + SIX_MEAT_SHORT_PICKLE;
  }
  // Default Naming
  else
  {
    // Name in respect to Patties
    if (bNumPatties == 1)
      bName += SP + SINGLE;
    if (bNumPatties == 2)
      bName += SP + DOUBLE;
    if (bNumPatties == 3)
      bName += SP + TRIPLE;
    if (bNumPickles == 4)
      bName += SP + QUADRUPLE;
    // Name in respect to Bacon
    if (bNumBacon == 0)
      bName += SP + ZERO_BACON;
    if (bNumBacon == 1)
      bName += SP + ONE_BACON;
    if (bNumBacon == 2)
      bName += SP + TWO_BACON;
    if (bNumBacon == 3)
      bName += SP + THREE_BACON;
    if (bNumBacon == 4)
      bName += SP + FOUR_BACON;
    // Name in respect to Pickles
    if (bNumPickles == 0)
      bName += SP + ZERO_PICKLE;
    if (bNumPickles == 1)
      bName += SP + ONE_PICKLE;
    if (bNumPickles == 2)
      bName += SP + TWO_PICKLE;
    if (bNumPickles == 3)
      bName += SP + THREE_PICKLE;
    if (bNumPickles == 4)
      bName += SP + FOUR_PICKLE;
    // Name for having Cheese
    if(bHasCheese)
      bName += SP + HAS_CHEESE;
    // Name for having Special Sauce
    if(bHasSpecialSauce)
      bName += SP + HAS_SAUCE;
  }
  // Default Name Ending
  bName += SP + BURGER;
}

void Burger::setPrice()
{
  bPrice += BUN_PRICE
            + (bNumPatties * PATTY_PRICE)
            + (bNumBacon * BACON_PRICE)
            + (bNumPickles * PICKLE_PRICE);
  if(bHasCheese)
    bPrice += CHEESE_PRICE;
  if(bHasSpecialSauce)
    bPrice += SAUCE_PRICE;
}
