// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         burger.h
// Description:

#ifndef BURGER_H
#define BURGER_H

#include "main.h"
//#include <string>
#include <iostream>
//#include <cstdlib>
using namespace std;

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
    int getNumPatties() const {return bNumPatties; };
    int getNumBacon() const {return bNumBacon; };
    int getNumPickles() const {return bNumPickles; };
    double getPrice() const {return bPrice; };
    bool getCheese() const {return bHasCheese; };
    bool getSpecialSauce() const {return bHasSpecialSauce; };
    bool getPathogen() const {return bHasPathogen; };
    string getName() const {return bName; };

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
