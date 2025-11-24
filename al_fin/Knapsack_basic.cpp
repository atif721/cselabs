#include <iostream>
using namespace std;

int knapsack(int value[], int weight[], int capacity, int size) {
  int profit = 0;
  int netValue[size];
  for (int i = 0; i < size; i++) {
    netValue[i] = value[i] / weight[i];
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (netValue[j] < netValue[j + 1]) {
        swap(netValue[j], netValue[j + 1]);
        swap(value[j], value[j + 1]);
        swap(weight[j], weight[j + 1]);
      }
    }
  }

  int i = 0;
  while (capacity > 0) {
    int currentWeight = weight[i];
    int currentValue = value[i];
    int currNetValue = netValue[i];

    if (capacity <= currentWeight) {
      profit += capacity * currNetValue;
      capacity = 0;
    } else {
      capacity -= currentWeight;
      profit += currentValue;
    }
    i++;
  }

  return profit;
}

int main() {
  int capacity;
  int size;

  cout << "Enter number of items : ";
  cin >> size;

  cout << "Enter capacity : ";
  cin >> capacity;

  int value[size];
  int weight[size];

  cout << "Enter values : ";
  for (int i = 0; i < size; i++) {
    cin >> value[i];
  }

  cout << "Enter weight : ";
  for (int i = 0; i < size; i++) {
    cin >> weight[i];
  }

  int result = knapsack(value, weight, capacity, size);
  cout << "Maximum Profit : " << result << endl;
}