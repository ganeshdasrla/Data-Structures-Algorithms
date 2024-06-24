#include <iostream>
#include <vector>
using namespace std;

vector<int> pattern(int N){
    // code here
    vector<int> ans;
    int num = N;
    bool isDecreasing = true;
    while(true) {
        if(num > 0 && isDecreasing) {
            ans.push_back(num);
            num = num-5;
        } else {
            isDecreasing = false;
            if(num > N){
                break;
            }
            ans.push_back(num);
            num = num+5;
        }
    }
    return ans;
}

int main() {
    vector<int> result = pattern(16);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}