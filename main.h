// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         12/01/2018
// File:         main.h
// Description:

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
using namespace std;


// Default Burger Names
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
// Numerical Constants
const double PI = 3.14;
const int CONTESTANTS = 15;
// Name Length
const int MAX_NAME_LENGTH = 30;
// Cholestorol Levels
const int MIN_CHOL = 30;
const int MAX_CHOL = 300;
// Initial Weight
const int MIN_WEIGHT = 90;
const int MAX_WEIGHT = 250;
const int MAX_WEIGHT_GAIN = 80;
// Weight Gain
const double WT_FROM_CHEESE = 1.2;
const double WT_FROM_SAUCE  = 2.1;
// Cash
const double MIN_CASH = 25.0;
const double MAX_CASH = 75.0;
// Health
const int MIN_HEALTH = 1;
const int MAX_HEALTH = 100;
// Vomit Dialogue
const string VOMIT_DIALOGUE[4] = {
                                  "LIGGGMMAAA!",
                                  "SAWCOOOON!!",
                                  "OOOOOOOOF!!!",
                                  "SUGGMAAAAA!"};
// BurgerMeister Name and Cash
const string NAME = "Krusty";
const int INITIAL_CASH = 100;
// BurgerMeister Fees
const int VOMITTING_COST = 5;
const int DEATH_COST = 35;

#endif
