#include<iostream>
using namespace std;

int pow(int x, int n) {
    if(n == 0) return 1;
    
    if(n%2  == 0) {
        int half = pow(x, n / 2);
        return half * half;

    } else {
        int half = pow(x, n / 2);
        return x * half * half;
    }
}

int main() {
    int n, x;
    cin>>x>>n;
    cout<<pow(x, n);
    return 0;
}
