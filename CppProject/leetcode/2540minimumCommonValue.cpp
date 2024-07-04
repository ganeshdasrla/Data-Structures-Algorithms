#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> countMap;
    for(int num : nums1) {
        countMap[num]++;
    }

    unordered_map<int, int> commonCountMap;
    for(int num : nums2) {
        if(countMap.find(num) != countMap.end()) {
            commonCountMap[num]++;
        }
    }

    int max_count = INT_MIN;
    int num = INT_MAX;
    for(const auto& pair : commonCountMap) {
        if(pair.second > max_count || (pair.second == max_count && pair.first < num)) {
            max_count = pair.second;
            num = pair.first;
        }
    }

    return num == INT_MAX ? -1 : num; // return -1 if no common element is found
}

int main() {
    vector<int> nums1 = {1, 2, 8, 12, 32, 34, 43, 52, 57, 62, 64, 67, 71, 71, 79, 81, 86, 91, 93, 94};
    vector<int> nums2 = {9, 11, 12, 14, 19, 25, 29, 31, 38, 39, 41, 42, 58, 63, 66, 70, 71, 73, 91, 91};
    int result = getCommon(nums1, nums2);
    cout << "Result: " << result << endl;
    return 0;
}
