#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include <string>

#include "car.h"

class ElectricCar : public Car {
 public:
  explicit ElectricCar(std::string plate) : Car(std::move(plate)) {}
  std::string getType() const override { return "ElectricCar"; }
};

#endif
