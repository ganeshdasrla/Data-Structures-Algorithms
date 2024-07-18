#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &ar, int target)
{
    int l = 0;
    int r = ar.size() - 1;
    int m = (l + r) / 2;

    while (l <= r)
    {
        if (ar[m] > target)
        {
            l = m + 1;
        }
        else if (ar[m] < target)
        {
            r = m - 1;
        }
        else
        {
            return true;
        }
        m = (l + r) / 2;
    }
    return false;
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
    cout << binarySearch(ar, target);
    return 0;
}