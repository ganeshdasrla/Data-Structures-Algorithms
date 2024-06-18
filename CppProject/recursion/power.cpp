#include <iostream>

using namespace std;

int power(int i, int n) {
    if(i > n ) return 1;
    int ans = n * power(i+1, n);
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<power(1, n);
    return 0;
}