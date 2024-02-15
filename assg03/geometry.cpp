#include "geometry.h"

void Point::SetX(const int new_x) { x = new_x; }

void Point::SetY(const int new_y) { y = new_y; }

PointArray::PointArray(const Point points[], const int size) {
  arrSize = size;
  pStart = new Point[arrSize];
  for (int i = 0; i < size; i++) {
    pStart[i] = points[i];
  }
}

PointArray::PointArray(const PointArray &pv) {
  pStart = new Point[pv.arrSize];
  arrSize = pv.arrSize;
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
  pStart = p;
  arrSize = n;
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

int main() { return 0; }
