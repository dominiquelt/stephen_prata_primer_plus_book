#include "ElectricSpot.h"

bool ElectricSpot::CanAccept(const Vehicle* v) const {
  return v->getType() == "ElectricCar";
}
