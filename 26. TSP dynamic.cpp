#include <stdio.h>
#include <limits.h>

// Number of cities
#define N 4

// Memoization table
int dp[1 << N][N];

// Distance matrix
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

// Utility function to find minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the TSP problem using dynamic programming and bit masking
int tsp(int mask, int pos) {
    if (mask == ((1 << N) - 1)) {
        // All cities have been visited, return to the starting city
        return dist[pos][0];
    }

    // Check if result is already computed
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int answer = INT_MAX;
    for (int city = 0; city < N; city++) {
        // If the city has not been visited yet
        if ((mask & (1 << city)) == 0) {
            // Recur to find the minimum cost path
            int newAnswer = dist[pos][city] + tsp(mask | (1 << city), city);
            answer = min(answer, newAnswer);
        }
    }

    // Store the result in dp table
    dp[mask][pos] = answer;
    return answer;
}

int main() {
    // Initialize the memoization table with -1
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from the first city (index 0) with mask 1 (indicating city 0 is visited)
    int result = tsp(1, 0);

    printf("The minimum cost to visit all cities is: %d\n", result);
    return 0;
}

