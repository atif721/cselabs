#include <bits/stdc++.h>
using namespace std;

void sortActivities(int a[], int s[], int f[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (f[j] > f[j + 1]) {
        swap(f[j], f[j + 1]);
        swap(s[j], s[j + 1]);
        swap(a[j], a[j + 1]);
      } 
    }
  }
}

void display(int a[], int s[], int f[], int n) {
  cout << "\n--- After sorting by finish time in ascending order ---\n";
  cout << "\nActivity\t";
  for (int i = 0; i < n; i++) cout << a[i] << "\t";
  cout << "\nStart\t\t";
  for (int i = 0; i < n; i++) cout << s[i] << "\t";
  cout << "\nFinish\t\t";
  for (int i = 0; i < n; i++) cout << f[i] << "\t";
  cout << "\n";
}

int selectActivities(int activityNum[], int start[], int finish[], int n,
  int selectedActivity[], int selectedStart[], int selectedFinish[]) {

  selectedActivity[0] = activityNum[0];
  selectedStart[0] = start[0];
  selectedFinish[0] = finish[0];
  int lastFinish = finish[0];
  int count = 1;

  for (int i = 1; i < n; i++) {
    if (start[i] >= lastFinish) {
      selectedActivity[count] = activityNum[i];
      selectedStart[count] = start[i];
      selectedFinish[count] = finish[i];
      lastFinish = finish[i];
      count++;
    }
  }
  return count;
}

int main() {
  int n;
  cout << "Enter the number of activities: ";
  cin >> n;

  int activityNum[n], start[n], finish[n];

  cout << "\nEnter activity numbers: ";
  for (int i = 0; i < n; i++)
    cin >> activityNum[i];

  cout << "Enter start times: ";
  for (int i = 0; i < n; i++)
    cin >> start[i];

  cout << "Enter finish times: ";
  for (int i = 0; i < n; i++)
    cin >> finish[i];

  sortActivities(activityNum, start, finish, n);
  display(activityNum, start, finish, n);

  int selectedActivity[n];
  int selectedStart[n];
  int selectedFinish[n];

  int count = selectActivities(activityNum, start, finish, n,
    selectedActivity, selectedStart, selectedFinish);

  display(selectedActivity, selectedStart, selectedFinish, count);

  return 0;
}