#include <bits/stdc++.h>
using namespace std;

int ffunc(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x;
        x /= 10;
    }
    return ans;
}

int inverse(int n)
{
    int left = 0, right = n;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int f_x = ffunc(mid);
        if (f_x == n)
        {
            return mid;
        }
        else if (f_x < n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << inverse(n);
}