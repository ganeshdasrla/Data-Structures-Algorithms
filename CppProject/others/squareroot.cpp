#include <bits/stdc++.h>
using namespace std;

int sqrt(int x)
{
    if (x == 0 || x == 1)
        return x;

    for (int i = 0; i < x; i++)
    {
        if (i * i > x)
            return i - 1;
    }
    return 0;
}

int main()
{
    int x;
    cin >> x;
    cout << sqrt(x);
    return 0;
}