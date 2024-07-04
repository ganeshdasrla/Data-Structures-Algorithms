#include <iostream>
#include <vector>

using namespace std;

// int quickSort(vector<int> &arr) {
//     int n = arr.size();
//     int pivot = arr[n-1];

//     int p = -1;
//     int j = 1;
//     while(j < n-1) {
//        if (arr[j] < pivot) {
//             p++;
//             swap(arr[p], arr[j]);
//         }
//         j++;
//     }
    
//     swap(arr[p + 1], pivot); // Place the pivot in its correct position
//     return p + 1; // Return the pivot index
// }

int pivot(vector<int>& arr, int l, int r) {
    int pivot_num = arr[r];
    int dash = l;
    for(int i = l; i < r; i++) {
        if(arr[i] <= pivot_num){
            swap(arr[i], arr[dash]);
            dash++;
        }
    }
    swap(arr[dash], arr[r]);
    return dash;
}

void quickSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int p = pivot(arr, l, r);

    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}



int main() {
    vector<int> arr = {10, 6, 12, 1, 11, 8, 13, 2, 5, 9};

    int n = arr.size();

    // int pi = quickSort(arr);
    // cout<<pi;

    quickSort(arr, 0, n-1);
    
    for(int num : arr) {
        cout<<num<<" ";
    }

    return 0;
}
