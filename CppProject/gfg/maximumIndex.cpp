#include <iostream>
#include <climits>
using namespace std;

int maxIndexDiff(int a[], int n) {
    if (n == 1) {
        return 0;
    }
    
    // Create two arrays to store minimum values from left and maximum values from right
    int LMin[n], RMax[n];
    
    // Initialize the first value of LMin and the last value of RMax
    LMin[0] = a[0];
    RMax[n-1] = a[n-1];
    
    // Fill the LMin array
    for (int i = 1; i < n; ++i) {
        LMin[i] = min(a[i], LMin[i-1]);
    }
    
    // Fill the RMax array
    for (int j = n-2; j >= 0; --j) {
        RMax[j] = max(a[j], RMax[j+1]);
    }
    
    // Traverse both arrays to find the maximum j - i such that LMin[i] <= RMax[j]
    int i = 0, j = 0, max_diff = -1;
    while (i < n && j < n) {
        if (LMin[i] <= RMax[j]) {
            max_diff = max(max_diff, j - i);
            j++;
        } else {
            i++;
        }
    }
    
    return max_diff;
}

int main() {
    int a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The maximum index difference is " << maxIndexDiff(a, n) << endl;
    return 0;
}
