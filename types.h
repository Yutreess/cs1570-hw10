
// some common constants and types
#pragma once

#include <array>
using namespace std;

// Numerical Constants
constexpr int MAX_CONTESTANTS = 15;
class Customer;
using Contestants = array<Customer, MAX_CONTESTANTS>;
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
const float WT_FROM_CHEESE = 1.2;
const float WT_FROM_SAUCE  = 2.1;
// Cash
const float MIN_CASH = 25.0;
const float MAX_CASH = 75.0;
// Health
const int MAX_HEALTH = 100;
