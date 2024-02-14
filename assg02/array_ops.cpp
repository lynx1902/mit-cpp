#include <iostream>
using namespace std;

const int WIDTH = 3, LENGTH = 4;

void printArray(int arr[], int len) {

  for (int i = 0; i < len; i++) {
    if (i == len - 1) {
      cout << arr[i] << endl;
    } else {
      cout << arr[i] << ", ";
    }
  }
}

void reverse(int arr[], int len) {
  int *p = &arr[0];
  for (int i = 0; i < len / 2; i++) {
    swap(*(arr + i), *(arr + len - i - 1));
  }
}

void transpose(const int input[][LENGTH], int output[][WIDTH]) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < LENGTH; j++) {
      output[j][i] = input[i][j];
    }
  }
}

int main() {
  int n, arr[n];

  int input[][LENGTH] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int output[][WIDTH] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  cout << "Enter length of array" << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  printArray(arr, n);
  reverse(arr, n);
  printArray(arr, n);
  transpose(input, output);
  for (int i = 0; i < LENGTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cout << output[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}
