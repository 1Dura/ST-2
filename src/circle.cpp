// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  if (r < 0) {
    throw std::invalid_argument(
        "Радиус не может быть отрицательным");
  }
  radius = r;
  updateFromRadius();
}

void Circle::setFerence(double f) {
  if (f < 0) {
    throw std::invalid_argument(
        "Длина окружности не может быть отрицательной");
  }
  ference = f;
  updateFromFerence();
}

void Circle::setArea(double a) {
  if (a < 0) {
    throw std::invalid_argument(
        "Площадь не может быть отрицательной");
  }
  area = a;
  updateFromArea();
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

void Circle::updateFromRadius() {
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

void Circle::updateFromFerence() {
  radius = ference / (2 * PI);
  area = PI * radius * radius;
}

void Circle::updateFromArea() {
  radius = std::sqrt(area / PI);
  ference = 2 * PI * radius;
}
