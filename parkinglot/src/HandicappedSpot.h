#ifndef HANDICAPPEDSPOT_H
#define HANDICAPPEDSPOT_H

#include "parkingspot.h"

class HandicappedSpot : public ParkingSpot {
 public:
  explicit HandicappedSpot(int id) : ParkingSpot(id) {}

  bool CanAccept(const Vehicle* v) const override;
};

#endif
