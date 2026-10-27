#include "RegularSpot.h"

bool RegularSpot::CanAccept(const Vehicle* v) const {
  return v->getType() == "Car" || v->getType() == "Motorcycle";
}
