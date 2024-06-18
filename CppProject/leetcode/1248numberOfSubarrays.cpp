#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


int numberOfSubarrays(vector<int>& nums, int k) {
    vector<int> even;
    int temp = 0, ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] % 2 == 0) {
            temp++;
        }
        else {
            even.push_back(temp);
            temp = 0;
        }
    }
    even.push_back(temp);
    // for(int i = 0; i < even.size(); i++) {
    //     cout<<even[i]<<" ";
    // }
    int m = even.size();
    for(int i = 0; i < m-k; i++) {
        ans += (even[i]+1) * (even[i+k]+1);
    }

    return ans;
}

int main(){
    std::vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int result = numberOfSubarrays(nums, 2);
    std::cout << "Result: " << result << std::endl;
    return result;
}