#include "HandicappedSpot.h"

bool HandicappedSpot::CanAccept(const Vehicle* v) const {
  return v->getType() == "HandicappedCar";
}
