#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool compare(pair<double,int> a, pair<double,int> b) {
    return a.first > b.first;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> values(n), weights(n);
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    // ratio and index
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
        ratio[i] = {(double)values[i] / weights[i], i};

    sort(ratio.begin(), ratio.end(), compare);

    double totalValue = 0;
    int remaining = capacity;

    vector<double> taken(n, 0.0);

    for (int k = 0; k < n; k++) {
        if (remaining == 0) break;

        int i = ratio[k].second;
        if (weights[i] <= remaining) {
            taken[i] = 1.0;
            totalValue += values[i];
            remaining -= weights[i];
        } else {
            taken[i] = (double)remaining / weights[i];
            totalValue += values[i] * taken[i];
            remaining = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum value Mr. Einstein can carry: " << totalValue << "\n\n";

    cout << "Selected Items (sorted by value/weight ratio):\n";
    cout << "------------------------------------------------\n";
    cout << left
         << setw(8) << "Item#"
         << setw(8) << "Value"
         << setw(8) << "Weight"
         << setw(8) << "Ratio"
         << setw(10) << "Fraction" << "\n";
    cout << "------------------------------------------------\n";

    double usedWeight = 0;

    for (auto &p : ratio) {
        int i = p.second;
        if (taken[i] > 0) {
            usedWeight += weights[i] * taken[i];
            cout << left
                 << setw(8) << i+1
                 << setw(8) << values[i]
                 << setw(8) << weights[i]
                 << setw(8) << p.first
                 << setw(10) << taken[i] * 100 << "%\n";
        }
    }

    cout << "\nTotal Value: " << totalValue << "\n";
    cout << "Total Weight Used: " << usedWeight << " / " << capacity << "\n";

    return 0;
}
