#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cout << "Enter first string: ";
  cin >> A;
  cout << "Enter second string: ";
  cin >> B;

  int m = A.size(), n = B.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  cout << "\nDP table (rows: A prefix, cols: B prefix)\n  ";

  cout << "  ";
  for (int j = 0; j < n; j++)
    cout << B[j] << " ";
  cout << "\n";

  for (int i = 0; i <= m; i++) {
    if (i == 0) cout << "  ";
    else cout << A[i - 1] << " ";

    for (int j = 0; j <= n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }

  string lcs = "";
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (A[i - 1] == B[j - 1]) {
      lcs.push_back(A[i - 1]);
      i--; j--;
    }
    else if (dp[i - 1][j] >= dp[i][j - 1]) i--;
    else j--;
  }
  reverse(lcs.begin(), lcs.end());

  cout << "\nLCS String: " << lcs << "\n";
  cout << "Length of LCS: " << dp[m][n] << "\n";

  return 0;
}
