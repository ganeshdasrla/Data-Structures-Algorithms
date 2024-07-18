// https://www.spoj.com/problems/PRATA/

#include <iostream>
#include <limits>

using namespace std;

long long maxByCook(long long rank, long long time_allowed) {
    long long beg = 0, end = time_allowed, ans = -1;

    while (beg <= end) {
        long long mid = (beg + end) / 2;

        // Calculate time for mid paratas using integer overflow prevention
        long long paratas_to_cook = rank * (mid + 1) * mid;
        if (paratas_to_cook > numeric_limits<long long>::max() / rank) {
            return -1; // Overflow case
        }
        long long time_for_mid = paratas_to_cook / 2;

        if (time_for_mid <= time_allowed) {
            ans = mid;
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

long long maxParatas(long long t, long long r[], int n) {
    long long total_paratas = 0;

    for (int i = 0; i < n; ++i) {
        long long cooked_by_one = maxByCook(r[i], t);
        if (cooked_by_one == -1) {
            return -1; // Overflow case
        }
        total_paratas += cooked_by_one;
    }

    return total_paratas;
}

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long p, n;
        cin >> p >> n;

        long long r[n];
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }

        long long beg = 0, end = (r[0] * p * (p + 1)) / 2, ans = -1;

        while (beg <= end) {
            long long mid = (beg + end) / 2;

            if (maxParatas(mid, r, n) >= p) {
                ans = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
