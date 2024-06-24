#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int n = a.size();
    vector<vector<int>> subarray;
    int start = 0, end = 0;
    long long sum = 0;

    while (end < n) {
        // Add the current element to the sum
        sum += a[end];

        // While the sum exceeds k, slide the window from the left
        while (sum > k && start <= end) {
            sum -= a[start];
            start++;
        }

        // If the sum equals k, store the current subarray
        if (sum == k) {
            vector<int> currentSubarray;
            for (int i = start; i <= end; i++) {
                currentSubarray.push_back(a[i]);
            }
            subarray.push_back(currentSubarray);
        }

        // Move the end pointer to the right
        end++;
    }
    sort(subarray.begin(), subarray.end());

    return subarray;
}

int main() {
    vector<int> a = {1, 2, 3, 1, 1, 1};
    long long k = 3;
    vector<vector<int>> result = subarraysWithSumK(a, k);

    for (const auto& sub : result) {
        for (int num : sub) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
