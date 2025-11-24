#include <bits/stdc++.h>
using namespace std;

void lcsAlgo(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "LCS length: " << dp[m][n] << endl;

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // lcs.insert(lcs.begin(), s1[i - 1]);
            lcs.push_back(s1[i - 1]);
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());

    cout << "The LCS: " << lcs << endl;
}

int main() {
    string s1, s2;
    cout << "The first sequence: ";
    cin >> s1;
    cout << "The second sequence: ";
    cin >> s2;

    lcsAlgo(s1, s2);

    return 0;
}
