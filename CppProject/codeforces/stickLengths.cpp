    #include <bits/stdc++.h>
    using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());

    // Determine the median
    int median = ar[n / 2];

    // Calculate the total cost to make all sticks equal to the median
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(ar[i] - median);
    }

    cout << sum << endl;

    return 0;
}
