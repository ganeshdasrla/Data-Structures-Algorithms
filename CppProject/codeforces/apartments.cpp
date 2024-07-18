#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> apartments[i];
    }

    // Sort both arrays
    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, matches = 0;

    // Two-pointer technique to find matches
    while (i < n && j < m)
    {
        if (abs(desired[i] - apartments[j]) <= k)
        {
            // Found a match
            matches++;
            i++;
            j++;
        }
        else if (apartments[j] < desired[i] - k)
        {
            // Apartment is too small, move to the next apartment
            j++;
        }
        else
        {
            // Desired size is too small, move to the next applicant
            i++;
        }
    }

    cout << matches << endl;
    return 0;
}
