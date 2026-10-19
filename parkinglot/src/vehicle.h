#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
 public:
  explicit Vehicle(std::string plate) : plate_(std::move(plate)) {}
  virtual ~Vehicle() = default;
  // copy
  Vehicle(const Vehicle&) = delete;
  Vehicle& operator=(const Vehicle&) = delete;
  // move
  Vehicle(Vehicle&&) = default;
  Vehicle& operator=(Vehicle&&) = default;

  std::string GetPlate() const;
  virtual std::string getType() const = 0;

 private:
  std::string plate_;
};

#endif
