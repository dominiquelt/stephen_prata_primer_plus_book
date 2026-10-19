#ifndef REGULARSPOT_H
#define REGULARSPOT_H

#include "parkingspot.h"

class RegularSpot : public ParkingSpot {
 public:
  explicit RegularSpot(int id) : ParkingSpot(id) {}

  bool CanAccept(const Vehicle* v) const override;
};

#endif
