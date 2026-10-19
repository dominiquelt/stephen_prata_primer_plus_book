#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "vehicle.h"

class ParkingSpot {
 public:
  explicit ParkingSpot(int id) : id_(id), vehicle_(nullptr) {}
  virtual ~ParkingSpot() = default;

  ParkingSpot(const ParkingSpot&) = delete;
  ParkingSpot& operator=(const ParkingSpot&) = delete;

  ParkingSpot(ParkingSpot&& other) noexcept {
    id_ = other.id_;
    vehicle_ = other.vehicle_;
    other.vehicle_ = nullptr;
  }
  ParkingSpot& operator=(ParkingSpot&& other) noexcept {
    if (this == &other) {
      return *this;
    }
    id_ = other.id_;
    vehicle_ = other.vehicle_;
    other.vehicle_ = nullptr;
    return *this;
  }

  bool Park(Vehicle*);
  void Leave();
  bool IsOccupied() const;
  virtual bool CanAccept(const Vehicle* v) const = 0;

 private:
  int id_;
  Vehicle* vehicle_;
};

#endif
