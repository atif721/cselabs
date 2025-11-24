#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter the number of activities: ";
  cin >> n;

  vector<int> activityNum(n), start(n), finish(n);

  cout << "Enter activity numbers: ";
  for (int i = 0;i < n;i++) cin >> activityNum[i];

  cout << "Enter start times: ";
  for (int i = 0;i < n;i++) cin >> start[i];

  cout << "Enter finish times: ";
  for (int i = 0;i < n;i++) cin >> finish[i];

  // Combine into vector of tuples: (finish, start, activityNum)
  vector<tuple<int, int, int>> activities(n);
  for (int i = 0;i < n;i++)
    activities[i] = make_tuple(finish[i], start[i], activityNum[i]);

  // Sort by finish time
  sort(activities.begin(), activities.end());

  // Greedy selection
  vector<tuple<int, int, int>> selected;
  selected.push_back(activities[0]);
  int lastFinish = get<0>(activities[0]);

  for (int i = 1;i < n;i++) {
    if (get<1>(activities[i]) >= lastFinish) {
      selected.push_back(activities[i]);
      lastFinish = get<0>(activities[i]);
    }
  }

  // Print output in formatted table
  cout << "\n--- Selected Activities (Maximum Set) ---\n";
  cout << "Number of activities selected: " << selected.size() << "\n\n";
  cout << left << setw(10) << "Activity"
    << setw(8) << "Start"
    << setw(8) << "Finish" << "\n";

  for (auto &a : selected) {
    cout << left << setw(10) << get<2>(a)
      << setw(8) << get<1>(a)
      << setw(8) << get<0>(a) << "\n";
  }

  return 0;
}
