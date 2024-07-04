#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Tortoise and Hare (Cycle Detection) Algorithm
        int tortoise = nums[0];
        int hare = nums[0];

        // Phase 1: Finding the intersection point
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Phase 2: Finding the entrance to the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = solution.findDuplicate(nums);
    std::cout << "The duplicate number is: " << duplicate << std::endl;
    return 0;
}