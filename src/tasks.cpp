// Copyright 2025 UNN-CS
#include "tasks.h"

double earthEndRope() {
  constexpr double earth_rad = 6378.1 * 1000.0;
  Circle new_earth(earth_rad);
  new_earth.setFerence(new_earth.getFerence() + 1.0);

  return new_earth.getRadius() - earth_rad;
}

double calculateMaterialPrice() {
  constexpr double cement_price = 1000.0;
  constexpr double fence_meter_price = 2000.0;
  constexpr double pool_rad = 3.0;
  constexpr double walkway_width = 1.0;

  Circle pool(pool_rad);
  Circle around_pool(pool_rad + walkway_width);
  double fence_price = 0.0;
  double cement_walkway_price = 0.0;

  fence_price = pool.getFerence() * fence_meter_price;
  cement_walkway_price = (around_pool.getArea() - pool.getArea())
                         * cement_price;
  return fence_price + cement_walkway_price;
}
