#include <stdio.h>

// Function to find the optimal cost using dynamic programming
int knapsack(int weights[], int values[], int capacity, int n) {
    int dp[n+1][capacity+1];
    int i, j;

    // Initialize the base cases
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= capacity; j++) {
        dp[0][j] = 0;
    }

    // Fill in the rest of the table
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= capacity; j++) {
            if (weights[i-1] <= j) {
                dp[i][j] = (values[i-1] + dp[i-1][j-weights[i-1]]) > dp[i-1][j] ? (values[i-1] + dp[i-1][j-weights[i-1]]) : dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // The optimal cost is stored in the bottom-right corner of the table
    return dp[n][capacity];
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {10, 20, 30, 40};
    int capacity = 10;
    int n = sizeof(weights)/sizeof(weights[0]);
    printf("Optimal cost: %d\n", knapsack(weights, values, capacity, n));
    return 0;
}