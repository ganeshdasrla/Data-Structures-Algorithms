#include <bits/stdc++.h>

using namespace std;

long long reqBalloons(vector<int> &balloonsNeeded, vector<int> &candiesPerBalloon, long long maxCandies)
{
    long long totalBalloons = 0;
    int n = balloonsNeeded.size();

    for (int i = 0; i < n; i++)
    {
        long long maxBalloons = balloonsNeeded[i] - maxCandies / candiesPerBalloon[i];
        if (maxBalloons < 0)
        {
            maxBalloons = 0;
        }
        totalBalloons += maxBalloons;
    }
    return totalBalloons;
}

long long minimizeMaxCandies(vector<int> &balloonsNeeded, vector<int> &candiesPerBalloon, long long totalBalloons)
{
    long long low = 0;
    long long high = LONG_MAX;
    long long ans = high;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (reqBalloons(balloonsNeeded, candiesPerBalloon, mid) <= totalBalloons)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<int> balloonsNeeded(n);
    vector<int> candiesPerBalloon(n);

    for (int i = 0; i < n; i++)
    {
        cin >> balloonsNeeded[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> candiesPerBalloon[i];
    }

    cout << minimizeMaxCandies(balloonsNeeded, candiesPerBalloon, m) << endl;

    return 0;
}
