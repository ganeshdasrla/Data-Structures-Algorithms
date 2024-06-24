/*
The condition "ai+ai+1
 is odd" means that we can only swap elements of different parity. If either the order of even elements or the order of odd elements is not non-decreasing, then it is impossible to sort the sequence. Otherwise, let's prove that it is always possible to sort the sequence. We can for example perform Bubble Sort algorithm. Note that this algorithm only swaps elements ai
 and ai+1
 if ai>ai+1
, so it will never swap two elements of the same parity (given our assumption on their order).
*/
#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        
        if (x % 2 == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    
    if (std::is_sorted(odd.begin(), odd.end()) && std::is_sorted(even.begin(), even.end())) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}