// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burger.h
// Description:

#ifndef BURGER_H
#define BURGER_H

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// Constants

const string DEFAULT = "Krusty";
const string BURGER  = "Burger";
// Burger ingreedient costs
const float PICKLE_PRICE = 0.25;
const float PATTY_PRICE  = 0.75;
const float BACON_PRICE  = 0.50;
const float BUN_PRICE    = 0.50;
const float CHEESE_PRICE = 0.25;
const float SAUCE_PRICE  = 0.10;
// Name per # of Patties
const string SINGLE    = "Single";
const string DOUBLE    = "Double";
const string TRIPLE    = "Triumph";
const string QUADRUPLE = "Quadro";
// Name per Ounces of Bacon
const string ZERO_BACON  = "Health Master";
const string ONE_BACON   = "Bacon";
const string TWO_BACON   = "Wilbur";
const string THREE_BACON = "Klogger";
const string FOUR_BACON  = "Porkreich";
// Name per Ounces of Pickles
const string ZERO_PICKLE  = "Tasteless";
const string ONE_PICKLE   = "Pickly";
const string TWO_PICKLE   = "Garden-Fresh";
const string THREE_PICKLE = "Kermit";
const string FOUR_PICKLE  = "Shrek";
// Name for having Cheese
const string HAS_CHEESE = "Cheesy";
// Name for having Special Sauce
const string HAS_SAUCE = "Tasty";
// Special Case Burger names & Space Insert
const string SIX_MEAT_SHORT_PICKLE = "Koronary";
const string MORE_PICKLE_LESS_MEAT = "Veggie";
const string SP		     = " ";
// Minimum and Maximum ingredient values
const short MIN_PATTIES = 1;
const short MAX_PATTIES = 4;
const short MIN_BACON = 0;
const short MAX_BACON = 4;
const short MIN_PICKLES = 0;
const short MAX_PICKLES = 4;

// Burger Class

class Burger
{
  public:

    // Constructors
    Burger(const int patties, const int bacon, const int pickles,
           const bool cheese, const bool sauce, const bool pathogen);
    Burger();
    // Set Functions
    void setNumPatties(const int patties);
    void setNumBacon(const int bacon);
    void setNumPickles(const int pickles);
    void setCheese(const bool cheese);
    void setSpecialSauce(const bool sauce);
    void setPathogen(const bool pathogen);
    void setName();
    void setPrice();
    // Get Functions
    int getNumPatties();
    int getNumBacon();
    int getNumPickles();
    double getPrice();
    bool getCheese();
    bool getSpecialSauce();
    bool getPathogen();
    string getName();
  private:
    int bNumPatties;
    int bNumBacon;
    int bNumPickles;
    float bPrice;
    bool bHasCheese;
    bool bHasSpecialSauce;
    bool bHasPathogen;
    string bName;
};

// Operator Overload
ostream& operator << (ostream& os, Burger& b);

#endif
