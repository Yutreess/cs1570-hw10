// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         customer.cpp
// Description:

// cmath is included elsewhere, we do this because it defined M_PI for us, M_PI = 3.14... bla bla
#define _USE_MATH_DEFINES 1

#include "types.h"
#include "customer.h"
#include "burgermeister.h"
using namespace std;

// Initialize Array and its Counter
std::vector<int> Customer::cNamesUsed;

// Number of Living Customers
int Customer::cAreLiving = MAX_CONTESTANTS;

// Contest BurgerMeister
BurgerMeister Customer::Krusty;

// Non-Member Functions
short randInterval(const int lower, const int upper)
{
  return (rand() % upper) + lower;
}

bool nameTaken(const int nameNumber)
{
  for(int i : Customer::cNamesUsed)
  {
    if(nameNumber == i)
      return true;
  }
  return false;
}

ostream& operator << (ostream& os, Customer& c)
{
  // Name
  c.getName();
  // Weight
  os << " weighs " << c.getWeight() << " lbs, ";
  // Cash
  os << "has $" << c.getCash();
  // Cholesterol
  os << ", " << c.getChol() << " IBU";
  // Life Status
  os << " and is "
  << (c.getAlive() ? "ALIVE " : "DEAD ");
  // Health
  os << "(" << c.getHealth() << " / " << MAX_HEALTH << ")";
  return os;
}

// Constructors

Customer::Customer()
{

  // Select random name
  int numNames = 24;
  int nameNumber;
  do
  {
    nameNumber = randInterval(1, numNames);
  }
  while(nameTaken(nameNumber));

  // Assign Name to current Customer
  ifstream name("simpson_names.dat");
  for(int i = 1; i <= nameNumber; i++)
    std::getline(name, cName);

  // Place currently used name into catalog of used names
  Customer::cNamesUsed.push_back(nameNumber);

  // Randomize Weight
  cWeight = randInterval(MIN_WEIGHT, MAX_WEIGHT);
  // Randomize Cholestorol
  cCholesterolLevel = randInterval(MIN_CHOL, MAX_CHOL);
  // Randomize Cash
  cCash = randInterval(MIN_CASH, MAX_CASH);
  // Make Living
  cIsAlive = true;
  // Set Health
  cHealth = MAX_HEALTH;

  // Close names file
  name.close();
}

void Customer::eat(Burger burg)
{
  // Declaring variable to store change in weight
  int weightChange;

  // Customer pays for Burger
  cCash -= burg.getPrice();
  Customer::Krusty += burg.getPrice();

  //TODO: Add Burger Price to BurgerMeister
  //      += burg.getPrice();
  if(!cIsAlive)
  {
    cout << "This Customer is dead." << endl;
  }
  else if(burg.getPathogen())
  {
    if(randInterval(1, 101) > cHealth)
      cIsAlive = false;
    else
    {
      // Cut Health in Half
      cHealth /= 2;
      // Vomits

    }

  }
  else
  {
    // Increase Customer's Cholesterol Level
    cCholesterolLevel += 2.5 * burg.getNumBacon()
                      + (M_PI / 2) * burg.getNumPatties()
                      + cWeight / ((burg.getNumPickles() + 1) * 10);

    // Calculate Anticipated Weight Change
    weightChange = 0.5 *
            pow(burg.getNumPatties(), 2)
            + (1.0 / 8.0) *
            pow(burg.getNumBacon(), 2)
            - burg.getNumPickles() / 4
            + WT_FROM_CHEESE + WT_FROM_SAUCE;
    cWeight += weightChange;
    // Decrease Health
    cHealth -= 2;

    // Customer dies if their weight gain is above 80
    if(weightChange >= MAX_WEIGHT_GAIN)
    {
      cIsAlive = false;
    }

    // Cholesterol is above 300
    if(cCholesterolLevel >= MAX_CHOL)
    {
      cIsAlive = false;
    }

    // Health goes to 0
    if(cHealth <= 0)
    {
      cIsAlive = false;
    }
  }
}

// Get Value Functions

int getNumLiving(Contestants& con)
{
  int numAlive = 0;
  for(Customer& cus : con)
  {
    if(cus.getAlive())
      numAlive++;
  }
  return numAlive;
}
