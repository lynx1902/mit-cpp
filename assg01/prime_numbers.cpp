#include <iostream>
using namespace std;

int main() {
  int N, j = 2;
  bool flag = true;
  cin >> N;
  while (N > 0) {

    flag = true;

    for (int i = 2; i < j; i++) {
      if (j % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      cout << j << ",";
      N--;
    }
    j++;
  }

  return 0;
}
