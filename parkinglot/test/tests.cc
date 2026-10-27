#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "ElectricCar.h"
#include "ElectricSpot.h"
#include "HandicappedCar.h"
#include "HandicappedSpot.h"
#include "RegularSpot.h"
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
  RegularSpot spot(1);
  Car car1("DW1111");
  EXPECT_TRUE(spot.Park(&car1));
  EXPECT_TRUE(spot.IsOccupied());
}

TEST(ParkingSpotPark, ParkOnOccupiedReturnFalse) {
  RegularSpot spot(1);
  Car car1("Dw1111");
  Car car2("Dw2222");
  spot.Park(&car1);
  EXPECT_FALSE(spot.Park(&car2));
}

TEST(ParkingSpotPark, ParkNullptrReturnFalse) {
  RegularSpot spot(1);
  EXPECT_FALSE(spot.Park(nullptr));
  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkingSpotLeave, VehicleBecomesNullPtr) {
  RegularSpot spot(1);
  Car car("dw1234");
  spot.Park(&car);

  ASSERT_TRUE(spot.IsOccupied());

  spot.Leave();

  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkingSpotOccupied, ReturnTrueOccupied) {
  RegularSpot spot(1);
  Car car("dw1234");
  spot.Park(&car);

  EXPECT_TRUE(spot.IsOccupied());
}
TEST(ParkingSpotOccupied, ReturnFalseOccupied) {
  RegularSpot spot(1);
  spot.Park(nullptr);
  EXPECT_FALSE(spot.IsOccupied());
}

TEST(ParkVehicle, AllSpotsOccupiedReturnsFalse) {
  ParkingLot lot(3, 0, 0);
  std::vector<Car> cars;
  cars.emplace_back("DW1");
  cars.emplace_back("DW2");
  cars.emplace_back("DW3");
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  Car car1("DW444");
  EXPECT_FALSE(lot.ParkVehicle(&car1));
}
TEST(ParkVehicle, FreeSpotReturnsTrueAndParks) {
  ParkingLot lot(2, 0, 0);
  Car car1("DW444");

  Car car2("DW445");
  lot.ParkVehicle(&car1);
  EXPECT_TRUE(lot.ParkVehicle(&car2));
}

TEST(CountFree, CountFreeWithFreeSpots) {
  ParkingLot lot(4, 0, 0);
  std::vector<Car> cars;
  cars.emplace_back("DW1");
  cars.emplace_back("DW2");
  cars.emplace_back("DW3");
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  EXPECT_EQ(lot.CountFree(), 1);
}

TEST(CountFree, NoFreeSpots) {
  ParkingLot lot(3, 0, 0);
  std::vector<Car> cars;
  cars.emplace_back("Dw111");
  cars.emplace_back("Dw222");
  cars.emplace_back("Dw333");
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });

  EXPECT_EQ(lot.CountFree(), 0);
}

TEST(CountOccupied, AllSpotsOccupied) {
  ParkingLot lot(3, 0, 0);
  std::vector<Car> cars;
  cars.emplace_back("Dw111");
  cars.emplace_back("Dw222");
  cars.emplace_back("Dw333");
  std::for_each(cars.begin(), cars.end(),
                [&lot](Car& car) { lot.ParkVehicle(&car); });
  EXPECT_EQ(lot.CountOccupied(), 3);
}

TEST(GetType, ReturnTypeElectric) {
  std::string plate1 = "dw1230";
  ElectricCar car(plate1);
  EXPECT_EQ(car.getType(), "ElectricCar");
}

TEST(GetType, ReturnTypeHandicapped) {
  std::string plate2 = "dw1256";
  HandicappedCar car(plate2);
  EXPECT_EQ(car.getType(), "HandicappedCar");
}

TEST(CanAcceptReg, AcceptsRegularCar) {
  Car car("dw1230");
  RegularSpot spot(1);
  EXPECT_TRUE(spot.CanAccept(&car));
}

TEST(CanAcceptReg, AcceptsMotorcycle) {
  Motorcycle m("dw1230");
  RegularSpot spot(1);
  EXPECT_TRUE(spot.CanAccept(&m));
}

TEST(CanAcceptReg, AcceptsElectricCar) {
  ElectricCar car("dw1230");
  RegularSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&car));
}

TEST(CanAcceptElectric, AcceptsRegularCar) {
  ElectricCar car("dw1230");
  ElectricSpot spot(1);
  EXPECT_TRUE(spot.CanAccept(&car));
}
TEST(CanAcceptElectric, DeclinesRegularCar) {
  Car car("dw773638236");
  ElectricSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&car));
}

TEST(CanAcceptElectric, DeclinesMotorcycle) {
  Motorcycle m("dw773638236");
  ElectricSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&m));
}

TEST(CanAcceptElectric, DeclinesHandicapped) {
  HandicappedCar h("dw773638236");
  ElectricSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&h));
}

TEST(CanAcceptHandicapped, AcceptsHandicappedCar) {
  HandicappedCar car("dw37737393");
  HandicappedSpot spot(1);
  EXPECT_TRUE(spot.CanAccept(&car));
}

TEST(CanAcceptHandicapped, DeclinesCar) {
  Car car("dw37737393");
  HandicappedSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&car));
}

TEST(CanAcceptHandicapped, DeclinesElectricCar) {
  ElectricCar car("dw37737393");
  HandicappedSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&car));
}

TEST(CanAcceptHandicapped, DeclinesMotorcycle) {
  Motorcycle m("dw773638236");
  HandicappedSpot spot(1);
  EXPECT_FALSE(spot.CanAccept(&m));
}

TEST(ParkElectric, ParkingLotHasAnElectricSpot) {
  ParkingLot lot(7, 1, 2);
  ElectricCar car("dw123");
  EXPECT_TRUE(lot.ParkVehicle(&car));
}

TEST(ParkElectric, ParkingLotDoesNotHaveAnElectricSpot) {
  ParkingLot lot(0, 0, 2);
  ElectricCar car("dw123");
  EXPECT_FALSE(lot.ParkVehicle(&car));
}

TEST(ParkHandicapped, ParkingLotHasHandicappedSpot) {
  ParkingLot lot(0, 0, 2);
  HandicappedCar car("dw123");
  EXPECT_TRUE(lot.ParkVehicle(&car));
}

TEST(ParkHandicapped, ParkingLotDoesNotHaveHandicappedSpot) {
  ParkingLot lot(0, 5, 0);
  HandicappedCar car("dw123");
  EXPECT_FALSE(lot.ParkVehicle(&car));
}

TEST(ParkRegularCar, ParkingWithDifferentSpotsReturnsTrue) {
  ParkingLot lot(10, 5, 1);
  Car car("dw123");
  EXPECT_TRUE(lot.ParkVehicle(&car));
}

TEST(ParkRegularCar, ParkingWithOnlyElectricSpotsReturnsFalse) {
  ParkingLot lot(0, 5, 0);
  Car car("dw123");
  EXPECT_FALSE(lot.ParkVehicle(&car));
}
