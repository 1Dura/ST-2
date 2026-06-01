// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
  double radius;
  double ference;
  double area;

  static double pi();
  static void requireNonNegative(double value);
  void refreshFromRadius();

 public:
  explicit Circle(double radiusValue);

  void setRadius(double radiusValue);
  void setFerence(double ferenceValue);
  void setArea(double areaValue);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
