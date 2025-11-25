#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
  int start;
  int end;
  int index;
};

// Comparator to sort activities by end time
bool compare(Activity a, Activity b) {
  return a.end < b.end;
}

void activitySelection(vector<int> &start, vector<int> &end) {
  int n = start.size();
  vector<Activity> activities(n);

  // Create activity objects
  for (int i = 0; i < n; i++) {
    activities[i].start = start[i];
    activities[i].end = end[i];
    activities[i].index = i + 1;
  }

  // Sort activities by end time (Greedy approach)
  sort(activities.begin(), activities.end(), compare);

  // Select activities
  vector<Activity> selected;
  selected.push_back(activities[0]);
  int lastEndTime = activities[0].end;

  for (int i = 1; i < n; i++) {
    if (activities[i].start >= lastEndTime) {
      selected.push_back(activities[i]);
      lastEndTime = activities[i].end;
    }
  }

  // Task 1 & 2: Print the selected events
  cout << "Maximum number of non-overlapping events: " << selected.size() << endl;
  cout << "\nSelected Events:" << endl;
  cout << "Event#\tStart\tEnd" << endl;
  cout << "----------------------" << endl;

  for (const auto &event : selected) {
    cout << event.index << "\t" << event.start << "\t" << event.end << endl;
  }
}

int main() {
  int n;
  cout << "Enter number of events: ";
  cin >> n;

  vector<int> start(n), end(n);

  cout << "Enter start times: ";
  for (int i = 0; i < n; i++) {
    cin >> start[i];
  }

  cout << "Enter end times: ";
  for (int i = 0; i < n; i++) {
    cin >> end[i];
  }

  activitySelection(start, end);

  return 0;
}

/* Example Test Case:
   Input:
   Number of events: 6
   Start times: 1 3 0 5 8 5
   End times: 2 4 6 7 9 9

   Output:
   Maximum number of non-overlapping events: 4
   Selected Events:
   Event#  Start  End
   ----------------------
   1       1      2
   2       3      4
   4       5      7
   5       8      9
*/