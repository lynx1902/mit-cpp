#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

double pi_calculator(long int n) {
  long int count = 0;
  srand(time(0));
  for (long int i = 0; i < n; i++) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;

    if (sqrt(pow(x, 2) + pow(y, 2)) < 1) {
      count++;
    }
  }

  double ratio = (double)count / n;
  return 4 * ratio;
}

int main() {
  long int n;
  cout << "Enter total number of dart throws to be simulated" << endl;
  cin >> n;
  cout << pi_calculator(n);
  return 0;
}
