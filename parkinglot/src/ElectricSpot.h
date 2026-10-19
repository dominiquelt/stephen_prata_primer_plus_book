#ifndef ELECTRICSPOT_H
#define ELECTRICSPOT_H

#include "parkingspot.h"

class ElectricSpot : public ParkingSpot {
 public:
  explicit ElectricSpot(int id) : ParkingSpot(id) {}

  bool CanAccept(const Vehicle* v) const override;
};

#endif
