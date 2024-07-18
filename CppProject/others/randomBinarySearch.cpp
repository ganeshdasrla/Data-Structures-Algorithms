#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int ans = 0;
    vector<int> prefMax(n), sufMin(n);
    prefMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefmax[i] = max(prefMax[i - 1], ar[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sufMin[i] = min(sufMin(i + 1), ar[i]);
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        if (i > 0)
            flag = false & (ar[i] > prefMax[i - 1]);
        if (i < n - 1)
            flag = false & (ar[i] < sufMin[i + 1]);
        if (flag)
            ans++;
    }
    cout<<ans;
    return 0;
}