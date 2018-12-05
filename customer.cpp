// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/10/2018
// File:         customer.cpp
// Description:


#include "customer.h"
#include "burgermeister.h"
using namespace std;

// Initialize Array and its Counter
int Customer::cNamesUsed[CONTESTANTS];
int Customer::cNumNamesUsed = 0;

// Number of Living Customers
int Customer::cAreLiving = CONTESTANTS;

// Contest BurgerMeister
BurgerMeister Customer::Krusty;

// Non-Member Functions

short randInterval(const int lower, const int upper)
{
  return (rand() % upper) + lower;
}

bool nameTaken(const int nameNumber)
{
  for(int i = 0; i < Customer::cNumNamesUsed; i++)
  {
    if(nameNumber == Customer::cNamesUsed[i])
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

int getNumLiving(Customer contestants[])
{
  int numAlive = 0;
  for(int i = 0; i < CONTESTANTS; i++)
  {
    if(contestants[i].getAlive())
      numAlive++;
  }
  return numAlive;
}

int nameCount(ifstream& in)
{
  // Allows the usage of the getline, no other purpose
  string temp;
  int numNames = 0;

  // Program will halt until connection to file established
  do
  {
    in.clear();
    in.open("simpson_names.dat");
  } while(!in);

  while (getline(in, temp, '\n'))
  {
    numNames++;
  }

  in.close();
  return numNames;
}

// Constructors

Customer::Customer()
{
  ifstream name;
  int nameNumber;
  int numNames = nameCount(name);
  name.open("simpson_names.dat");

  // Select random unused name
  do
  {
    nameNumber = randInterval(1, numNames);
  }
  while(nameTaken(nameNumber));

  // Assign Name to current Customer
  for(int i = 1; i <= nameNumber; i++)
    name.getline(cName, MAX_NAME_LENGTH);

  // Place currently used name into catalog of used names
  Customer::cNamesUsed[Customer::cNumNamesUsed] = nameNumber;

  // Increment Names Used
  Customer::cNumNamesUsed++;

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
  //cHealth = randInterval(MIN_HEALTH, MAX_HEALTH);
  // They haven't vommitted.... yet.
  cVomitted = false;
  // Close names file
  name.close();
}

void Customer::nullVomitted()
{
  cVomitted = false;
}

void Customer::eat(Burger burg)
{
  // Declaring variable to store change in weight
  int weightChange;

  // Customer pays for Burger
  payBurgerMeister(burg);

  //TODO: Add Burger Price to BurgerMeister
  //      += burg.getPrice();
  if(!cIsAlive)
  {
    cout << "This Customer is dead." << endl;
  }
  if(burg.getPathogen())
  {
    if(randInterval(1, 101) > cHealth)
    {
      cIsAlive = false;
      cVomitted = false;
    }
    else
    {
      // Cut Health in Half
      cHealth /= 2;
      // Vomits
      vomit();
    }
  }
  else
  {
    // Increase Customer's Cholesterol Level
    cCholesterolLevel += 2.5 * burg.getNumBacon()
                      + (PI / 2) * burg.getNumPatties()
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
      Customer::Krusty -= DEATH_COST;
      cVomitted = false;
    }

    // or if Cholesterol is above 300
    else if(cCholesterolLevel >= MAX_CHOL)
    {
      cIsAlive = false;
      Customer::Krusty -= DEATH_COST;
      cVomitted = false;
    }

    // or if Health goes to 0
    else if(cHealth < MIN_HEALTH)
    {
      cIsAlive = false;
      Customer::Krusty -= DEATH_COST;
      cVomitted = false;
    }
  }
}

void Customer::vomit()
{
  // Set HasVomitted to true
  cVomitted = true;

  // Customer Vomitting dialogue
  cout << "|||||" << cName << " barfs "
  << VOMIT_DIALOGUE[randInterval(0, 3)] << " "
  << VOMIT_DIALOGUE[randInterval(0, 3)] << endl;
  // Krusty pays for cleanup. It doesn't get done, but he pays nonetheless.
  Customer::Krusty -= VOMITTING_COST;
}

void Customer::toss(Customer& victim, Burger tBurg)
{
  // Health increases by 2
  cHealth += 2;

  // Pay burgerMeister for thrown Burger
  payBurgerMeister(tBurg);

  // Announce the throw
  cout << "##### " << cName << " yeets burger at ";
  victim.getName();
  cout << endl;
}

void Customer::payBurgerMeister(Burger burg)
{
  cCash -= burg.getPrice();
  Customer::Krusty += burg.getPrice();
}



void Customer::getName() const
{
  int i = 0;
  while (cName[i] != '\0')
  {
    cout << cName[i];
    i++;
  }
}

/*
int Customer::getHealth() const
{
  return cHealth;
}
*/

/*
int Customer::getNamesUsed()
{
  return cNamesUsed;
}
int Customer::getNumNamesUsed()
{
  return cNumNamesUsed;
}
*/
