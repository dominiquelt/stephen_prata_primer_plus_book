#ifndef HANDICAPPEDCAR_H
#define HANDICAPPEDCAR_H

#include <string>

#include "car.h"

class HandicappedCar : public Car {
 public:
  explicit HandicappedCar(std::string plate) : Car(std::move(plate)) {}
  std::string getType() const override { return "HandicappedCar"; }
};

#endif
