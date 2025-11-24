#include <iostream>
#include <string>
using namespace std;

int main() {
  string S1 = "kind";
  string S2 = "ending";

  int m = S1.length(); // length of S1
  int n = S2.length(); // length of S2

  int table[m + 1][n + 1]; // DP table

  // Initialize table with 0
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      table[i][j] = 0;
    }
  }

  // Fill the DP table
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      }
      else {
        if (table[i - 1][j] >= table[i][j - 1])
          table[i][j] = table[i - 1][j];
        else
          table[i][j] = table[i][j - 1];
      }
    }
  }

  // Print length of LCS
  cout << "Length of LCS: " << table[m][n] << endl;

  // Reconstruct LCS string
  string lcs = "";
  int i = m;
  int j = n;

  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcs = S1[i - 1] + lcs;
      i--;
      j--;
    }
    else if (table[i - 1][j] > table[i][j - 1]) {
      i--;
    }
    else {
      j--;
    }
  }

  cout << "LCS: " << lcs << endl;

  return 0;
}
