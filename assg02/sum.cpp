#include <iostream>
using namespace std;

int sumDefault(int a, int b, int c = 0) { return a + b + c; }
// int sum = 0;
int sumArr(int n, int *arr) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

int sumRecursion(int n, int *arr) {
  if (n == 1) {
    return arr[0];
  } else if (n == 0) {
    return 0;
  } else {
    return sumRecursion(n - 1, arr) + arr[n - 1];
  }
}

int main() {
  int n, arr[n];
  cin >> n;
  cout << "Enter the integers to add!" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int arrSum = sumRecursion(n, arr);
  cout << "Sum is " << arrSum << endl;
  return 0;
}
