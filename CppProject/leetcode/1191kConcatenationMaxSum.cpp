#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int kadanes(vector<int> &arr)
{
    int csum = arr[0];
    int msum = max(0, csum);

    for (int i = 1; i < arr.size(); i++)
    {
        if (csum >= 0)
        {
            csum += arr[i];
        }
        else
        {
            csum = arr[i];
        }

        if (csum > msum)
        {
            msum = csum;
        }
    }
    return msum;
}

int kadanesoftwo(vector<int> &arr)
{
    vector<int> narr(arr.size() * 2);
    for (int i = 0; i < arr.size(); i++)
    {
        narr[i] = arr[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        narr[i + arr.size()] = arr[i];
    }
    return kadanes(narr);
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (k == 1)
    {
        return kadanes(arr);
    }
    else if (sum < 0)
    {
        return kadanesoftwo(arr);
    }
    else
    {
        return kadanesoftwo(arr) + (k - 2) * sum;
    }
}

int main()
{
    vector<int> arr1 = {1, 2};
    int k1 = 3;
    cout << "Input: [1, 2], k = 3" << endl;
    cout << "Output: " << kConcatenationMaxSum(arr1, k1) << endl;

    vector<int> arr2 = {1, -2, 1};
    int k2 = 5;
    cout << "Input: [1, -2, 1], k = 5" << endl;
    cout << "Output: " << kConcatenationMaxSum(arr2, k2) << endl;

    vector<int> arr3 = {-1, -2};
    int k3 = 7;
    cout << "Input: [-1, -2], k = 7" << endl;
    cout << "Output: " << kConcatenationMaxSum(arr3, k3) << endl;

    return 0;
}
