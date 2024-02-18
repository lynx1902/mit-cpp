#include <vector>

template <class T> class Stack;

template <class T> Stack<T> operator+(const Stack<T> &a, const Stack<T> &b);

template <class T> class Stack {
  friend Stack<T> operator+ <>(const Stack<T> &a, const Stack<T> &b);
  std::vector<T> stk;

public:
  bool empty() { return stk.size() == 0 ? true : false; }

  void push(const T &item) {
    int prevSize = stk.size();
    stk.resize(prevSize + 1);
    stk.push_back(item);
  }

  T &top() { return (stk.end() - 1); }

  void pop() {
    int curSize = stk.size();
    stk.pop_back();
    stk.resize(curSize - 1);
  }
};

template <class T> Stack<T> operator+(const Stack<T> &a, const Stack<T> &b) {
  Stack<T> result = a;

  for (int i = 0; i < a.stk.size(); i++) {
    result.stk.push_back(b.stk[i]);
  }
  return result;
}
