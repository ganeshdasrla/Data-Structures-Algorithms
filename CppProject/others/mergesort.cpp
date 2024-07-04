#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
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

    while (i < size_A && j < size_B) {
        if (A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
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
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> arr = {4, 3, 21, 2, 34, 5, 6, 43, 5, 67, 73, 5, 4};

    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
