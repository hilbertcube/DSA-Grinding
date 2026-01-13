#include "headers.hpp"

// 0/1 Knapsack problem
int knapSack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D DP table with (n+1) rows and (W+1) columns, initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            // Get the weight and value of the current item (using 0-based indexing)
            int currentWeight = weights[i - 1];
            int currentValue = values[i - 1];

            // If the current item's weight is less than or equal to the current capacity 'w'
            if (currentWeight <= w) {
                // Option 1: Include the item. Value is its value plus the max value 
                // of the remaining capacity using previous items.
                int includeValue = currentValue + dp[i - 1][w - currentWeight];

                // Option 2: Exclude the item. Value is the same as the max value
                // without considering this item.
                int excludeValue = dp[i - 1][w];

                // Store the maximum of the two options
                dp[i][w] = max(includeValue, excludeValue);
            } else {
                // If the item cannot fit, it must be excluded
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is the maximum value that can be put in a knapsack of capacity W
    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // Maximum knapsack capacity
    int n = values.size(); // Number of items

    cout << "Maximum value for knapsack capacity " << W << ": "
         << knapSack(W, weights, values, n) << endl;

    return 0;
}