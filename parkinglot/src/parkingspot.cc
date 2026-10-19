#include "parkingspot.h"

bool ParkingSpot::Park(Vehicle* v) {
  if (vehicle_ != nullptr || v == nullptr || IsOccupied() || !CanAccept(v)) {
    return false;
  }
  vehicle_ = v;
  return true;
}

void ParkingSpot::Leave() {
  vehicle_ = nullptr;
}

bool ParkingSpot::IsOccupied() const {
  return vehicle_ != nullptr;
}
