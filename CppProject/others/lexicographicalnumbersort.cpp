
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool lexicographicalComparator(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    return strA < strB;
}


int main() {
    std::vector<int> numbers = {1, 2, 10, 20, 3, 30, 12, 15};
    
    std::sort(numbers.begin(), numbers.end(), lexicographicalComparator);
    
    std::cout << "Lexicographically sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}