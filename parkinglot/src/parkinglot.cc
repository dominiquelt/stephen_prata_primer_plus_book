#include "parkinglot.h"

#include <algorithm>

#include "ElectricSpot.h"
#include "HandicappedSpot.h"
#include "RegularSpot.h"

ParkingLot::ParkingLot(size_t regular, size_t electric, size_t handicapped) {
  for (size_t i = 0; i < regular; i++) {
    spots_.push_back(std::make_unique<RegularSpot>(i));
  }
  for (size_t i = 0; i < electric; i++) {
    spots_.push_back(std::make_unique<ElectricSpot>(i));
  }
  for (size_t i = 0; i < handicapped; i++) {
    spots_.push_back(std::make_unique<HandicappedSpot>(i));
  }
}
bool ParkingLot::ParkVehicle(Vehicle* v) {
  auto pspot = std::find_if(spots_.begin(), spots_.end(),
                            [v](const std::unique_ptr<ParkingSpot>& spot) {
                              return !spot->IsOccupied() && spot->CanAccept(v);
                            });
  if (pspot == spots_.end()) {
    return false;
  } else {
    return (*pspot)->Park(v);
  }
}
int ParkingLot::CountFree() const {
  return std::count_if(spots_.begin(), spots_.end(),
                       [](const std::unique_ptr<ParkingSpot>& spot) {
                         return !spot->IsOccupied();
                       });
}
int ParkingLot::CountOccupied() const {
  return std::count_if(spots_.begin(), spots_.end(),
                       [](const std::unique_ptr<ParkingSpot>& spot) {
                         return spot->IsOccupied();
                       });
}
