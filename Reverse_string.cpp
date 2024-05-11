#include <iostream>
#include <string>
using namespace std;

void Reverse(string &str) {
  int len = str.length();
  for (int i = 0; i < (len >> 1); i++) {
    swap(str[i], str[len - i - 1]);
  }
}

int main() {
  string str;
  while (cin >> str) {
    Reverse(str);
    cout << str << endl;
  }
  return 0;
}