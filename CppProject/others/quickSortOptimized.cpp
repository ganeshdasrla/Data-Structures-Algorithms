#include <iostream>
#include <vector>

using namespace std;

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

int randomPivot(vector<int>& arr, int l, int r) {
    int random_index = l + (rand() % (r-l+1));
    swap(arr[random_index], arr[r]);
    return pivot(arr, l , r);
}

void quickSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int p = randomPivot(arr, l, r);

    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

int main() {
    vector<int> arr = {10, 6, 12, 1, 11, 8, 13, 2, 5, 9};

    int n = arr.size();
    quickSort(arr, 0, n-1);
    
    for(int num : arr) {
        cout<<num<<" ";
    }

    return 0;
}
