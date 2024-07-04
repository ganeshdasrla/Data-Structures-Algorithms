#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to merge two sorted subarrays A[l...m] and A[m+1...r]
    void merge(vector<int>& nums, int l, int m, int r) {
        // Calculate sizes of two subarrays
        int size_A = m - l + 1;
        int size_B = r - m;

        // Create temporary arrays A and B
        vector<int> A(size_A);
        vector<int> B(size_B);

        // Copy data to temporary arrays A[] and B[]
        for (int i = 0; i < size_A; i++) {
            A[i] = nums[l + i];
        }
        for (int j = 0; j < size_B; j++) {
            B[j] = nums[m + 1 + j];
        }

        // Merge the temporary arrays back into nums[l...r]
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = l; // Initial index of merged subarray

        // Compare elements from A[] and B[] and merge into nums[]
        while (i < size_A && j < size_B) {
            if (A[i] <= B[j]) {
                nums[k++] = A[i++];
            } else {
                nums[k++] = B[j++];
            }
        }

        // Copy remaining elements of A[], if any
        while (i < size_A) {
            nums[k++] = A[i++];
        }

        // Copy remaining elements of B[], if any
        while (j < size_B) {
            nums[k++] = B[j++];
        }
    }

    // Merge sort function to recursively sort the array
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return; // Base case: when l and r are the same or l > r

        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Recursively sort first and second halves
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        // Merge the sorted halves
        merge(nums, l, m, r);
    }

    // Function to call merge sort and return sorted array
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};

int main() {
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    Solution solution;
    vector<int> sorted_nums = solution.sortArray(nums);

    // Print sorted array
    cout << "Sorted array: ";
    for (int num : sorted_nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
