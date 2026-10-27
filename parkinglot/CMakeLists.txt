cmake_minimum_required(VERSION 3.10)

project(parkinglot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. GTEST
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# 2. SOURCE CODE
add_library(parking_lib
    src/car.cc
    src/motorcycle.cc
    src/vehicle.cc
    src/parkingspot.cc
    src/parkinglot.cc
    src/HandicappedCar.cc
    src/ElectricCar.cc
    src/ElectricSpot.cc
    src/HandicappedSpot.cc
    src/RegularSpot.cc
    )
add_executable(app src/main.cc)
target_link_libraries(app PRIVATE parking_lib)

# 3. TEST CODE
enable_testing()

add_executable(tests test/tests.cc)
target_include_directories(tests PRIVATE src)
target_link_libraries(tests PRIVATE parking_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
