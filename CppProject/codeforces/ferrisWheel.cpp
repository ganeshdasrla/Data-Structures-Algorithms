#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());
    int i = 0, j = n - 1;

    int count = 0;
    while (i <= j)
    {
        if (ar[i] + ar[j] <= x)
        {
            i++;
        }
        count++;
        j--;
    }
    cout << count;
    return 0;
}