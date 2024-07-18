#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &ar, int target, int l, int r)
{
    if (l > r)
        return false;

    int m = (l + r) / 2;
    if (ar[m] == target)
    {
        return true;
    }
    else if (ar[m] > target)
    {
        return binarySearch(ar, target, l, m - 1);
    }
    else
    {
        return binarySearch(ar, target, m + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());

    int target;
    cin >> target;
    cout << binarySearch(ar, target, 0, ar.size() - 1);
    return 0;
}