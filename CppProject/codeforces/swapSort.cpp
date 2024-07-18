#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortWithSwaps(vector<int>& ar, int n) {
    vector<pair<int, int>> swaps;

    for (int i = 0; i < n; ++i) {
        int min_index = i;

        for (int j = i + 1; j < n; ++j) {
            if (ar[j] < ar[min_index]) {
                min_index = j;
            }
        }

        if (i != min_index) {
            swap(ar[i], ar[min_index]);
            swaps.push_back({i, min_index});
        }
    }

    cout << swaps.size() << endl;
    for (const auto& swap : swaps) {
        cout << swap.first << " " << swap.second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    sortWithSwaps(array, n);

    return 0;
}
