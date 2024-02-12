#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
  int N, arr[N], sum = 0, max_val = INT32_MIN, min_val = INT32_MAX;
  double mean;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
    sum += arr[i];
  }
  mean = sum / N;
  cout << "Mean: " << mean << endl;
  cout << "Max Val: " << max_val << endl;
  cout << "Min Val: " << min_val << endl;
  cout << "Range: " << (max_val - min_val) << endl;
}
