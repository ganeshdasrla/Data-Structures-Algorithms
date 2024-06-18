#include <iostream>

using namespace std;

int fibnanci(int n) {
    if(n <= 1)  return n;
    int ans = fibnanci(n-1) + fibnanci(n-2);
    cout<<ans<<" ";
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<fibnanci(n);
    return 0;
}