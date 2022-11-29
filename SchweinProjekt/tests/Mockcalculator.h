#pragma once
#include "gmock/gmock.h"
#include "../source/calculator.h"

class Mockcalculator : public calculator {
 public:
  MOCK_METHOD(double, add, (double a, double b), ( override));
  MOCK_METHOD(double, sub, (double a, double b), ( override));
};
