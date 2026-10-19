#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "car.h"
#include "motorcycle.h"
#include "parkinglot.h"
#include "parkingspot.h"
#include "vehicle.h"

TEST(GetPlate, ReturnValue) {
  std::string platenumber = "DW123";
  Car car(platenumber);
  std::string actualplate = car.GetPlate();
  EXPECT_EQ(platenumber, actualplate);
}

TEST(GetType, ReturnTypeCar) {
  std::string platenumber = "DW123";
  Car car(platenumber);
  EXPECT_EQ(car.getType(), "Car");
}

TEST(GetType, ReturnTypeMotorcycle) {
  std::string platenumber = "DW123";
  Motorcycle motor(platenumber);
  EXPECT_EQ(motor.getType(), "Motorcycle");
}

TEST(ParkingSpotPark, ParkOnEmptySpotReturnTrue) {
  ParkingSpot spot(1);
  Car car1("DW1111");
  EXPECT_TRUE(spot.Park(&car1));
  EXPECT_TRUE(spot.IsOccupied());
}

TEST(ParkingSpotPark, ParkOnOccupiedReturnFalse) {
  ParkingSpot spot(1);
  Car car1("Dw1111");
  Car car2("Dw2222");
  spot.Park(&car1);
  EXPECT_FALSE(spot.Park(&car2));
}

TEST(ParkingSpotPark, ParkNullptrReturnFalse) {
  ParkingSpot spot(1);
  EXPECT_FALSE(spot.Park(nullptr));
  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkingSpotLeave, VehicleBecomesNullPtr) {
  ParkingSpot spot(1);
  Car car("dw1234");
  spot.Park(&car);

  ASSERT_TRUE(spot.IsOccupied());

  spot.Leave();

  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkingSpotOccupied, ReturnTrueOccupied) {
  ParkingSpot spot(1);
  Car car("dw1234");
  spot.Park(&car);

  EXPECT_TRUE(spot.IsOccupied());
}
TEST(ParkingSpotOccupied, ReturnFalseOccupied) {
  ParkingSpot spot(1);
  spot.Park(nullptr);
  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkVehicle, AllSpotsOccupiedReturnsFalse) {
  ParkingLot lot(3);
  std::vector<Car> cars = {Car("DW1"), Car("DW2"), Car("DW3")};
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  Car car1("DW444");
  EXPECT_FALSE(lot.ParkVehicle(&car1));
}
TEST(ParkVehicle, FreeSpotReturnsTrueAndParks) {
  ParkingLot lot(2);
  Car car1("DW444");
  Car car2("DW445");
  lot.ParkVehicle(&car1);
  EXPECT_TRUE(lot.ParkVehicle(&car2));
}

TEST(CountFree, CountFreeWithFreeSpots) {
  ParkingLot lot(4);
  std::vector<Car> cars = {Car("DW1"), Car("DW2"), Car("DW3")};
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  EXPECT_EQ(lot.CountFree(), 1);
}

TEST(CountFree, NoFreeSpots) {
  ParkingLot lot(3);
  std::vector<Car> cars = {Car("Dw111"), Car("Dw222"), Car("Dw333")};
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });

  EXPECT_EQ(lot.CountFree(), 0);
}

TEST(CountOccupied, AllSpotsOccupied) {
  ParkingLot lot(3);
  std::vector<Car> cars = {Car("Dw111"), Car("Dw222"), Car("Dw333")};
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  EXPECT_EQ(lot.CountOccupied(), 3);
}
