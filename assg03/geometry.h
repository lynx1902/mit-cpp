class Point {
private:
  int x, y;

public:
  Point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
  int getX() const { return x; }
  int getY() const { return y; }

  void SetX(const int new_x);
  void SetY(const int new_y);
};

class PointArray {
private:
  Point *pStart;
  int arrSize;

  void resize(int n);

public:
  PointArray() {
    arrSize = 0;
    pStart = new Point[arrSize];
  }
  PointArray(const Point points[], const int size);

  PointArray(const PointArray &pv);

  ~PointArray() { delete[] pStart; }

  void push_back(const Point &p);

  void insert(const int position, const Point &p);

  void remove(const int pos);

  const int getSize() const;

  void clear();

  Point *get(const int position);

  const Point *get(const int position) const;
};
