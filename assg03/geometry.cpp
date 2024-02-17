#include "geometry.h"
#include <cmath>
// #include <iostream>

void Point::SetX(const int new_x) { x = new_x; }

void Point::SetY(const int new_y) { y = new_y; }

PointArray::PointArray(const Point points[], const int size) {
  arrSize = size;
  pStart = new Point[size];
  for (int i = 0; i < size; i++) {
    pStart[i] = points[i];
  }
}

PointArray::PointArray(const PointArray &pv) {
  arrSize = pv.arrSize;
  pStart = new Point[arrSize];

  for (int i = 0; i < arrSize; i++) {
    pStart[i] = pv.pStart[i];
  }
}

void PointArray::resize(int n) {
  Point *p = new Point[n];
  int minSize = arrSize > n ? n : arrSize;
  for (int i = 0; i < minSize; i++) {
    p[i] = pStart[i];
  }
  delete[] pStart;
  arrSize = n;
  pStart = p;
}

void PointArray::push_back(const Point &p) {
  resize(arrSize + 1);
  pStart[arrSize - 1] = p;
}

void PointArray::insert(const int position, const Point &p) {
  resize(arrSize + 1);
  for (int i = arrSize - 1; i > position - 1; i--) {
    pStart[i] = pStart[i - 1];
  }
  pStart[position] = p;
}

void PointArray::remove(const int pos) {
  if (pos >= 0 && pos < arrSize) {
    for (int i = pos; i < arrSize - 1; i++) {
      pStart[i] = pStart[i + 1];
    }
    resize(arrSize - 1);
  }
}

const int PointArray::getSize() const { return arrSize; }

void PointArray::clear() {
  delete[] pStart;
  arrSize = 0;
  // resize(0);
}

Point *PointArray::get(const int position) {
  if (position >= 0 && position < arrSize) {
    return pStart + position;
  } else {
    return NULL;
  }
}

const Point *PointArray::get(const int position) const {
  if (position >= 0 && position < arrSize) {
    return pStart + position;
  } else {
    return NULL;
  }
}

int Polygon::numPol = 0;

Polygon::Polygon(Point points[], const int len) : ptArr(points, len) {
  ++numPol;
}

Polygon::Polygon(PointArray &p) : ptArr(p) {
  // ptArr = PointArray(p);
  ++numPol;
}

int Polygon::getNumSides() const { return ptArr.getSize(); }

const PointArray *Polygon::getPoints() const { return &ptArr; }

Polygon::~Polygon() { --numPol; }

Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2,
                               const Point &p3, const Point &p4 = Point(0, 0)) {
  constructorPoints[0] = p1;
  constructorPoints[1] = p2;
  constructorPoints[2] = p3;
  constructorPoints[3] = p4;
  return constructorPoints;
}

Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
    : Polygon(updateConstructorPoints(
                  lowerLeft, Point(lowerLeft.getX(), upperRight.getY()),
                  upperRight, Point(upperRight.getX(), lowerLeft.getY())),
              4) {}

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury)
    : Polygon(updateConstructorPoints(Point(llx, lly), Point(llx, ury),
                                      Point(urx, ury), Point(urx, lly)),
              4) {}

double Rectangle::area() const {
  int length = ptArr.get(3)->getX() - ptArr.get(0)->getX();

  int breadth = ptArr.get(1)->getY() - ptArr.get(0)->getY();

  return std::abs((double)length * breadth);
}

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

double Triangle::area() const {
  int d1x = ptArr.get(0)->getX() - ptArr.get(1)->getX();
  int d1y = ptArr.get(0)->getY() - ptArr.get(1)->getY();
  int d2x = ptArr.get(1)->getX() - ptArr.get(2)->getX();
  int d2y = ptArr.get(1)->getY() - ptArr.get(2)->getY();
  int d3x = ptArr.get(0)->getX() - ptArr.get(2)->getX();
  int d3y = ptArr.get(0)->getY() - ptArr.get(2)->getY();

  double a = std::sqrt(std::pow(d1x, 2) + std::pow(d1y, 2));
  double b = std::sqrt(std::pow(d2x, 2) + std::pow(d2y, 2));
  double c = std::sqrt(std::pow(d3x, 2) + std::pow(d3y, 2));

  double s = (a + b + c) / 2.0;

  double sa = s - a;
  double sb = s - b;
  double sc = s - c;

  return std::sqrt(s * sa * sb * sc);
}
