#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int size_A = m - l + 1;
    int size_B = r - m;

    vector<int> A(size_A);
    vector<int> B(size_B);

    for (int i = 0; i < size_A; i++) {
        A[i] = arr[l + i];
    }

    for (int i = 0; i < size_B; i++) {
        B[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    long long inversions = 0;

    while (i < size_A && j < size_B) {
        if (A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            inversions += (size_A - i); // Count the inversions
            j++;
        }
        k++;
    }

    while (i < size_A) {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < size_B) {
        arr[k] = B[j];
        j++;
        k++;
    }

    return inversions;
}

long long mergeSortAndCount(vector<int>& arr, int l, int r) {
    long long inversions = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        inversions += mergeSortAndCount(arr, l, m);
        inversions += mergeSortAndCount(arr, m + 1, r);
        inversions += mergeAndCount(arr, l, m, r);
    }
    return inversions;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    long long inversionCount = mergeSortAndCount(arr, 0, n - 1);
    cout << "Number of inversions are: " << inversionCount << endl;

    return 0;
}
