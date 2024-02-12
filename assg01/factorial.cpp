#include <iostream>
using namespace std;

long factorial(int N) {
  if (N == 1) {
    return 1;
  }
  if (N == 0) {
    return 1;

  } else {
    return N * factorial(N - 1);
  }
}

int main() {
  int N;
  cin >> N;
  cout << "Factorial is " << factorial(N);
}
