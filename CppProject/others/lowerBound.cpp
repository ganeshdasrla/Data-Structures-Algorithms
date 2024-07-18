#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &ar, int s, int e, int target)
{
    int ans = ar.size();

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] >= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
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
    cout << lowerBound(ar, 0, ar.size() - 1, target);
    return 0;
}
