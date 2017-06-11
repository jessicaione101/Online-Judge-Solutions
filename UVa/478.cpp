// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=419

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <memory>

std::pair<double, double> operator-(const std::pair<double, double> l,
                                    const std::pair<double, double> r) {
  std::pair<double, double> result;
  result.first = l.first - r.first;
  result.second = l.second - r.second;
  return result;
}

class Figure {
 public:
  virtual bool isInside(std::pair<double, double> point) = 0;
};

class Rectangle : public Figure {
 public:
    Rectangle(double upper_left_x, double upper_left_y,
              double lower_right_x, double lower_right_y)
      : upper_left_x(upper_left_x), upper_left_y(upper_left_y),
        lower_right_x(lower_right_x), lower_right_y(lower_right_y) {}
    bool isInside(std::pair<double, double> point) override {
      return point.first > upper_left_x && point.first < lower_right_x &&
        point.second < upper_left_y && point.second > lower_right_y;
    }

 private:
  double upper_left_x, upper_left_y, lower_right_x, lower_right_y;
};

class Circle : public Figure {
 public:
    Circle(double center_x, double center_y, double radius)
      : center_x(center_x), center_y(center_y), radius(radius) {}
    bool isInside(std::pair<double, double> point) {
      double squared_distance =
        (center_x - point.first) * (center_x - point.first) +
        (center_y - point.second) * (center_y - point.second);
      return squared_distance < radius*radius;
    }

 private:
  double center_x, center_y, radius;
};

class Triangle : public Figure {
 public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
      v1 = std::make_pair(x1, y1);
      v2 = std::make_pair(x2, y2);
      v3 = std::make_pair(x3, y3);
    }
    bool isInside(std::pair<double, double> point) {
      return sameSide(point, v1, v2, v3) && sameSide(point, v2, v1, v3) &&
        sameSide(point, v3, v1, v2);
    }

 private:
  std::pair<double, double> v1, v2, v3;
  double crossProduct(const std::pair<double, double>& point1,
                      const std::pair<double, double>& point2) {
    double x1, x2, y1, y2;
    x1 = point1.first;
    x2 = point2.first;
    y1 = point1.second;
    y2 = point2.second;
    return x1*y2 - y1*x2;
  }
  bool sameSide(const std::pair<double, double>& point1,
                const std::pair<double, double>& point2,
                const std::pair<double, double>& point3,
                const std::pair<double, double>& point4) {
    double cross_product1, cross_product2;
    cross_product1 = crossProduct(point4-point3, point1-point3);
    cross_product2 = crossProduct(point4-point3, point2-point3);
    return (cross_product1 >= 0 && cross_product2 >= 0) ||
      (cross_product1 < 0 && cross_product2 < 0);
  }
};


int main() {
  std::vector<std::unique_ptr<Figure>> figures;
  char type;
  std::cin >> type;
  while (type != '*') {
    if (type == 'r') {
      double upper_left_x, upper_left_y, lower_right_x, lower_right_y;
      std::cin >> upper_left_x >> upper_left_y >>
        lower_right_x >> lower_right_y;
      figures.emplace_back(new Rectangle(
        upper_left_x, upper_left_y, lower_right_x, lower_right_y));
    } else if (type == 'c') {
      double center_x, center_y, radius;
      std::cin >> center_x >> center_y >> radius;
      figures.emplace_back(new Circle(center_x, center_y, radius));
    } else if (type == 't') {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      figures.emplace_back(new Triangle(x1, y1, x2, y2, x3, y3));
    }
    std::cin >> type;
  }

  std::vector<std::pair<double, double>> points;
  double x, y;
  std::cin >> x >> y;
  while (x != 9999.9 || y != 9999.9) {
    points.push_back(std::make_pair(x, y));
    std::cin >> x >> y;
  }

  bool inside = false;
  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = 0; j < figures.size(); ++j) {
      if (figures[j]->isInside(points[i])) {
        std::cout << "Point " << i+1 <<
          " is contained in figure " << j+1 << std::endl;
        inside = true;
      }
    }
    if (!inside)
      std::cout << "Point " << i+1
        << " is not contained in any figure" << std::endl;
    inside = false;
  }

  return 0;
}
