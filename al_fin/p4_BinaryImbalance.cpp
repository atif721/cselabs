#include<iostream>
using namespace std;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    string s;

    cin >> n >> s;

    bool result = false;

    for (auto i : s) {
      if (i == '0') {
        result = true;
        break;
      }
    }

    cout << (result ? "YES" : "NO") << endl;
  }

  return 0;
}