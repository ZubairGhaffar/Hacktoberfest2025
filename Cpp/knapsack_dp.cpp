#include <iostream>
#include <vector>
using namespace std;

/*
 * 0/1 KNAPSACK PROBLEM (DYNAMIC PROGRAMMING)
 * -------------------------------------------
 * Time Complexity: O(N * W)
 * Space Complexity: O(N * W)
 * 
 * Problem Statement:
 * Given weights[] and values[] of N items and a knapsack capacity W,
 * find the maximum total value that can be obtained by including
 * or excluding each item (only once).
 */

int knapsack(int W, vector<int>& weights, vector<int>& values, int N) {
    // DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build DP table bottom-up
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Option 1: Include the current item
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                // Option 2: Exclude the current item
                int exclude = dp[i - 1][w];
                // Take maximum of both
                dp[i][w] = max(include, exclude);
            } else {
                // If item too heavy, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum value
    return dp[N][W];
}

int main() {
    // Number of items
    int N = 4;

    // Values (profits) and Weights of items
    vector<int> values = {60, 100, 120, 80};
    vector<int> weights = {10, 20, 30, 40};

    // Maximum weight capacity of the knapsack
    int W = 50;

    int maxValue = knapsack(W, weights, values, N);

    cout << "Maximum value that can be obtained = " << maxValue << endl;

    return 0;
}
