#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0; // If there is only one element, no jumps needed
    
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= n - 1) break; // If we can reach or exceed the last index, no need to continue
        }
    }
    
    return jumps;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: [2, 3, 1, 1, 4]" << endl;
    cout << "Minimum number of jumps: " << jump(nums1) << endl;
    
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "\nInput: [2, 3, 0, 1, 4]" << endl;
    cout << "Minimum number of jumps: " << jump(nums2) << endl;
    
    return 0;
}
