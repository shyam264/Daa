#include <stdio.h>

// Define a large value for infinity
#define INF 1000000

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to find the optimal cost of the binary search tree
int optimalBST(int keys[], int freq[], int n) {
    int cost[n+1][n+1]; // Cost matrix
    int i, j, k, len;

    // Initialize the cost matrix for single keys
    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Fill the cost matrix for all lengths of subtrees
    for (len = 2; len <= n; len++) { // Length of the chain
        for (i = 0; i <= n - len; i++) {
            j = i + len - 1;
            cost[i][j] = INF; // Initialize to a large value
            
            // Calculate the sum of frequencies from i to j
            int freqSum = sum(freq, i, j);

            // Try making all keys in interval keys[i..j] as root
            for (k = i; k <= j; k++) {
                // Cost when keys[k] becomes root
                int c = ((k > i) ? cost[i][k - 1] : 0) +
                        ((k < j) ? cost[k + 1][j] : 0) +
                        freqSum;

                // Update cost[i][j] if we get a lower cost
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    // The optimal cost is in cost[0][n-1]
    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20}; // Example keys
    int freq[] = {34, 8, 50};  // Frequencies corresponding to the keys
    int n = sizeof(keys) / sizeof(keys[0]); // Number of keys

    printf("The cost of the Optimal Binary Search Tree is: %d\n", optimalBST(keys, freq, n));
    return 0;
}

