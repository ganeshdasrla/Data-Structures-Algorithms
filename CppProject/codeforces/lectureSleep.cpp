#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    // Prefix sums
    vector<int> pre(n + 1, 0), pre_weighted(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
        pre_weighted[i + 1] = pre_weighted[i] + t[i] * a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int st = i;
        int en = i + k - 1;
        if (en >= n)
            break;

        // Calculate theorems if we keep Mishka awake from [st, en]
        int curr = pre_weighted[st] + (pre[en + 1] - pre[st]) + (pre_weighted[n] - pre_weighted[en + 1]);
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}
