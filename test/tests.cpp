// Copyright 2025 UNN-CS
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {

constexpr double kEps = 1e-9;

double pi() {
  return std::acos(-1.0);
}

}  // namespace

TEST(CircleConstructor, StoresRadiusAndDerivedValues) {
  Circle circle(2.5);

  EXPECT_NEAR(2.5, circle.getRadius(), kEps);
  EXPECT_NEAR(5.0 * pi(), circle.getFerence(), kEps);
  EXPECT_NEAR(6.25 * pi(), circle.getArea(), kEps);
}

TEST(CircleConstructor, AcceptsZeroRadius) {
  Circle circle(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleConstructor, RejectsNegativeRadius) {
  EXPECT_THROW(Circle(-0.01), std::invalid_argument);
}

TEST(CircleSetRadius, RecalculatesEverything) {
  Circle circle(1.0);
  circle.setRadius(7.0);

  EXPECT_NEAR(7.0, circle.getRadius(), kEps);
  EXPECT_NEAR(14.0 * pi(), circle.getFerence(), kEps);
  EXPECT_NEAR(49.0 * pi(), circle.getArea(), kEps);
}

TEST(CircleSetRadius, RejectsNegativeInput) {
  Circle circle(4.0);

  EXPECT_THROW(circle.setRadius(-3.0), std::invalid_argument);
  EXPECT_NEAR(4.0, circle.getRadius(), kEps);
}

TEST(CircleSetFerence, RecalculatesRadiusAndArea) {
  Circle circle(1.0);
  circle.setFerence(10.0 * pi());

  EXPECT_NEAR(5.0, circle.getRadius(), kEps);
  EXPECT_NEAR(10.0 * pi(), circle.getFerence(), kEps);
  EXPECT_NEAR(25.0 * pi(), circle.getArea(), kEps);
}

TEST(CircleSetFerence, AcceptsZero) {
  Circle circle(9.0);
  circle.setFerence(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleSetFerence, RejectsNegativeInput) {
  Circle circle(4.0);

  EXPECT_THROW(circle.setFerence(-1.0), std::invalid_argument);
  EXPECT_NEAR(4.0, circle.getRadius(), kEps);
}

TEST(CircleSetArea, RecalculatesRadiusAndFerence) {
  Circle circle(1.0);
  circle.setArea(36.0 * pi());

  EXPECT_NEAR(6.0, circle.getRadius(), kEps);
  EXPECT_NEAR(12.0 * pi(), circle.getFerence(), kEps);
  EXPECT_NEAR(36.0 * pi(), circle.getArea(), kEps);
}

TEST(CircleSetArea, AcceptsZero) {
  Circle circle(3.0);
  circle.setArea(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleSetArea, RejectsNegativeInput) {
  Circle circle(4.0);

  EXPECT_THROW(circle.setArea(-1.0), std::invalid_argument);
  EXPECT_NEAR(4.0, circle.getRadius(), kEps);
}

TEST(CircleSequence, ValuesRemainConsistentAfterSeveralUpdates) {
  Circle circle(2.0);

  circle.setFerence(8.0 * pi());
  circle.setArea(9.0 * pi());

  EXPECT_NEAR(3.0, circle.getRadius(), kEps);
  EXPECT_NEAR(6.0 * pi(), circle.getFerence(), kEps);
  EXPECT_NEAR(9.0 * pi(), circle.getArea(), kEps);
}

TEST(CircleMath, FerenceOverRadiusIsTwoPi) {
  Circle circle(12.0);

  EXPECT_NEAR(2.0 * pi(), circle.getFerence() / circle.getRadius(), kEps);
}

TEST(CircleMath, AreaOverSquaredRadiusIsPi) {
  Circle circle(12.0);
  const double squaredRadius = circle.getRadius() * circle.getRadius();

  EXPECT_NEAR(pi(), circle.getArea() / squaredRadius, kEps);
}

TEST(CircleMath, LargeRadiusKeepsPrecision) {
  Circle circle(1000000.0);

  EXPECT_NEAR(1000000.0, circle.getRadius(), 1e-6);
  EXPECT_NEAR(pi() * 1e12, circle.getArea(), 1e3);
}

TEST(CircleMath, SmallRadiusKeepsPrecision) {
  Circle circle(0.000001);

  EXPECT_NEAR(0.000001, circle.getRadius(), 1e-15);
  EXPECT_NEAR(pi() * 1e-12, circle.getArea(), 1e-20);
}

TEST(EarthAndRopeTask, GapDoesNotDependOnEarthRadius) {
  EXPECT_NEAR(1.0 / (2.0 * pi()), earthEndRope(), 1e-9);
}

TEST(PoolTask, IncludesPathAndOuterFenceCosts) {
  const double expected = 7.0 * pi() * 1000.0 + 8.0 * pi() * 2000.0;

  EXPECT_NEAR(expected, calculateMaterialPrice(), 1e-8);
}

TEST(PoolTask, ResultIsInExpectedRange) {
  EXPECT_GT(calculateMaterialPrice(), 70000.0);
  EXPECT_LT(calculateMaterialPrice(), 73000.0);
}

TEST(CircleSetters, NegativeFailedUpdateLeavesOldState) {
  Circle circle(5.0);
  const double oldRadius = circle.getRadius();
  const double oldFerence = circle.getFerence();
  const double oldArea = circle.getArea();

  EXPECT_THROW(circle.setArea(-5.0), std::invalid_argument);

  EXPECT_NEAR(oldRadius, circle.getRadius(), kEps);
  EXPECT_NEAR(oldFerence, circle.getFerence(), kEps);
  EXPECT_NEAR(oldArea, circle.getArea(), kEps);
}
