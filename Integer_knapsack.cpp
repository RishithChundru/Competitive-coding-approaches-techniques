#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack Problem
int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();

    // Create a DP table with dimensions (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Option to include or exclude the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // Cannot include the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[n][W]
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values);
    cout << "The maximum value that can be achieved is: " << maxValue << endl;

    return 0;
}
