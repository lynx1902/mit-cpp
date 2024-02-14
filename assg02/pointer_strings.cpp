#include <cstring>
#include <iostream>
using namespace std;

int str_length(char str[]) {
  char *p = str;
  int len = 0;
  while (*p != '\0') {
    len++;
    p++;
  }
  return len;
}

void swapInt(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void swapIntPointers(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swapPointers(int **a, int **b) {
  int temp = **a;
  **a = **b;
  **b = temp;
}

int main() {
  char *oddOrEven = "Never odd or even";
  char *nthCharPtr = &oddOrEven[5];
  nthCharPtr = nthCharPtr - 2;
  cout << *nthCharPtr << endl;
  char **pointerPtr = &nthCharPtr;
  cout << pointerPtr << endl;
  cout << **pointerPtr << endl;
  nthCharPtr = nthCharPtr + 1;
  cout << nthCharPtr - oddOrEven << endl;

  cout << str_length(oddOrEven) << endl;

  return 0;
}
