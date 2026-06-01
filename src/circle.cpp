// Copyright 2025 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

double Circle::pi() {
  return std::acos(-1.0);
}

void Circle::requireNonNegative(double value) {
  if (value < 0.0) {
    throw std::invalid_argument("circle value must be non-negative");
  }
}

void Circle::refreshFromRadius() {
  ference = 2.0 * pi() * radius;
  area = pi() * radius * radius;
}

Circle::Circle(double radiusValue) {
  setRadius(radiusValue);
}

void Circle::setRadius(double radiusValue) {
  requireNonNegative(radiusValue);
  radius = radiusValue;
  refreshFromRadius();
}

void Circle::setFerence(double ferenceValue) {
  requireNonNegative(ferenceValue);
  ference = ferenceValue;
  radius = ference / (2.0 * pi());
  area = pi() * radius * radius;
}

void Circle::setArea(double areaValue) {
  requireNonNegative(areaValue);
  area = areaValue;
  radius = std::sqrt(area / pi());
  ference = 2.0 * pi() * radius;
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getFerence() const {
  return ference;
}

double Circle::getArea() const {
  return area;
}
