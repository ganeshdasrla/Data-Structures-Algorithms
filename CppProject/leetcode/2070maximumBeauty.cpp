#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int n = queries.size();  // Number of queries
    vector<pair<int, int>> new_queries;  // (query_value, original_index)
    
    // Pair each query with its index
    for (int i = 0; i < n; i++) {
        new_queries.push_back({ queries[i], i });
    }

    vector<int> ans(n, 0);  // Result vector, initialized with zeros
    
    // Sort items by price, and by beauty if prices are equal
    sort(items.begin(), items.end());

    // Sort queries by value
    sort(new_queries.begin(), new_queries.end());

    int max_beauty = 0;  // Variable to track maximum beauty found
    
    // Process each query
    for (int j = 0, i = 0; j < n; j++) {
        // Update max_beauty while items' price is within query price
        while (i < items.size() && items[i][0] <= new_queries[j].first) {
            max_beauty = max(max_beauty, items[i][1]);
            i++;
        }
        // Store the maximum beauty found for this query
        ans[j] = max_beauty;
    }
    
    return ans;  // Return the result
}

int main() {
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    vector<int> result = maximumBeauty(items, queries);

    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
