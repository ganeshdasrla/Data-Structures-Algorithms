#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double root(double x, int n)
{
    if (x == 0.0)
        return 0.0; // Edge case: root of 0 is 0

    double low = 0.0;
    double high = x;
    double mid = 0.0;
    double error = 0.001;

    while (high - low > error)
    {
        mid = low + (high - low) / 2.0;
        double mid_pow_n = pow(mid, n);

        if (fabs(mid_pow_n - x) < error)
        {
            return mid;
        }
        else if (mid_pow_n > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return mid;
}

int main()
{
    double x1 = 7.0;
    int n1 = 3;
    cout << fixed << setprecision(3);
    cout << "root(" << x1 << ", " << n1 << ") = " << root(x1, n1) << endl;

    double x2 = 9.0;
    int n2 = 2;
    cout << "root(" << x2 << ", " << n2 << ") = " << root(x2, n2) << endl;

    return 0;
}
