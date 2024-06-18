#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int i = 0, j = 0, count = 0, sum = 0, temp = 0;
    //temp is used to store the previous count of valid subarrays.
    while (j<nums.size()) {
        sum += nums[j];
        if (nums[j] == 1){
            temp = 0;
        } 
        if (sum > goal) {
            sum -= nums[i];
            i++;
        }
        while (sum == goal && i <= j) {
            temp++;
            sum -= nums[i];
            i++;
        }
        j++;
        count += temp;
    }
    return count; 
}

int main() {
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Result for nums1: " << numSubarraysWithSum(nums1, goal1) << endl;  // Output should be 4

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Result for nums2: " << numSubarraysWithSum(nums2, goal2) << endl;  // Output should be 15

    return 0;
}
