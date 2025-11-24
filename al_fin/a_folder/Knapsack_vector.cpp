#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, capacity;
  cout << "Enter number of items: ";
  cin >> n;
  cout << "Enter knapsack capacity: ";
  cin >> capacity;

  vector<int> value(n), weight(n);
  vector<double> ratio(n);
  vector<int> idx(n);
  for (int i = 0; i < n; i++)
    idx[i] = i;

  cout << "Enter values: ";
  for (int i = 0; i < n; i++)
    cin >> value[i];

  cout << "Enter weights: ";
  for (int i = 0; i < n; i++)
    cin >> weight[i];

  for (int i = 0; i < n; i++) {
    ratio[i] = (double)value[i] / weight[i];
  }

  sort(idx.begin(), idx.end(), [&](int a, int b) {
    return ratio[a] > ratio[b];
    });

  double profit = 0;
  int rem = capacity;

  cout << "\nSelection Order (Highest ratio first):\n";
  for (int i = 0; i < n && rem > 0; i++) {
    int id = idx[i];
    if (weight[id] <= rem) {
      rem -= weight[id];
      profit += value[id];
      cout << "Item " << (id + 1) << " (full): +" << value[id] << " (w=" << weight[id] << ")\n";
    }
    else {
      double frac = (double)rem / weight[id];
      profit += frac * value[id];
      cout << "Item " << (id + 1) << " (fraction " << rem << "/" << weight[id]
        << "): +" << (int)(frac * value[id]) << "\n";
      rem = 0;
    }
  }

  cout << "\nMaximum Profit = " << (int)profit << endl;
  return 0;
}

