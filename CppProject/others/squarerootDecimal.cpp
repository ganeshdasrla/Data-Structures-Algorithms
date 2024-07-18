#include <bits/stdc++.h>
using namespace std;

double sqrt(double x, int p)
{
    if (x == 0 || x == 1)
        return x;

    double precision = pow(10, -p);
    double left = 0, right = x, ans = 0;

    while ((right - left) > precision)
    {
        double mid = left + (right - left) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return ans;
}

int main()
{
    double x;
    int p;
    cin >> x >> p;
    double ans = sqrt(x, p);
    cout << fixed << setprecision(p) << ans << endl;
    return 0;
}
