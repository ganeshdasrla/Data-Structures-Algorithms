#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;

    set<char> stt;
    for(int i = 0; i < n; i++) {
        stt.insert(s[i]);
        ans+=stt.size();
    }
    cout<<ans<<endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
