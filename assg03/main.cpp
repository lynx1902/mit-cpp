#include "geometry.h"
#include <iostream>

void printAttributes(Polygon *p) {
  std::cout << "Area of polygon is " << p->area() << std::endl;
  const PointArray *pt = p->getPoints();
  for (int i = 0; i < pt->getSize(); i++) {

    std::cout << "Coordinates: (" << pt->get(i)->getX() << ", "
              << pt->get(i)->getY() << ")" << std::endl;
  }
}

int main(int argc, char *argv[]) {
  int llx, lly, urx, ury;
  std::cout << "Enter coordinates of Rectangle as x1, y1, x2, y2 " << std::endl;
  std::cin >> llx >> lly >> urx >> ury;
  Point lowerLeft(llx, lly), upperRight(urx, ury);
  Rectangle R(lowerLeft, upperRight);
  printAttributes(&R);

  int ax, ay, bx, by, cx, cy;
  std::cout << "Enter coordinates of Triangle as x1, y1, x2, y2, x3, y3 "
            << std::endl;
  std::cin >> ax >> ay >> bx >> by >> cx >> cy;
  Point A(ax, ay), B(bx, by), C(cx, cy);
  Triangle T(A, B, C);
  printAttributes(&T);
  return 0;
}
