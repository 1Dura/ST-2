// Copyright 2025 UNN-CS
#include "tasks.h"

double earthEndRope() {
  constexpr double earthRadiusMeters = 6378.1 * 1000.0;

  Circle earth(earthRadiusMeters);
  Circle raisedRope(earthRadiusMeters);
  raisedRope.setFerence(earth.getFerence() + 1.0);

  return raisedRope.getRadius() - earth.getRadius();
}

double calculateMaterialPrice() {
  constexpr double poolRadius = 3.0;
  constexpr double pathWidth = 1.0;
  constexpr double concretePrice = 1000.0;
  constexpr double fencePrice = 2000.0;

  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);

  const double pathArea = outer.getArea() - pool.getArea();
  const double concreteCost = pathArea * concretePrice;
  const double fenceCost = outer.getFerence() * fencePrice;

  return concreteCost + fenceCost;
}
