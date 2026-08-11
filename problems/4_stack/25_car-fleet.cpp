#include "headers.h"
#include <gtest/gtest.h>

int carFleet(int target, vector<int> &position, vector<int> &speed) {
}

TEST(CarFleet, BasicCase) {
  vector<int> position = {10, 8, 0, 5, 3};
  vector<int> speed = {2, 4, 1, 1, 3};
  EXPECT_EQ(carFleet(12, position, speed), 3);
}

TEST(CarFleet, SingleCar) {
  vector<int> position = {3};
  vector<int> speed = {3};
  EXPECT_EQ(carFleet(10, position, speed), 1);
}

TEST(CarFleet, AllMergeIntoOne) {
  vector<int> position = {0, 2, 4};
  vector<int> speed = {4, 2, 1};
  EXPECT_EQ(carFleet(100, position, speed), 1);
}

TEST(CarFleet, NoMerging) {
  vector<int> position = {6, 8, 10};
  vector<int> speed = {3, 2, 1};
  EXPECT_EQ(carFleet(12, position, speed), 3);
}

TEST(CarFleet, TwoCarsSamePositionCatchUp) {
  vector<int> position = {4, 0};
  vector<int> speed = {2, 1};
  EXPECT_EQ(carFleet(10, position, speed), 1);
}

TEST(CarFleet, EmptyInput) {
  vector<int> position = {};
  vector<int> speed = {};
  EXPECT_EQ(carFleet(10, position, speed), 0);
}
