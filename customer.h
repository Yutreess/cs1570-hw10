// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         customer.h
// Description:

#pragma once

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "types.h"
#include "burger.h"

// Vomit Dialogue
const string VOMIT_DIALOGUE[4] = {
                                  "BLEEHHLECH",
                                  "GURGLAHCH",
                                  "PAGHLAECH",
                                  "JELECHAAM"};

// Customer Class
class BurgerMeister;
class Customer
{
  public:
    // To use for storing previously used names
    static std::vector<int> cNamesUsed;
    static int cAreLiving;
    static BurgerMeister Krusty;

    // Constructors
    Customer();

    // Customer Actions
    void eat(Burger burg);
    void vomit();
    void toss();

    // Get Value Functions
    int getNumLiving(Contestants&);
    int getWeight() const { return cWeight; }
    short getChol() const { return cCholesterolLevel; }
    float getCash() const { return cCash; }
    bool getAlive() const { return cIsAlive; }
    void getName() const { cout << cName; }
    int getHealth() const { return cHealth; }
  private:
    int cWeight;
    short cCholesterolLevel;
    float cCash;
    int cHealth;
    bool cIsAlive;
    string cName;
};

// Non-member Functions
short randInterval(const int lower, const int upper);

ostream& operator << (ostream& os, Customer& c);

//void feedCustomers(Customer contestants[]);

bool nameTaken(const int nameNumber);
