#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <cassert>

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double perimetr() const = 0;
  virtual double area() const = 0;
};

class Triangle final: public Shape
{
private:
  double a, b, c;
public:
  Triangle(double x, double y, double z): a(x), b(y), c(z) {}
  double perimetr() const override final {
    return a + b + c;
  }
  double area() const override final {
    double p = perimetr() / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); // формула Герона
  }
};

class Square final: public Shape
{
private:
  double side;
public:
  Square(double x): side(x) {}
  double perimetr() const override final {
    return 4 * side;
  }
  double area() const override final {
    return side * side;
  }
};

class Circle final: public Shape
{
private:
  double radius;
public:
  Circle(double x): radius(x) {}
  double perimetr() const override final {
    return 2 * std::numbers::pi * radius;
  }
  double area() const override final {
    return std::numbers::pi * radius * radius;
  }
};

// Функция для демонстрации с assert
void demonstrate() {
  std::vector<Shape*> shapes;
  shapes.push_back(new Triangle(3.0, 4.0, 5.0));
  shapes.push_back(new Square(2.5));
  shapes.push_back(new Circle(1.0));
  ////////////////////
  assert(std::abs(shapes[0]->perimetr() - 12.0) < 0.001);
  assert(std::abs(shapes[0]->area() - 6.0) < 0.001);
//////////////////////////////
  assert(std::abs(shapes[1]->perimetr() - 10.0) < 0.001);
  assert(std::abs(shapes[1]->area() - 6.25) < 0.001);
//////////////////
  assert(std::abs(shapes[2]->perimetr() - (2 * std::numbers::pi * 1.0)) < 0.001);
  assert(std::abs(shapes[2]->area() - (std::numbers::pi * 1.0 * 1.0)) < 0.001);
  for (auto shape: shapes) {
    delete shape;
  }
}

int main() {
  demonstrate();
}