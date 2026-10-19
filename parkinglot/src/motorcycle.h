#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>

#include "vehicle.h"

class Motorcycle : public Vehicle {
 public:
  explicit Motorcycle(std::string plate) : Vehicle(std::move(plate)) {}
  std::string getType() const override;
};

#endif
