// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         customer.h
// Description:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
//#include <cstdlib>
#include <fstream>
#include <cmath>
#include "burger.h"
//#include "burgermeister.h"
class BurgerMeister;

using namespace std;

// Customer Class
class Customer
{
  public:
    // To use for storing previously used names
    static int cNamesUsed[CONTESTANTS];
    static int cNumNamesUsed;
    // Number of Customers Alive
    static int cAreLiving;
    // Contest BurgerMeister
    static BurgerMeister Krusty;

    // Constructors
    Customer();

    // Member operator Overloads
    //Customer& operator -= (const double price);

    // Reset Functions
    void nullVomitted();
    // Customer Actions
    void eat(Burger burg);
    void vomit();
    void toss(Customer& victim, Burger tBurg);
    void payBurgerMeister(Burger burg);

    // Get Value Functions


    int getWeight() const { return cWeight; };
    short getChol() const { return cCholesterolLevel; };
    double getCash() const { return cCash; };
    bool getAlive() const { return cIsAlive; };
    void getName() const;
    int getHealth() const { return cHealth; };
    bool getHasVomitted() const { return cVomitted; };
  private:
    int cWeight;
    short cCholesterolLevel;
    double cCash;
    int cHealth;
    bool cIsAlive;
    bool cVomitted;
    char cName[MAX_NAME_LENGTH];
};

// Non-member Functions

short randInterval(const int lower, const int upper);

bool nameTaken(const int nameNumber);

ostream& operator << (ostream& os, Customer& c);

int getNumLiving(Customer contestants[]);

int nameCount(ifstream & in);

#endif
