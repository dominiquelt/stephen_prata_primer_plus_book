#ifndef CAR_H
#define CAR_H

#include <string>

#include "vehicle.h"

class Car : public Vehicle {
 public:
  explicit Car(std::string plate) : Vehicle(std::move(plate)) {}

  std::string getType() const override;
};
#endif
