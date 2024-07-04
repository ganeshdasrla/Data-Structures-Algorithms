#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    if (k == 0)
    {
        cout << (a[0] == 1 ? -1 : 1);
        return 0;
    }
    if (k == n)
    {
        cout << a.back();
        return 0;
    }
    else
    {
        if (a[k] == a[k - 1])
        {
            cout << -1;
            return 0;
        }
        else
        {
            cout << a[k - 1];
            return 0;
        }
    }
    return 0;
}