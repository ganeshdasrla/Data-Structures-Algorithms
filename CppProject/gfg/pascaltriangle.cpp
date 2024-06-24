#include <iostream>
#include <vector>
using namespace std;

vector<long long> nthRowOfPascalTriangle(int n) {
    vector<long long> ans(n, 1);
    long long mod = 1e9+7;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j > 0; j--) {
            ans[j] = (ans[j] + ans[j-1]) % mod;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> result = nthRowOfPascalTriangle(N);
    
    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
