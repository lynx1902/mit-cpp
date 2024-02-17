#include <iostream>
#include <ostream>
#include <string>
using namespace std;

const string vowels = "aeiou";

string pigLatinify(string str) {
  if (str.length() == 0) {
    return str;
  }
  for (int i = 0; i < vowels.length(); i++) {
    if (str.substr(0, 1) == vowels.substr(i, 1)) {
      str.append("way");
      return str;
    }
  }

  if (str.substr(0, 2) == "qu") {
    int end = str.length();
    string predicate = str.substr(2, end - 2);
    predicate.append("quay");
    return predicate;
  } else {
    string start = str.substr(0, 1);
    string rem = str.substr(1, str.length() - 1);
    rem.append(start);
    rem.append("ay");
    return rem;
  }
}

int main() {
  string ans = pigLatinify("adjective");
  cout << "Pig Latin is: " << ans << endl;

  return 0;
}
