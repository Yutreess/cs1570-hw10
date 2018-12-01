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
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "burger.h"
#include "burgermeister.h"
using namespace std;

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
const int MAX_HEALTH = 100;
// Burger Class

class Customer
{
  public:
    // To use for storing previously used names
    static int cNamesUsed[CONTESTANTS];
    static int cNumNamesUsed;
    static BurgerMeister Krusty;

    // Constructors
    Customer();

    // Customer Actions
    void eat(Burger burg);
    void vomit();
    void toss();

    // Get Value Functions
    int getWeight();
    short getChol();
    double getCash();
    bool getAlive();
    void getName();
    int getHealth();
  private:
    int cWeight;
    short cCholesterolLevel;
    double cCash;
    int cHealth;
    bool cIsAlive;
    char cName[MAX_NAME_LENGTH];
};

// Non-member Functions

short randInterval(const int lower, const int upper);

ostream& operator << (ostream& os, Customer& c);

//void feedCustomers(Customer contestants[]);

bool nameTaken(const int nameNumber);


#endif
