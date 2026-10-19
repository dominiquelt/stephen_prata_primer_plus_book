#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include <vector>

#include "parkingspot.h"

class Vehicle;

class ParkingLot {
 public:
  explicit ParkingLot(size_t regular, size_t electric, size_t handicapped);
  ~ParkingLot() = default;

  ParkingLot(const ParkingLot&) = delete;
  ParkingLot& operator=(const ParkingLot&) = delete;

  ParkingLot(ParkingLot&&) = default;
  ParkingLot& operator=(ParkingLot&&) = default;

  bool ParkVehicle(Vehicle* v);
  int CountFree() const;
  int CountOccupied() const;

 private:
  std::vector<std::unique_ptr<ParkingSpot>> spots_;
};

#endif
