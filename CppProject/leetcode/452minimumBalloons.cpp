#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customSort(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), customSort);
    int n = points.size();

    int needed_arrows = 1;
    int i = 1;
    int end = points[0][1];
    while (i < n)
    {
        if (points[i][0] > end)
        {
            needed_arrows++;
            end = points[i][1];
        }
        i++;
    }
    return needed_arrows;
}

int main()
{
    vector<vector<int>> nums = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int ans = findMinArrowShots(nums);
    std::cout << "The minimum ballons are: " << ans << std::endl;
    return 0;
}
